#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Problem: An array with a element occuring more than n/2 times. Report that answer

//* Method - I (Brute Force)
// Make a nested loop to get the requency of each element in it and then if > n/2, then report the answer

//. T.C -> O(n^2)
//. S.C -> O(1)

void bruteApproach(int n, int arr[]) {
  int ans = -1;

  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (arr[i] == arr[j])
        cnt++;
    }

    if (cnt > n / 2) {
      ans = cnt;
      break;
    }
  }

  cout << ans << endl;
}

//* Method - II (Better Solution)
// Hashing - Store the freq. of all the elements and check in the map which has > n/2 occurence

//. T.C -> O(nlog(n)) + O(n)
//. S.C -> O(n)
void betterSolution(int n, int arr[]) {
  map<int, int> mp;

  // O(n*log(N))
  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
  }

  // O(N)
  for (auto elem : mp) {
    if (elem.second > n / 2) {
      cout << elem.first << endl;
      break;
    }
  }

  return;
}

//* Method - II.V (Slightly Better and easy Solution)
// Simply sort and return the middle element

//. T.C -> O(nlog(n))
//. S.C -> O(n), due to merge sort or can be any other if using other sorting algorithm

//! sort() uses many different algorithms internally, hence its space complexity can't be determined correctly
int betterBetterSolution(vector<int> &nums) {

  sort(nums.begin(), nums.end());

  int index = nums.size() / 2;

  return nums[index];
}

//* Method - III (Optimal Solution)
//! Moore's Voting Algorithm

//. T.C -> O(n) + O(n), the second one will only occur if we also verify for majority element
//. S.C -> O(1)
void optimalApproach(int n, int arr[]) {
  int i = 0;
  int elem = arr[i];
  int cnt = 0;

  for (int i = 0; i < n; i++) {

    // If cnt = 0, reset the element
    if (cnt == 0)
      elem = arr[i];

    // Increase the counter if we get the chosen one
    if (arr[i] == elem)
      cnt++;

    else
      cnt--;
  }

  //! Verify if the majority elem actually exists (not necessary, if we know that there actually does exists a majority element)
  int occ = 0;
  for (int i = 0; i < n; i++) {

    if (arr[i] == elem)
      occ++;
  }

  if (occ > n / 2)
    cout << elem << endl;
  else
    cout << -1 << endl;
}