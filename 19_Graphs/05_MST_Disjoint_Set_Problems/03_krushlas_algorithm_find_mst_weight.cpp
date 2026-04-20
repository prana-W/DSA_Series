#include <bits/stdc++.h>
using namespace std;

// Note: We don't need to return mst array in GFG, so no need to store MST connections, just keep track of sum (mst_weight)
//? Problem Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

// This algorithm also helps us find the MST (we can also do this using Prims Algorithm, already discussed previously)

/*

1. Sort all the edges according to weight

2. For each edge, check if u, v belong to same component or not, if they do, then obviously we won't do anything, if they don't then we just joing u to v in MST and add the weight to our mst_weight

3. Since weights are in ascending order, the final result will be minimum and hence we will get the mst weight

*/

//. T.C -> O(E*log(E)), due to sorting
//. S.C -> O(V), due to DSU

class Solution {
  public:
  
  class DisjointSet {

    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {

        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int upU = findUPar(u);
        int upV = findUPar(v);
        if (upU == upV) return;

        if (size[upU] < size[upV]) {
            parent[upU] = upV;
            size[upV] += size[upU];
        }

        else {
            parent[upV] = upU;
            size[upU] += size[upV];
        }
    }
};
    
    static bool comp(vector<int>& e1, vector<int>& e2) {
        if (e1[2] < e2[2]) return true;
        
        return false;
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        // Sorting edges according to weight
        sort(edges.begin(), edges.end(), comp);
        
        DisjointSet ds(V);
        int ans = 0;
        
        vector<pair<int, int>>mst;
        
        for (auto &elem : edges) {
            int u = elem[0], v = elem[1], w = elem[2];
            
            // If already connected component, then don't do anything else
            if(ds.findUPar(u) == ds.findUPar(v)) continue;
            
            ans += w;
            ds.unionBySize(u, v);
            mst.push_back({u, v});
            
        }
        
        return ans;
        
    }
};