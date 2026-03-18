#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Use concept of include/exclude with bit masking (can also be done by recursion), to create all possible combinations. Sort all these final combination and make a single iteration to check if it is overlapping and update the ans size and find its minimum

//. T.C -> O(2^n * (n + nlog(n) + x)), 2^n possible combinations, n for creating the combination, nlog(n) to sort those combinations and x for final check if overlapping or not
//. S.C -> O(n), for storing the combination
int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        // Total number of intervals
        int n = intervals.size();

        // Store the max size of non-overlapping subset
        int maxValid = 0;

        // Try all subsets using bitmasking
        for (int mask = 0; mask < (1 << n); ++mask) {

            // Vector to hold selected subset
            vector<vector<int>> subset;

            // Construct subset from bitmask
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i))
                    subset.push_back(intervals[i]);
            }

            // Sort subset by start time
            sort(subset.begin(), subset.end());

            // Check if it's non-overlapping
            bool valid = true;
            for (int i = 1; i < subset.size(); ++i) {
                if (subset[i][0] < subset[i-1][1]) {
                    valid = false;
                    break;
                }
            }

            // If valid, update maxValid size
            if (valid)
                maxValid = max(maxValid, (int)subset.size());
        }

        // Answer = total - size of max valid subset
        return n - maxValid;
}

//* Method - II (Greedy Approach)
// Similar to 06_n_meetings_in_one_room, try to sort using the end times and then check how many are overlapping and count those

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals based on their end time (greedy strategy)
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        // Count of intervals to remove
        int count = 0;

        // Store end time of the last non-overlapping interval
        int prevEnd = intervals[0][1];

        // Iterate through intervals starting from the second
        for (int i = 1; i < intervals.size(); i++) {

            // If current interval starts before the last accepted interval ends
            if (intervals[i][0] < prevEnd) {
                // Overlapping interval, increase removal count
                count++;
            } else {
                // No overlap, update the end of last accepted interval
                prevEnd = intervals[i][1];
            }
        }

        // Return minimum intervals to remove
        return count;
    }