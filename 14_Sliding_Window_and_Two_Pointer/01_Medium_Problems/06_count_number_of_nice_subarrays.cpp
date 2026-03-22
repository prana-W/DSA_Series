#include <bits/stdc++.h>
using namespace std;

//! Note: We can do analogy in this problem by thinking of all the evens as 0 and all the odds as 1, then this question becomes exactly same as previous problem 05_binary_subarrays

//* Method - I (Brute Force)
// Check all subarrays

//. T.C -> O(n^2)
//. S.C -> O(1)
int brute(vector<int>& nums, int k) {

    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int odds = 0;
        for (int j = i; j < n; j++) {
            if(nums[j]%2 == 1) odds++;

            if (odds == k) ans++;
            if (odds > k) break;
        }

    }

    return ans;
    
}

//* Method - II (Better Solution)
// Similar to previous problem's better solution

//. T.C -> O(n*log(n))
//. S.C -> O(n)
int better(vector<int>& nums, int k) {

    int n = nums.size();
    int ans = 0;

    map<int, int>mp;
    if (nums[0]%2==0) mp[0] = 0;
    int odds = 0;

    for (int i = 0; i < n; i++) {

        if (nums[i]%2) {
            odds++;
        }

        if (odds == k) ans++;
        if (mp.find(odds-k) != mp.end()) {
            ans += mp[odds-k];
        }

        mp[odds]++;

    }

    return ans;
}

//* Method - III (Optimal Solution)
// Similar to previous problem's optimal solution

int atMostK(vector<int>& nums, int k) {

    int left = 0, odds = 0, ans = 0, n = nums.size();

    for (int right = 0; right < n; right++) {

        if (nums[right]%2) odds++;

        while(odds > k) {
            if (nums[left]%2) odds--;
            left++;
        }

        ans += (right - left + 1);
    }

    return ans;

}
int optimal(vector<int>& nums, int k) {

    int n = nums.size();
    int ans = 0;

    ans = (atMostK(nums, k) - atMostK(nums, k-1));

    return ans;
}