#include <bits/stdc++.h>
using namespace std;

//! Problem: Find the maximum element in the array

//* Method - I (Least Optimised) - Naive/Brute
// Sort the element and return the last element of the new sorted array
//. T.C -> O(n*log n)
//. S.C -> O(1), ignoring the recursive stack space

//* Method - II (Most Optimised) 
// Traverse the entire array and return the largest element
//. T.C -> O(n) and S.C -> O(1)
int largestElement(vector<int>&arr, int n){
    int largest = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
}