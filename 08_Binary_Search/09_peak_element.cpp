#include <bits/stdc++.h>
using namespace std;

// Problem: Find the peak element from an array. Consider the element before and after the first and last element respectively to be -INFINITY. If multiple answers return any one

//* Method - I (Brute/Navive)
//! Linear Search
//. T.C -> O(n)
//. O(1)

//* Method - II (Optimal Solution)
//! Binary Search

// We can think of the array with several peaks and downs, hence it can be thought be containing several sorted portions in it.

//. T.C -> O(log(n))
int optimalSolution(vector<int>arr) {

    int n = arr.size();

    // Short-circuit Evalutation

    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n-1] > arr[n-2]) return (n-1);

    // Using Binary serach from 1 - n-2

    int low = 1, high = n-2;

    while (low <= high) {
        int mid = (low+high)/2;

        if (arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) return mid;
        else if (arr[mid-1] < arr[mid]) low = mid+1;
        else high = mid-1;
    }

    return -1;

}


