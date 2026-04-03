#include <bits/stdc++.h>
using namespace std;

// Same as previous problem, jsut initiliase dp with INT_MIN, to avoid confusion

//* Method - I (Memoization DP)

//. T.C -> O(m*n)
//. S.C -> O(m*n + m), O(rows) for for recursive stack space 


int solve(int r, int c, vector<vector<int>>& mat, vector<vector<long long>>& dp) {
    if (r >= mat.size()) return 0;

    //! Note: Did INT_MIN here to avoid wrong checking as sum might be -1 itself (due to negatie numbers in the problem)
    if(dp[r][c] != INT_MIN) return dp[r][c];

    dp[r][c] = mat[r][c] + min(solve(r+1, c, mat, dp), solve(r+1, c+1, mat, dp));

    return dp[r][c];
}
int minimumTotal(vector<vector<int>>& triangle) {

    vector<vector<long long>>dp(triangle.size());

    for (int r = 0; r < triangle.size(); r++) {
        for(int c = 0; c < triangle[r].size(); c++) {
            dp[r].push_back(INT_MIN);
        }
    }

    return solve(0, 0, triangle, dp);
    
}

//* Method - II (Tabulation DP, Not Space Optimised)

//. T.C -> O(m*n)
//. S.C -> O(m*n)
int minimumTotal(vector<vector<int>>& triangle) {

    vector<vector<long long>>dp(triangle.size());

    for (int r = 0; r < triangle.size(); r++) {
        for(int c = 0; c < triangle[r].size(); c++) {
            dp[r].push_back(INT_MIN);
        }
    }

    for (int r = triangle.size()-1; r >= 0; r--) {
        for (int c = triangle[r].size()-1; c >= 0; c--){

            dp[r][c] = triangle[r][c];
            if(r+1 < triangle.size()) dp[r][c] += min(dp[r+1][c], dp[r+1][c+1]);
        }
    }

    return dp[0][0];
    
}

//* Method - III (Tabulation DP, Space Optimised)

//. T.C -> O(m*n)
//. S.C -> O(n)
int minimumTotal(vector<vector<int>>& triangle) {

    vector<int>lastRow(triangle.back().size());

    for (int c = lastRow.size() - 1; c >= 0; c--) {
        lastRow[c] = triangle.back()[c];
    }

    for (int r = triangle.size()-2; r >= 0; r--) {

        vector<int>currentRow(triangle.back().size());

        for (int c = triangle[r].size()-1; c >= 0; c--){

            currentRow[c] = triangle[r][c];
            if(r+1 < triangle.size()) currentRow[c] += min(lastRow[c], lastRow[c+1]);
        }

        lastRow = currentRow;
    }

    return lastRow[0];
    
}