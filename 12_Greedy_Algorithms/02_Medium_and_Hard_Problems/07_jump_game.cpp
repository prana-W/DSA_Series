#include <bits/stdc++.h>
using namespace std;

// Track a maxi value. This is the maximum index that one can track at current stage. Iterate in the nums array. If maxi is smaller than the current index, it means, there is no chance to outpass even the current index, that it surely isn't possible to reach the end, so return false

// Also during each iteration, update maxi if we can travel even further

// Also check is maxi is greater than the end index, if it is at any point, we can surely reacch the end and return true

//. T.C -> O(n)
//. S.C -> O(1)
bool canJump(vector<int>& nums) {

    int maxi = 0;

    for (int i = 0; i < nums.size(); i++) {

        if (maxi < i) return false;

        maxi = max(maxi, (nums[i] + i));

        if (maxi >= nums.size()-1) return true;
    }

    return false;

}