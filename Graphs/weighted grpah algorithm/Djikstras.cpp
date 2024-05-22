#include<bits/stdc++.h>
using namespace std ;
#define V 9
#define INF 1e9

vector<int> Djikstra(vector<int> graph[], int s){
    // Initialization 
    vector<bool> visited(V, false);
    vector<int> distance(V,INF);
    distance[0] = 0;

    // we run a loop V-1 times 
    for( int i = 0; i < V-1; i++){
        // find the vertex which is not yet found and has min distance to continue relaxing the undiscovered edges
        int u = -1 ;
        for(int v = 0; v < V; v++){
            if( !visited[v] &&( u == -1 || distance[v] < distance[u])){
                u = v;
            }
        }

        //mark the vertex as visited 
        visited[u] = true;

        // now relax the edges
        for(int v = 0; v < V; v++){
            if( !visited[v] && graph[u][v] != false){
                distance[v] = min( distance[v] , distance[u] + graph[u][v]);
            }
        }
    }
    return distance;
}

int main(){
    /* Let us create the example graph discussed above */
    vector<int> graph[V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    
    vector<int> res = Djikstra(graph,0);

    for(int i = 0; i < V; i++){
        cout << "Shortest distance from starting node -> " << i << " : " << res[i] << endl;
    }
}