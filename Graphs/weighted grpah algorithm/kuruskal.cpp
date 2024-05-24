#include<bits/stdc++.h> 
using namespace std;

//secondly make the DSU class 
class DSU{
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int V) {
        parent.resize(V);
        rank.resize(V, 1);
        for (int i = 0; i < V; ++i)
            parent[i] = i;
    }
    
    int find(int i){
        if(parent[i] == i){
            return i;
        }
        else{
            return parent[i] = find(parent[i]);
        }
    }

    void unionSets(int x, int y) {
        int x_rep = find(x);
        int y_rep = find(y);

        if (x_rep == y_rep) {
            return;
        }

        if (rank[x_rep] < rank[y_rep]) {
            parent[x_rep] = y_rep;
        } 
        else if (rank[x_rep] > rank[y_rep]) {
            parent[y_rep] = x_rep;
        } 
        else {
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }
};

//firstly make the class for Graph 
class Graph{
    //whenever i define a class and these variables defined below will be avialable to all the functions used under garpah 
    vector<vector<int>> edgeList;
    int V;
public:
    // this tells the variable in the scope of the class to be the value passed 
    Graph(int V){
        this -> V = V;
    }

    // add edge function will aslo access the scope variable edgelist
    void addEdge(int u, int v, int w){
        edgeList.push_back({w, u, v});
    }

    //Now make the main function Kuruskal 
    void KuruskalMST(){
        //step 1: sort all edges 
        sort(edgeList.begin(),edgeList.end(),[](const vector<int>& e1, const vector<int> & e2){ return e1[0]<e2[0];});

        // step 2 : do the union and find operation to get whenevr a cycle is formed 
        DSU s(V);
        int ans = 0;
        cout << "Following are the edges in the constructed MST" << endl; 
        for (auto edge : edgeList) { 
            int w = edge[0]; 
            int x = edge[1]; 
            int y = edge[2]; 
  
            // Take this edge in MST if it does 
            // not forms a cycle 
            if (s.find(x) != s.find(y)) {     // this non equality of find ensures that there is no cycle formed 
                s.unionSets(x, y); 
                ans += w; 
                cout << x << " -- " << y << " == " << w 
                     << endl; 
            } 
        } 
        cout << "Minimum Cost Spanning Tree: " << ans; 

    }


};
  
// Driver code 
int main() 
{ 
    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    Graph g(4); 
    g.addEdge(0, 1, 10); 
    g.addEdge(1, 3, 15); 
    g.addEdge(2, 3, 4); 
    g.addEdge(2, 0, 6); 
    g.addEdge(0, 3, 5); 
  
    // Function call 
    g.KuruskalMST(); 
  
    return 0; 
}