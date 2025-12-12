#include <bits/stdc++.h>
using namespace std;

// Problem: Sorted array with all the elements appearing twice, except one element, find that one element which appears once

//* Method - I (Naive Approach)
//! Linear Search

//. T.C -> O(n)
int bruteForce(vector<int>arr) {
    int n = arr.size();

    if (n == 1) return arr[0];

    for (int i = 0; i < n; i++) {

        // We are at the first element
        if (i == 0) {

            if (arr[i] != arr[i+1]) return arr[i];

        }
        // We are at the last element
        else if (i == n-1) {
            if (arr[i] != arr[i-1]) return arr[i];
        }

        // We are in the middle
        else {
            if (arr[i] != arr[i-1] && arr[i] != arr[i+1]) return arr[i];
        }
    }

    return -1;
}

//! Really? Who uses LINEAR SEAFRCH on a sorted array!!!! 

//. T.C -> O(log(n))
int binarySeachForSingleElement(vector<int>arr) {

    int n = arr.size();

    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n-1] != arr[n-2]) return arr[n-1];

    int low = 1, high = n-2; // this is to avoid multiple checks if by-chance mid occurs at the beginning or the end

    while (low <= high) {
        int mid = (low + high)/2;

        if (arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]) return arr[mid];

        // We are on the LEFT HALF
        if ((mid%2 == 1 && arr[mid-1] == arr[mid]) || (mid%2 == 0 && arr[mid+1] == arr[mid])) {

            low = mid+1;

        }

        // We are on the RIGHT HALF
        else {

            high = mid-1;

        }
    }

    return -1;
}