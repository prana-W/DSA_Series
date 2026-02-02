#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)

// Go through each sliding window each time and find the maximum

//. T.C -> O(n*k)
//. S.C -> O(k), for storing the answer

//* Method - II (Optimal Approach)
//! Deque Method

// Iterate the array, pop all the elements till the incoming is greaer or equal to the top (that is back). Since any smaller element is insignificant for us later anyway.

// If the front() is the outgoing element, pop the front.

// Note: The elements always occur in the deque in the order they appear in array

// Store the front() in the answer each time, as that it is the answer

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    int n = nums.size();

    vector<int>ans;
    deque<int>dq;

    // For the first window
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && nums[i] > dq.back()) {
            dq.pop_back();
        }

        if (dq.empty() || dq.back() >= nums[i]) {
            dq.push_back(nums[i]);
        }
    }

    ans.push_back(dq.front());

    int i = 0; // Outgoing Element
    int j = k; // Incoming Element

    while (j < n) {

        // Popping Outgoing element if it is the front
        if (!dq.empty() && dq.front() == nums[i]) {
            dq.pop_front();
        }

        // Pop all the smaller elements fromt the back, as they will be insignificant later anyway
        while (!dq.empty() && nums[j] > dq.back()) {
            dq.pop_back();
        }

        // Store the answer
        if (dq.empty() || dq.back() >= nums[j]) {
            dq.push_back(nums[j]);
        }

        ans.push_back(dq.front());

        i++;
        j++;
    }

    return ans;        
}