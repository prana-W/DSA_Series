#include <bits/stdc++.h>
using namespace std;

// Concpet: Number of ways to reach a node, is sum of total ways to reach all its adjancet node, so while doing Dijstra's Algorithm using PQ, whwnver we find the distance less than already set, then update the ways of node to its parent, if we find the distance to be same as already set, just increase the ways (don't reset as in previous case)

//* Dijstra's Allgorithm

//. T.C -> O(E*log(V))
//. S.C -> O(V+E)
int countPaths(int n, vector<vector<int>>& roads) {

    int MOD = 1000000007;

    vector<vector<pair<long long, long long>>>adj(n);

    for (int i = 0; i < roads.size(); i++) {
        adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }
    
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
    vector<long long>dist(n, LLONG_MAX);
    vector<long long>ways(n, 0);

    pq.push({0, 0});
    dist[0] = 0;
    ways[0] = 1;

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        long long node = top.second;
        long long d = top.first;

        if (d > dist[node]) continue;

        for(auto elem : adj[node]) {
            long long nei = elem.first;
            long long weight = elem.second;

            // If found a new path with less path sum, then reset the ways for nei node
            if(d+weight < dist[nei]) {
                dist[nei] = d + weight;
                pq.push({dist[nei], nei});
                ways[nei] = ways[node];
            }

            // If found another path with same path sum, then just increase the nei node ways by the total ways to reach this new parent node
            else if(d+weight == dist[nei]) ways[nei] = (ways[nei] + ways[node])%MOD;

        }
    }

    return ways.back();        
}