#include <bits/stdc++.h>
using namespace std;

//! There can be positives and 0s in the given array

//* My Approach (See TUF Approach in last for a better code and approach) ----------------

//* Method - I (Memoization DP)

// Just like in 03_parition_into_subset_with_subset_k, we used the concept in 01_sbuset_with_sum_tar and used that to find our answer, we will also in this problem, use the concept of 04_count_subset_with_subset_k and first count all the possible values of sum1 from 0 to sum/2 (as after that it behaves as sum2). Then we will simply find the absolute diff and if it matches the given diff, we increase our answer with the number of ways we could have obtained that sum1

//. T.C -> O(n*sum/2)
//. S.C -> O(n*sum/2 + n)

int solve(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    
    if (ind == arr.size() && target == 0) return 1;
    if (ind == arr.size()) return 0;
    
    if (dp[ind][target] != -1) return dp[ind][target];
    
    int notPick = solve(ind+1, target, arr, dp);
    int pick = 0;
    if(target-arr[ind] >= 0) pick = solve(ind+1, target-arr[ind], arr, dp);
    
    return dp[ind][target] = pick + notPick;
}
int countPartitions(vector<int>& arr, int diff) {
    
    int sum = 0;
    for (auto &elem : arr) {
        sum += elem;
    }
    
    vector<vector<int>>dp(arr.size(), vector<int>(sum/2 + 1, -1));
    
    for (int sum1 = 0; sum1 <= sum/2; sum1++) {
        solve(0, sum1, arr, dp);
    }
    
    int ans = 0;
    
    for (int x = 0; x <= sum/2; x++) {
        
        if(dp[0][x] == 0) continue;
        
        int sum1 = x;
        int sum2 = sum - x;
        
        int difference = abs(sum2 - sum1);
        
        if (difference == diff) ans += dp[0][x];
    }
    
    return ans;
}

//* Method - II (Tabulation DP, Not Space Optimised)

// dp[ind][tar]: Total ways to obtain tar from 0 to ind, so for the final check for last index

//. T.C -> O(n*sum/2)
//. S.C -> O(n*sum/2)
int countPartitions(vector<int>& arr, int diff) {
    
    int sum = 0;
    for (auto &elem : arr) {
        sum += elem;
    }
    
    vector<vector<int>>dp(arr.size(), vector<int>(sum/2 + 1, 0));
    
    dp[0][0] = 1;
    if(arr[0] <= sum/2) dp[0][arr[0]] += 1;
    
    for (int i = 1; i < arr.size(); i++) {
        for (int sum1 = 0; sum1 <= sum/2; sum1++) {
            
            int notPick = dp[i-1][sum1];
            int pick = 0;
            if(sum1-arr[i] >= 0) pick = dp[i-1][sum1-arr[i]];
            
            dp[i][sum1] = pick + notPick;
        }
    }
    
    int ans = 0;
    
    for (int x = 0; x <= sum/2; x++) {
        
        if(dp.back()[x] == 0) continue;
        
        int sum1 = x;
        int sum2 = sum - x;
        
        int difference = abs(sum2 - sum1);
        
        if (difference == diff) ans += dp.back()[x];
    }
    
    return ans;
}

//* Method - III (Tabulation DP, Space Optimised)
// We make the loop in reverse of sum1, to avoid making a temp dp array and then copying it in main dp array

//. T.C -> O(n*sum/2)
//. S.C -> O(sum/2)
int countPartitions(vector<int>& arr, int diff) {
    
    int sum = 0;
    for (auto &elem : arr) {
        sum += elem;
    }
    
    vector<int>dp(sum/2 + 1, 0);
    
    dp[0] = 1;
    if(arr[0] <= sum/2) dp[arr[0]] += 1;
    
    for (int i = 1; i < arr.size(); i++) {
        for (int sum1 = sum/2; sum1 >= 0; sum1--) {
            
            int notPick = dp[sum1];
            int pick = 0;
            if(sum1-arr[i] >= 0) pick = dp[sum1-arr[i]];
            
            dp[sum1] = pick + notPick;
        }
    }
    
    int ans = 0;
    
    for (int x = 0; x <= sum/2; x++) {
        
        if(dp[x] == 0) continue;
        
        int sum1 = x;
        int sum2 = sum - x;
        
        int difference = abs(sum2 - sum1);
        
        if (difference == diff) ans += dp[x];
    }
    
    return ans;
}

//* Most Optimal (TUF Approach) ----------------

// We know s - 2*s1 = d, so rearranging, our s1 becomes (s-d)/2, so in other words we just have to find total sets whose sum equal to s1 i.e. (s-d)/2, so just reuse the previous code and put target as (s-d)/2

// Also don't forget for checking invaliud cases, before doing procedding, as our code for findint total subsets with sum k, expects a non-negative target and and also an integer value

//. T.C -> O(n*target)
//. S.C -> O(target)
int countPartitions(vector<int>& arr, int diff) {
    
    int sum = 0;
    for (auto &elem : arr) {
        sum += elem;
    }
    
    //! This is very important
    if (sum - diff < 0 || (sum - diff) % 2) return 0;
    
    int target = (sum-diff)/2;
    
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