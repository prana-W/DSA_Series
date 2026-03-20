#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Check all subarrays naively

//. T.C -> O(n^2)
//. S.C -> O(1)
int brute(vector<int>& nums, int goal) {

    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {

        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += nums[j];

            if (sum == goal) ans++;
            if (sum > goal) break;
        }
    }

    return ans;
    
}

//* Method - II (Better Solution, My Method)

// First pre-compute indices of ones and the consecutive zeroes (sandwiched) before the one and the previous one

// Then if the goal is zero, simply use the zeroFreq array to compute the answer using the given formula

// If it is non-zero, choose the series of ones such that it sums up to goal, and then we make all the possible combinations using this base series and the consecutive zeroes before the starting one and after the ending one, with the forumula and finally compute the answer

//. T.C -> O(n)
//. S.C -> O(n)
int mySolution(vector<int>& nums, int goal) {

    vector<int>ones; // Indices of one
    vector<int>zeroFreq; // Freq of zero to the left of any one (sandwiched between the previous one)

    int cnt = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1){ 
            ones.push_back(i);
            zeroFreq.push_back(cnt);
            cnt = 0;
        }
        else cnt++;
    }

    // For hypothetical one at infinity
    zeroFreq.push_back(cnt);

    int ans = 0;

    // If goal is one, simply find the consecutive zerores and use the given formula to find total subarrays
    if (goal == 0) {
        for (auto elem : zeroFreq) {
            ans += ((elem)*(elem+1))/2;
        }

        return ans;
    }

    int i = 0;
    int j = goal-1;

    while(j < ones.size()) {

        // Consecutive zeroes to the left of starting one
        int left = zeroFreq[i];

        // Consecutive zerores to the right of ending one
        int right = zeroFreq[j+1];

        // Formula for total subarrays with the starting and ending pair of one with all the combinations with zeroes
        ans += (1 + left + right + left*right);

        i++;
        j++;     
    }
    
    return ans;
}

//* Method - II.V (Better Solution)
//! Using prefix sum and Hashmap (similar to 07_Arrays_27_count_subarrays_sum_equal_to_k or 560. Leetcode Problem)

//. T.C -> O(n*log(n)) or O(n) in average for unordered
//. S.C -> O(n)
int better(vector<int>& nums, int goal) {

    map<int, int>mp;
    int sum = 0, ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if (sum == goal) ans++;

        if (mp.find(sum-goal) != mp.end()) {
            ans += mp[sum-goal];
        }

        mp[sum]++;
    }

    return ans;
    
}

//* Method - III (Optimal Approach, My Method)
// Do the same thing as in Method - II (My Method), but instead of precomputing and then using, we will compute in variables, use it and move on

//. T.C -> O(n)
//. S.C -> O(1)
int optimal(vector<int>& nums, int goal) {

    int cnt1 = 0, cnt2 = 0, sum = 0, ans = 0;
    int i = 0, j = 0, n = nums.size();

    // If goal is 0, use the same concept to find the consecutive zeroes and using the formula
    if (goal == 0) {

        while(i < n) {

            if (nums[i] == 0) cnt1++;
            else {
                ans += ((cnt1)*(cnt1+1)/2);
                cnt1 = 0;
            }

            i++;
        }

        if (cnt1) ans += ((cnt1)*(cnt1+1)/2);

        return ans;

    }

    while(j < n) {

        // i will point to the starting one, also counting zeroes before starting one
        while (i < n && nums[i] == 0) {
            cnt1++;
            i++;
        }

        j = max(i, j);

        // here j will point after the ending one
        while(j < n && goal != sum) {
            sum += nums[j];
            j++;
        }

        // Counting zeroes after ending one
        while(j < n && nums[j] == 0) {
            cnt2++;
            j++;
        }

        if(sum == goal) ans += (1 + cnt1 + cnt2 + (cnt1*cnt2));

        sum -= nums[i];
        i++;

        cnt1 = 0;
        cnt2 = 0;            
    }

    return ans;
    
}

//* Method - III.V (Optimal Approach)
// Make a helper function to find at most sum k, then use the function to find the difference of atMost(goal) - atMost(goal-1), this gives us the total subarrays with exactly sum as goal

//. T.C -> O(n)
//. S.C -> O(1)

int subarraysAtMostK(vector<int>& nums, int k) {

    if (k < 0) return 0;

    int n = nums.size(), sum = 0, ans = 0;

    int left = 0;

    for (int right = 0; right < n; right++) {
        sum += nums[right];

        while(sum > k) {
            sum -= nums[left];
            left++;
        }

        ans += (right-left+1);

    }

    return ans;

}
int optimal(vector<int>& nums, int goal) {

    return (subarraysAtMostK(nums, goal) - subarraysAtMostK(nums, goal-1));
    
}