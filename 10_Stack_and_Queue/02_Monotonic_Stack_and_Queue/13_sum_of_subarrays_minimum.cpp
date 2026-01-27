#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
//! Recursive method

// Find the minimum element in a array, then try to find the number of total subarrays in that array that will contain the minimum element, (since it is minimum, we just have to do (no. of subarrays with that element)*element) to find the contribution in sum due to that element, then use recursuve funnction to find the totalSum in the right half and left half and finally returnn the total sum

// Array is actual from left to right index

//. T.C -> O(n^2), in worst case. If array is increasing sorted
//. S.C -> O(n), recursive stack space in worst case
int totalSum(vector<int>& arr, int left, int right) {

        if (right < left) return 0;

        int n = (right - left + 1); // Size of the new array
        long long int lim = 1e9 + 7;
        
        // Finding the index of the minimum element
        int minIndex = left;
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex]) minIndex = i;
        }

        // (right-minIndex+1)*(minIndex-left+1)  is the number of subarrys that contains arr[minIndex]
        long long int sum = ((right-minIndex+1)%lim*(minIndex-left+1)%lim * arr[minIndex]%lim)%lim;

        // Find totalSum in left Half
        sum += totalSum(arr, minIndex+1, right);

        // Find totalSum in right half
        sum += totalSum(arr, left, minIndex-1);

        return (sum%lim);

    }

int bruteRecursiveForce(vector<int>& arr) {
        return totalSum(arr, 0, arr.size()-1); 
}

//* Method - I.V (Brute Force)
// Find all the possible subarry and find the minimum in that and add to the answer

//. T.C -> O(n^2)
//. S.C -> O(1)
int bruteForce(vector<int>& arr) {

        int n = arr.size();

        long long int ans = 0;

        long long int lim = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            int mini = INT_MAX;
            for (int j = i; j < n; j++) {

                mini = min(mini, arr[j]);

                ans = ((ans%lim) + (mini%lim))%lim;

            }
        }

        int fAns = ans%lim;

        return fAns;
        
}

//* Method - II (Optimal Solution)

// Think of it as the contrivutions made by each element. So then we just need to find the sum of the product of contribution and the element.

// For each element, try to find its next smaller element and previous smaller or equal element using a monotonic stack. Then we can predict the total number of elements to its right and left combineing which in different combinations which can result in the element itself being the minimum. This is similar concept as used in the first approach. Find all the subarrays in which the minimum is a particular element and then use that contribution. 
// We end up looking the entire array after the PSEE and before the NSE, for this portion, our element would be the minimum. 

//! See notes

//. T.C -> O(3n)
//. S.C -> O(4n)
int optimalApproach(vector<int>& arr) {

        int n = arr.size();
        long long int lim = 1e9 + 7;
        long long int ans = 0;

        stack<pair<int, int>>st, st2;
        vector<int>nse(n); // To find the index of NSE
        vector<int>psee(n); // To find the index of PSEE

        for (int i = 0; i < n; i++) {

            while(!st.empty() && st.top().second > arr[i]) {
                st.pop();
            }

            if (!st.empty() && st.top().second <= arr[i]) {
                psee[i] = st.top().first;
            }
            else psee[i] = -1; // Assume PSEE exists at hypothetical -1 index (to  take the entire left portion)

            st.push({i, arr[i]});

        }
        
        for (int i = n-1; i >= 0; i--) {

            while(!st2.empty() && st2.top().second >= arr[i]) {
                st2.pop();
            }

            if (!st2.empty() && st2.top().second < arr[i]) {
                nse[i] = st2.top().first; 
            }
            else nse[i] = n; // Assume NSE exists at hypothetical n index, (to take the entire right portion)

            st2.push({i, arr[i]});
        }

        for (int i = 0; i < n; i++) {
            long long  int leftPortion = (i - psee[i]);
            long long int rightPortion = (nse[i] - i);

            // Total number of subarrays that can be formed which has the arr[i] as minimum
            int totalSubarraysWithElementAsMinimum = (leftPortion%lim * rightPortion%lim)%lim;

            ans += totalSubarraysWithElementAsMinimum%lim * arr[i]%lim;
        }

        return ans%lim;
}