#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of n subintervals. Merge all the overlaaping subintervals into one and find out how many minimum number of intervals can we get

//* Method - I
// Sort the given array of intervals. At each step, check if the given interval can be merged with the previous interval, for checking see, if the first element of the current interval lies in between the previoius interval, if it does, it will overlap, now see the second element of the interval, to check if the netinterval (overlapped interval) needs to be expanded or remain intact. If it doesn't lie, it means intervals don't overlap and then create a new interval in the answer

//. T.C -> O(nlog(n) + 2n), first is for sorting and the 2*n is because if we see carefully, we are touching each element twice
//. S.C -> O(n)
vector<vector<int>>mergeIntervalsSolutionOne(vector<vector<int>>arr){

    int n = arr.size();
    vector<vector<int>>ans;

    sort (arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        
        int start = arr[i][0];
        int end = arr[i][1];

        // If the first element of any interval is already smaller than the second element of previous interval, no need to check this, as it already would have been considered

        //! We could optimise by a single iteration as if one interval is taken/merged by the other interval, it won't be considered again later
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        // For a given interval, keep on checking all the intervals in its right that can be merged
        for (int j = i+1; j < n; j++) {

            // it means it can be merged
            if (arr[j][0] <= end) {

                // start would be same as the other interval is merged, but the ends depend on whether the second interval ends longer or smaller than the previous interval
                end = max (end, arr[j][1]);
                
            }

            // We break outside, as if it can't be merged, the other intnervals can't be merged either due to array being sorted
            else break;

            ans.push_back({start, end});

        }
    } 

    return ans;

}

//* Method - II (Optimised Solution)

//. T.C -> O(n*log(n) + n)
//. S.C -> O(n)
vector<vector<int>>optimalSolution(vector<vector<int>>arr){

    int n = arr.size();
    vector<vector<int>>ans;

    sort (arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {

        // Consider a new answer/interval if the ans is empty, or if the first element of the current interval is greater than the second element of the previous interval
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            // create a new interval

            ans.push_back({arr[i][0], arr[i][1]}); // or ans.push_back(arr[i]);
        }

        // If it is lying inside, it is mergable
        else {

            // update the second element of the interval (answer) 
            ans.back()[1] = max(ans.back()[1], arr[i][1]);


        }

    }

    return ans;



}

