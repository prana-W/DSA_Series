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

//* Method - II (Better Solution, Dijstra's Algo with PQ)

//. T.C -> O(k*E*log(V))
//. S.C -> O(V+E)

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

    vector<pair<int, int> > adj[n];
    for (auto it : flights) {
        adj[it[0]].push_back({ it[1], it[2] });
    }
    
    // (stops, (node, cost))
    // priority_queue<pair<int, pair<int, int>>> q;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    vector<int> costs(n, 1e9);
    
    // We can have k+1 stops after src (including dest)
    q.push({0, {src, 0}});
    costs[src] = 0;
    
    while(!q.empty()) {
        
        auto it = q.top();
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

//* Method - III (Optimal, Queue Based Approach)

//! Note: As the state is stop and cost, we put both in the queue, as both are needed and we don't need current value, but the value at the tiome the entry was made

// As the state stop is unit, it increases one-by-one, so that's why queue is better, it is similar to why queue was better in unweighted graph (there we had weight = 1), here we have 1 stop count beteween each flight

//. T.C -> O(k*(V+E)), at worst case there can be k times reprocessment of a node, because after that we don't proceess further due to (stops > k) condition
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