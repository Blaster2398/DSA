//to get the topological sorting done we need the indegree array 

#include<bits/stdc++.h>
using namespace std ;

//this is for directed graphs 
void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
}

vector<int> topoSort(vector<vector<int>> &adj, int V){

    vector<int> results;

    // Calculating the indegree of an vertex
    int in_deg[V] = {0};
    for(int i = 0; i < V; i++) {
        for( auto it : adj[i]) {
            in_deg[it]++;
        } 
    }

    // make the queue and add the initial elements 
    queue<int> q;
    for(int i = 0; i < V; i++){
        if( in_deg[i] == 0 ){
            q.push(i);
        }
    }

    //now repetedly do the sorting using while loop
    while( !q.empty() ){
        int ft = q.front();
        cout << ft <<endl;
        q.pop();
        results.push_back(ft);
        
        //decrease the in_deg of the connected nodes by 1
        for(auto i : adj[ft]){
            in_deg[i]--;

            if(in_deg[i] == 0){
                q.push(i);
            }
        }

    }

    // Check for cycle
    if (results.size() != V) {
        cout << "Graph contains cycle!" << endl;
        return {};
    }

    return results;
}
 
int main(){
    int V ,E ;
    // cout << "Enter the number of vertices"<< endl;
    cin >> V;
    vector<vector<int>> adj(V);
    // cout << "Enter the number of edges" << endl;
    cin>> E ;
    // cout << "Enter the directed edges" << endl;
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        addEdge(adj , u, v);
    }

    vector<int> topo = topoSort( adj, V);

    for(auto i : topo){
        cout << i << '-' ;
    }

    return 0;

}