#include <bits/stdc++.h>
using namespace std;

//* Method - I (Recursive Approach)
// Make a recursive function with the index, original array, sum, k and ans (bool) as a paramters (all passed by refeerence.) Exclude and include each element and add to the sum. Since we are not storing the subsequence, we don't require any time for copying(push_back) the subsequence into the result array, hence all the operations inside the funciotn takes O(1) time

//! Note: T.C is only 2^n, as we are not stroing/copying the subsequence anywhere
//. T.C -> O(2^n) 
//. S.C -> O(n)
void check(int ind, vector<int>& arr, int& sum, int& k, bool& ans) {
        
        if (sum == k) {
            ans = true;
            return;
        }
        
        //! Note: sum > k, only works if numbers are non-negative, else remove the condition
        if (ind == arr.size() || ans || sum > k) {
            return;
        }
        
        // Exclude
        check(ind+1, arr, sum, k, ans);
        
        // Include
        sum += arr[ind];
        check(ind+1, arr, sum, k, ans);
        
        // Backtracking
        sum -= arr[ind];
}

bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        
        bool ans = false;
        int sum = 0;
        
        check(0, arr, sum, k, ans);
        
        return ans;
        
}

//* Method - II (DP, Tabulation)
//. T.C -> O(n*k)