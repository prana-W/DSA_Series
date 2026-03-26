#include <bits/stdc++.h>
using namespace std;

//! The problem uses the concept of connected graphs(see pg: 141)

//* Method - I (Adjancency Matrix)
// In the problem we are given a adjency matrix, here we have solved it using the matrix itself

// Keep on doing dfs in the main function till all the nodes are visible, the number of times we have to force traversal from the main function is the number of components of the graph

//. T.C -> O(n) + O(n + 2e), O(n) for loop over visited array in main function and O(n+2e) for the entire dfs
//. S.C -> O(n)

//! Note: We are treating everything in 0-based indexing and not as in the question (in question it is 1-based indexing)

void dfs(int node, vector<bool>& visited, vector<vector<int>>& isConnected) {

    visited[node] = true;
    
    for (int i = 0; i < isConnected[node].size(); i++) {
        if (isConnected[node][i] == 1) {
            int neighbour = i;
            if (!visited[neighbour]) dfs(neighbour, visited, isConnected);
        }
    }
} 
int methodI(vector<vector<int>>& isConnected) {

    int n = isConnected.size();

    vector<bool>visited(n, false);
    int ans = 0;

    for(int i = 0; i < n; i++) {
        if (!visited[i]) ans++;

        dfs(i, visited, isConnected);
    }

    return ans;
    
}

//* Method - II (Adjancenncy List)
// Convert the given adjancecny matrix into adjancecny list and then do the problem, everything else is same

void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj) {

    visited[node] = true;
    
    for (auto it : adj[node]) {
        if(!visited[it]) dfs(it, visited, adj);
    }

} 
int methodII(vector<vector<int>>& isConnected) {

    int n = isConnected.size();

    // Converting to Adjancency List
    vector<vector<int>>adj;
    for (int i = 0; i < n; i++) {
        vector<int>neighbour;
        for (int j = 0; j < n; j++) {

            // Ignoring self-loops
            if (isConnected[i][j] == 1 && i != j) neighbour.push_back(j);

        }
        adj.push_back(neighbour);
    }

    vector<bool>visited(n, false);
    int ans = 0;

    for(int i = 0; i < n; i++) {
        if (!visited[i]) ans++;

        dfs(i, visited, adj);
    }

    return ans;
    
}