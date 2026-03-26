#include <bits/stdc++.h>
using namespace std;

//? Pg: 145

//? Problem: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

//. T.C -> O(n + 2e), for undirected graph
//. S.C -> O(n), visited array, recursive stack space (in worst in case of skewed is O(n)), ans array and adjency matrix

void traversal(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {
    
    visited[node] = true;
    ans.push_back(node);
    
    for (auto it : adj[node]) {

        // Traverse the neighbour if not already visited
        if (!visited[it]) traversal(it, adj, visited, ans);
    }
}
vector<int> dfs(vector<vector<int>>& adj) {
    
    vector<int>ans;
    vector<bool>visited(adj.size(), false);
    
    traversal(0, adj, visited, ans);
    
    return ans;
    
}