// this is the adjacency matrix implementation
#include<bits/stdc++.h>
using namespace std ;

#define V 5

void primsMST( int graph[V][V]){
    int res=0;
    bool mstSet[V];                // this will tell is the node is visited or not 
    int key[V];                    // will have the min value edge connected from any other node 
    int parent[V];                 // this will store the MST 
    
    fill(key,key+V,INT_MAX);
    fill(mstSet,mstSet+V,false);
    key[0] = 0; 
    parent[0] = -1;

    // for the V vertices of the MST 
    for( int count = 0; count < V; count++){

        // to get the node which is at min distance from the explored graph 
        //  this will firstly set u = node that is not yet discovered and then
        //  find the node which has min key from the undiscovered nodes  
        int u = -1;
        for(int v = 0; v < V; v++){
            if( mstSet[v] == false && (u == -1 || key[v] < key[u])){
                u = v;
            }
        }

        mstSet[u] = true;
        res = res + key[u];

        // to update the key values and the parent we only consider those nodes 
        // which are not yet discovered and are connected to the min node found above 
        for( int v = 0; v < V; v++){
            if((graph[u][v] != 0) && (mstSet[v] == false) && ( graph[u][v] < key[v])){
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    // Print the constructed MST
    cout << "The cost of the MST is: " << res <<endl;
    cout << "Edge \tWeight" << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
    }

}

int main(){
    
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    primsMST(graph);

    return 0;
}