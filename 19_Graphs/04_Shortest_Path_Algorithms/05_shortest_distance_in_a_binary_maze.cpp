#include <bits/stdc++.h>
using namespace std;

//? Problem-1: https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
//? Problem-2: https://leetcode.com/problems/shortest-path-in-binary-matrix/

//* Problem - 1

// As the graph is not weighted, we can get the optimal distance at once as all have unit weight using a BFS traversal, therefore since each node will only be processed once, we can simply use a queue, as a PQ uses a extra logarithmic time for pushing and popping, therefore if all veritces will ony be processed once, there is no need to use PQ and increase time complexity, queue will itself work sufficitently

// So solve using a simple BFS traversal

//. T.C -> O(n*m)
//. S.C -> O(n*m)
int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
    
    // If src or dest is empty
    if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0) return -1;

    vector<vector<int>>dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));

    queue<pair<int, pair<int, int>>>q;

    // Add src and mark its initial dist as 0
    q.push({0, source});
    dist[source.first][source.second] = 0;

    while(!q.empty()) {

        auto top = q.front();
        int d = top.first, r = top.second.first, c = top.second.second;
        q.pop();

        // Explore all possible paths
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int newR = r + dx[i];
            int newC = c + dy[i];

            if (newR < 0 || newC < 0 || newR >= grid.size() || newC >= grid[0].size() || grid[newR][newC] == 0) continue;

            if(d+1 < dist[newR][newC]) {
                dist[newR][newC] = d + 1;
                q.push({d+1, {newR, newC}});
            }
        }
    }

    if(dist[destination.first][destination.second] == INT_MAX) return -1;

    return dist[destination.first][destination.second];
    
}

//* Problem - 2

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

    if (grid[0][0] == 1 || grid.back().back() == 1) return -1;

    vector<vector<int>>dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));

    queue<pair<int, pair<int, int>>>q;
    q.push({0, {0, 0}});
    dist[0][0] = 0;

    while(!q.empty()) {

        auto top = q.front();
        int d = top.first, r = top.second.first, c = top.second.second;
        q.pop();

        int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

        for (int i = 0; i < 8; i++) {
            int newR = r + dx[i];
            int newC = c + dy[i];

            if (newR < 0 || newC < 0 || newR >= grid.size() || newC >= grid[0].size() || grid[newR][newC] == 1) continue;

            if(d+1 < dist[newR][newC]) {
                dist[newR][newC] = d + 1;
                q.push({d+1, {newR, newC}});
            }
        }
    }

    if(dist.back().back() == INT_MAX) return -1;
    return dist.back().back() + 1;        
}