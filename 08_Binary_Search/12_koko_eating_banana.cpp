#include <bits/stdc++.h>
using namespace std;

// Go to Leetcode - 875

// Helper function to find the maximum element in the array for both brute and better solution
int maxInArray(vector<int>arr) {
    int maxi = INT_MIN;

    for (auto elem : arr) {
        maxi = max(maxi, elem);
    }

    return maxi;
}

// Helper function to return total hours required for a given eating speed for both brute and optimal Solution
int checkFn(vector<int>arr, int speed) {

    long long  totalHours = 0;

    for (int i = 0; i < arr.size(); i++) {
        totalHours += ceil((long long)(arr[i])*1.0/speed);
    }

    // as we want to return int, but totalHours might increase INT_MAX, since this can never be the answer according to constraints, it's ok to tamper it to reach INT_MAX, so that we can still return it
    if (totalHours > INT_MAX) totalHours = INT_MAX; 

    return totalHours;
}

//* Method - I (Brute Force)

//. T.C -> O(n*M), M is the maximum element
//. S.C -> O(1)

int bruteForce(vector<int>piles, int k) {

    // Koko can eat a minimum of 1 banana per hour and a maximum of M banana per hour, cuz even if it can eat > M banana in an hour, there is no pile with > M banana, so he can't eat > M banana in an hour even if he could as there are not so many banana in any pile

    int maxElement = maxInArray(piles);

    // i -> Number of banana in an hour
    for (int i = 1; i <= maxElement; i++) {

        int requiredHours = checkFn(piles, i); // total hours to consume all banana if eats at a speed of i banana/hour
        if (requiredHours == k) return i;

    }

    return -1;
    
}

//* Method - II (Optimal Solution)
//! Binary Search

//. T.C -> O(n * log(M))
//. S.C -> O(1)
int optimalSolution(vector<int>piles, int k) {

    int maxElement = maxInArray(piles);

    int low = 1, high = maxElement;

    while (low <= high) {
        int mid = low + (high - low)/2;

        int requiredHours = checkFn(piles, mid);

        if (requiredHours <= k) high = mid - 1; // if we take less time, then eat less to increase time. if take required time, then try eating even less to check if takes same time
        else low = mid + 1;
    }


    return low; //! if we look closely ans will always be low, if low takes over high. If finding difficult just use ans variable and store answer in the first condition

}

