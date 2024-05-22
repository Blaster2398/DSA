
#include<bits/stdc++.h>
using namespace std ;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);

}

void DFS(vector<int> adj[], int s, bool visited[]){
    visited[s] = true;
    cout << s << " ";
    for(int u : adj[s]){
        if(visited[u] == false){
            DFS(adj, u, visited);
        }
    }

}

int main(){
    int V , E;
    cout<<"Enter the number of verices and edges"<<endl;
    cin >> V >> E;
    vector<int> adj[V];
    cout << "Enter the u and v values of edge " << endl;
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    bool visited[V] = {false};
    
    int s;
    cout << "Enter the starting node ";
    cin >> s;
    cout << "here is the DFS traversal :";

    // this loop will take care of the disconnected part
    for( int i = 0; i < V; i++){
        if(visited[i] == false){
            DFS(adj, s, visited);
        }
    }

    return 0;
}