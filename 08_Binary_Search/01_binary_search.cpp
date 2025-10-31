#include <bits/stdc++.h>
using namespace std;

//* Iterative Binary Search

//. T.C -> O(log (n))
int func(int arr[], int n, int target) {

    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high)/2; 

        // int mid = low + (high - low)/2; -> To bypass the overflow case if exists

        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    return -1;
}

//* Recursive Binary Search

// Since there is a repetation in each step, we can reuse the code and that's when recursion comes into the picture

int recFunc(int arr[], int target, int low, int high) {

    // Base Case

    if (low > high) return -1; // when exhausts and still answer not found

    int mid = (low + high)/2;

    if (arr[mid] == target) return mid;
    else if (arr[mid] > target) return recFunc(arr, target, mid + 1, high); // trim the search space
    else return recFunc(arr, target, low, mid - 1); // trim the search space
    
}
