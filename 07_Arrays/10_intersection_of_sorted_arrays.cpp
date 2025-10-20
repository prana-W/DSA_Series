#include <bits/stdc++.h>
using namespace std;

// Problem: Return the array containing the common elements in two sorted arrays. Note: In the answer, we can have duplicates, if exists!

//* Method - I (Brute Force)
//! Works for both sorted and unsorted array. 

//. T.C -> O(n1*n2)
//. Extra S.C -> O(n2), where n2 is the size of the visited array. Hence, we can consider the smaller length array as second array, to slightly reduce extra space required. Note: We are also using some space for storing the ans, so tell that to the interviewer. 
vector<int> intersectionBrute(vector<int> arr, vector<int> brr) {
  int n1 = arr.size();
  int n2 = brr.size();

  vector<int> intersectionArr;
  vector<int> visited(n2, 0); // This keeps tracks of all the elements in brr[] that is taken into intersectionArr[]

  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n2; j++) {
      if (arr[i] == arr[j] && visited[j] == 0) {
        intersectionArr.push_back(arr[i]);
        visited[j] = 1;
        break;
      }

      //! This statement is only valid if both the arrays are sorted, else don't use this
      if (brr[j] > arr[i])
        break; // If brr[j] is greater, then obviously the upcomming elements would also be greater, since sorted array
    } 
  }

  return intersectionArr;
}

//* Method - II (Optimal Solution)
//! Works for sorted arrays only
//! Two-Pointer Approach

//. T.C -> O(n1 + n2), when such a consider occurs, when we reach the end of both the array
//. Extra S.C -> O(1), since no extra space is taken for solving the problem
//. S.C -> O(n1+n2) if we consider space for returning the answer
vector<int> intersectionOptimal(vector<int> arr, vector<int> brr) {
  int i = 0;
  int j = 0;

  vector<int> intersectionArr;

  while (i < arr.size() && j < brr.size()) {

    if (arr[i] < brr[j]) {
      i++;
    } else if (arr[i] > brr[j]) {
      j++;
    } else {
      intersectionArr.push_back(arr[i]);
      i++;
      j++;
    }
  }

  return intersectionArr;
}

// Personal Note: I think we could also have first sorted both the arrays and then used the second approach. For this: T.C -> O(n1*log(n1) + n2*log(n2) + n1 + n2). This would have better T.C than the first approach for the unsorted array