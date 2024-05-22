#include<bits/stdc++.h>
using namespace std ;

void apUtil(int u, vector<int> adj[], vector<bool> &visited, vector<int>& disc, vector<int>& low, int time, int parent, vector<bool> & isAP){
    visited[u] = true;
    int children = 0;  // this is to check if the root node is a AP or not 
    
    // as low for any node can be equal to or less than the discovery time never greater 
    disc[u] = low[u] = time;
    time++;

    for( auto v : adj[u]){
        if(visited[v] == false){
            children++;
            apUtil(v,adj,visited,disc,low,time,u,isAP);
            
            // check is subtree rooted with v has a connection with one of its ancestors
            low[u] = min( low[u], low[v]);

            // if u is not root and low(children) > disc(parent) then nopde u is AP
            if(parent != -1 && low[v] >= disc[u] ){
                isAP[u] = true;
            }
        }

        //if v meets a node that is previously discovered and is not its parent then update the low value
        else if( v != parent ){
            low[u] = min( low[u], disc[v] );
        }
    }
    //if u is the root of the DFS and has more than 1 children then its a AP
    if( parent == -1 && children > 1 ){
        isAP[u] = true;
    }
}

void AP(vector<int> adj[], int V){
    // initialization
    vector<int> disc(V,0);
    vector<int> low(V);
    vector<bool> visited(V, false);
    vector<bool> isAP(V, false);
    int time = 0 , parent = -1;

    //we are doing this for disconnected graph so use a loop of DFS
    for(int u = 0; u < V; u++){
        if(visited[u] == false){
            apUtil(u, adj, visited, disc, low, time, parent, isAP);
        }
    }
    //printing the AP's
    for(int i = 0; i < V; i++)
        if(isAP[i] == true)
            cout << i << " ";

}

// Utility function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}


int main()
{
    // Create graphs given in above diagrams
    cout << "Articulation points in first graph \n";
    int V = 5;
    vector<int> adj1[V];
    addEdge(adj1, 1, 0);
    addEdge(adj1, 0, 2);
    addEdge(adj1, 2, 1);
    addEdge(adj1, 0, 3);
    addEdge(adj1, 3, 4);
    AP(adj1, V);

    cout << "\nArticulation points in second graph \n";
    V = 4;
    vector<int> adj2[V];
    addEdge(adj2, 0, 1);
    addEdge(adj2, 1, 2);
    addEdge(adj2, 2, 3);
    AP(adj2, V);

    cout << "\nArticulation points in third graph \n";
    V = 7;
    vector<int> adj3[V];
    addEdge(adj3, 0, 1);
    addEdge(adj3, 1, 2);
    addEdge(adj3, 2, 0);
    addEdge(adj3, 1, 3);
    addEdge(adj3, 1, 4);
    addEdge(adj3, 1, 6);
    addEdge(adj3, 3, 5);
    addEdge(adj3, 4, 5);
    AP(adj3, V);

    return 0;
}