#include <bits/stdc++.h>
using namespace std;

//* Method - I (Better Solution)
//! Prefix and Suffix max
// Find the maximum element in the left and right of a particular index. If both are greater than the height of the current building, then the height of the rainwater would be (min(left, right) - arr[i]).

//! Note: This can be further optimised byh only using suffixMax, and insitead of using prefixMax, we can remfeber the max as we are traversing from the left, hence eliminating the need for prefixMax

//. T.C -> O(3n)
//. S.C -> O(2n), for storing left and right max of every index
int betterSolution(vector<int>& arr) {

        int n = arr.size();

        // Finding left and right max for every index
        vector<int>leftMax(n, -1); //! Prefix Sum
        vector<int>rightMax(n, -1); //! Suffix Max

        int maxi = -1;

        for (int i = 0; i < n; i++) {
            leftMax[i] = maxi;
            maxi = max(maxi, arr[i]);
        }

        maxi = -1;

        for (int i = n-1; i >= 0; i--) {
            rightMax[i] = maxi;
            maxi = max(maxi, arr[i]);
        } 

        // Calculating the final answer
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (leftMax[i] > arr[i] && rightMax[i] > arr[i]) {
                ans += (min(leftMax[i], rightMax[i]) - arr[i]);
            }
        }

        return ans;
        
}

//* Method - II (Optimal Solution)

// We can use two pointers one from left and one from right.
// If we find that leftMax (till now) is smaller or equal than rightMax (till now), then surely, we can consider that elevation to only depend on the leftMax and hence check if possible and update our answer and move left pointer. If we find rightMax is smaller than leftmax (till now), then we use the right elevetaion with rightMax as min. to find the ans.

// Concept: Total water at any index = min(leftMax, rightMax) - arr[i]

//. T.C -> O(n)
//. S.C -> O(1)

int trap(vector<int>& arr) {

    int n = arr.size();

    int leftMax = -1;
    int left = 0;

    int rightMax = -1;
    int right = n-1;

    int ans = 0;

    while (left <= right) {

        if (leftMax <= rightMax) {
            if(leftMax > arr[left] && rightMax > arr[left]) ans += (leftMax - arr[left]);

            leftMax = max(leftMax, arr[left]);
            left++;
        }
        else {
            if(leftMax > arr[right] && rightMax > arr[right]) ans += (rightMax - arr[right]);

            rightMax = max(rightMax, arr[right]);
            right--;
        }
    }

    return ans;
}