#include <bits/stdc++.h>
using namespace std;

//! Problem: Find the second largest element in the array (or can be asked for second smallest)

//* Method - I (Least Optimsed) - Brute Force
// Sort the array and go from back till, we get a different element than the last element, that will be the second largest element
//. T.C -> O(n*log(n) + n) (sorting and traversing)
int secondLargestBrute(int n, int arr[]) {

  // When the size is less than two
  if (n < 2) {
    return -1; // -1 means, doen't exist
  }

  sort(arr, arr + n);

  int sndLargest = -1;

  // We can't directly return arr[n-2], ecuase what if the largest element has some duplicates. Check for yourself.
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] != arr[n - 1]) {
      sndLargest = arr[i];
      break;
    }
  }

  return sndLargest;
}

//* Method - II - Better Solution
// Find the largest element in the first pass/traversal and then find another largest element now equals the largest element
//. T.C -> O(2n)
int secondLargestBetter(int n, int arr[]) {

  // First find the largest element

  int largestElem = arr[0];

  for (int i = 0; i < n; i++) {
    if (arr[i] > largestElem) {
      largestElem = arr[i];
    }
  }

  // Then, find the largest element, that is also not equal to largest element
  int secondLargestElem = INT_MIN;
  for (int i = 0; i < n; i++) {

    if (arr[i] > secondLargestElem && arr[i] != largestElem) {
      secondLargestElem = arr[i];
    }
  }

  return secondLargestElem;
}

//* Method - III - Optimal Solution
// Traverse the entire array once and store the largestElement like we prvisouly did, if we find any new largestElement (> largest), store the previous value of it inside the secondLargest. Also, if the new element is not greater than largestElement, but greater than secondLargest element, we store that value inside the secondLargest element.
//. T.C -> O(n)
int secondLargestOptimal(int n, int arr[]) {
  int largestElem = arr[0];
  int scdLargestElem = INT_MIN;

  //! Note: Don't do anything if equal to largestElem
  for (int i = 0; i < n; i++) {
    if (arr[i] > largestElem) {
      scdLargestElem = largestElem;
      largestElem = arr[i];
    } else if (arr[i] < largestElem && arr[i] > scdLargestElem) {
      scdLargestElem = arr[i];
    }
  }
}

//. HW: Do for second smallest (same logic as above)
