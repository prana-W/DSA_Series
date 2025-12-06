#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array containing many elements and k, find the total number of subarrays (contigious elements in the array), whose sum is equal to k

//* Method - I (Mega Brute Force)

//. T.C -> O(n^3)
//. S.C -> O(1)
int megaBruteForce(vector<int> &nums, int k) {

  int n = nums.size();

  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {

      int sum = 0;

      for (int k = i; k <= j; k++) {
        sum += nums[k];

        if (sum == k)
          ans++;
      }
    }
  }

  return ans;
}

//* Method - II (Better Solution)

//. T.C -> O(n^2)
//. S.C -> O(1)
int betterSolution(vector<int> &nums, int k) {

  int ans = 0;

  for (int i = 0; i < nums.size(); i++) {
    int sum = 0;
    for (int j = i; j < nums.size(); j++) {
      sum += nums[j];

      if (sum == k)
        ans++;
    }
  }

  return ans;
}

//* Method - III (Optimal Solution)
//! Prefix Sum

// We will use the same concept as used in the Lecture - 14 of Array (Longest Subarray with sum k)

// We iterate and add the prefixSum into the map along with its count/frequency. Whenever the prefixSum == k, we incrememnt our answer. Also in each step we try to find if sum-k exists in the map or not, if it does, we add the frequency of the number of times x-k occurs, so we can have k that many times

//. T.C -> O(n*log(n)) for ordered map and O(n) for most of the cases if unordered map and O(n^2) for the worst case in unordered map
//. S.C -> O(n)
int optimalSolution(vector<int> &nums, int k) {

  int ans = 0;

  map<int, int> mp; // or can use unordered_map

  int sum = 0;

  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    mp[sum]++;

    if (sum == k)
      ans++;

    if (mp.find(sum - k) != mp.end()) {
      ans += mp[sum - k];
    }
  }

  return ans;
}
