#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Concept of include/exclude. Also, first sort the given array and also store the answer in a set

//. T.C -> O(2^t * k * log(k)), here k is the average length of the container array
void comb(vector<int>& arr, int index, int& sum, int target, vector<int>& container, set<vector<int>>& ans) {

        if (sum == target) {
            ans.insert(container);
            return;
        }

        if (index == arr.size() || sum > target) return;

        // Exclude (with next index)
        comb(arr, index+1, sum, target, container, ans);

        // Include (with next index)
        container.push_back(arr[index]);
        sum += arr[index];

        comb(arr, index+1, sum, target, container, ans);

        // For Backtracking
        sum -= arr[index];
        container.pop_back();

}

vector<vector<int>> brute(vector<int>& candidates, int target) {

    // Sorted to only get unique answers
        sort(candidates.begin(), candidates.end());

        set<vector<int>>ans;
        vector<int>container;
        int sum = 0;

        comb(candidates, 0, sum, target, container, ans);

        vector<vector<int>>fAns;

        for (auto elem : ans) {
            fAns.push_back(elem);
        }

        return fAns;  
        
}

//* Method - II (Optimal Solution)
// Here instead of pick and not pick i.e. include or exclude, we use subsequences

// Sort the array, then make a recursive function. During each recursion, make an iteration from that index till end. Skip the iteraation, if the i-1 >= index and the current element is equal to previous element, it means we won't take duplicates during a single function call. Therefore, if we took 2 as an element in this recursive function, we won't include another 2 this time. That will be taken care of in the next recursive function.

//. T.C -> O(2^t * k), 2^t combinations exist and k is the average length of those subsequence
//. S.C -> O(k*x), for storing the answer and excluding the recursive stack space
void comb(vector<int>& arr, int index, int& sum, int target, vector<int>& container, vector<vector<int>>& ans) {

        if (sum == target) {
            ans.push_back(container);
            return;
        }

        if (index == arr.size() || sum > target) return;

        // Iterate all the remaining indices
        for (int i = index; i < arr.size(); i++) {

            // Only take a element if, it was not taken already during this iteration
            if (i-1 >= index && arr[i] == arr[i-1]) continue;

            sum += arr[i];
            container.push_back(arr[i]);

            comb(arr, i+1, sum, target, container, ans);

            sum -= arr[i];
            container.pop_back();
        }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>>ans;
        vector<int>container;
        int sum = 0;

        comb(candidates, 0, sum, target, container, ans);

        return ans;  
        
}
