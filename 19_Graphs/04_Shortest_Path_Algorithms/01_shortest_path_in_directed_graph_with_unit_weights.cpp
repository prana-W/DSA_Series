#include <bits/stdc++.h>
using namespace std;

//? Problem: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

// Use simple BFS, intitialise dist of all to INT_MAX, this array can also be treated to check if a node is already visited or not, just put the distance of the neighbour of the current node if the distance from current ndoe + 1 is smaller than the already set dist of the neihbour

//* Method - I (BFS)
// used on unweighted graph in finding shortest path

//. T.C -> O(V+2E)
//. S.C -> O(V + V+2E)
vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {

    vector<vector<int>>adj(V);
    
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    
    vector<int>dist(V, INT_MAX);
    
    queue<int>q;
    q.push(src);
    dist[src] = 0;
    
    while(!q.empty()) {
        
        int node = q.front();
        q.pop();
        
        for(auto elem : adj[node]) {
            if(dist[elem] == INT_MAX) {
                q.push(elem);
                dist[elem] = dist[node] + 1;
            }
        }
        
    }
    
    for (int i = 0; i < V; i++) {
        if(dist[i] == INT_MAX) dist[i] = -1;
    }
    
    return dist;
    
}