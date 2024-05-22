//here we are basically computing the number of edges in a adj list therefore 
//the time compexity of the prog is O(V+E) the V is there so as to ger the 
//coernor case when none of the node is connected
#include<bits/stdc++.h>
using namespace std ;

//this is for ndirected graphs 
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// here the V is number of vertices and s is the source 
void BFS(vector<int> adj[], bool visited[], int s ){
    
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

int BFS_DIS(vector<int> adj[], int V, int &count){
    bool visited[V+1]={false};
    for(int i = 0; i < V; i++){
        if(visited[i] == false){
            BFS(adj, visited, i);
            count++;
        }
    } 
    return count;
}
 
int main(){
    int V ,E ,count;
    count = 0; //this will count the number of connected components in nthe graph 
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
    }cout << "BFS" << endl;
    BFS_DIS(adj,V, count);
    cout<<"count of connected components:"+count<<endl;



    return 0;

}