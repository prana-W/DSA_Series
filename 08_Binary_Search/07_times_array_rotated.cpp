#include <bits/stdc++.h>
using namespace std;

// Problem: Array with unique elements, find out how many times it has been right rotated

// Simply find the index of the minimum element in the rotated sorted

//! HW: Do for duplicates, similarly as in search in rotated array ||

int findKRotation(vector<int> &arr) {

  int low = 0, high = arr.size() - 1;

  int mini = INT_MAX;
  int ans = 0;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[low] <= arr[mid]) {
      if (arr[low] < mini) {
        ans = low;
        mini = arr[low];
      }
      low = mid + 1;
    }

    else {

      if (arr[mid] < mini) {
        ans = mid;
        mini = arr[mid];
      }
      high = mid - 1;
    }
  }

  return ans;
}