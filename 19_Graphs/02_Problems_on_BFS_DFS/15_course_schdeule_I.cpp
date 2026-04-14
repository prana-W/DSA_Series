#include <bits/stdc++.h>
using namespace std;

// Treat courses as tasks, and indegree mean prerequisite and all the prerequiste must be completed before doing any course, so in other words we have to move in a linear manner to complete the courses such that prequisites is done first for a course, so in simple terms just check if Topo sort is possible or not, or in other words, check if graph is cyclic or not. If cyclic, then Topo sort is not possible and hence return false, if acyclic, then Topo Sort is possible and hence return true

// In this problem, we can complete the course, only if there is no cycle in the directed graph.

//* Method - I (DFS)

//. T.C -> O(V+E)
//. S.C -> O(V+E + 2V +V)

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
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    int V = numCourses;

    vector<vector<int>>adj(V);
    vector<bool>visited(V, false);
    vector<bool>pathVisited(V, false);
    
    // Creating Adjancency List from input
    for (int i = 0; i < prerequisites.size(); i++) {
        
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        
        adj[u].push_back(v);
    }
    
    // DFS over all the non visited loops, if any dfs returns true, it means there is a cycle and hence return false
    for(int i = 0; i < V; i++) {
        if(!visited[i] && dfs(i, adj, visited, pathVisited)) return false;
    }
    
    // If reached here, it means no cycle exists and hence return true
    return true;
    
}

//* Method - II (BFS)

//. T.C -> O(V+E)
//. S.C -> O(V + V+E)
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    int V = numCourses;

    vector<int>indegree(V, 0);
    vector<vector<int>>adj(V);
    int ans = 0;
    
    // Creating Adjancency List and indegree array
    for(int i = 0; i < prerequisites.size(); i++) {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        
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
        
        // Increase the answer (as this node has effective indegree as 0)
        ans++;
        
        // Reduce indegree for all the adjacent neighbour and push the neighbour node if it has an indegree of 0
        for(auto elem : adj[node]) {
            indegree[elem]--;
            if(indegree[elem] == 0) q.push(elem);
        }
    }
    
    // If ans == V, it means there is no cycle, hence possible
    return ans == V;
    
}