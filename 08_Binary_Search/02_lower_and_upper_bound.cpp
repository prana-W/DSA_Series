#include <bits/stdc++.h>
using namespace std;

//? Problem 1, Find the Lower Bound: Smallest index such that arr[ind] >= tar, tar is given. If not exists return the last hypothetical index of the array, or in other words the size of the array

//* Method - I (Linear Search)
//. T.C -> O(n)

//* Method - II (Binary Search if the array is sorted)
//. T.C -> O(log(n))

// Store whenever we get something >= tar, and then go to left portion and continue, else go to the right portion

int lowerBound(int n, int arr[], int tar) {
    int low = 0, high = n-1;

    int ans = n; // if answer doesn't exist

    while (low <= high) {
        int mid = (low + high)/2;

        if (arr[mid] >= tar) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    return ans;
}

//! We have a STL called, lower_bound(startIterator, endIterator), which returns the iterator of the lower_bound, for index subtract the starting iterator

//? Problem 2, Upper Bound - Smallest index such that arr[ind] > tar

//. T.C -> O(log(n))
int upperBound(int n, int arr[], int tar) {
    int low = 0, high = n-1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high)/2;

        if (arr[mid] > tar) {
            ans = mid;
            high = mid - 1;
        }

        else low = mid + 1;
    }

    return ans;
}

//! We also have a STL for upper_bound() which returns the iterator, which when subtracted from starting iterator, gives us the index

//? Problem: Search Insert Position, Return the index of the tar if available else return the index, where it should have been if not avaiable. 

// This is just a lower_bound problem, so just return the lower bound of the tar


//? Problem: Floor in an sorted array, largest number in the array <= tar

//* Direct Method

// This is just a upper_bound problem, just return the ((upper_bound() - arr.begin()) - 1), or the index before the upper_bound index, or return the element at that index if asked. Also check for edge cases.

//* Indirect

int floorFunc(int n, int arr[], int tar) {
    int lo = 0, hi = n - 1;
    int ans = -1; // assume doesn't exist

    while (lo <= hi) {
        int mid = (lo + hi)/2;

        if (arr[mid] <= tar) {
            ans = arr[mid];
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
}



//? Problem: Ceil in an sorted array, smallest number as >= tar

// This is just a lower_bound() problem, return the index of the lower_bound or the element at that index, also check for edge cases