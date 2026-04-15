#include <bits/stdc++.h>
using namespace std;

//* Method - I (DFS)
// Any node that is a part of cycle can never be our answer. Any node part of the cycle and every node part of this cycle, directly or indirectly could never be our answer.

// So, we just do a DFS and keep on exploring all the paths that we have, we if ever encounter a cycle anywhere in the path, we can never reach our endgoal, if we don't detect any cycle and also reach the end, we can say that we reached a terminal node (safe node), and hence include the curren node in ourr answer

//. T.C -> O(V+E)
//. S.C -> O(V+E)

bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& pathVisited, vector<int>& ans) {

    visited[node] = true;
    pathVisited[node] = true;

    for (auto elem : adj[node]) {
        if(!visited[elem] &&  dfs(elem, adj, visited, pathVisited, ans)) return true;
        else if (pathVisited[elem]) return true;
    }

    pathVisited[node] = false;
    ans.push_back(node);

    return false;

}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

    int V = graph.size();

    vector<vector<int>>adj(V);
    vector<int>ans;

    for (int i = 0; i < V; i++) {
        for (auto elem : graph[i]) {
            int u = i;
            int v = elem;

            adj[u].push_back(v);
        }
    }

    vector<bool>visited(V, false);
    vector<bool>pathVisited(V, false);

    for(int i = 0; i < V; i++) {
        if(!visited[i]) dfs(i, adj, visited, pathVisited, ans);
    }

    sort(ans.begin(), ans.end());

    return ans;
    
}

//* Method - II (BFS)
// First find all the nodes with outdegree 0, these are for sure terminal node, that find all the nodes that leads to this node, and reduce their outdegree, just like that, keep on doing it till we find all the nodes whose outdegree ultimately becomes 0. This is our key intuition, but finding all the nodes that lead to current node is very time cinsuming task, so we create the graph in reverse (incoming edges becoming outgoinf and vicec-versa)

// So simply the problem reverses and becomes find all the nodes with indegree zero, then go to all its neignhbours and reduce their indegeree, if any neigboiur gets a 0 indegree again add it to queue and so on. So it just become BFS with Topological Sort of thing, which find all the nodes that ultimaely reaches 0 indegree

//. T.C -> O(V+E)
//. S.C -> O(V+E)

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

    int V = graph.size();

    vector<vector<int>>adj(V);
    vector<int>indegree(V, 0);

    for (int i = 0; i < V; i++) {
        for (auto elem : graph[i]) {
            int u = i;
            int v = elem;

            // Reversing the Graph
            adj[v].push_back(u);
            indegree[u]++;
        }
    }

    queue<int>q;
    vector<int>ans;

    for (int i = 0; i < V; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto elem : adj[node]) {
            indegree[elem]--;

            if(indegree[elem] == 0) q.push(elem);
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
    
}