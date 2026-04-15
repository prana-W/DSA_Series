#include <bits/stdc++.h>
using namespace std;

// Use simple BFS, intitialise dist of all to -1, this array can also be treated to check if a node is already visited or not, just put the distance of current level by increasing the distacne to the previous level by one

//. T.C -> O(V+E)
//. S.C -> O(V + V+E)

vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {

    vector<vector<int>>adj(V);
    
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    
    vector<int>dist(V, -1);
    
    queue<int>q;
    q.push(src);
    dist[src] = 0;
    
    while(!q.empty()) {
        
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            int node = q.front();
            q.pop();
            
            for(auto elem : adj[node]) {
                if(dist[elem] == -1) {
                    q.push(elem);
                    dist[elem] = dist[node] + 1;
                }
            }
        }
        
    }
    
    return dist;
    
}