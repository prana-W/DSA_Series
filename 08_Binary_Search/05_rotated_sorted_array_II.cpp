#include <bits/stdc++.h>
using namespace std;

//? Problem 2: Rotated (in left maybe) sorted and might be distinct elements in the array. Find wheather or not the element exists

//! Tip: In this type of question containing duplicates, try writing code for unique elements and then modify the code to check where the testcases are/might fail

// Previous solution won't work here.
// Example: [1 0 1 1 1], target = 0
// If arr[low] = arr[mid] = arr[high], we won't be able to trim predict which portion is actually sorted. Therefore, if we encounter such case we check if arr[mid] == target, if not, then arr[low] == arr[mid] == arr[high] != target and hence we can do low++ and high-- and then proceed again!!!

// This way, we can keep on moving until such case doesn't arise and then the Algorithm would be same

//. T.C -> O(log(n)) - average; O(n/2) in worst case where we shrink almost half of the elements
//. S.C -> O(1)
bool rotatedSortedTwo(vector<int> arr, int target) {
  int low = 0, high = arr.size() - 1;

    while (low <= high) {
        
        int mid = (low + high)/2;

        if (arr[mid] == target) return true;

        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;

            continue;
        }

        if (arr[low] <= arr[mid]) {

            if (arr[low] <= target && target <= arr[mid]) {

                high = mid-1; // target lies in this portion only

            }

            else {
                low = mid+1; // target lies in the other portion
            }

        }

        else {

            if (arr[mid] <= target && target <= arr[high]) {
                low = mid + 1; // target lies in this portion only
            }

            else {
                high = mid - 1; // target lies in the other portion
            }

        }
    }

    return false;
}