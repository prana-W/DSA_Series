#include <bits/stdc++.h>
using namespace std;

// First find the total number of wires already and total components, minimum V-1 edges are required to connect V nodes and since no two computer is connected with more than one wire, we can use the extra wires from one component, to connect with the another component, therfore we can see that we need (x-1) operations, where x is the number of components in the graph. Also if total wires is less than V-1, then we can never find the answer
// Similar problem to 01_number_of_provinces.cpp

//* Method - I (DFS)
// Use DFS to find the total components of the graph

//. T.C -> O(V+E)
//. S.C -> O(V+E)

void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj) {

    visited[node] = true;

    for (auto it : adj[node]) {
        if(!visited[it]) dfs(it, visited, adj);
    }

} 

int makeConnected(int n, vector<vector<int>>& connections) {

    if(connections.size() < n-1) return -1;

    vector<vector<int>>adj(n);

    for (auto elem : connections) {
        int u = elem[0], v = elem[1];

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    vector<bool>visited(n, false);
    int ans = 0;

    for(int i = 0; i < n; i++) {
        if (!visited[i]) { 
            ans++;
            dfs(i, visited, adj);
        }
    }

    return ans-1;
    
}

//* Method - II (DSU)
// Use Union-Find to find the total number of components of graph or in terms of DSU, total number of ultimate bosses or sets

//. T.C -> O((V+E) * alpha(V))
//. S.C -> O(V), for storing the size array in DSU

class DSU {

    vector<int>size, parent;

    public:
        
        DSU(int n) {
            for (int i = 0; i < n+1; i++) {
                parent.push_back(i);
                size.push_back(1);
            }
        }

        int findUPar(int n) {
            if (parent[n] == n) return n;

            return parent[n] = findUPar(parent[n]);
        }

        void unionBySize(int u, int v) {
            int upU = findUPar(u);
            int upV = findUPar(v);

            if(upU == upV) return;

            if(size[upU] < size[upV]) {
                parent[upU] = upV;
                size[upV] += size[upU];
            }
            else {
                parent[upV] = upU;
                size[upU] += size[upV];
            }
        }
};

int makeConnected(int n, vector<vector<int>>& connections) {

    if(connections.size() < n-1) return -1;

    DSU ds(n);

    for (auto elem : connections) {
        int u = elem[0], v = elem[1];
        ds.unionBySize(u, v);
    }

    int ans = 0;

    for (int node = 0; node < n; node++) {
        if(ds.findUPar(node) == node) ans++;
    }

    return ans-1;
    
}