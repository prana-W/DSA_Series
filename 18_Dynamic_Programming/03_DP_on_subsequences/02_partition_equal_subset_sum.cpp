#include <bits/stdc++.h>
using namespace std;

//! We need to parition the array into exactly two subsets with equal sum. Also no elements should be left begind, hence in other words we need to check if the sum of any of the subset is equal to total_sum/2, then the sum of the other subset will also be total_sum/2 and hence such a subset will exist

//! Can be further optimised, by checking the total sum for odd, if odd then it can't be partiioned into to subsets with equal sum, so just return false  

//* Solve like previous problem, just pass target = total_sum/2

//* Other Method
bool solve(int ind, int sum1, int sum2, vector<int>& nums, vector<vector<int>>& dp) {

    if(ind == nums.size() && sum1 == sum2 && sum1 != 0) return true;
    if(ind >= nums.size()) return false;

    if(dp[ind][sum1] != -1) return dp[ind][sum1];

    // Pick the element in the first subset
    bool pickInFirst = solve(ind+1, sum1+nums[ind], sum2, nums, dp);
    // Pick the element in the second subset
    bool pickInSecond = solve(ind+1, sum1, sum2+nums[ind], nums, dp);

    return dp[ind][sum1] = (pickInFirst || pickInSecond);
}
bool canPartition(vector<int>& nums) {
    
    int sum = 0;
    for(auto elem : nums) {
        sum += elem;
    }

    // We have two independent states, ind and sum1 (sum2 = sum-sum1, so it is depenededntt on sum1, now just use simple DP to check it)
    vector<vector<int>>dp(nums.size(), vector<int>(sum+1, -1));

    return solve(0, 0, 0, nums, dp);
    
}