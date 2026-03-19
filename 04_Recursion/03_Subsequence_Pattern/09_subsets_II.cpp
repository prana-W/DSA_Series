#include <bits/stdc++.h>
using namespace std;

//? Pg: 74
//! check solution
//* Method - I 
// Inlcude/Exclude concept

// Sort the input array and pass it to recursive funciton, also store the answer in a set to avoid duplicates and have a ascending order, at last put all the elements of set into the matrix

void solve(int index, vector<int>& arr, vector<int>& ds, set<vector<int>>& ans) {
        if (index == arr.size()) {
            ans.insert(ds);
            return;
        }

        // Exclude
        solve(index+1, arr, ds, ans);

        // Include
        ds.push_back(arr[index]);
        solve(index+1, arr, ds, ans);
        ds.pop_back();
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int>ds;
        set<vector<int>>ans;

        solve(0, nums, ds, ans);

        vector<vector<int>>fAns;

        for (auto elem : ans) {
            fAns.push_back(elem);
        }

        return fAns;
        
}

//* Method - II (Optimal Approach)
// Similar to Combination Sum II

// Sort and use the iteration way to include all the indices till the end, also include every variation in ans without any checks and return when index is at the end

void solve(int index, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
        
    //! All the variation are stored directly in ans
    ans.push_back(ds);

    if (index == arr.size()) {
        return;
    }

    for (int i = index; i < arr.size(); i++) {

        // Skip elements which are equal to previous
        if (i-1 >= index && arr[i] == arr[i-1]) continue;

        ds.push_back(arr[i]);
        solve(i+1, arr, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> optimal(vector<int>& nums) {

    sort(nums.begin(), nums.end());

    vector<int>ds;
    vector<vector<int>>ans;

    solve(0, nums, ds, ans);

    return ans;
        
}