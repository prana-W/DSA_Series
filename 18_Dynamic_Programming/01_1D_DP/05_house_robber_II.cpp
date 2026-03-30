#include <bits/stdc++.h>
using namespace std;

//! First solve previous problem 04_max_sum_of_non_adjancent_elements_or_house_robber

// We can't rob first and last house together. Therfore, make two new arrays from the input array, one without the first house and second array without the last house, now solve both using the same code as House Robber and find the maximum of the two

//* Method - I (Tabulation, Not Space Optimised)
int solve(vector<int>& nums) {

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
int rob(vector<int>& arr) {

    int n = arr.size();

    if (n == 0) return 0;
    if (n == 1) return arr[0];

    // Create two arrays:
    // arr1 excludes the first house
    // arr2 excludes the last house
    vector<int> arr1, arr2;
    for (int i = 0; i < n; i++) {
        if (i != 0) arr1.push_back(arr[i]);
        if (i != n - 1) arr2.push_back(arr[i]);
    }

    // Compute maximum loot for both cases and return the maximum
    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);
    return max(ans1, ans2);
        
}

//* Method - II (Tabulation, Space Optimised)