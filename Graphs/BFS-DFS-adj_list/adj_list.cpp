//Billo Bagge Billeyan Da Ki Karegi
//Bagge - Bagge Billeyan Da Ki Karegi

#include<bits/stdc++.h>
using namespace std ;

//this is for ndirected graphs 
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 

int main(){
    int V;
    cout << "Enter the number of vertices"<<endl;
    cin >> V ;
    V=4 ;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    // Print adjacency list
    for(int i = 0; i < V; i++) {
        cout << "Adjacency list of vertex " << i << ": ";
        for(int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

}