#include <bits/stdc++.h>
using namespace std;

//? https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

//* Method - I; Type - I (BFS, Single Component)
//! Assuming we have a single component, that is graph is not broken into components; NOTE: In GFG, the problem has multiple components, so this code will not work there!

// Do a simple BFS, and if we find a neighbour which is not our parent and is already visited, it means someone else has already reaached it from the other path from any node and so have we, hence it means there is a common path. But make sure it is not current node's parent. Because parent is always our neighbour, so any neighbour not our parent, which is also visited means a cycle exists!!

//. T.C -> O(V + 2E)
//. S.C -> O(V)

bool bfsSingleComponent(int V, vector<vector<int>>& edges) {
    
    vector<bool>visited(V, false);
    vector<vector<int>>adj(V);
    
    // Creating adjancncy list from input
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // (node, parent_node)
    queue<pair<int, int>>q;
    q.push({0, -1});
    visited[0] = true;
    
    while(!q.empty()) {
   
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for (auto it : adj[node]) {
            if(!visited[it]) {
                q.push({it, node});
                visited[it] = true;
            }
            else if (visited[it] && it != parent) return true;
        } 
        
    }
    
    return false;
    
}

//* Method - I; Type - II (BFS, Multiple Components)
//! Graph can be split into multiple components

// Same concept as above but here we are checking for each components

//. T.C -> O(V + 2E)
//. S.C -> O(V)

//! Note: We can also do below without storing the parent node and simply checking if a node has more than one neighobour that is visited, becuase every ndoe will have one neighbout visited (their parent), if it has more than one, it means that it is some otehr node that was visited by some other path and hence a cycle exists

bool bfsComponent(int node, vector<bool>& visited, vector<vector<int>>& adj) {

    queue<pair<int, int>>q;
    q.push({node, -1});
    visited[node] = true;
    
    while(!q.empty()) {

        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for (auto it : adj[node]) {
            if(!visited[it]) {
                q.push({it, node});
                visited[it] = true;
            }
            else if (visited[it] && it != parent) return true;
        } 
        
    }
    
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    
    vector<bool>visited(V, false);
    vector<vector<int>>adj(V);
    
    // Creating adjancncy list from input
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Doing BFS for all the components, and checking if either gives a cycle
    for (int i = 0; i < V; i++) {
        if (!visited[i] && bfsComponent(i, visited, adj)) return true;
    }
    
    return false;
    
}

//* Method - II (DFS, Multiple Components)
// Using DFS instead of BFS for multiple component graph

//. T.C -> O(V + 2E)
//. S.C -> O(V)

// DFS function to detect cycle
bool dfs(int node, int parent, vector<int> adj[], vector<int>& visited) {
    // Mark current node visited
    visited[node] = 1;

    // Traverse neighbors
    for (int neighbor : adj[node]) {

        // If neighbor not visited, recurse
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited)) return true;
        }

        // If neighbor visited and not parent, cycle exists
        else if (neighbor != parent) {
            return true;
        }
    }

    // No cycle found from this path
    return false;
}

// Function to check cycle in graph
bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);

    // Check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) return true;
        }
    }
    return false;
}