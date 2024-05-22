
#include<bits/stdc++.h>
using namespace std ;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);

}

bool DFS(vector<int> adj[], int s, bool visited[], int parent){
    visited[s] = true;
    
    for(int u : adj[s]){
        if(visited[u] == false){
            parent = s;
            if(DFS(adj, u, visited, parent) == true){
                return true;
            }
        }
        else if(parent != u ){  // this wil check is that visited node is not then just parent of the node u
            return true;
        }
    }
    return false;
}

int main(){
    int V , E;
    // cout<<"Enter the number of verices and edges"<<endl;
    cin >> V >> E;
    
    vector<int> adj[V];
    // cout << "Enter the u and v values of edge " << endl;
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    
    bool visited[V];
    for(int i =0; i < V; i++){
        visited[i] = false;
    }

    int parent;
    int cycle =0;
    // this loop will take care of the disconnected part
    for( int i = 0; i < V; i++){
        if(visited[i] == false){
            if(DFS(adj, i, visited,-1)==true){
                cycle = 1;
            }
        }
    }

    cout <<(cycle == 1 ? "yes there is a cycle":"No there is no cycle" )<<endl;

    return 0;
}