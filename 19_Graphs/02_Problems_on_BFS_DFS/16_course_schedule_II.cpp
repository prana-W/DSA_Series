#include <bits/stdc++.h>
using namespace std;

//* Method - I (DFS)
// Just do DFS for Topo sort as we normally did, but in addition to that pass on a pathVisited array, if we encounter pathVisited already marked true in a given path, then return true, which means a cycle exits, in the main function if dfs returns true then a cycle exists and hence return an empty array else reverese the ans array and return the answer

//. T.C -> O(V+E)
//. S.C -> O(V + V + V+E)

bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& pathVisited, vector<int>& ans) {
    
    visited[node] = true;
    pathVisited[node] = true;
    
    // DFS on all the nodes dependent on ccurrent node
    for (auto elem : adj[node]) {
        if(!visited[elem] && dfs(elem, adj, visited, pathVisited, ans)) return true;
        else if(pathVisited[elem]) return true;
    }
    
    pathVisited[node] = false;
    ans.push_back(node);

    return false;
    
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

    int V = numCourses;

    vector<bool>visited(V, false);
    vector<bool>pathVisited(V, false);
    vector<vector<int>>adj(V);
    vector<int>ans;
    
    for(int i = 0; i < prerequisites.size(); i++) {

        //! Since we have to do bi first then ai, it means edge is from bi to ai
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];
        
        adj[u].push_back(v);
    }
    
    for (int node = 0; node < V; node++) {
        if(!visited[node] && dfs(node, adj, visited, pathVisited, ans)) return {};
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
    
}

//* Method - II (BFS)

// Just check if no graph is acyclic (by checking size of ans/topo sort array and tiotal given vertices) and then return the Topo Sort

//. T.C -> O(V+E)
//. S.C -> O(V + V+E)
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

    int V = numCourses;

    vector<int>indegree(V, 0);
    vector<vector<int>>adj(V);
    vector<int>ans;
    
    // Creating Adjancency List and indegree array
    for(int i = 0; i < prerequisites.size(); i++) {

        //! Since we have to do bi first then ai, it means edge is from bi to ai
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];
    
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

    // Checking if cycle exists
    if(ans.size() != V) return {};        
    return ans;
    
}