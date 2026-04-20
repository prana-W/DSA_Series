#include <bits/stdc++.h>
using namespace std;

//? Pg: 153 

//. T.C -> O(4*alpha) which is about O(constant)

class DisjointSet {

    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        // Initialisation of parent and size
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Finding the ultimate parent 
    int findUPar(int node) {

        if (node == parent[node]) return node;

        // Doing path compression
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {

        int upU = findUPar(u);
        int upV = findUPar(v);

        // it means already both belong to same set
        if (upU == upV) return;

        // If smaller attached to higher, no change in rank will occur in the rank of the higher

        // upU is attached to upV
        if (rank[upU] < rank[upV]) {
            parent[upU] = upV;
        }

        // upV is attached to upU
        else if (rank[upV] < rank[upU]) {
            parent[upV] = upU;
        }

        // upU is attached to upV and here rank increases, since both had same rank, so increment of one happens
        else {
            parent[upV] = upU;
            rank[upU]++;
        }
    }

    void unionBySize(int u, int v) {
        int upU = findUPar(u);
        int upV = findUPar(v);
        if (upU == upV) return;

        // upU is attached to upV
        if (size[upU] < size[upV]) {
            parent[upU] = upV;
            size[upV] += size[upU];
        }

         // upV is attached to upU
        else {
            parent[upV] = upU;
            size[upU] += size[upV];
        }
    }
};
int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // if 3 and 7 in same component or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}
