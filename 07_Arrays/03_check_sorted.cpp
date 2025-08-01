#include <bits/stdc++.h>
using namespace std;

//! Problem: Check if the given array is sorted in a non-descending order

// Iterate the entire array and if any element is less than the previous array, then the array is obviously not sorted in a non-descending order
//. T.C -> O(n)
bool checkSorted(int n, int arr[]) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) {
            return false;
        } 
    }

    return true;    
}

