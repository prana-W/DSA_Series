#include <bits/stdc++.h>
using namespace std;

//! Minimum distance is maximum

// Logic: First sort the stalls array and then assign the stall to the cows in this way. This simplifies our calculation for adjacent stalls for minimum distance. For a given distance x, check if we are able to put to k cows in it for minimum x distance between each cows, if yes, then it could be our answer. If not able to put the k cows inside the stalls for any x, then that won't be possible.
// Extreme minimum distances can be 1 to (max-min)

// A function that checks if it is possible to place 'totalCows' for a min distance between any two cows as 'distance'
bool canWePlace(vector<int> stalls, int distance, int totalCows) {
  int cowCount = 1;
  int lastCoordinate = stalls[0]; // last position of the cow placed

  for (int i = 1; i < stalls.size(); i++) {
    if ((stalls[i] - lastCoordinate) >= distance) {
      cowCount++;                 // place the cow at this position
      lastCoordinate = stalls[i]; // update the lastCoordinate as the cow was placed here
    }
  }

  // if we can place more cows than required, than the 'distance' is possible
  if (cowCount >= totalCows)
    return true;
  return false;
}

//* Method - I (Brute Force)
//. T.C -> O(n * (max-min))
//. S.C -> O(1)
int brute(vector<int> stalls, int k) {

  sort(stalls.begin(), stalls.end()); // sorting the array

  for (int i = 1; i < (stalls.back() - stalls.front()); i++) {
    if (canWePlace(stalls, i, k))
      continue;
    else
      return (i - 1); // it was possible for the last distance
  }

  return -1;
}

//.* Method - II (Optimal Solution)
//! Binary Search

//. T.C -> O(n*log(n)) + O(n *  log(max - min)), first for sorting and the other for binary search
//. S.C -> O(1), ignoring the Space complexity due to sorting. 

//! sort() uses several algorithms internally, which can vary the space complexity. Generally O(log n) for recursive stack space
int optimalApproach(vector<int> stalls, int k) {

  // Sorted the stalls, so we just have to check adjacent distances for the minimum distance
  sort(stalls.begin(), stalls.end());

   //! low can be further optimised
   // we can take 'low' as the minimum distance between the adjacenet stalls[i] in the stalls array after sorting
  int low = 1;
  int high = stalls.back() - stalls.front();

  int ans = -1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (canWePlace(stalls, mid, k)) {

      low = mid + 1;
      ans = mid;

    }

    else {
      high = mid - 1;
    }
  }

  return ans; //! or return high; as 'high' will have our answer
}   