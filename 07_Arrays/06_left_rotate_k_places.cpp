#include <bits/stdc++.h>
using namespace std;

// Problem: Rotate an array to its left by any given places

//* Method - I - Brute Force
// First do d = d%n (to simplify d), then store the first d elements into temp and place the remaining by shifting to left by d places. Then, place the elements in temp

//. T.C -> O(n+d), by taking sum of the three t.c
//. Extra Space -> O(d)
void rotateLeftBrute(int n, int arr[], int d) {

  // Get the net left rotation
  d = d % n;

  // Store the first d elements in temp array

  vector<int> temp;
  // O(d)
  for (int i = 0; i < d; i++) {
    temp.push_back(arr[i]);
  }

  // Shift the remaining elements by d places to its left

  // O(n-d)
  for (int i = d; i < n; i++) {
    arr[i - d] = arr[i];
  }

  // Put the temp array elements after the remaining elements

  // O(d)
  for (int i = n - d; i < n; i++) {
    arr[i] = temp[i - (n - d)];
  }
}


//* Method - II - Most Optimal Solution (slightly more complexity in time, but less in space)
// Reverse the part which we were refereing to as temp in earlier method, then reverse the remaining portion, after the reversal of both the portions, reverse the entire final array itself

//. T.C -> O(2*n), time complexity is slightly larger than the previous method
//. Extra Space -> O(1)
void rotateLeftOptimal(int n, int arr[], int d) {

  d = d%n;

  // O(d)
  reverse(arr, arr + d); // Reverse the first portion

  // O(n-d)
  reverse(arr + d, arr + n); // Reverse the second portion

  // O(n)
  reverse(arr, arr + n); // Reverse the entire array
}


// Problem 2: For right rotation

// For right rotation (for d elements)

//* Method - I (Brute Force)

void rightRotationRight(int n, int arr[], int d) {

  d = d%n;

  vector<int>temp;
  
  // Store the portion which will come in the begining in a temp array
  for (int i = n-d; i < n; i++) {
    temp.push_back(arr[i]);
  }
  

  for (int i = 0; i < n-d; i++) {
    arr[i+d] = arr[i];
  }


  for (int i = 0; i < d; i++) {
    arr[i] = temp[i];
  }



}

//* Method - II (Optimal Solution)

void rightRotationOptimal (int n, int arr[], int d) {
  d = d%n;

  reverse (arr, arr+(n-d));
  reverse (arr+n-d, arr+n);

  reverse(arr, arr+n);

}

int main() {

  int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  rightRotationOptimal(9, arr, 5); // Passed by refrence, as we have an array here

  for (auto element : arr) {
    cout << element << " ";
  }

}