#include <bits/stdc++.h>
using namespace std;

// Problem: Move all the zeroes in an array to the end

//* Method - I (Brute Force Method)

//. T.C -> O(2*n)
//. Extra Space -> O(x), where x is the number of non-zero elements, x can be n, so the worst case is O(n)
void moveZeroesBrute(int n, int arr[]) {

  vector<int> temp;

  // Copy all the non-zeroes elements into the temp array
  // O(n)
  for (int i = 0; i < n; i++) {
    if (arr[i] != 0) {
      temp.push_back(arr[i]);
    }
  }

  // Place all the non-zero elements, that is all the elements of the temo array into the original array
  // O(x)
  for (int i = 0; i < temp.size(); i++) {
    arr[i] = temp[i];
  }

  // Fill the remaining spaces with zero
  // O(n-x)
  for (int i = temp.size(); i < n; i++) {
    arr[i] = 0;
  }
}

//* Method - II (Optimal Solution) - Sir Solution
//. T.C -> O(n)
//. Extra Space -> O(1)
void moveZeroesOptimalSirSolution(int n, int arr[]) {

  int j = -1; // Index tracking the position of zero

  // Finding the index of the first zero element
  // O(x), x is index where the first zero element is found
  for (int i = 0; i < n; i++) {
    if (arr[i] == -1) {
      j = i; // Store the index where the first zero element is found and break
      break;
    }
  }

  if (j == -1)
    return;

  // O(n-x)
  for (int i = j + 1; i < n; i++) {
    if (arr[i] != 0) {
      swap(arr[i], arr[j]);
      j++;
    }
  }
}

//* Method - III - My Solution
//. T.C -> O(n)
//. Extra Space -> O(1)
void moveZeroesOptimal(int n, int arr[]) {
  int j = 0; // Index tracking the position of the next incoming element (non-zero)
  for (int i = 0; i < n; i++) {
    if (arr[i] != 0) {
      arr[j] = arr[i]; // Placing the non-zero element at the desired location
      j++;
    }
  }

  for (int k = j; k < n; k++) {
    arr[k] = 0;
  }
}