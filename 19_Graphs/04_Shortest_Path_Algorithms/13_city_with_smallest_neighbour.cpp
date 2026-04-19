#include <bits/stdc++.h>
using namespace std; 

//* Method - I (Floyd Warshall Algorithm)

//. T.C -> O(V^3)
//. S.C -> O(V^2)
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

    const long long INF = INT_MAX;
    
    // Initialise dist with INF
    vector<vector<int>>dist(n, vector<int>(n, INF));

    // Make dist. from i to i as 0
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    // Make it like a directed graph
    for (auto elem : edges) {
        int u = elem[0], v = elem[1], w = elem[2];

        dist[u][v] = w;
        dist[v][u] = w;

    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] == INF || dist[k][j] == INF) continue;

                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

            }
        }
    }

    int mini = INT_MAX;
    int ans = -1;

    // Find the node which has the least cnt of neighbours at a threshold distance
    for (int i = 0; i < n; i++) {

        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if(dist[i][j] <= distanceThreshold) cnt++;
        }

        if (cnt <= mini) {
            mini = cnt;
            ans = i;  
        }
    }

    return ans;
    
}

//* Method - II (Dijkstra Algorithm)
// Apply dijkstra algorithm on all the nodes, to do the same thing

// If graph is sparse, then, this will be better method, else if the graph is very dense, then E will be about V^2, leading to about V^3*log(V) and hence worse time complexity 

//. T.C -> O(V*E*log(V))
//. S.C -> O(V^2)
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

    const long long INF = INT_MAX;

    vector<vector<pair<int, int>>>adj(n);

    for (auto elem : edges) {
        int u = elem[0], v = elem[1], w = elem[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<vector<int>>dist(n, vector<int>(n, INT_MAX));

    // Applying Disktra's Algo over all the nodes
    for (int node = 0; node < n; node++) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, node});
        dist[node][node] = 0;

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int topNode = top.second;
            int d = top.first;

            if (dist[node][topNode] < d) continue;

            for (auto elem : adj[topNode]) {
                int nei = elem.first, w = elem.second;

                if (d + w < dist[node][nei]) {

                    dist[node][nei] = d + w;
                    pq.push({dist[node][nei], nei});

                }
            }
        }
    }

    int mini = INT_MAX;
    int ans = -1;

    for (int i = 0; i < n; i++) {

        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if(dist[i][j] <= distanceThreshold) cnt++;
        }

        if (cnt <= mini) {
            mini = cnt;
            ans = i;  
        }
    }

    return ans;
    
}