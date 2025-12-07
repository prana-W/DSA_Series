#include <bits/stdc++.h>
using namespace std;

// Problem: Find 4 different indices such that their sum equals k. Indices should be unique

//* Method - I (Brute Force)
// Make four nested loops and store the answer in a set for unique quddruples

//. T.C -> O(n^4)
//. S.C -> O(2*x), x is the number of quads for storing the answer (set ans and vector ans)

//* Method - II (Better Solution)
// Make three pointers. Keep everything between j and k in the set, and then check at each step if the required exists in the map

//. T.C -> O(n^3 * log(x)), x is varying. It is the number of elements in the set
//. S.C -> O(n + 2*x), first for the internal hash set and the second for storing the answer (ans and fAns)
void betterSolution(vector<int> arr, int k) {

  int n = arr.size();

  set<vector<int>> ans;     // for giving unique quads
  vector<vector<int>> fAns; // for returning the final answer in vector form

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      set<int> st; //! Hash Set
      for (int k = j + 1; k < n; k++) {
        int required = k - (arr[i] + arr[j] + arr[k]);

        if (st.find(required) != st.end()) {

          vector<int> reqElem = {arr[i], arr[j], arr[k], required};
          sort(reqElem.begin(), reqElem.end()); // for giving quads with sorted element

          ans.insert(reqElem);
        }

        st.insert(arr[k]); // Insert the element in the map after checking, for future check
      }
    }
  }

  // For returning unique quadruples
  for (auto element : ans) {
    fAns.push_back(element);
  }

  // return fAns;
}

//! The above is Sir's method of doing this. I implemented the above solution using map with storing indices as well. Refer 3-Sum Problem Method-II.V to see my method

//* Method - III (Optimal Solution)
// In this method, we get rid of extra hash set and also the ans set which we were using for storing the answer for unique answer

// Sort the given array
// Fix i and j and then run two pointers k and l
// Avoid duplicates by moving the pointers, if it has the same element it was earlier

// Similar to Optimal Solution in 3-Sum

//. T.C -> O(n*log(n) + n^3)
//. S.C -> O(x), for storing the answer
vector<vector<int>> optimalSolution(vector<int> &nums, int target) {

  int n = nums.size();

  sort(nums.begin(), nums.end());

  vector<vector<int>> ans;

  for (int i = 0; i < n; i++) {

    if (i > 0 && nums[i] == nums[i - 1])
      continue;

    for (int j = i + 1; j < n; j++) {

        // We only ignore if it was taken before that is second element was once this before
      if (j > i + 1 && nums[j] == nums[j - 1])
        continue;

      int k = j + 1;
      int l = n - 1;

      while (k < l) {

        // Instead of adding all at once and going out of bounds of integer, we do it like this
        long long sum = nums[i];
        sum += nums[j];
        sum += nums[k];
        sum += nums[l];

        if (sum < target) {
          k++;
        }

        else if (sum > target) {
          l--;
        }

        else {

          vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
          sort(temp.begin(), temp.end());

          ans.push_back(temp);

          k++;
          l--;

          while (k < l && nums[k] == nums[k - 1]) {
            k++;
          }

          while (k < l && nums[l] == nums[l + 1]) {
            l--;
          }
        }
      }
    }
  }

  return ans;
}