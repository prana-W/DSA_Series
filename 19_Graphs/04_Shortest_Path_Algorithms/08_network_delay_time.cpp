#include <bits/stdc++.h>
using namespace std;

// A simple Dijstra' Algorithm and find the dist from src to all the nodes, and find the maximum of all

// Since nodes are 1-based index, so subtraact 1 for the node input to solve all of it using 0-based indexing

//. T.C -> O((E+V) * log(V))
//. S.C -> O(E+V)
int networkDelayTime(vector<vector<int>>& times, int n, int k) {

    vector<vector<pair<int, int>>>adj(n);

    for (int i = 0; i < times.size(); i++) {
        adj[times[i][0]-1].push_back({times[i][1]-1, times[i][2]});
    }

    vector<int>dist(n, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({0, k-1});
    dist[k-1] = 0;

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int node = top.second, d = top.first;

        if (d > dist[node]) continue;

        for(auto elem : adj[node]) {
            int nei = elem.first;
            int weight = elem.second;

            if(d + weight < dist[nei]) {
                dist[nei] = d + weight;
                pq.push({dist[nei], nei});
            }
        }
    }

    int ans = -1;

    for (auto elem : dist) {
        ans = max(ans, elem);
    }

    if (ans == INT_MAX) return -1;
    return ans;        
}