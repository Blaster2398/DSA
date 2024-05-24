#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent;

public:
    DisjointSet(int n) {
        parent.resize(n);
        //initialization
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        else{
            return find(parent[x]);
        }
    }

    void unionSets(int x, int y) {
        int x_rep = find(x);
        int y_rep = find(y);

        if (x_rep != y_rep) {
            parent[y_rep] = x_rep;
        }
    }
};

int main() {
    // Example usage
    int n = 5;
    DisjointSet dsu(n);

    dsu.unionSets(0, 1);
    dsu.unionSets(2, 3);
    dsu.unionSets(3, 4);

    cout << dsu.find(0) << endl;//0
    cout << dsu.find(1) << endl;//0
    cout << dsu.find(2) << endl;//2
    cout << dsu.find(3) << endl;//2
    cout << dsu.find(4) << endl;//2


    return 0;
}