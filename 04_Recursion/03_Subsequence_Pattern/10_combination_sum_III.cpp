#include <bits/stdc++.h>
using namespace std;

// In other words, question is saying for a given arr = {1, 2, 3, 4, 5, 6, 7, 8, 9}, find all the subsequence whose sum is equal to n and the size of the subsequence is k

// Solve this using simple include/exclude method

//. T.C -> O(2^9 * k)
//. S.C -> O(k), for recursive stack space
void solve(int index, vector<int>& arr, int& sum, int& n, int& k, vector<int>& ds, vector<vector<int>>& ans) {

    if (ds.size() == k && sum == n) {
        ans.push_back(ds);
        return;
    }
    
    if ((index == arr.size()) || (ds.size() > k) || (sum > n)) return;

    // Exclude
    solve(index+1, arr, sum, n, k, ds, ans);

    // Include
    sum += arr[index];
    ds.push_back(arr[index]);

    solve(index+1, arr, sum, n, k, ds, ans);

    sum -= arr[index];
    ds.pop_back();
}
vector<vector<int>> combinationSum3(int k, int n) {

    vector<int>arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int>ds;
    vector<vector<int>>ans;
    int sum = 0;

    solve(0, arr, sum, n, k, ds, ans);
    
    return ans;
        
}