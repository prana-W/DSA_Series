#include <bits/stdc++.h>
using namespace std;

// Just like 03_grid_unqiue_path, here keep track of the minimum sum. Also for the out-of-boundaries, treat there sum as INT_MAX, to avoid that path

//! In case of negatives, initialise dp array with INT_MIN, to avoid wrong checking

//* Method - I (Memoization DP)

//. T.C -> O(m*n)
//. S.C -> O(m*n + m*n)

// Recursive function to find the minimum sum from (r, c) to (m-1, n-1)
int solve(int r, int c, vector<vector<int>>& grid, vector<vector<long long>>& dp) {
    if (r >= grid.size() || c >= grid[0].size()) return INT_MAX;

    if(dp[r][c] != -1) return dp[r][c];

    dp[r][c] = grid[r][c] + min(solve(r, c+1, grid, dp), solve(r+1, c, grid, dp));

    return dp[r][c];
}
int minPathSum(vector<vector<int>>& grid) {

    vector<vector<long long>>dp(grid.size(), vector<long long>(grid[0].size(), -1));

    dp.back().back() = grid.back().back();

    return solve(0, 0, grid, dp);
    
}

//* Method - II (Tabulation DP, Not Space Optimised)

//. T.C -> O(m*n)
//. S.C -> O(m*n)
int minPathSum(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>>dp(m, vector<int>(n, INT_MAX));
    dp[m-1][n-1] = grid[m-1][n-1];

    for (int r = m-1; r >= 0; r--) {
        for (int c = n-1; c >= 0; c--) {
            if(r == m-1 && c == n-1) continue;

            if (r < m-1) dp[r][c] = min(dp[r][c], dp[r+1][c]);
            if (c < n-1) dp[r][c] = min(dp[r][c], dp[r][c+1]);
            dp[r][c] += grid[r][c];
        }
    }

    return dp[0][0];
    
}

//* Method - III (Tabulation DP, Space Optimised)

//. T.C -> O(m*n)
//. S.C -> O(n)
int minPathSum(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector<int>lastRow(n);
    lastRow[n-1] = grid[m-1][n-1];

    for (int c = n-2; c >= 0; c--) {
        lastRow[c] = (lastRow[c+1] + grid[m-1][c]);
    }

    for (int r = m-2; r >= 0; r--) {
        int rightMinSum = INT_MAX; // initiallu keep thr out-of-bounds right path sum as INT_MAX
        vector<int>currRow(n, 0);
        for (int c = n-1; c >= 0; c--) { 

            currRow[c] = grid[r][c] + min(rightMinSum, lastRow[c]);
            rightMinSum = currRow[c];

        }
        lastRow = currRow;
    }

    return lastRow[0];
    
}