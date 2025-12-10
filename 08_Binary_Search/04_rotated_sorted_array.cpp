#include <bits/stdc++.h>
using namespace std;

//? Problem 1: Rotated (in left maybe) sorted and unique array. Find the index of the target

//* Method - I (Brute Force)
// Linear Search
//. T.C -> O(n)

//* Method - II (Optimal Solution)
//! Binary Search, as some part of array is sorted, we can solve this in O(log(n))

// Dry run [4 5 6 7 0 1 2], tar = 0 and understand it on your own
//. T.C -> O(log(n))
//. S.C -> O(1)
int optimalSolutionRotatedSortedArray(vector<int>arr, int target) {

    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        
        int mid = (low + high)/2;

        if (arr[mid] == target) return mid;

        //! Left portion (low to mid) is properly sorted
        if (arr[low] <= arr[mid]) {

            if (arr[low] <= target && target <= arr[mid]) {

                high = mid-1; // target lies in this portion only

            }

            else {
                low = mid+1; // target lies in the other portion
            }

        }

        //! Right portion (mid to high) is properly sorted
        else {

            if (arr[mid] <= target && target <= arr[high]) {
                low = mid + 1; // target lies in this portion only
            }

            else {
                high = mid - 1; // target lies in the other portion
            }

        }
    }

    return -1;

}



