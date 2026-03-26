#include <bits/stdc++.h>
using namespace std;

//* Method - I (Using DFS)

//. T.C -> O(v) + O(v + 2e), for loop over visited and dfs

void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj, vector<vector<int>>& ans) {
    
    visited[node] = true;

    // Add current traversal's answer in last element of ans
    ans.back().push_back(node);
    
    for (auto it : adj[node]) {
        if (!visited[it]) dfs(it, visited, adj, ans);
    }

}
vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
    
    // Creating Adjancency List
    vector<vector<int>>adj(V);
    for (int i = 0; i < edges.size(); i++) {
        
        int node1 = edges[i][0];
        int node2 = edges[i][1];
        
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
        
    }
    
    vector<bool>visited(V, false);
    vector<vector<int>>ans;
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            // This will act as the container for the answers
            ans.push_back({}); 
            dfs(i, visited, adj, ans);
        }
    }
    
    return ans;
    
}

//* Method - II (Using BFS)

//. T.C -> O(v) + O(v + 2e), for loop over visited and bfs
//. S.C -> O(v + 2e), O(v) for queue and visited and O(2e) for adjancency

vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
    
    // Creating Adjancency List
    vector<vector<int>>adj(V);
    for (int i = 0; i < edges.size(); i++) {
        
        int node1 = edges[i][0];
        int node2 = edges[i][1];
        
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
        
    }

    // BFS Traversal for all the non-visted nodes
    
    queue<int>q;
    vector<bool>visited(V, false);
    vector<vector<int>>ans;
    
    for(int i = 0; i < V; i++) {
        
        vector<int>temp;
        
        if (!visited[i]) {
            
                q.push(i);
                visited[i] = true;
                
                while(!q.empty()) {
                    
                    int node = q.front();
                    temp.push_back(node);
                    
                    for (auto it : adj[node]) {
                        if(!visited[it]) {
                            q.push(it);
                            visited[it] = true;
                            
                        }
                    }
                    
                    q.pop();
                }
                
        }
        
        if(temp.size()) ans.push_back(temp);
    }
    
    return ans;
    
}