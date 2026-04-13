#include <bits/stdc++.h>
using namespace std;

//? Problem Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

//? Pg: 146

//* Method - I (DFS)
// We can't do same algoriohtm as we used in the undirected graph for cycle detectiobnn. Here we can say a cycle exists we find a node already visited only if it is in the same path, if we change return(backtrack) and start another recursion call, that counts as another path i.e. on the same path, the node has to be visited again!

// We use two new arrays, visited and pathVisited. visited works just like it does, keeping track of visited nodes and preventing dfs again and again for the same node. pathVisited keeps track of the current path, whenever we return (backtrack) from the recursion, we revert back the step we took in the pathVisited, so the  pathVisited keeps track of our current path, and we encounter a node that is pathVisited again, we can say that a cycle does exist. Also traverse in the graph component wise, as it might not be able to possible to traverse the entire graph using a single dfs.

//! Note: We can further optimise space by using a single array for visited and path visited. -1 for unvisited, 1 for visited and 2 for pathvisited or something like this. Do using this as Homework

//. T.C -> O(V+E)
//. S.C -> O(V+E + 2V +V), (V+E) for adjancency List, O(2V) for visited and pathVisited, O(V) for recursion stack space

bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& pathVisited) {
    
    visited[node] = true;
    pathVisited[node] = true;
    
    for (auto elem : adj[node]) {

        // If not visited, do DFS
        if(!visited[elem] && dfs(elem, adj, visited, pathVisited)) return true;

        // If already the node is visited during the current path, then cycle does exists
        else if (pathVisited[elem]) return true;
    }
    
    // Backtracking our pathVisited choice
    pathVisited[node] = false;
    
    return false;
    
}
bool isCyclic(int V, vector<vector<int>> &edges) {
    
    vector<vector<int>>adj(V);
    vector<bool>visited(V, false);
    vector<bool>pathVisited(V, false);
    
    // Creating Adjancency List from input
    for (int i = 0; i < edges.size(); i++) {
        
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    // DFS over all the non visited loops
    for(int i = 0; i < V; i++) {
        if(!visited[i] && dfs(i, adj, visited, pathVisited)) return true;
    }
    
    return false;
    
}