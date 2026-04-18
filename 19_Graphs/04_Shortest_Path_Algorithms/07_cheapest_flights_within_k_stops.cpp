#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute, Modified Bellman-Ford Algorithm)
// Todo: Do after doing Bellman-Ford Algorithm

//. T.C -> O(k*E)
//. S.C -> O(n)
int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k) {

    vector<int> cost(n, 1e9), curr(n, 1e9);
    cost[src] = 0;

    for(int i = 0; i <= k; i++){
        for(auto &flt: flights){
            curr[flt[1]] = min(curr[flt[1]], cost[flt[0]] + flt[2]);
        }
        swap(cost, curr);
    }

    if(cost[dst] == 1e9) return -1;
    return cost[dst];
}

//* Method - II (Better, Dijstra's Algo with PQ)
// Same solution as below buut with PQ, unnnncessery, idk why :(

//* Method - III (Optimal, Queue Based Approach)
//! AI is saying it is quadratic solution, which even I believe, but in GFG, LeetCode, striver and Aditya Verma this type of solution is discussed
// Todo: Verify this!!
//. T.C -> O(V+E)
//. S.C -> O(V+E)

int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    
    vector<pair<int, int> > adj[n];
    for (auto it : flights) {
        adj[it[0]].push_back({ it[1], it[2] });
    }
    
    // (stops, (node, cost))
    queue<pair<int, pair<int, int> > > q;
    vector<int> costs(n, 1e9);
    
    // We can have k+1 stops after src (including dest)
    q.push({0, {src, 0}});
    costs[src] = 0;
    
    while(!q.empty()) {
        
        auto it = q.front();
        q.pop();
        
        int stops = it.first, node = it.second.first, cost = it.second.second;
        
        // if stop is more than k, then no need to do further stuffs
        if (stops > k) continue;
        
        for (auto elem : adj[node]) {
            int nei = elem.first;
            int weight = elem.second;
            
            if (cost + weight < costs[nei] && stops <= k) {
                costs[nei] = cost + weight;
                q.push({stops+1, {nei, cost+weight}});
            } 
        }
    }
    
    if (costs[dst] == 1e9) return -1;
    return costs[dst];
    
}