#include <bits/stdc++.h>
using namespace std;

//? Pg: 152

// Start with a visited array, min-heap (PQ) with wt, node and parent, initially insert the node 0 and its parent as -1. Also always mark visited only after popping it (not unlike visiting when inserting)

// Go to the adjancent nodes of the top node and if it is marked as unvisited then, push it in PQ

// When the parent is not -1, then (paren, node) is added to the mst array before popping it from the PQ

// Also before popping add the wt. to the sum total_ege_wt_sum we are maintaining

// Also before doing anything, check if it is already visited

// Prim's algorithm works on the intuition of greedy. We take the node and then use a pq to insert the least weight and then consider it, and ignore when the node is already visited, as we only need one edge between nodes

//* Finding MST and sum

//. T.C -> O(E*log(E))
//. S.C -> O(V+E), priority can have in the worst case all the edges
void spanningTree(int V, vector<vector<int>>& edges) {
    
    vector<vector<pair<int, int>>>adj(V);
    vector<bool>visited(V, false);
    
    for (auto elem : edges) {
        int u = elem[0], v = elem[1], w = elem[2];
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
    pq.push({0, {0, -1}});
    
    int sum = 0;
    vector<pair<int, int>>mst; // This contains the nodes connected in the final MST
    
    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        
        int node = top.second.first;
        int parent = top.second.second;
        int w = top.first;
        
        // Continue of already visited
        if(visited[node]) continue;
        visited[node] = true;

        // Include in answer
        sum += w;
        mst.push_back({parent, node});
        
        for (auto elem : adj[node]) {
            
            int nei = elem.first, weight = elem.second;
            
            // Push the neigbour if not already visited
            if(visited[nei]) continue;
            
            pq.push({weight, {nei, node}});
        }
    }
    
    // return sum;
    // return mst;
    
}