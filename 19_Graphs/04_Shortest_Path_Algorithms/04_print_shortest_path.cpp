#include <bits/stdc++.h>
using namespace std;

//! In undirected weighted graph

//* Method - I (My Method, Brute Force)

// Similar to word ladder II, push the entire path as an array instead of just node in pair of PQ, this way we keep on forming paths, each time when we find a smaller distance from our destination then update the ans path

//. T.C -> O(E*log(V) * V)
//. S.C -> O(E*V) for PQ
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    
    vector<vector<pair<int, int>>>adj(n+1);
    
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        int w = edges[i][2];
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        
    }
    
    vector<int>dist(n+1, INT_MAX);
    vector<int>ans;
    int pathSum = INT_MAX;
    
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
    pq.push({0, {1}});
    
    while(!pq.empty()) {
        auto [d, path] = pq.top();
        pq.pop();
        
        if (d < pathSum && path.back() == n) {
            ans = path;
            pathSum = d;
        }
        
        for (auto elem : adj[path.back()]) {
            
            int nei = elem.first;
            int weight = elem.second;
            
            if (d + weight < dist[nei]) {
                dist[nei] = (d + weight);
                
                vector<int>temp = path;
                temp.push_back(nei);
                
                pq.push({dist[nei], temp});
            }
            
        }
    }
    
    if(pathSum == INT_MAX) pathSum = -1;
    
    // Add first element as the total path distance of our path
    vector<int>fAns;
    fAns.push_back(pathSum);
    
    for(auto elem : ans) {
        fAns.push_back(elem);
    }
    
    return fAns;
    
}

//* Method - II (Optimal Approach)
// Use a standard Dijstra'a Algorithm and also make a single parent array of size n+1. now whenever we push any node in the PQ, also update its parent in the parent array. At the end first check if the pathDistance to the end node is valid, after that push last node in the stack and keep on pushing the parent of the top of stack till we find the node 1 (src), now first put the total pathSum till our destination in our ans array, then empty the stack into this array and return this array finally at the end!

//. T.C -> O(E*log(V) + V)
//. S.C -> O(V + V+E)
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    
    vector<vector<pair<int, int>>>adj(n+1);
    
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        int w = edges[i][2];
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        
    }
    
    vector<int>dist(n+1, INT_MAX);
    vector<int>parent(n+1, -1);
    
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        //! if already small dist exists for the node
        if (d > dist[node]) continue;
        
        for (auto elem : adj[node]) {
            int nei = elem.first;
            int weight = elem.second;
            
            if (d + weight < dist[nei]) {
                dist[nei] = (d + weight);
                pq.push({dist[nei], nei}); 
                parent[nei] = node;
            }
        }
    }
    
    if(dist[n] == INT_MAX) return {-1};
    
    stack<int>st;
    st.push(n);
    
    while(st.top() != 1) {
        st.push(parent[st.top()]);
    }
    
    vector<int>ans;
    ans.push_back(dist[n]);
    
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
    
}