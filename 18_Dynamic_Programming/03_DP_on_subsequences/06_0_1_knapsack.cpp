#include <bits/stdc++.h>
using namespace std;

//? Pg: 192

//* Method - I (Brute, Recursion)

// Take or not take each index element and find the maximum value, also when we take, add the value of that index and pass the reduced wt further on

// solve(ind, wt) counts maximum value obtainable using items from ind → n-1 with remaining capacity W

//. T.C -> O(2^n)
//. S.C -> O(n)

int solve(int ind, int W, vector<int>& val, vector<int>& wt) {
    
    if(W < 0) return INT_MIN;
    if(ind == wt.size()) return 0;
    
    int notTake = solve(ind+1, W, val, wt);
    int take = val[ind] + solve(ind+1, W-wt[ind], val, wt);
    
    return max(take, notTake);
}
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    
    return solve(0, W, val, wt);
    
}

//* Method - II (Memoization DP)

//. T.C -> O(n*W)
//. S.C -> O(n*W + n)

int solve(int ind, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
    
    if(ind == wt.size()) return 0;
    
    if (dp[ind][W] != -1) return dp[ind][W];
    
    int notTake = solve(ind+1, W, val, wt, dp);
    int take = 0;
    
    //! Early pruning, to avoid unnncessary recursive func call
    if (W-wt[ind] >= 0) take = val[ind] + solve(ind+1, W-wt[ind], val, wt, dp);
    
    return dp[ind][W] = max(take, notTake);
}
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    
    vector<vector<int>>dp(wt.size(), vector<int>(W+1, -1));
    return solve(0, W, val, wt, dp);
    
}

//* Method - III (Tabulation DP, Not Space Optimised)

//. T.C -> O(n*W)
//. S.C -> O(n*W)

// dp[ind][wt]: Total value from 0 to ind with a total weight of wt
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    
    vector<vector<int>>dp(wt.size(), vector<int>(W+1, 0));
    
    // If wt = 0, then nothing is stolen
    dp[0][0] = 0;

    // We can steal the first item, if total weight is greater than or equal to the weight of first item till end
    for (int weight = wt[0]; weight <= W; weight++) {
        dp[0][weight] = val[0];
    }
    
    for (int i = 1; i < wt.size(); i++) {
        for (int weight = 0; weight <= W; weight++) {
            int notTake = dp[i-1][weight];
            int take = 0;
            if(weight-wt[i] >= 0) take = val[i] + dp[i-1][weight-wt[i]];
            
            dp[i][weight] = max(take, notTake);
        }
    }
    
    return dp.back()[W];
    
}

//* Method - IV (Tabulation DP, Space Optimised)
// Use the reverse loop to avoid temp dp array.

//. T.C -> O(n*W)
//. S.C -> O(W)
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    
    vector<int>dp(W+1, 0);
    
    for (int i = 0; i < wt.size(); i++) {

        //! Notice: We can limit weight till wt[i] only as after that only the pevious dp[weight] will be overwrting itself and no actual update will be made to all the furhter values in dp, as the take one would be ignored due to negative indices
        for (int weight = W; weight >= 0; weight--) {
            
            int notTake = dp[weight];
            int take = val[i] + dp[weight-wt[i]];
            
            dp[weight] = max(take, notTake);
        }
    }
    
    return dp[W];
    
}