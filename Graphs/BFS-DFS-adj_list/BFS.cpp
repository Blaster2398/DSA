//Billo Bagge Billeyan Da Ki Karegi
//Bagge - Bagge Billeyan Da Ki Karegi

#include<bits/stdc++.h>
using namespace std ;

//this is for ndirected graphs 
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// here the V is number of vertices and s is the source 
void BFS(vector<int> adj[], int V, int s){
    bool visited[V+1]={false};
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(q.empty() == false){
        int u = q.front();
        //now delete and show u in the O/P
        q.pop();
        cout << u <<" ";
        visited[u] = true;
        for(int v: adj[u]){
            if(visited[v] == false){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
 
int main(){
    int V ,E;
    cout << "Enter the number of vertices"<<endl;
    cin >> V;
    vector<int> adj[V];
    cout << "Enter the number of edges" << endl;
    cin>> E ;
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        addEdge(adj , u, v);
    }
    // Print adjacency list
    for(int i = 0; i < V; i++) {
        cout << "Adjacency list of vertex " << i << ": ";
        for(int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    cout << "BFS" << endl;
    BFS(adj, V, 0);



    return 0;

}