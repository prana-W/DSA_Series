#include <bits/stdc++.h>
using namespace std;

//! For a undirected graph, convert it into directed by having two edges in parrel with the same weight

// This algorithm is used when we want to find shortest path in a negative weighted graph optimally.

// If the path sum of a cycle comes out to be negative it is said to be negative cycle.


/*

- Relax all the edges n-1 times sequentially, n is the total number of nodes.

- Relax: if (dist[u] + edge_wt < dist[v]), then dist[v] = dist[u] + w

- Relax one more time and if still any further edge gets relaxed, then the graph has negative cycle and hence it is not possible to find the shortest distance. 

*/

// Why n-1 times? Because in a graph of n nodes, in the worst case, we will take n-1 edges to reach from the first to the last, therby we iterate for n- iterations

//? Problem: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

//. T.C -> O(V*E)
//. S.C -> O(V)
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    
    vector<int>dist(V, 1e8);
    dist[src] = 0;

    // Relax for V-1 times
    for (int i = 1; i <= V-1; i++) {
        
        for (auto elem : edges) {
            int u = elem[0], v = elem[1], w = elem[2];
            
            if(dist[u] != 1e8 && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
        
    }
    
    // Checking for negative cycle, if even now relaxation is possible, then there must be a negative cycle
    for(auto elem : edges) {
        int u = elem[0], v = elem[1], w = elem[2];
            
        if(dist[u] != 1e8 && dist[u] + w < dist[v]) return {-1};
    }
    
    return dist;
    
}