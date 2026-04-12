#include <bits/stdc++.h>
using namespace std;

//! This is just the problem of surrounded ones, here we are checking total number of surrounded ones

//* Method - I (DFS)

// DFS the boundary cells and mark all the connected ones into 2, this 2 represents the cell is safe. At the end count the number of cells that is 1, these are the cells that are surrounded by water and can't be reached off shore

// Turn visited grid cells into 2, to represtn it is already visited and also to represented it is safe

//. T.C -> O(n*m)
//. S.C -> O(n*m), we are using the grid space itself and also we have recusrvie stack space

void dfs(int r, int c, vector<vector<int>>& grid) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0 || grid[r][c] == 2) return;

    grid[r][c] = 2;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
        int newR = r + dx[i];
        int newC = c + dy[i];

        dfs(newR, newC, grid);
    }
}
int numEnclaves(vector<vector<int>>& grid) {

    for (int j = 0; j < grid[0].size(); j++) {
        dfs(0, j, grid);
        dfs(grid.size()-1, j, grid);
    }

    for (int i = 1; i < grid.size()-1; i++) {
        dfs(i, 0, grid);
        dfs(i, grid[0].size()-1, grid);
    }

    int ans = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 2) {
                grid[i][j] = 1;
            }
            else if (grid[i][j] == 1) ans++;
        }
    }

    return ans;
    
}

//* Method - II (BFS)
// Same concept of traversing the cells from boundary annd maerking all the conncected ones into  2, representing safe, at the end conunt the total ones (whiich represtrn unsafe) and just revert 2s back to 1s to restore the original grid

// Mark cells added into queu as 2, to mark them safe and also it represent visited. This allows us to solve the problem without any space for visited array

//. T.C -> O(n*m)
//. S.C -> O(n*m), for queue in worst case when all cells is 1

int numEnclaves(vector<vector<int>>& grid) {

    queue<pair<int, int>>q;

    // Adding all the boundary 1 cells to queue and marking them 2 (for representing safe and already visited)
    for (int j = 0; j < grid[0].size(); j++) {
        if(grid[0][j] == 1) {
            q.push({0, j});
            grid[0][j] = 2;
        }
        if (grid.back()[j] == 1) {
            q.push({grid.size()-1, j});
            grid[grid.size()-1][j] = 2;
        }
    }
    for (int i = 1; i < grid.size()-1; i++) {
        if(grid[i][0] == 1){
            q.push({i, 0});
            grid[i][0] = 2;
        }
        if(grid[i].back() == 1) {
            q.push({i, grid[0].size()-1});
            grid[i][grid[0].size()-1] = 2;
        }
    }

    int ans = 0;

    while(!q.empty()) {
        
        auto [row, col] = q.front();
        q.pop();

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int newR = row + dx[i];
            int newC = col + dy[i];

            // Checking if out of bounds and invalid cell
            if (newR < 0 || newC < 0 || newR >= grid.size() || newC >= grid[0].size() || grid[newR][newC] != 1) continue;

            // Adding to queue and marking 2 (for representing safe and already visited)
            q.push({newR, newC});
            grid[newR][newC] = 2;
        }
    }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 1; // turning back to 1 to restore the grid
                }
                else if (grid[i][j] == 1) ans++;
            }
    }

    return ans;
    
}