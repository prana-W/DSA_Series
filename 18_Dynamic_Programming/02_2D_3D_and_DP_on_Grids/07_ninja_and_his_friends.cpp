#include <bits/stdc++.h>
using namespace std;

//? Problem: https://leetcode.com/problems/cherry-pickup-ii/

//* Method - I (Brute Force, Recursion)
// We can maintain threee parameters, r, c1, c2, being the row of robot1 and robot2 (both will have same row at any time as both move down simulat.), and coloumn of  robot1 and robot2 respectively. Each robot can go to three coloumns, making in total a 3x3 i.e. 9 combinations of movements possible collectively, find the maximum of these 9 combos and return that adding the current cells (only include once iof both are at same)

//. T.C -> O(3^n * 3^n)
//. S.C -> O(n), recursive stack space

int solve(int r, int c1, int c2, vector<vector<int>>& grid) {

    if (r >= grid.size() || c1 < 0 || c2 < 0 || c1 >= grid[0].size() || c2 >= grid[0].size()) return 0;

    int nextSum = 0;

    // Exploring all 9 combinations of the two robot orientation in next step
    int dj[3] = {-1, 0, 1};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int cNew1 = c1 + dj[i];
            int cNew2 = c2 + dj[j];
            
            // Find the max sum in nextRow
            nextSum = max(nextSum, (solve(r+1, cNew1, cNew2, grid))); 
        }
    }

    // Including the cells of both robots if not at same cell
    if (c1 != c2) return (nextSum + grid[r][c1] + grid[r][c2]);
    return (nextSum + grid[r][c1]);
}
int cherryPickup(vector<vector<int>>& grid) {

    // Solve using three parameters, row, colo1 and col2
    return solve(0, 0, grid[0].size()-1, grid);
    
}

//* Method - II (Memoization DP)
// Use DP with three states for solving, one for row, one for col1 and col2

//. T.C -> O(n*m*m*9)
//. S.C -> O(n*m*m + n), O(n*m*m) for DP and O(n) for recursive stack space

int solve(int r, int c1, int c2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {

    if (r >= grid.size() || c1 < 0 || c2 < 0 || c1 >= grid[0].size() || c2 >= grid[0].size()) return 0;

    if(dp[r][c1][c2] != -1) return dp[r][c1][c2];

    int dj[3] = {-1, 0, 1};
    int nextSum = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int cNew1 = c1 + dj[i];
            int cNew2 = c2 + dj[j];
            
            nextSum = max(nextSum, (solve(r+1, cNew1, cNew2, grid, dp))); 
        }
    }

    if (c1 != c2) return dp[r][c1][c2] = (nextSum + grid[r][c1] + grid[r][c2]);
    return dp[r][c1][c2] = (nextSum + grid[r][c1]);
}
int cherryPickup(vector<vector<int>>& grid) {

    // (n x m x m) DP
    vector<vector<vector<int>>>dp (grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));

    return solve(0, 0, grid[0].size()-1, grid, dp);
    
}

//* Method - III (Tabulation, Not Space Optimised)

//. T.C -> O(n*m*m*9)
//. S.C -> O(n*m*m)
int cherryPickup(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<vector<int>>>dp (m, vector<vector<int>>(n, vector<int>(n, -1)));

    for(int r = m-1; r >= 0; r--) {
        for (int c1 = n-1; c1 >= 0; c1--) {
            for (int c2 = n-1; c2 >= 0; c2--) {

                int dj[3] = {-1, 0, 1};
                int nextSum = 0;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int cNew1 = c1 + dj[i];
                        int cNew2 = c2 + dj[j];
                        
                        if(r+1 < m && cNew1 >= 0 && cNew1 < n && cNew2 >= 0 && cNew2 < n) nextSum = max(nextSum, (dp[r+1][cNew1][cNew2])); 
                    }
                }

                if (c1 != c2) dp[r][c1][c2] = (nextSum + grid[r][c1] + grid[r][c2]);
                else dp[r][c1][c2] = (nextSum + grid[r][c1]);
                    
            }
        }
    }

    return (dp[0][0][n-1]);
    
}

//* Method - IV (Tabulation, Space Optimised)

// Use a 2D array to keep track of states (c1, c2) for the lastRow, and use this to calculate the answer for each row and update it


//. T.C -> O(n*m*m*9)
//. S.C -> O(m*m)
int cherryPickup(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>>lastRow(n, vector<int>(n, -1));

    for(int r = m-1; r >= 0; r--) {

        vector<vector<int>>currRow(n, vector<int>(n));

        for (int c1 = n-1; c1 >= 0; c1--) {
            for (int c2 = n-1; c2 >= 0; c2--) {

                int dj[3] = {-1, 0, 1};
                int nextSum = 0;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int cNew1 = c1 + dj[i];
                        int cNew2 = c2 + dj[j];
                        
                        if(r+1 < m && cNew1 >= 0 && cNew1 < n && cNew2 >= 0 && cNew2 < n) nextSum = max(nextSum, (lastRow[cNew1][cNew2])); 
                    }
                }

                if (c1 != c2) currRow[c1][c2] = (nextSum + grid[r][c1] + grid[r][c2]);
                else currRow[c1][c2] = (nextSum + grid[r][c1]);
                    
            }
        }

        lastRow = currRow;
    }

    return (lastRow[0][n-1]);
    
}