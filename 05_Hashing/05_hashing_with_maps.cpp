#include <bits/stdc++.h>
using namespace std;

// Problem: Find the frequenchy of all the numbers in the array

//! Important Points

// When the number of queries were very large, then hasing with arrays was much more complex and not possible since, we can't store large number size arrays. In such a case Hasing with maps is much more better solution.

// Map stores all the values in sorted order
// By default, the value is 0 for any key
// Key: Number of the array
// Value: Frequency of that number

/*
    ** Time Complexity --> map
    storing, fetching --> log(N) in all cases(best-avg.-worst)
    n is the number of elements in the map

*/

int main() {

  int n;
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // pre-compute
  map<int, int> mpp;
  // unordered_map<int, int>mpp;
  
  // O(n) for the loop
  for (int i = 0; i < n; i++) {
    mpp[arr[i]]++; // O(log n) for maps and usually O(1) for unordered map and might be O(n) in worst case
  }

  // iterate in the map
  // for (auto it : mpp)
  // {
  //     cout << it.first << "->" << it.second << endl;
  // }

  int q; // q is the number of queries
  cin >> q;


  // O(q) for the loop
  while (q--) {
    int number;
    cin >> number;
    // fetch
    cout << number << ": " << mpp[number] << endl; // O(log n) for the map and O(1) or O(n) for the unordered map
  }

  return 0;
}


//* Final Summary

// The fetching and storing will take O(log n) for maps and ususally O(1) for unordered map, but in worst case O(n).

// The loops also take O(N), N is the number of iterations in loop. Here we have two major loops (one for n and another for q).

// Therefore, total time complexity will be the product of the time complexity of the loop and the inner map (fetching/storing)

// Therefore, first preference should be unordered map in any problem, as it will in most of the cases be the better solution. But in worst case scenarios, it might end up taking very long, in such a situation, we have to use map only, as in the worst case, it would be more faster than unordered map.
