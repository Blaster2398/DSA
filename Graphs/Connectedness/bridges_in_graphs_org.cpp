#include<bits/stdc++.h>
using namespace std ;

//make the DFS function called bridgeUtil
void bridgeUtil(int u, vector<int> adj[], vector<bool> &visited, vector<int> &disc, vector<int> &low, int parent, int &time){
    visited[u] = true;
    // update the values of disc and low and then increase the time 
    disc[u] = low[u] = time;
    time++;

    for(auto v : adj[u]){
        if(visited[v] == false){
            bridgeUtil(v,adj,visited,disc,low,u,time);
            
            // check is subtree rooted with v has a connection with one of its ancestors
            low[u] = min( low[u], low[v]);

            // if u is not root and low(children) > disc(parent) then nopde u->v is a bridge 
            if(low[v] > disc[u] ){
                cout << u << " " << v << endl;
            }
        }
        //if v meets a node that is previously discovered and is not its parent then update the low value
        else if( v != parent ){
            low[u] = min( low[u], disc[v] );
        }
    }
}

// make the bridge function that will call the dfs for the disconnected graph 
void bridge( vector<int> adj[], int V){
    vector<bool> visited(V,false);
    vector<int> disc( V, -1);
    vector<int> low( V,-1);
    int time = 0 ;
    int parent =-1;

    //call DFS for disconnected component
    for(int i = 0; i < V; i++){
        if(visited[i] == false){
            bridgeUtil(i , adj, visited, disc, low, parent, time);
        }
    }
}

// Utility function to add an edge
void addEdge( vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// Driver program to test above function
int main()
{
    // Create graphs given in above diagrams
    cout << "\nBridges in first graph \n";
    int V = 5;
    vector<int> adj1[V];
    addEdge( adj1 , 1, 0);
    addEdge( adj1 , 0, 2);
    addEdge( adj1 , 2, 1);
    addEdge( adj1 , 0, 3);
    addEdge( adj1 , 3, 4);
    bridge(adj1,V);

    cout << "\nBridges in second graph \n";
     V = 4;
    vector<int> adj2[V];
    addEdge( adj2 , 0, 1);
    addEdge( adj2 , 1, 2);
    addEdge( adj2 , 2, 3);
    bridge(adj2,V);

    cout << "\nBridges in third graph \n";
    V = 7;
    vector<int> adj3[V];
    addEdge( adj3 , 0, 1);
    addEdge( adj3 , 1, 2);
    addEdge( adj3 , 2, 0);
    addEdge( adj3 , 1, 3);
    addEdge( adj3 , 1, 4);
    addEdge( adj3 , 1, 6);
    addEdge( adj3 , 3, 5);
    addEdge( adj3 , 4, 5);
    bridge( adj3,V);

    return 0;
}
