#include <bits/stdc++.h>
using namespace std;

//? Problem - 1 (with only positives): https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1

//? Problem - 2 (with poth positves and negatives): https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/


//? Problem - 1

//* Method - I (Not Reccomended, Memoization DP, My Method)

// We only take sum in DP upto sum/2, because after that it is symmetrical and is not required. We have two DP states, index and sum1, and at the end just do sum-2*sum1, to find the absolute difference of the two subsets

//. T.C -> O(n * sum/2)
//. S.C -> O(n * sum/2 + n)

// dp[ind][sum1]: Minimum possible absolute difference we can achieve using elements from index ind → n-1, given that the current subset1 sum is already sum1, so we just have to return dp[0][0], initial base case
int solve(int ind, int sum1, int& sum, vector<int>& arr, vector<vector<int>>& dp) {
    
    //! If sum1 > sum/2, then consider it INT_MAX
    if(sum1 > sum/2) return INT_MAX;
    if (ind == arr.size()) {
        return abs(sum - 2*sum1);
    }
    
    if (dp[ind][sum1] != -1) return dp[ind][sum1];
    
    // If we pick in second, we don't modify sum1
    int pickInSecond = solve(ind+1, sum1, sum, arr, dp);
    
    // If we pick in first, we modify sum1
    int pickInFirst = solve(ind+1, sum1+arr[ind], sum, arr, dp);
    
    return dp[ind][sum1] = min(pickInFirst, pickInSecond);
}
int minDifference(vector<int>& arr) {
    
    int sum = 0;
    for (auto elem : arr) {
        sum += elem;
    }
    
    vector<vector<int>>dp(arr.size(), vector<int>(sum/2 + 1, -1));
    
    return solve(0, 0, sum, arr, dp);
    
}

//* Method - I.V (Memoization DP, Preffered Solution, TUF Method)
// We use the concept of 01_subset_sum_equal_to_target and find all the possible sum1 that is possible from 0 to n-1, then just find the minimum absolute difference (s - 2*s1) for the 0th index (if dp started from 0 to n-1). So we will use the code for subset_sum_equal_to_target and call it for all the possible target from 0 to sum/2, for all the possible candidates of sum1, and then just compute the minimum absolute differnce of the all, if a particular sum1 value is possible

//. T.C -> O(n * sum/2)
//. S.C -> O(n * sum/2 + n)

int check(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    
    if (target == 0) return 1;
    if (ind == arr.size() || target < 0) return 0;
    
    if(dp[ind][target] != -1) return dp[ind][target];
    
    int notTake = check(ind+1, target, arr, dp);
    int take = check(ind+1, target-arr[ind], arr, dp);
    
    return dp[ind][target] = (notTake || take);

}
int minDifference(vector<int>& arr) {

    int sum = 0;
    for (auto elem : arr) {
        sum += elem;
    }
    
    vector<vector<int>>dp(arr.size(), vector<int>(sum/2 + 1, -1));

    int ans = INT_MAX;

    // Calling DP for all possible target for sum1 and finding the minimum answer using that sum1
    for (int sum1 = 0; sum1 <= sum/2; sum1++) {
        if(check(0, sum1, arr, dp) == 1) ans = min(ans, abs(sum - 2*sum1));
    }

    return ans;
    
}

//* Method - II (Tabulation DP, TUF Method)
// Just like subset_sum_equal problem we form our table, and check for all the possible sum1 for the last index, and compute the minimum answer from it.

//. T.C -> O(n * sum/2)
//. S.C -> O(n * sum/2)
int minDifference(vector<int>& arr) {
    
    int sum = 0;
    for (auto elem : arr) {
        sum += elem;
    }
    
    vector<vector<bool>>dp(arr.size(), vector<bool>(sum/2 + 1, false));

    for (int i = 0; i < arr.size(); i++) {
        dp[i][0] = true;
    }
    
    // Another base case
    if (arr[0] <= sum/2) dp[0][arr[0]] = true;
    
    // dp[x][y]: If it is possible to get sum1 as y from index 0 to ind 
    
    for (int i = 1; i < arr.size(); i++) {
        for (int tar = 1; tar <= sum/2; tar++) {
            
            bool notTake = dp[i-1][tar];
            
            bool take = false;
            if(tar >= arr[i]) take = dp[i-1][tar - arr[i]];
            
            dp[i][tar] = notTake || take;
        }
    }
    
    int ans = INT_MAX;

    for (int sum1 = 0; sum1 <= sum/2; sum1++) {
        if(dp.back()[sum1]) ans = min(ans, abs(sum - 2*sum1));
    }

    return ans;
    
}

//* Method - III (Tabulation, Space Optimised)
// Just use a single DP and use tar in reverse manner to avoid collision and updateing dp array inplace rather than creating a temp array and storing and then copying it in main dp array

//. T.C -> O(n * sum/2)
//. S.C -> O(sum/2)
int minDifference(vector<int>& arr) {
    
    int sum = 0;
    for (auto elem : arr) {
        sum += elem;
    }
    
    vector<bool>dp(sum/2 + 1, false);
    dp[0] = true;
    
    for (int i = 0; i < arr.size(); i++) {
        for (int tar = sum/2; tar >= 0; tar--) {
            
            bool notPick = dp[tar];
            bool pick = false;
            if(tar - arr[i] >= 0) pick = dp[tar - arr[i]];
            
            dp[tar] = pick || notPick;
        }
    }
    
    int ans = INT_MAX;

    for (int sum1 = 0; sum1 <= sum/2; sum1++) {
        if(dp[sum1]) ans = min(ans, abs(sum - 2*sum1));
    }

    return ans;
    
}

//? Problem - 2 
// Todo: Do for negative variant from LeetCode as well!