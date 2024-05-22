#include<bits/stdc++.h>
using namespace std ;

// Low value of u can change in two cases: 

// Case1 (Tree Edge): If node v is not stackMemeber already, then after the DFS of v is complete, a minimum of low[u] and low[v] will be updated to low[u]. 
// low[u] = min(low[u], low[v]); 
// Case 2 (Back Edge): When child v is already stackMemeber, then a minimum of low[u] and Disc[v] will be updated to low[u]. 
// low[u] = min(low[u], disc[v]); 


// now for the util function that will do the job
void sccUtil(int u, vector<int> &disc, vector<int> &low, vector<bool> &stackMemeber, stack<int> &st, vector<int> adj[], int & time){
    // do the usual DFS step
    stackMemeber[u] = true;
    // now for the iniializartion of the low and disc values 
    disc[u] = low[u] = time;
    time++;

    //also add this element in the stack 
    st.push(u);

    for( auto v : adj[u] ){
        if(disc[v] == -1){
            sccUtil(v, disc, low, stackMemeber, st, adj, time);

            // check if the subtree rooted with v has a connection to any ancestor of u 
            low[u] = min( low[u] , low[v] );
        }
        // update the low value of u only if v is still in stack (i.e it has a back edge not a cross edge )
        else if( stackMemeber[v] == true ){
            low[u] = min( low[u] , disc[v] );
        }
    }

    //from here the code is intresting cause we find the head node pop the stack and print the SCC
    int w = 0;   // to store the extracted vertices
    if( low[u] == disc[u] ){
        while(st.top() != u){
            w = (int)st.top();
            cout << w << " ";
            stackMemeber[w] = false;  // now you will not update the low[u] with the help of already popped out v which could be reached from some other u
            st.pop();
        }
        //for the last element repeat the steps i.e u
        w = (int)st.top();
        cout << w << endl;
        stackMemeber[w] = false;  
        st.pop();
    }
}

void SCC(vector<int> adj[], int V){
    //initializations 
    vector<bool> stackMemeber(V,false);
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    stack<int> st;
    int time  = 0;
    
    // DFS for disconnected graph
    for( int i = 0; i < V; i++){
        if(disc[i] == -1){
            sccUtil(i, disc, low, stackMemeber, st, adj, time);
        }
    }

}


// Utility function to add an edge
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

// Driver program to test above function
int main()
{
    cout << "\nSCCs in first graph \n";
    int V = 5;
    vector<int> adj1[V];
    addEdge(adj1,1, 0);
    addEdge(adj1,0, 2);
    addEdge(adj1,2, 1);
    addEdge(adj1,0, 3);
    addEdge(adj1,3, 4);
    SCC(adj1, V);
 
    cout << "\nSCCs in second graph \n";
    V = 4;
    vector<int> adj2[V];
    addEdge(adj2,0, 1);
    addEdge(adj2,1, 2);
    addEdge(adj2,2, 3);
    SCC(adj2,V);
 
    cout << "\nSCCs in third graph \n";
    V = 7;
    vector<int> adj3[V];
    addEdge(adj3,0, 1);
    addEdge(adj3,1, 2);
    addEdge(adj3,2, 0);
    addEdge(adj3,1, 3);
    addEdge(adj3,1, 4);
    addEdge(adj3,1, 6);
    addEdge(adj3,3, 5);
    addEdge(adj3,4, 5);
    SCC(adj3, V);
 
    cout << "\nSCCs in fourth graph \n";
    V = 11;
    vector<int> adj4[V];
    addEdge(adj4, 0, 1);
    addEdge(adj4, 0, 3);
    addEdge(adj4, 1, 2);
    addEdge(adj4, 1, 4);
    addEdge(adj4, 2, 0);
    addEdge(adj4, 2, 6);
    addEdge(adj4, 3, 2);
    addEdge(adj4, 4, 5);
    addEdge(adj4, 4, 6);
    addEdge(adj4, 5, 6);
    addEdge(adj4, 5, 7);
    addEdge(adj4, 5, 8);
    addEdge(adj4, 5, 9);
    addEdge(adj4, 6, 4);
    addEdge(adj4, 7, 9);
    addEdge(adj4, 8, 9);
    addEdge(adj4, 9, 8);
    SCC(adj4, V );
 
    cout << "\nSCCs in fifth graph \n";
    V = 7 ;
    vector<int> adj5[V];
    addEdge(adj5, 0, 1);
    addEdge(adj5, 1, 2);
    addEdge(adj5, 2, 3);
    addEdge(adj5, 2, 4);
    addEdge(adj5, 3, 0);
    addEdge(adj5, 4, 2);
    SCC(adj5, V);
 
    return 0;
}