#include <bits/stdc++.h>
using namespace std;

//! Problem: Remove duplicate elements in-place from a sorted array

//* Method - I - Brute Force
// Make a Set Data structure and iterate through the array and put each elements into the set. The set will only contain the unique elements in sorted order. Then iterate again through the array and replace it with the elements of the set (Note: Only the unique elements in the beggining of the array is our concern, rest elements doesn't matter to the verdict)
//. T.C -> O(n*log n + n)
//. S.C -> O(n),
// if all were unique elements, we would need n space for set
void removeDuplicatesBrute(int n, int arr[]) {
  set<int> st;

  // n*log(n)
  for (int i = 0; i < n; i++) {
    st.insert(arr[i]); // T.C -> log (n)
  }

  int index = 0;
  // T.C -> n
  for (auto element : st) {
    arr[index] = element;
    index++;
  }
}

//* Method - II - Optimal Solution
// Iterate thorugh the array and find the unique element and start placing it in the begining
//! Two-Pointer Approach
//. T.C -> O(n)
//. S.C -> O(1)
void removeDuplicatesOptimal(int n, int arr[]) {

    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            arr[i+1] = arr[j];
            i++;
        }
    }

    cout << "Unique elements:" << i+1 << endl;
}