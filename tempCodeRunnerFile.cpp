// Shortest path in an undirected graph
//Using BFS 
#include<bits/stdc++.h>
using namespace std ;



//this is for ndirected graphs 
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// here the V is number of vertices and s is the source 
int* dist_BFS(vector<int> adj[], int V, int s, int* dist){
    bool visited[V]={false};
    int L = 0;
    queue<int> q;
    visited[s] = true;
    dist[s] = L;
    L++;
    q.push(s);
    while(q.empty() == false){
        int u = q.front();
        //now delete and show u in the O/P
        q.pop();
        // cout << u <<" ";
        visited[u] = true;
        for(int v: adj[u]){
            if(visited[v] == false){
                visited[v] = true;
                dist[v] = L;
                q.push(v);
            }
        }
        L++;
    }
}
 
int main(){
    int V ,E;
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
    int s;
    cout << " enter the starting point ";
    cin >> s;
    int dist[V] = {-1};
    dist_BFS(adj, V, s, dist);


    for(int i = 0; i < V; i++){
        cout << dist[i] << " ";
    }


    return 0;

}