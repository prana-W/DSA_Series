#include <bits/stdc++.h>
using namespace std;

//* Method - I (Recursive Approach)
// Generate the subsequences ust like in previous problem, with an additional parameter of sum 'k', at the base case only include it ans if it satisfies the condition. 

//! If all elements are non-negative then,
// We can further optimize it by pruning, by returning instanly without inclusion, if at any step the sum reaches greater than k, then return instantly without going further

//. T.C -> O(2^n * n)
//. S.C -> O(n) extra space, due to recursive stack space

void findSubsequence(int ind, int sum, int k, vector<int> &cur, 
                vector<int> &arr, vector<vector<int>> &res) {
    int n = arr.size();
    
    // base case
    if(ind == n) {

        // check if sum of elements of current
        // subset is equal to k
        if(sum == k) {

            // add the subset in result
            res.push_back(cur);
        }
        return;
    }

    // skip the current element arr[ind]
    findSubsequence(ind + 1, sum, k, cur, arr, res);

    // add the current element in subset
    cur.push_back(arr[ind]);
    findSubsequence(ind + 1, sum + arr[ind], k, cur, arr, res);

    // remove the added element
    cur.pop_back();
}

// Function to find the subsequences
// with sum of its elements k
vector<vector<int>> subsequencesSumK(vector<int> &arr, int k) {

    // to store the subsequences
    // with sum of its elements k
    vector<vector<int>> res;

    // to store the current subset
    vector<int> cur;

    findSubsequence(0, 0, k, cur, arr, res);

    return res;
}