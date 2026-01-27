#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Get all the subarrays and find the maxi-mini in that and add to the ans

//. T.C -> O(n^2)
//. S.C -> O(1)
long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        long long int ans = 0;

        for (int i = 0; i < n; i++) {
            int mini = INT_MAX;
            int maxi = INT_MIN;
            for (int j = i; j < n; j++) {

                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);

                ans += (maxi - mini);

            }
        }

        return ans;
}

//* Method - II (Optimal Approach)

// Use the similar concept of sum_of_subarrays_minimum.

// Using the concept of NGE, PGEE, NSE, PSEE, we find the frequency of all the subarrays in which the particular element was minimum and maximum

//. T.C -> O(5n), O(4n) for the four helper function and O(n) for main loop
//. S.C -> O(8n), O(2n) in each helper function, one for stack and one for array

vector<int>nextSmaller(vector<int>& nums) {

        int n = nums.size();

        stack<pair<int, int>>st;
        vector<int>nse(n);

        for (int i = n-1; i >= 0; i--) {

            while(!st.empty() && st.top().second >= nums[i]) {
                st.pop();
            }

            if (!st.empty() && st.top().second < nums[i]) {
                nse[i] = st.top().first;
            }
            else nse[i] = n;

            st.push({i, nums[i]});
        }

        return nse;

    }

vector<int>previousSmallerAndEqual(vector<int>& nums) { 

        int n = nums.size();

        stack<pair<int, int>>st;
        vector<int>psee(n);

        for (int i = 0; i < n; i++) {
            while(!st.empty() && st.top().second > nums[i]) {
                st.pop();
            }

            if (!st.empty() && st.top().second <= nums[i]) {
                psee[i] = st.top().first;
            }
            else psee[i] = -1;

            st.push({i, nums[i]});
        }

        return psee;

    }

vector<int>nextGreater(vector<int>& nums) {

        int n = nums.size();

        stack<pair<int, int>>st;
        vector<int>nge(n);

        for (int i = n-1; i >= 0; i--) {

            while(!st.empty() && st.top().second <= nums[i]) {
                st.pop();
            }

            if (!st.empty() && st.top().second > nums[i]) {
                nge[i] = st.top().first;
            }
            else nge[i] = n;

            st.push({i, nums[i]});
        }

        return nge;

    }

vector<int>previousGreaterAndEqual(vector<int>& nums) { 

        int n = nums.size();

        stack<pair<int, int>>st;
        vector<int>pgee(n);

        for (int i = 0; i < n; i++) {
            while(!st.empty() && st.top().second < nums[i]) {
                st.pop();
            }

            if (!st.empty() && st.top().second >= nums[i]) {
                pgee[i] = st.top().first;
            }
            else pgee[i] = -1;

            st.push({i, nums[i]});
        }

        return pgee;

    }

long long optimalApproach(vector<int>& nums) {

        int n = nums.size();
        long long int ans = 0;

        vector<int>nse = nextSmaller(nums);
        vector<int>psee = previousSmallerAndEqual(nums);

        vector<int>nge = nextGreater(nums);
        vector<int>pgee = previousGreaterAndEqual(nums);

        for (int i = 0; i < n; i++) {

            // Addition

            long long int left = (i - pgee[i]);
            long long int right = (nge[i] - i);

            //! (left*right => Number of times nums[i] was maximum)

            ans += (left*right*nums[i]);

            // Subtraction

            left = (i - psee[i]);
            right = (nse[i] - i);

            //! (left*right => Number of times nums[i] was minimum)

            ans -= (left*right*nums[i]);

        }  

        return ans;
        
}