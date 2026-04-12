#include <bits/stdc++.h>
using namespace std;

// Do DFS and just find the total components of the Graph. To reduce SC, just change the visited nodes to some character here (-), then revert it back to 1. 

//. T.C -> O(n*m)
//. S.C -> O(n*m), since we are using the grid matrix itself for tracking visiting

void dfs(int r, int c, vector<vector<char>>& grid) {

    if(r < 0 || r >= grid.size() || c < 0 || c >= grid[r].size() || grid[r][c] == '0' || grid[r][c] == '-') return;

    grid[r][c] = '-';

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
        int newR = r+dx[i];
        int newC = c+dy[i];

        dfs(newR, newC, grid);
    }

}
int numIslands(vector<vector<char>>& grid) {

    int ans = 0;

    for(int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[r].size(); c++) {
            if(grid[r][c] == '1') {
                dfs(r, c, grid);
                ans++;
            }
        }
    }

    for(int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[r].size(); c++) {
            if(grid[r][c] == '-') {
                grid[r][c] = '1';
            }
        }
    }

    return ans;
    
}

//! Can also be solved by BFS