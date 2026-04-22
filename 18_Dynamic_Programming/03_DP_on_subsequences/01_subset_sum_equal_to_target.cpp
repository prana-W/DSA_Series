#include <bits/stdc++.h>
using namespace std;

//? Pg: 191

//* Method - I (Brute Force, Recursion)
// Simple pick, not pick concept

//. T.C -> O(2^n)
//. S.C -> O(n), recursive stack space

bool check(int ind, int target, vector<int>& arr) {
    
    if (target == 0) return true;

    //! Early pruning, if all elments are positive and target becomes less than zero
    if (ind == arr.size() || target < 0) return false;
    
    // Not pick and pick
    return (check(ind+1, target, arr) || check(ind+1, target-arr[ind], arr));
}
bool isSubsetSum(vector<int>& arr, int sum) {
    return check(0, sum, arr);   
}

//* Method - II (Memoization DP)
// There are some overlapping subproblems, so we can make a dp with first state as the index and the second state as the target required as of now

//. T.C -> O(n*target)
//. S.C -> O(n*target + n)

int check(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    
    if (target == 0) return 1;
    if (ind == arr.size() || target < 0) return 0;
    
    if(dp[ind][target] != -1) return dp[ind][target];
    
    int notTake = check(ind+1, target, arr, dp);
    int take = check(ind+1, target-arr[ind], arr, dp);
    
    return dp[ind][target] = (notTake || take);

}
bool isSubsetSum(vector<int>& arr, int target) {
    
    // dp[ind][tar] means if it is possible to form target using elements from index ind to end
    vector<vector<int>>dp(arr.size(), vector<int>(target+1, -1));

    return check(0, target, arr, dp);
    
}

//* Method - III (Tabulation DP, Not Space Optimised)

//. T.C -> O(n*target)
//. S.C -> O(n*target)
bool isSubsetSum(vector<int>& arr, int target) {
    
    // dp[i][tar] = can we form tar using elements from 0 → i
    vector<vector<bool>>dp(arr.size(), vector<bool>(target+1, false));
    
    // It is possible to get tar = 0 from every index, as we won't take any element from this index till end
    for(int i = 0; i < arr.size(); i++) {
        dp[i][0] = true;
    } 

    //! Another base case
    if (arr[0] <= target) dp[0][arr[0]] = true;
    
    for (int i = 1; i < arr.size(); i++) {
        for (int tar = 1; tar <= target; tar++) {

            bool notTake = dp[i-1][tar];

            bool take = false;
            if(tar-arr[i] >= 0) take = dp[i-1][tar-arr[i]];
            
            dp[i][tar] = notTake || take;
        }
    }

    return dp.back()[target];
    
}

//* Method - IV (Tabulation, Space Optimised)

// As only the nextIndex result is important, we can use a single DP array to store the result of the next DP array and store in the result in a temp array and then copy it to the nextRow DP

//. T.C -> O(n*target)
//. S.C -> O(n)
bool isSubsetSum(vector<int>& arr, int target) {
    
    vector<bool> dp(target + 1, false);
    dp[0] = true;  // sum 0 is always possible
    
    for (int i = 0; i < arr.size(); i++) {

        //! Reverse Loop ensures there is no collision and hence we don't require temp array
        for (int tar = target; tar >= arr[i]; tar--) {
            dp[tar] = dp[tar] || dp[tar - arr[i]];
        }
    }

    return dp[target];
}