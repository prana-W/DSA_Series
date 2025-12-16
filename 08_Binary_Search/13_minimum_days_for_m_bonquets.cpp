#include <bits/stdc++.h>
using namespace std;

// Helper function that returns the minimum and maximum from the array
pair<int, int> minAndMaxInArray(vector<int>arr) {

    int mini = INT_MIN;
    int maxi = INT_MIN;

    for (auto elem : arr) {
        mini = min(mini, elem);
        maxi = max(maxi, elem);
    }

    return {mini, maxi};
}

// Takes mid -> total number of days passed, k -> adjacent flowers from bloom required and returns the total number of bonquets that can be made from the inputs
int checkFn(vector<int>arr, int mid, int k) {
        int ans = 0;
        int cnt = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= mid) cnt++;
            else cnt = 0;

            if (cnt == k) {
                ans++;
                cnt = 0;
            }
        }

        return ans;
    }

// Problem: See Leetcode

//* Method - I (Brute Force)

//. T.C -> O((M-m+1)*(n)), M: Maximum element, m: minimum element, n: Total elements
//. S.C -> O(1)
int bruteForce(vector<int>bloomDay, int m, int k) {

    // when total days required is more than available
    long long maximumDaysRequired = (long long)(m) * (long long)(k);
    if (bloomDay.size() < maximumDaysRequired) return -1;    

    pair<int, int> result = minAndMaxInArray(bloomDay);

    int minimumElement = result.first;
    int maximumElement = result.second;

    for (int i = minimumElement; i < maximumElement; i++) {
        if (checkFn(bloomDay, i, k) >= m) return i;
    }

    return -1;

}

//* Method - II (Optimal Solution)

//. T.C -> O(log(M-m+1) * n)
//. S.C -> O(1)
int minDays(vector<int>& bloomDay, int m, int k) {

    // when total days required is more than available
    long long maximumDaysRequired = (long long)(m) * (long long)(k);
    if (bloomDay.size() < maximumDaysRequired) return -1;    

    pair<int, int> result = minAndMaxInArray(bloomDay);

        int minimumElement = result.first;
        int maximumElement = result.second;

        int low = minimumElement, high = maximumElement;

        while(low <= high) {
            int mid = low + (high - mid)/2;

            int tB = checkFn(bloomDay, mid, k);

            if (tB >= m) high = mid - 1;
            else low = mid + 1;
        }

        return low;

    }