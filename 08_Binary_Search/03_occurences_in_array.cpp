#include <bits/stdc++.h>
using namespace std;

//? Problem 1: Find the first and the last occurence of an element tar in a sorted array, or else return {-1, -1}, if doesn't exist

//* Method - I (Brute Force - Linear Search)

//. T.C -> O(n)
//. S.C -> O(1)
pair<int, int>bruteForce(int n, int arr[], int tar) {

    int first = -1, last = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == tar && first == -1) first = i;
        if (arr[i] == tar) last = i;
    }

    return {first, last};

}

//* Method - II (Using Binary Search)

//. T.C -> O(2 * log(n))
//. S.C -> O(1)
pair<int, int>firstLastOcc(int n, int arr[], int tar) {
    
    int lb = lower_bound(arr, arr+n, tar) - arr;
    int ub = (upper_bound(arr, arr+n, tar) - arr) - 1;

    if (lb == n || arr[lb] != tar) return {-1, -1};

    return {lb, ub};
}

//* Method - II.5 (Using Vanilla Binary Search, without any STLs)

//. T.C -> O(2*log(n))
//. S.C -> O(1)
pair<int, int>firstLastOccVanilla(int n, int arr[], int tar) {

    int low = 0, hi = n-1;
    int first = -1, last = -1;


    // Finding first index

    while (low <= hi) {
        int mid = (low + hi)/2;

        if (arr[mid] == tar) {
            first = mid;
            hi = mid - 1;
        }

        else if (arr[mid] < tar) {
            low = mid + 1;
        }

        else {
            hi = mid - 1;
        }
    }

    if (first == -1) return {-1, -1}; // If first occurence is -1, then the element doesn't exist

    // Finding Last occurence

    low = 0, hi = n-1;
    
    while (low <= hi) {
        int mid = (low + hi)/2;

        if (arr[mid] == tar) {
            last = mid;
            low = mid + 1;
        }

        else if (arr[mid] < tar) {
            low = mid + 1;
        }

        else {
            hi = mid - 1;
        }
    }

    return {first, last};

}   

//? Problem 3: Find the total number of occurences of tar element in the array

// Simply find the first and the last occurence and do (lastOcc - firstOcc + 1), if the element exists i.e. if firstOcc != -1, else return 0