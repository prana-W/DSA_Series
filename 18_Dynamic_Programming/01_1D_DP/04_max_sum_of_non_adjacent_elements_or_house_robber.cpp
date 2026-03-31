#include <bits/stdc++.h>
using namespace std;

//! (TUF Methods, DP on Subsequences) ---------------------------------------
// Using the concept of pick and not-pick. Either skip the current index and go to next index immeditely or pick the current index and go to the next's next index (as we can't take adjacent indices)

//* Method - I (Brute Force)
//! Here we are going from n-th to 0th

int solve(int ind, vector<int>& nums) {
    if (ind == 0) return nums[ind];
    if (ind <  0) return 0;

    int pick = nums[ind] + solve(ind-2, nums);
    int notPick = 0 + solve(ind-1, nums);

    return max(pick, notPick);
}
int brute(vector<int>& nums) {
    int n = nums.size();

    return solve(n-1, nums);
}

// Similarly as below, we can memoize it and also form tabulation methods etc


//! (My Methods) ------------------------------------------

//* Method - I (Brute Force, Recursive)

// We choose the current index and either index+2 or index+3 (whichever gives maximum answer) recursively

// [2, 1, 1, 2], for this the answer will be 4

//. T.C -> O(2^n)
//. S.C -> O(n)

int maxSumfromIthIndex(int index, vector<int>& nums) {

    if (index >= nums.size()) return 0;

    return (nums[index] + max(maxSumfromIthIndex(index+2, nums), maxSumfromIthIndex(index+3, nums)));

}
int brute(vector<int>& nums) {

    return max(maxSumfromIthIndex(0, nums), maxSumfromIthIndex(1, nums));        
    
}

//* method - II (Better Solution, Memoization)
//! Top-Down (required to base case)

// We find the maxSumTillIthIndex, in main we call the function for n-1 and n-2, as the end house could be either (n-1)th or (n-2)th, then use dp to find it recursively

//. T.C -> O(n)
//. S.C -> O(n + n), dp array and recursive stack space

int maxSumTillIthIndex(int index, vector<int>& nums, vector<int>& dp) {

    if (index < 0 || index >= nums.size()) return 0;
    if (dp[index] != -1) return dp[index];

    dp[index] = nums[index] + max(maxSumTillIthIndex(index-2, nums, dp), maxSumTillIthIndex(index-3, nums, dp));

    return dp[index];

}

int better(vector<int>& nums) {

    int n = nums.size();

    vector<int>dp(nums.size(), -1);

    return max(maxSumTillIthIndex(n-1, nums, dp), maxSumTillIthIndex(n-2, nums, dp));
    
}

//* Method - III (Optimal, Tabulation, Not Space Optimised)
//! Iterative (Bottom-Up, base case to required)

//. T.C -> O(n)
//. S.C -> O(n), for dp

int optimalI(vector<int>& nums) {

    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int>dp(n, -1);

    dp[0] = nums[0];
    dp[1] = nums[1];
    if(n > 2) dp[2] = nums[0] + nums[2];

    for (int i = 3; i < n; i++) {
        dp[i] = nums[i] + max(dp[i-2], dp[i-3]);
    }

    return max(dp[n-1], dp[n-2]);
    
}

//* Method - III.V (Optimal, Tabulation, Space Optimised)

//. T.C -> O(n)
//. S.C -> O(1)

int optimalII(vector<int>& nums) {

    int n = nums.size();

    int prev3 = 0; // max sum till (i-3)th index
    int prev2 = 0; // max sum till (i-2)th index
    int prev1 = 0; // max sum till (i-1)th index

    for (int i = 0; i < n; i++) {

        int temp = prev1;

        prev1 = nums[i] + max(prev2, prev3);
        prev3 = prev2;
        prev2 = temp;
    }

    return max(prev1, prev2);
    
}
