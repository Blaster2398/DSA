#include <bits/stdc++.h>
using namespace std;
#define V 9  // Updated to 9 vertices to match the given edges
typedef pair<int, int> pii;

void addEdge(vector<vector<pii>>& adj, int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

vector<int> Dijkstra(vector<vector<pii>>& adj, int s) {
    // initialization
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> distance(V, INT_MAX);
    pq.push({0, s});  // here we store the values as (distance, node) so to sort according to distance
    distance[s] = 0;

    // now loop over the priority queue and each time take out the smallest unvisited edge (by default the elements in pq are unvisited)
    // and then do the relaxation operation to whichever node you can reach through it and then push them to the pq
    while (!pq.empty()) {
        int u = pq.top().second;  // get the shortest distance vertex
        pq.pop();

        for (auto& i : adj[u]) {
            int v = i.first;
            int wt = i.second;

            // do the relaxation
            if (distance[v] > distance[u] + wt) {
                distance[v] = distance[u] + wt;
                pq.push(make_pair(distance[v], v));
            }
        }
    }
    return distance;
}

int main() {
    vector<vector<pii>> adj(V);
    // Making the above-shown graph
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    // Print the adjacency list
    for (int u = 0; u < V; u++) {
        cout << "Adjacency list of vertex " << u << ":\n";
        for (auto& i : adj[u]) {
            cout << "node -> " << i.first << "  weight -> " << i.second << endl;
        }
        cout << endl;
    }

    int s = 0;
    cout << "Enter the source vertex: ";
    cin >> s;
    cout << endl;

    vector<int> res = Dijkstra(adj, s);

    for (int i = 0; i < V; ++i) {
        cout << "Distance from vertex " << s << " to vertex " << i << " is " << res[i] << endl;
    }

    return 0;
}
