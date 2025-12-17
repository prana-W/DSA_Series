#include <bits/stdc++.h>
using namespace std;

//* Method - II (Better Force)

//. T.C -> O(n)
//. S.C -> O(1)
int bruteForceSolution(vector<int> arr, int k) {
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] <= k)
      k++;
    else
      break;
  }

  return k;
}

//* Method - III (Optimal Solution and My code)
//! Binary Search

//! Observation: To find the missing number till any index just do:
// arr[i] - (i+1), this gives us the number of missing numbers in the left side of the index

// Since arr[i] is present at index i, and there should have been (i+1) ideally at the index i, so by getting a difference, we can predict, how many nummbers are missing in the left of index i

//. T.C -> O(log(n))
int optimalSolution(vector<int> arr, int k) {

  int n = arr.size();

  int low = 0, high = n - 1;
  int ansInd = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    int missLeft = arr[mid] - (mid + 1);

    // If less is missing, go right
    if (missLeft < k)
      low = mid + 1;

      // if more is missing, go left. If equal is missing, still go left, because, we want to go to the extreme point. Example: 1, 4, 5, 6, 7; all 4,5,6,7 has 2 elements missing but we will try to move to 4, so that we can simply return 3 by doing arr[i] - 1
    else {
      high = mid - 1;
      ansInd = mid;
    }
  }

  int missing = arr[ansInd] - (ansInd + 1);

  
  if (missing >= k) {
    return arr[ansInd] - (missing - k) - 1;
  }

  else {
    return arr[ansInd] + (k - missing);
  }

  return -1;
}

//* Method - III.V (Optimal and small code, Sir's Method)

// Basically, our answer is going to lie between the two indices (if lies between our array), so our high at the end is going to point to the lower index of those pair of index, if we get the lower index, we can simply find the required answer
int optimalSolutionButEasyCode(vector<int> arr, int k) {

  int n = arr.size();

  int low = 0, high = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    int missLeft = arr[mid] - (mid + 1);

    // If less is missing, go right
    if (missLeft < k)
      low = mid + 1;

    else {
      high = mid - 1;
    }
  }

  return k + high - 1;

  // becuase we find the more elements in the right of final high, that is the correct way.

  // so, more = k-missing = k - (arr[high] - (high+1))
// ans = arr[high] + more = arr[high] + (k - arr[high] + high - 1) = k + high - 1
}

// in the above, basically, our high will point to the smaller index of the two indexes between which our answer is going to lie. Therefore to get the correct answer, we see how much more is required to get to the ans from our arr[high] and this gives us a formula as high + k - 1, which by observing works in all cases (even edge case when high is out of bounds, negative index)
