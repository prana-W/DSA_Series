#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=edJ19qIL8WQ

//! Note:
// Here all the array/vector/data_type must be sorted!! As we are using binary search under the hood!
// Also, all these calculations are using O(log n) time complexity. Baseball huh?

void binarySearchSTL() {
  int arr[5] = {4, 5, 8, 9};

  //* binary_search
  // It will always return 0 or 1 depending if the element exists or not
  bool res = binary_search(arr, arr + 5, 8); // First argument is the starting iterator, second is the ending iterator (not including this in search), third is the target element

  vector<int> v = {8, 10, 45, 99};
  bool res2 = binary_search(v.begin(), v.end(), 45);

  cout << res << endl;
}

void lowerBoundSTL() {
  int arr[6] = {1, 4, 5, 6, 9, 9};

  cout << lower_bound(arr, arr + 6, 4) - arr << endl; // 1

  // lower_bound(...) returns the iterator pointing to the first occurence of an element if it exists, else it points to an element immeditely after where it should been have existed!
  // By doing lower_bound(...) - starting_iterator, we get the index of the the element being pointed by that iterator.

  cout << lower_bound(arr, arr + 6, 7) - arr << endl; // 4

  cout << lower_bound(arr, arr + 6, -50) - arr << endl; // 0 (The first index)

  cout << lower_bound(arr, arr + 6, 50) - arr << endl; // 6 (The index after the last)

  vector<int> v = {1, 4, 5, 6, 9, 9};

  int response = lower_bound(v.begin(), v.end(), 3) - v.begin();

  cout << response << endl;
}

void upperBoundSTL() {
  int arr[6] = {1, 4, 5, 6, 9, 9};

  cout << upper_bound(arr, arr + 6, 4) - arr << endl; // 2

  // upper_bound(...) points to the iterator occuring after the last occurence of an element. If the element doesn't occur, it will point to the next iterator, where the element should have been

  cout << upper_bound(arr, arr + 6, 7) - arr << endl; // 4

  cout << upper_bound(arr, arr + 6, -50) - arr << endl; // 0 (The first index)

  cout << upper_bound(arr, arr + 6, 50) - arr << endl; // 6 (The index after the last)

  vector<int> v = {1, 4, 5, 6, 9, 9};

  int response = upper_bound(v.begin(), v.end(), 3) - v.begin();

  cout << response << endl;
}

int main() {
  // binarySearchSTL();
  // lowerBoundSTL();
  upperBoundSTL();
}