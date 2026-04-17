#include <bits/stdc++.h>
using namespace std;

//? Pg: 148
//? Problem-1: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

//! Concept: Dijstra's Algorithm never works for negative weighted graphs
// Reason, if node 0 and 1 has a weight of -2, then first (0, 0) in PQ, then as 1 is neighbour, so (-2, 1) in PQ, then again since 0 is neighbour of 1, so (-4, 0) and this makes an infinite cycle of pushing the nodes in PQ again and again!!

//* Method - I (Using Min-Heap (PQ))
//! For undirected weighted graph

// Initialise the dist array with src having 0 dist, and push the (dist, node) in pq, then for all the adjancet nodes, find the one that is smaller than previous and then update the dist array and push in the pq

//. T.C -> O(E*log(V))

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
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        
        for (auto elem : adj[node]) {
            int nei = elem.first;
            int weight = elem.second;
            
            if (d + weight < dist[nei]) {
                dist[nei] = (dist[node] + weight);
                pq.push({dist[nei], nei});
            }
        }
    }
    
    return dist;
}

//* Method - II (Using Set DS)
//! For undirected weighted graph

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
        
        for (auto elem : adj[node]) {
            int nei = elem.first;
            int weight = elem.second;
            
            if (d + weight < dist[nei]) {
                dist[nei] = (dist[node] + weight);
                st.insert({dist[nei], nei});
            }
        }
    }
    
    return dist;
}