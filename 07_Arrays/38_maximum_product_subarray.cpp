#include <bits/stdc++.h>
using namespace std;

// Problem: Return the maximum product from the subarray (contigous part of the array)

//* Method - I (Brute Force)
// Generate all the subarrays

//. T.C -> O(n^3)
//. S.C -> O(1)

//* Method - II (Better Solution)
// Iterate the array twice and keep track of the product while moving

//. T.C -> O(n^2)
//. S.C -> O(1)
void betterSolution(vector<int>arr) {
    int n = arr.size();

    long long maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        long long prod = 1;
        for (int j = i; j < n; j++) {
            prod *= (long long int)(arr[j]);

            maxi = max(prod, maxi);
        }

    }

    cout << maxi << endl;
}

//* Method - III (Optimal Solution)
//! Tell this as the final optimal solution. There also exists an optimal solution by modifying the Kadane's Algorithm, but that is not very intuitive and hard to explain, hence avoid that solution

// Check the prefix and suffix of all the element and store the maxium value. Also, whenever encounter a zero, simply turn back the prefix and suffix from 0 back to 1 and continue

//. T.C -> O(n)
//. S.C -> O(1)
int optimalSolution(vector<int>& nums) {

        long long pref = 1, suff = 1;

        long long ans = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {

            pref = pref * (long long)(nums[i]);
            suff = suff * (long long)(nums[n - i -1]);

            ans = max(ans, pref);
            ans = max(ans, suff);

            if (pref == 0) pref = 1;
            if (suff == 0) suff = 1;
        }

        return ans;
        
    }