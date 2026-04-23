#include <bits/stdc++.h>
using namespace std;

//? Problem - 1: (non-negatives only) https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

//? Problem - 2: (with negatives as well) https://www.geeksforgeeks.org/problems/count-the-subset-with-sum-equal-to-k/1

//? Problem - 1 (with positives only)

//* Method - I (Memoization DP)

//. T.C -> O(n*target)
//. S.C -> O(n*target + n)

// Keep a dp of two states index and target, so it will be a 2D DP with arr size as first and target+1 as the other. Also only count when we reach the end and the target is equal to 0. Because it might be that we get target as 0 in the middle and we have 0s in the array as well, so we can't instantly from there but actually reach the end and then only return.

// dp[ind][target]: from ind to end, count of total subsets from ind to end with target as target
int solve(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    
    if (ind == arr.size() && target == 0) return 1;
    if (ind == arr.size() || target < 0) return 0;
    
    if(dp[ind][target] != -1) return dp[ind][target];
    
    int notPick = solve(ind+1, target, arr, dp);
    int pick = solve(ind+1, target-arr[ind], arr, dp);
    
    return dp[ind][target] = pick + notPick;
    
}
int perfectSum(vector<int>& arr, int target) {
    
    vector<vector<int>>dp(arr.size(), vector<int>(target+1, -1));
    return solve(0, target, arr, dp);
        
}

//* Method - II (Tabulation DP, Not Space Optimised)

//. T.C -> O(n*target)
//. S.C -> O(n*target + n)
int perfectSum(vector<int>& arr, int target) {
    
    // dp[ind][tar]: Number of subsets from 0 to ind with tar starting at target at index ind, so we need to return dp[n-1][target], as we want total subsets from start to end with tar as target at index n-1
    vector<vector<int>>dp(arr.size(), vector<int>(target+1, 0));
    
    // If we don't pick anything from first index and we already have tar as 0, then that is one possiblity
    dp[0][0] = 1;

    // We can pick the first element and then the tar would reach 0, so that's another one possiblity
    if(arr[0] <= target) dp[0][arr[0]] += 1;
    
    for (int i = 1; i < arr.size(); i++) {
        for (int tar = 0; tar <= target; tar++) {
            int notPick = dp[i-1][tar];
            
            int pick = 0;
            if (tar-arr[i] >= 0) pick = dp[i-1][tar-arr[i]];
            
            dp[i][tar] = pick + notPick;
        }
    }
    
    return dp.back()[target];

}


//* Method - III (Tabulation DP, Space Optimised)
// We make a reverse loop for tar, to avoid collision and solve without a temp dp array

//. T.C -> O(n*target)
//. S.C -> O(target)
int perfectSum(vector<int>& arr, int target) {
    
    vector<int>dp(target+1, 0);
    
    dp[0] = 1;
    if(arr[0] <= target) dp[arr[0]] += 1;
    
    for (int i = 1; i < arr.size(); i++) {
        for (int tar = target; tar >= 0; tar--) {
            
            int notPick = dp[tar];
            
            int pick = 0;
            if (tar-arr[i] >= 0) pick = dp[tar-arr[i]];
            
            dp[tar] = pick + notPick;
        }
    }
    
    return dp[target];

}

//? Problem - 2 (Solve for both positives and negatives)
// Todo