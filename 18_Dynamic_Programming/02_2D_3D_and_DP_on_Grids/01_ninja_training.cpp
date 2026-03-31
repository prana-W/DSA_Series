#include <bits/stdc++.h>
using namespace std;

//? Problem: https://www.geeksforgeeks.org/problems/geeks-training/1

//* Method - I (Brute Force, Recursion)

//* Method - II (Better, Memoization DP)

//. T.C -> O(n*3*3), n*3 elements and 3 times going into each task each time
//. S.C -> O(3*n + n), O(3n) for DP array and O(n) for recursive stack space

// maxPointTillEnd -> returns the maximum points that can be earned from day = day to end
//! We can also do by maxPointTillDay and calculate for n-1th day in main function
int maxPointTillEnd(int day, int task, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    if (day >= mat.size()) return 0;
    
    if (dp[day][task] != -1) return dp[day][task];
    
    // Finding the maximum points that can be earned from (day+1) to end
    int maxi = 0;
    for (int i = 0; i < 3; i++) {
        // Don't perform the same task the next day
        if (i == task) continue;
        maxi = max(maxPointTillEnd(day+1, i, mat, dp), maxi);
    }
    
    // Maximum points for current day will be points for current day + maximum points in day+1 to end
    dp[day][task] = mat[day][task] + maxi;
    
    return dp[day][task];
    
}
int maximumPoints(vector<vector<int>>& mat) {
    
    vector<vector<int>>dp(mat.size(), vector<int>(mat[0].size(), -1));
    
    // For day - 0, try to do all the tasks and finding the maximum of all
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, maxPointTillEnd(0, i, mat, dp));
    }

    return ans;
    
}

//* Method - III (Optimal, Tabulation DP, Not Space Optimised)

//. T.C -> O(n*3*3)
//. S.C -> O(n*3)
int maximumPoints(vector<vector<int>>& mat) {
    
    vector<vector<int>>dp(mat.size(), vector<int>(mat[0].size(), -1));
    
    dp[0][0] = mat[0][0];
    dp[0][1] = mat[0][1];
    dp[0][2] = mat[0][2];
    
    int ans = 0;
    
    // Finding the maximum points from day-0 till ith day
    // i -> current day
    for (int i = 1; i < mat.size(); i++) {
        // j -> current task
        for (int j = 0; j < 3; j++) {
            
            // Finding the maxPoint from last day excluding the task we are doing now
            int maxPointTillLastDay = 0;
            for (int lastTask = 0; lastTask < 3; lastTask++) {
                if (lastTask == j) continue;
                maxPointTillLastDay = max(maxPointTillLastDay, dp[i-1][lastTask]);
            }
            
            dp[i][j] = maxPointTillLastDay + mat[i][j];
        }
    }
    
    for (int task = 0; task < 3; task++) {
        ans = max(ans, dp[mat.size()-1][task]);
    }
    
    return ans;
}

//* Method - IV (Optimal, Tabulation DP, Space Optimised)

//. T.C -> O(n*3*3)
//. S.C -> O(6)
int maximumPoints(vector<vector<int>>& mat) {
    
    // Trackiong the maximum points for each task till last day
    vector<int>taskLast = {mat[0][0], mat[0][1], mat[0][2]};
    int ans = 0;
    
    // Finding the maximum points from day-0 till ith day
    for (int i = 1; i < mat.size(); i++) {
        // Tracking maximum points till current day for each task
        vector<int>taskCurrent(3, 0);
        for (int j = 0; j < 3; j++) {
            
            // Finding the maxPoint from last day excluding the task we are doing now
            int maxPointTillLastDay = 0;
            for (int lastTask = 0; lastTask < 3; lastTask++) {
                if (lastTask == j) continue;
                maxPointTillLastDay = max(maxPointTillLastDay, taskLast[lastTask]);
            }
            
            taskCurrent[j] = maxPointTillLastDay + mat[i][j];
            
        }
        
        taskLast = taskCurrent;
        
    }
    
    for (int task = 0; task < 3; task++) {
        ans = max(ans, taskLast[task]);
    }
    
    return ans;
}