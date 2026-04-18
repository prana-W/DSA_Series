#include <bits/stdc++.h>
using namespace std;

//? Problem: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

//! Note: All solutions are intended to be used with 

//! Method - III is the standard solution for this DAG as due to DAG we can use Topo Sort which is a better solution than all the other solutions

//* Method - I (My Method, DFS+DP)
// This approach is better than my second method using BFS, as memoization ensures 1 computation per node only

// Reverse all the edges. Now the question becomes the shortest distance from a node to src(0). Now just use DFS from 0 to V-1 vertices, to check all the valid paths and finding the minimum, we will use memoization DP for instantly finding the distance from a particular node to src(0), if we have already found that distance

// dfs(node) gives the shortest distance from node to src(0)

//. T.C -> O(V+E)
//. S.C -> O(V+E)

int dfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
    
    // as it is src node
    if (node == 0) return dist[node] = 0;
    if(dist[node] != INT_MAX) return dist[node];
    
    int ans = INT_MAX;
    
    for (auto elem : adj[node]) {
        
        int nei = elem.first;
        int weight = elem.second;
        
        // if shortest dist from neighbour is already INT_MAX, so no need to go further in that path
        int shortestNeigDist = dfs(nei, adj, dist);
        if(shortestNeigDist == INT_MAX) continue;
        
        // find minimum distance of all the paths from current node to src(0)
        ans = min(weight + shortestNeigDist, ans);
    }
    
    return dist[node] = ans;
}
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    
    vector<vector<pair<int, int>>>adj(V);
    
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        int w = edges[i][2];
        
        // Reversing the edges
        adj[v].push_back({u, w});
        
    }
    
    vector<int>dist(V, INT_MAX);
    
    for(int i = 0; i < V; i++) {
        dfs(i, adj, dist);
    }
    
    // if dist is INT_MAX, it means it is not possible to reach src(0)
    for(int i = 0; i < V; i++) {
        if(dist[i] == INT_MAX) dist[i] = -1;
    }
    
    return dist;
}

//* Method - II (My Method, Using Queue)
// If the sum of distance of neigbour with weight is less than the alreay set dist of the negibour, then update the dist

//! This approach is not optimal as several nodes might be processed again and again, so it will increase the time complexity, if each node once than V + E, but if many times than it becomes a multiple and hence increases to a square!!

//! Node is processed multiple times as we don't get the optimal distance at once due to weighted nature of graph

//. T.C -> O(V*E) in worst case due to same node being processed multiple times!!
//. S.C -> O(V+E)
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    
    vector<vector<pair<int, int>>>adj(V);

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        int w = edges[i][2];
        
        adj[u].push_back({v, w});
        
    }
    
    vector<int>dist(V, INT_MAX);
    
    queue<int>q;
    q.push(0);
    dist[0] = 0;
    
    while(!q.empty()) {
        
        int node = q.front();
        q.pop();
        
        for(auto elem : adj[node]) {
            
            int weight = elem.second;
            
            // Slight modification here
            if(dist[node] + weight < dist[elem.first]) {
                q.push(elem.first);
                dist[elem.first] = dist[node] + weight;
            }
        }
    }
    
    for (int i = 0; i < V; i++) {
        if(dist[i] == INT_MAX) dist[i] = -1;
    }
    
    return dist;
    
}

//* Method - III (Recommended Solution, Topo Sort)

/*

1. Do a Topo Sort on the graph by DFS storing nodes in a stack.

2. Take all nodes out of stack one by one and relax the edges. Mark the distance of the src node as 0 and initialise rest distances by infinity.

Take out elements from the top of stack, go to all the neigbhours of the node and their dist would be min(curr_dist, weight+dist(parent_node)), and pop the top of stack.

*/

//. T.C -> O(V+E)

void topoSort(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& visited, stack<int>& st) {
    
    visited[node] = true;
    
    for (auto elem : adj[node]) {
        int nei = elem.first;
        
        if(!visited[nei]) {
            topoSort(nei, adj, visited, st);
        }
    }
    
    st.push(node);
    
}
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    
    vector<vector<pair<int, int>>>adj(V);

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        int w = edges[i][2];
        
        adj[u].push_back({v, w});
        
    }
    
    vector<bool>visited(V, false);
    stack<int>topo;
    
    // Find Topo Sort
    for(int i = 0; i < V; i++) {
        if(!visited[i]) topoSort(i, adj, visited, topo);
    }
    
    // Initialise distace
    vector<int>dist(V, INT_MAX);
    dist[0] = 0; // Set src node's distance as 0
    
    while(!topo.empty()) {
        int node = topo.top();
        topo.pop();
        
        for(auto elem : adj[node]) {
            int nei = elem.first;
            int weight = elem.second;
            
            // continue as already distance from src to parent node is Infinite
            if (dist[node] == INT_MAX) continue;
            if (dist[node] + weight < dist[nei]) dist[nei] = dist[node] + weight;
        }
    }
    
    for(int i = 0; i < V; i++) {
        if(dist[i] == INT_MAX) dist[i] = -1;
    }
    
    return dist;
    
}

//* Method - IV (Not Reccomended, Dijkstra's Algorithm will work as well)
//. T.C -> O(E*log(V))