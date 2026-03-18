#include <bits/stdc++.h>
using namespace std;

// First insert the newInterval according to ascedning order logic, then simply use the logic of 07_Arrays_33_merge_overlapping_subintervals for merging overllaping intervals

//. T.C -> O(n)
//. S.C -> O(n)
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        // Inserting newInterval according to ascending order

        if (intervals.size() == 0) {
            return {newInterval};
        }
        
        int n = intervals.size();
        int s = newInterval[0];
        int e = newInterval[1];

        vector<vector<int>>temp;
        if (s < intervals[0][0]) temp.push_back(newInterval);

        for (int i = 0; i < n; i++) {
            temp.push_back(intervals[i]); 
            if ((i+1 < n && s >= intervals[i][0] && s < intervals[i+1][0]) || (i == n-1 && s >= intervals[i][0])){ 
                temp.push_back(newInterval);
            }
        }

        // Same Logic below as 07_Arrays_33_merge_overlapping_subintervals

        vector<vector<int>>ans;

        ans.push_back(temp[0]);

        for (int i = 1; i < temp.size(); i++) {
            if (temp[i][0] >= ans.back()[0] && temp[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], temp[i][1]);
            }
            
            else ans.push_back(temp[i]);
        }

        return ans;
        
}