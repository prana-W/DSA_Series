#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force, Recursive Approach)
// Try all right and down paths, if we get out of bounds or an obstacle return, if we reach the (m-1, n-1), increase the answer counter

void solve(int r, int c, vector<vector<int>>& grid, int& ans) {

    if (r >= grid.size() || c >= grid[0].size() || grid[r][c] == 1) return;

    if (r == grid.size()-1 && c == grid[0].size()-1) ans++;

    solve(r, c+1, grid, ans);
    solve(r+1, c, grid, ans);

}
int brute(vector<vector<int>>& grid) {

    int ans = 0;
    solve(0, 0, grid, ans);
    return ans;
    
}

//* Method - II (Memoization DP)
// Same as previous problem, just return the number of paths for the obstacle cell as 0

//. T.C -> O(m*n)
//. S.C -> O(m*n + m*n)

int paths(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {

    if (r >= grid.size() || c >= grid[0].size() || grid[r][c] == 1) return 0;

    if (dp[r][c] != -1) return dp[r][c];

    dp[r][c] = paths(r, c+1, grid, dp) + paths(r+1, c, grid, dp);

    return dp[r][c];
}
int uniquePathsWithObstacles(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>>dp(m, vector<int>(n, 0));

    // Set paths from target to target as 1, if not blocked
    if(grid[m-1][n-1] != 1) dp[m-1][n-1] = 1;

    return paths(0, 0, grid, dp);
    
}

//* Method - III (Tabulation DP, Not Space Optimised)
// Same concept as before just skip when we get an obstacle

//! There might be need to use long long in dp in LeetCode as there might be some test cases that can overflow it

//. T.C -> O(m*n)
//. S.C -> O(m*n)

int uniquePathsWithObstacles(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>>dp(m, vector<int>(n, 0));

    if(grid[m-1][n-1] != 1) dp[m-1][n-1] = 1;

    for (int r = m-1; r >= 0; r--) {
        for (int c = n-1; c >= 0; c--) {
            // If blocked continue
            if(grid[r][c] == 1) continue;
            if (r < m-1) dp[r][c] += dp[r+1][c];
            if (c < n-1) dp[r][c] += dp[r][c+1];
        }
    }

    return dp[0][0];       
}

//* Method - IV (Tabulation DP, Space Optimised)
// Same as beofre, just take care of cells with 1
// While initialising lastRow array, do it by iterationg, from right to left, if at any point we encounter an obstacle, then mark that cell as 0 obviously, same concept for currRow array inside loop

//! There might be need to use long long for the arrays

//. T.C -> O(m*n)
//. S.C -> O(n)

int uniquePathsWithObstacles(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    if(grid[m-1][n-1] == 1) return 0;

    vector<int>lastRow(n, 0);
    lastRow[n-1] = 1; // Let path from target cell to target cell be 1

    for (int j = n-2; j >= 0; j--) {
        if (grid[m-1][j] == 1) {
            lastRow[j] = 0;
            continue;
        };
        lastRow[j] = lastRow[j+1];
    }

    for (int r = m-2; r >= 0; r--) {
        vector<int>currRow(n, 0);
        int rightCellPath = 0;
        for (int c = n-1; c >= 0; c--) {
            if(grid[r][c] == 1) {
                currRow[c] = 0;
                rightCellPath = 0;
                continue;
            }
            currRow[c] = rightCellPath + lastRow[c];            

            rightCellPath = currRow[c];    
        }

        lastRow = currRow;
    }

    return lastRow[0];      
}

//* 