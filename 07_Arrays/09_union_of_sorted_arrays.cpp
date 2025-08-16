#include <bits/stdc++.h>
using namespace std;

// Problem: Return the union of two (sorted) arrays; union array should only have the unique elements (no duplicates should be present in it) and also it should be sorted

//* Method - I (Brute Force Method) - Works for both sorted and unsorted array
// Make a set data structure, and iterate and put all the elements of both the arrays into it. Since set is used, it will only have unique and sorted elements

//. T.C -> O(n1 log n + n2 log n) + O(n1 + n2)
//. S.C - > O(n1 + n2) + O(n1 + n2), the second term is for unionArr, for returning the answer, while the first term is for set (considering all distinct elements)
vector<int> unionBrute(int n1, int arr1[], int n2, int arr2[]) {

  set<int> st;

  // Step 1: Copy all the elements into the set
  // O(n1*log(n)), n is the size of the set (which will be varying at each step)
  for (int i = 0; i < n1; i++) {
    st.insert(arr1[i]);
  }

  // O(n2*log(n)), n is the size of the set (which will be varying at each step)
  for (int i = 0; i < n2; i++) {
    st.insert(arr2[i]);
  }

  vector<int> unionArr;

  // O(n1 + n2), when all the elements in arr1 and arr2 were distinct collectively
  for (auto element : st) {
    unionArr.push_back(element);
  }

  return unionArr;
}

//* Method - II (Optimal Approach)
//! Only works for sorted arrays
//! Two-Pointer Approach
// Note, we will be returning unique and sorted union array

//. T.C -> O(n1 + n2)
//. S.C -> O(n1 + n2), only for returning the answer
vector<int> unionOptimal(vector<int> arr, vector<int> brr) {
  int n1 = arr.size();
  int n2 = brr.size();

  int i = 0; // Pointer for arr
  int j = 0; // Pointer for brr

  vector<int> unionArr;

  while (i < n1 && j < n2) {
    if (arr[i] <= brr[j]) {
      // Only take the element, if not already present in the unionArr or if no element is present in the unionArr
      if (unionArr.size() == 0 || unionArr.back() != arr[i])
        unionArr.push_back(arr[i]);

      i++;
    } else {
      if (unionArr.size() == 0 || unionArr.back() != brr[j])
        unionArr.push_back(brr[j]);

      j++;
    }
  }

  // At this pointer either of the array would be exhausted

  while (i < n1) {
    if (unionArr.size() == 0 || unionArr.back() != arr[i])
      unionArr.push_back(arr[i]);

    i++;
  }

  while (j < n2) {

    if (unionArr.size() == 0 || unionArr.back() != brr[j])
      unionArr.push_back(brr[j]);

    j++;
  }

  return unionArr;
}
