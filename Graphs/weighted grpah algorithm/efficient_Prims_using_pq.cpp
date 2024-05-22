// this is an efficient implementation of the prims algo with the use of prioriyty queue 
// here we will only print the cost of the MST 
#include<bits/stdc++.h>
using namespace std ;

typedef pair<int,int> pii;

int  primsSpanningTree(int V, int E, int graph[][3]){

    int res = 0;   // this is the result that is going to be returned 

    vector<vector<pii>> adj(V);
    // we have to create a adj list with vector pair 
    for(int i =0; i < E; i++){
        int u = graph[i][0];
        int v = graph[i][1];
        int wt = graph[i][2];
        adj[u].push_back({wt, v});
        adj[v].push_back({wt, u});
    }

    // create a pq and a visited vector
    priority_queue<pii, vector<pii>,greater<pii>> poq;
    vector<bool> visited(V, false);

    poq.push({0,0});

    while(!poq.empty()){
        auto ft = poq.top();
        poq.pop();

        int wt = ft.first;
        int u = ft.second;

        // if u is already visited then just continuen this loop 
        if(visited[u] == true){
            continue;
        }

        visited[u] = true;
        res = res + wt;

        // now push those nodes from the adj list those are not visited 
        for(auto v : adj[u]){
            if(visited[v.second] == false){
                poq.push({v.first,v.second});
            }
        }
    }
    return res ;
}


int main(){
    int graph[][3] = {{0, 1, 5},
                      {1, 2, 3},
                      {0, 2, 1}};
 
    // Function call
    cout << primsSpanningTree(3, 3, graph) << endl;
 
    return 0;
}