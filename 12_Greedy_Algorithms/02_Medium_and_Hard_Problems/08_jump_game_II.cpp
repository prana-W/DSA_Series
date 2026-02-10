#include <bits/stdc++.h>
using namespace std;

// If we are at index - 0, we can go to maximum till index 2, so at the index 2, we check the currMaxi (which is 5 and then onlhy update the lastInd) and increment the ans, it means, we take the jump.

// We have a section, inside whjich we can land anywhere, now we want to get the 

// We are doing this to check the maximum index we can reach in a given section and only jump to the farthest distance that can be jumped from that section. Hence only update ans at the end moment, when we know the farthest distance that can be travelled for that section

// [2, 2, 3, 5, 6, 7]


//. T.C -> O(n)
//. S.C -> O(1)
int jump(vector<int>& nums) {

    // Edge case
    if (nums.size() == 1) return 0;

    int maxi = 0; // maximum index we can reach at any given point
    int ans = 0; // minimum steps taken
    int lastInd = 0; // this is the oldest maxi length

    for (int i = 0; i < nums.size(); i++) {

        maxi = max(maxi, (nums[i] + i));

        // If we reach the end of the initial maximum section, at that point we update lastInd to latest maxi value and take the step, this is to ensure we take the least amount of step as possible
        if (i == lastInd) {
            ans++;
            lastInd = maxi;
        }

        if (lastInd >= nums.size()-1) return ans;
    }

    return ans;

}