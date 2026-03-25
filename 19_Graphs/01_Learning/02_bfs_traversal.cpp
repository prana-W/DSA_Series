#include <bits/stdc++.h>
using namespace std;

//? Problem: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// Each node goes once into the ans(bfs) array and run on all its neighbours (that is runs on all its degrees)

//. T.C -> O(n + 2*e), O(n) for all the nodes for queue and O(2e) for the total edges in the second loop by the adjencny list
//. S.C -> O(n), queue data structure and visited array
vector<int> bfs(vector<vector<int>> &adj) {
    
    // Since 0-based indexing, so size is adj.size()
    vector<bool>visited(adj.size(), false);
    vector<int>ans;
    
    queue<int>q;
    q.push(0);
    visited[0] = true;
    
    while(!q.empty()) {
        
        int node = q.front();
        ans.push_back(node);
        
        for (auto elem : adj[node]) {
            if (!visited[elem]) {
                q.push(elem);
                visited[elem] = true;
            }
        }
        
        q.pop();
    
    }
    
    return ans;
    
}