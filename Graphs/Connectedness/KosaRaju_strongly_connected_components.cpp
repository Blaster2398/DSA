#include<bits/stdc++.h>
using namespace std ;
#define V 5

// make the adjecency list 
void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
}

void topoSort(int u, vector<bool>& visited, stack<int>& Stack, vector<vector<int>> &adj){
    visited[u] = true;
    for(auto v : adj[u]){
        if(visited[v] == false){
            topoSort(v, visited, Stack, adj);
        }
    }
    Stack.push(u);
}

void getTranspose(vector<vector<int>> & adj, vector<vector<int>> & trans){
    for(int u = 0; u < V; u++){
        for( auto v : adj[u]){
            trans[v].push_back(u);
        }
    }
}

void DFS(int s, vector<vector<int>> & transAdj, vector<bool>& visited){ //this will find the final DFS also print the result 
    visited[s] = true;
    cout << s << " ";
    for( auto v : transAdj[s]){
        if(visited[v] == false){
            DFS(v, transAdj, visited);
        }
    }

}

// this is the main function which will do the 3 steps 
// Step 1: do topological sorting using DFS
// Step 2: transpose the adjecency list
// Step 3: do DFS according to the O/P of Step 1
void printSSCs(vector<vector<int>> & adj){
    // intialization 
    stack<int> Stack;
    vector<bool> visited(V,false);
    vector<vector<int>> transAdj(V);

    //do a DFS for Disconnected graph / topological sorting
    for( int i = 0; i < V; i++){
        if(visited[i] ==false){
            topoSort(i, visited, Stack, adj);
        }
    }
    
    // take the transpose of the adj list
    getTranspose(adj,transAdj);

    //reinitialize visited array for DFS once more
    fill(visited.begin(), visited.end(), false);

    while( !Stack.empty() ){
        int v = Stack.top();
        Stack.pop();

        if( visited[v] == false ){
            DFS(v, transAdj, visited);
            cout << endl; // for differentiating with the different Stronglly connected components 
        }
    }
}





int main(){
    vector<vector<int>> adj(V);

    addEdge(adj, 1, 0);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);

    cout << "Following are the SCC's " << endl;
    printSSCs(adj);
    return 0;
}