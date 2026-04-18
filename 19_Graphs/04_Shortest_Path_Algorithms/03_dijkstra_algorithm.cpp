#include <bits/stdc++.h>
using namespace std;

//? Pg: 148
//? Problem-1: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

//! Concept: Dijstra's Algorithm never works for negative weighted graphs
// Reason, if node 0 and 1 has a weight of -2, then first (0, 0) in PQ, then as 1 is neighbour, so (-2, 1) in PQ, then again since 0 is neighbour of 1, so (-4, 0) and this makes an infinite cycle of pushing the nodes in PQ again and again!!

//! Concept: This will also work if we use queue instead of PQ (min-heap) or set, but to avoid unncessary work and improving time complexity we use this appraoch by using min-heap or set

// This is because we are using a greedy approach of doing the job on the minimum distance first, dry run with queue and compare why it is better

//* Method - I (Using Min-Heap (PQ))
//! For undirected weighted graph

// Initialise the dist array with src having 0 dist, and push the (dist, node) in pq, then for all the adjancet nodes, find the one that is smaller than previous and then update the dist array and push in the pq

//. T.C -> O(E*log(V)), E is total number of edges and V is the number of nodes
// O(V^2 * log(heap_size)) -> O(E*log(V^2)) -> O(E*log(V)), (V^2 -> E)

//. S.C -> O(V+E)
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    
    vector<vector<pair<int, int>>>adj(V);
    
    // O(E)
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        int w = edges[i][2];
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        
    }
    
    vector<int>dist(V, INT_MAX);
    
    // O(E) at max
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    
    // Outer loop for about O(V)
    while(!pq.empty()) {
        auto [d, node] = pq.top(); 
        pq.pop(); // O(log(heap_size))

        //! if already a smaller dist exists for node, then continue
        if (d > dist[node]) continue;
        
        // O(V) in worst
        for (auto elem : adj[node]) {
            int nei = elem.first;
            int weight = elem.second;
            
            if (d + weight < dist[nei]) {
                dist[nei] = (d + weight);
                pq.push({dist[nei], nei}); // O(log(heap_size))
            }
        }
    }
    
    return dist;
}

//* Method - II (Using Set DS)
//! For undirected weighted graph

//. T.C -> O(E*log(E)
//. S.C -> O(V+E)

// Just used set DS instead of min-heap. Smallest element will be the first element in set, so use that and erase that

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    
    vector<vector<pair<int, int>>>adj(V);
    
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        int w = edges[i][2];
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        
    }
    
    vector<int>dist(V, INT_MAX);
    
    set<pair<int, int>>st;
    dist[src] = 0;
    st.insert({0, src});
    
    while(!st.empty()) {
        auto [d, node] = *st.begin();
        st.erase(st.begin());

        if (d > dist[node]) continue;
        
        for (auto elem : adj[node]) {
            int nei = elem.first;
            int weight = elem.second;
            
            if (d + weight < dist[nei]) {
                dist[nei] = (d + weight);
                st.insert({dist[nei], nei});
            }
        }
    }
    
    return dist;
}