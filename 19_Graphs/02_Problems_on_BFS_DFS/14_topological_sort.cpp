#include <bits/stdc++.h>
using namespace std;

//? Pg: 147 (for BFS)

//? Problem: https://www.geeksforgeeks.org/problems/topological-sort/1

//! Note: Here it is only possible if no cycle exits, else if a cycle exits, then obviously it won't be able to solved!!

//! DAG (Directed Acyclic Graph) is necessary for Topo Sort

//* Method - I (DFS, Brute, My Solution)
//? This will give TLE in GFG, so use I.V for DFS, this solution is just for understanding the problem.

// Think of the graph like task, we have to do task that are not dependent on any other task first, and then move on, so in this way any tasks is completed first if all its prerequiste is done. 

// In this way we can use a simple DFS optimally to first choose a task, complete all the tasks that must be done before it first and then push the current task.

// Here we create an adjancnencny matrix. Then we do DFS for all the non-visitred nodes in main function. During each DFS, we first mark the current node as visited, and then try to do DFS over all the non-visited nodes that must be completed before the current node, this is done by traversing the col for current node over all the rows. After all the dependent nodes are traversed, then only push the current node in answer, now simply return the answer

//. T.C -> O(V^2)
//. S.C -> O(V^2)

void dfs(int node, vector<vector<bool>>& adj, vector<bool>& visited, vector<int>& ans) {
    
    visited[node] = true;
    
    // DFS on all the nodes, current node is dependent on
    for(int r = 0; r < adj.size(); r++) {
        if(adj[r][node] && !visited[r]) {
            dfs(r, adj, visited, ans);
        }
    }
    
    ans.push_back(node);
}
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    
    vector<bool>visited(V, false);
    vector<vector<bool>>adj(V, vector<bool>(V, false));
    vector<int>ans;
    
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u][v] = true;
    }
    
    for (int node = 0; node < V; node++) {
        if(!visited[node]) dfs(node, adj, visited, ans);
    }
    
    return ans;
}

//* Method - I.V (DFS, Optimal Solution)
// The above solution is giving TLE as we are using an adjanceney Matrix. Now we will solve the problem using adjancney List and in reverse. Go to a node, do DFS for all the nodes that is depended on this node, then add the current node to the answer, this makes the final answer in reverse, so just reverse the answer before returning it.

//. T.C -> O(V+E)
//. S.C -> O(V+E)

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {
    
    visited[node] = true;
    
    // DFS on all the nodes dependent on ccurrent node
    for (auto elem : adj[node]) {
        if(!visited[elem]) dfs(elem, adj, visited, ans);
    }
    
    ans.push_back(node);
    
}
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    
    vector<bool>visited(V, false);
    vector<vector<int>>adj(V);
    vector<int>ans;
    
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    for (int node = 0; node < V; node++) {
        if(!visited[node]) dfs(node, adj, visited, ans);
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

//* Method - II (BFS)
//! Kahn's Algorithm

//. T.C -> O(V+E)
//. S.C -> O(V + V+E)

//! Intuition: Indegree of a node = number of prerequisites required for that task

// We will use Queue + Indegree array along with adjancency list for solving this problem.

// 1. Insert all nodes with indegree as 0
// 2. Take out node from queue and reduce all the indegrees of its adjancent nodes and push all the adjancet nodes with 0 indegree

vector<int> topoSort(int V, vector<vector<int>>& edges) {
    
    vector<int>indegree(V, 0);
    vector<vector<int>>adj(V);
    vector<int>ans;
    
    // Creating Adjancency List and indegree array
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        indegree[v]++;
    }
    
    queue<int>q;
    
    // Pushing all the nodes with 0 indegree
    for (int i = 0; i < V; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    
    while(!q.empty()) {
        
        int node = q.front();
        q.pop();
        
        // Pushing current node to ans
        ans.push_back(node);
        
        // Reduce indegree for all the adjacent neighbour and push the neighbour node if it has an indegree of 0
        for(auto elem : adj[node]) {
            indegree[elem]--;
            if(indegree[elem] == 0) q.push(elem);
        }
    }
    
    return ans;
}