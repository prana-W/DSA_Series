#include <bits/stdc++.h>
using namespace std;

//? Problem: https://leetcode.com/problems/minimum-falling-path-sum/description

//* Method - I (Memoization DP)

// Start from the first row and find the minimum of all the answers, for ending, it is simlar to previous problem

//. T.C -> O(m*n)
//. S.C -> O(m*n + m*n)

int solve(int r, int c, vector<vector<int>>& mat, vector<vector<int>>& dp) {

    if (r >= mat.size()) return 0;
    if(c < 0 || c >= mat[0].size()) return INT_MAX;

    if(dp[r][c] != INT_MIN) return dp[r][c];

    int nextSum = min(solve(r+1, c-1, mat, dp), solve(r+1, c, mat, dp));
    nextSum = min(nextSum, solve(r+1, c+1, mat, dp));

    dp[r][c] = mat[r][c] + nextSum;

    return dp[r][c];
}
int minFallingPathSum(vector<vector<int>>& matrix) {

    vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(), INT_MIN));

    int ans = INT_MAX;

    for (int c = 0; c < matrix[0].size(); c++) {
        ans = min(ans, solve(0, c, matrix, dp));
    }

    return ans;
    
}

//* Method - II (Tabulation DP, Not Space Optimised)

//. T.C -> O(m*n)
//. S.C -> O(m*n)
int minFallingPathSum(vector<vector<int>>& matrix) {

    vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(), INT_MIN));

    for (int r = matrix.size()-1; r >= 0; r--) {
        for (int c = matrix[0].size()-1; c >= 0; c--){

            dp[r][c] = matrix[r][c];
            if (r+1 == matrix.size()) continue;

            int nextSum = dp[r+1][c];
            if(c-1 >= 0) nextSum = min(nextSum, dp[r+1][c-1]);
            if(c+1 < matrix[0].size()) nextSum = min(nextSum, dp[r+1][c+1]);

            dp[r][c] += nextSum;

        }
    }

    int ans = INT_MAX;

    for (int c = 0; c < matrix[0].size(); c++) {
        ans = min(ans, dp[0][c]);
    }

    return ans;
    
}

//* Method - III (Tabulation DP, Space Optimised)

//. T.C -> O(m*n)
//. S.C -> O(n)
int minFallingPathSum(vector<vector<int>>& matrix) {

    vector<int>lastRow(matrix[0].size());

    for (int c = lastRow.size() - 1; c >= 0; c--) {
        lastRow[c] = matrix.back()[c];
    }

    for (int r = matrix.size()-2; r >= 0; r--) {

        vector<int>currentRow(matrix[0].size());

        for (int c = matrix[0].size()-1; c >= 0; c--){

            currentRow[c] = matrix[r][c];

            int nextSum = lastRow[c];
            if(c-1 >= 0) nextSum = min(nextSum, lastRow[c-1]);
            if(c+1 < matrix[0].size()) nextSum = min(nextSum, lastRow[c+1]);

            currentRow[c] += nextSum;
        }

        lastRow = currentRow;
    }

    int ans = INT_MAX;

    for (int c = 0; c < matrix[0].size(); c++) {
        ans = min(ans, lastRow[c]);
    }

    return ans;
    
}