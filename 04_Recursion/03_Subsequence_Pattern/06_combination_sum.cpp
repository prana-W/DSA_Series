#include <bits/stdc++.h>
using namespace std;

// We have two options. Pick a element and stay at the same index (as we can take it in next steps), or not pick a element and move on.

//. T.C -> O(2^t * k), k is the average length of the array
//. S.C -> O(k*x), k is the average length and x is the total combinations; total space for answer (we have not includede recurisve stack space)
void comb(vector<int>& arr, int index, int& sum, int target, vector<int>& container, vector<vector<int>>& ans) {

        if (sum == target) {
            ans.push_back(container);
            return;
        }
        if (index == arr.size() || sum > target) return;
        
        // Include (with same index)
        container.push_back(arr[index]);
        sum += arr[index];

        comb(arr, index, sum, target, container, ans);

        // For Backtracking
        sum -= arr[index];
        container.pop_back();

        // Exclude (with next index)
        comb(arr, index+1, sum, target, container, ans);

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>>ans;
        vector<int>container;
        int sum = 0;

        comb(candidates, 0, sum, target, container, ans);

        return ans;  
}