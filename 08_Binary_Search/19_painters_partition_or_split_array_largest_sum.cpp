#include <bits/stdc++.h>
using namespace std;

// Similar to Book Allocation Problem

int totalSplits(vector<int>arr, int sum) {
        int splits = 1;
        int cnt = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (cnt + arr[i] <= sum) {
                cnt += arr[i];
            }
            else {
                splits++;
                cnt = arr[i];
            }
        }

        return splits;
}

int splitArray(vector<int>& nums, int k) {

        if (nums.size() < k) return -1;

        int low = INT_MIN, high = 0;

        for (auto elem : nums) {
            low = max(low, elem);
            high += elem;
        }

        while (low <= high) {
            int mid = low + (high-low)/2;

            int splits = totalSplits(nums, mid);

            if (splits > k) low = mid + 1;
            else high = mid - 1;
           
        }

        return low;
        
}