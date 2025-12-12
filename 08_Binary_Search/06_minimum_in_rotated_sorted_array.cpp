#include <bits/stdc++.h>
using namespace std;

// Problem: Find the minimumm element from a rotated (might be) sorted array with unique elements

//! HW Do for duplicates

//. T.C -> O(log(n))
//. S.C -> O(1)
int sirSolution(vector<int> arr) {
  int low = 0, high = arr.size();

  int ans = INT_MAX;

  while (low <= high) {
    int mid = (low + high) / 2;

    //! This block is used for further optimisation

    // If arr[low] <= arr[high], then the entire subarray is sorted, hence clearly the answer (if exists) would be simply the first element (element at low) of the subarray and hence we don't need to actually perform a binary search on the array
    if (arr[low] <= arr[high]) {
        ans = min(ans, arr[low]);
        break;
    }

    // Left portion is sorted
    if (arr[mid] >= arr[low]) {

      ans = min(arr[low], ans);
      low = mid + 1; // eliminate the left portion

    }

    // if left not sorted, then right will be definitely sorted
    else {

      ans = min(arr[mid], ans);
      high = mid - 1; // eliminate the right portion
    }
  }

  return ans;
}