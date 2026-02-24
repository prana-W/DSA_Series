#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Make a outer loop from i = 0 till end, and make a inner loop from j = i till end, if the total zeroes encountered by the j becomes greater than k, then include the size of the subarray and move on to next i

//. T.C -> O(n^2)
//. S.C -> O(1)
int bruteForce(vector<int>& nums, int k) {

        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            int zeroes = 0;
            int j = i;

            if (nums[j] == 0) zeroes++;

            while (j < n) {
       
                if (zeroes > k) break;

                j++;
                if (j < n && nums[j] == 0) zeroes++;
            }

            ans = max(ans, j-i);
        }

        return ans;
        
}


//* Method - II (Optimal Approach, Sliding Window)
// Make two pointer, i and j.
// Move j to right till zeroes becomes k+1, calculate the length of the subarray and include in the answer if greater, then move i till zeroes becomes less than or equal to k, and conotinue like this

//. T.C -> O(n)
//. S.C -> O(1)
int optimal(vector<int>& nums, int k) {

        int n = nums.size();

        int i = 0;
        int j = 0;

        int zeroes = 0;
        int ans = 0;

        // If the first element is zero
        if (nums[0] == 0) zeroes++;

        while(j < n) {
            while (j < n && zeroes <= k) {
                j++;
                if (j < n && nums[j] == 0) zeroes++;
            }

            ans = max(ans, j-i);

            while(i < n && zeroes > k) {
                if (nums[i] == 0) zeroes--;
                i++;
            }
          
        }

        return ans;
        
}

//* Method - III (Optimal and easy code, Sliding Window)

// Here the left pointer starts moving with right, when the zeroes > k, hence making a maximum window size which will only increase when zeroes < k, then left won't move with right and window will grow

//! Dry run one test case to understand what's happening

//. T.C -> O(n)
//. S.C -> O(1)
int longestOnes(vector<int>& arr, int k) {

        int n = arr.size();
        int left = 0;
        int zeroes = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            if (arr[right] == 0) zeroes++;

            if (zeroes > k) {
                if (arr[left] == 0) zeroes--;
                left++;
            }

            ans = max(ans, right-left+1);

        }

        return ans;
        
}