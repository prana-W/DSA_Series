#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force, Recursion)

// Try to explore right and down path from each cell and count in ans if we reach the (m-1, n-1), if we get out of bounds, return

//. T.C -> O(2^(m*n))
//. S.C -> O(m+n)

void solve(int r, int c, int& m, int& n, int& ans) {

    if (r == m-1 && c == n-1) ans++;

    if(r >= m || c >= n) return;

    solve(r, c+1, m, n, ans);
    solve(r+1, c, m, n, ans);

}
int uniquePaths(int m, int n) {

    int ans = 0;

    solve(0, 0, m, n, ans);
    return ans;
    
}

//* Method - II (Better, Memoization DP)

//. T.C -> O(m*n)
//. S.C -> O(m*n + m*n)

// This function calculates the total paths to reach the target from (r, c)
int pathsTillEnd(int r, int c, int& m, int& n, vector<vector<int>>& dp) {

    if (r >= m || c >= n) return 0;
    if(dp[r][c] != -1) return dp[r][c];

    dp[r][c] = pathsTillEnd(r, c+1, m, n, dp) + pathsTillEnd(r+1, c, m, n, dp);

    return dp[r][c];

}
int uniquePaths(int m, int n) {

    vector<vector<int>>dp(m, vector<int>(n, -1));
    dp[m-1][n-1] = 1; // Base value for DP

    // We need to find the path from (0, 0) to end
    return pathsTillEnd(0, 0, m, n, dp);
    
}

//* Method - III (Optimal, Tabulation DP, Not Space Optimised)

//. T.C -> O(m*n)
//. S.C -> O(m*n)
int uniquePaths(int m, int n) {

    vector<vector<int>>dp(m, vector<int>(n, 0));
    dp[m-1][n-1] = 1;

    for (int r = m-1; r >= 0; r--) {
        for (int c = n-1; c >= 0; c--) {
            if(c+1 < n) dp[r][c] += dp[r][c+1];
            if(r+1 < m) dp[r][c] += dp[r+1][c];
        }
    }
    
    return dp[0][0];
    
}

//* Method - IV (Optimal, Tabulation, Space Optimised)

// Instead of making a 2D DP, make a array that stores the total paths for a row, now use this to compute the downPaths for the previous row and so on. We can finid the rightPath, by making a single varible inside the loop

//. T.C -> O(m*n)
//. S.C -> O(n)
int uniquePaths(int m, int n) {

    // Total Paths in the lastRow
    vector<int>lastRowPaths(n, 1);

    for (int r = m-2; r >= 0; r--) {

        vector<int>currRowPaths(n);
        int rightPath = 0;

        for (int c = n-1; c >= 0; c--) {
            currRowPaths[c] = (lastRowPaths[c] + rightPath);
            rightPath = currRowPaths[c];
        }

        lastRowPaths = currRowPaths;
    }
    
    return lastRowPaths[0];
    
}

//* Method - V (Most Optimal Approach, Combinatronics)

// We are at (0, 0) and to reach (m-1, n-1), we need to travel m-1 steps in down and n-1 steps in right. Therefore total (m+n-2) steps out of which (m-1) will be down and (n-1) will be right

// Therefore use nCr, to calculate the total ways of choosing (n-1) right steps out of (m+n-2) total steps, and the remaining will automaitccaly become down steps

//. T.C -> O(min(m, n))
//. S.C -> O(1)

int comb(int n, int r) {

    //! For furhter optmising the compleixty
    r = min(r, n-r);

    long long ans = 1;

    for (long long i = 1; i <= r; i++) {
        ans *= n;
        ans /= i;
        
        n--;
    }
    return ans;
}
int uniquePaths(int m, int n) {

    return comb(m+n-2, n-1);
    
}