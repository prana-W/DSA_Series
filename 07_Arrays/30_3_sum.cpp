#include <bits/stdc++.h>
using namespace std;

// Problem: Return all the unique triplets such that the sum of triplets (triplets should be unique, i.e. no two triplets should give the same elements) which equal 0

//* Method - I (Brute Force)
// Make three nested loops and check all the possible tripletes that sum equals 0

//. T.C -> O(n^3 * (x)), x is the size of the set
//. S.C -> O(x), size of the set
void bruteSolution(vector<int> arr) {
  int n = arr.size();

  set<vector<int>> st;
  vector<vector<int>> ans;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (arr[i] + arr[j] + arr[k] == 0) {

          vector<int> temp = {arr[i], arr[j], arr[k]};
          sort(temp.begin(), temp.end());

          st.insert(temp); // To store unqiue triplets in the final answer
        }
      }
    }
  }

  for (auto elem : st) {
    ans.push_back(elem);
  }

  // return ans;
}

//* Method - II (Better Solution)
// Using Hashing, to avoid the third loop, we simply run two nested loops, calculate the required third element and then simply check if it exists in the array or not

//. T.C -> O(n^2 * log(x)), x is the size of the set. We could have also used unordered set
//. S.C -> O(n) + O(x), n due to hashSet and x due to st set (ignoring for storing the final answer)
void betterSolution(vector<int> arr) {

  int n = arr.size();

  set<vector<int>> st;     // answer
  vector<vector<int>> ans; // answer but in vector

  for (int i = 0; i < n; i++) {

    set<int> hashSet;

    for (int j = i + 1; j < n; j++) {
      int required = -(arr[i] + arr[j]);

      if (hashSet.find(required) != hashSet.end()) {
        vector<int> temp = {arr[i], arr[j], required};
        sort(temp.begin(), temp.end());

        st.insert(temp);
      }

      hashSet.insert(arr[j]);
    }
  }

  for (auto elem : st) {
    ans.push_back(elem);
  }

  // return ans;
}

//* Method - II.V (My Solution)

//. T.C -> O(n^2*log(n))
//. S.C -> O(n + x), one due to map and the other due to set (ignoring for storing the final answer)
vector<vector<int>> myBetterSolution(vector<int> &nums) {

  int n = nums.size();

  set<vector<int>> ans;
  map<int, int> mp;

  for (int i = 0; i < n; i++) {
    mp[nums[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int req = 0 - (nums[i] + nums[j]);

      if (mp.find(req) != mp.end() && mp[req] > j) {

        vector<int> temp;

        temp.push_back(nums[i]);
        temp.push_back(nums[j]);
        temp.push_back(req);

        sort(temp.begin(), temp.end());

        ans.insert(temp);
      }
    }
  }

  vector<vector<int>> fAns;

  for (auto elem : ans) {
    fAns.push_back(elem);
  }

  return fAns;
}

//* Method - III (Optimal Solution)
// Sort the arrahy and iterate the array once (i-pointer), then use the two-pointer approach on the remaining sorted portion of the array to find the required sum.

//. T.C -> O(n*log(n) + n^2)
//. S.C -> O(x), x is the number of unique triplets, this is for reporting the answer and no extra space is taken other than this 
vector<vector<int>> optimalSolution(vector<int> arr) {

  sort(arr.begin(), arr.end());

  int n = arr.size();
  vector<vector<int>> ans;

  for (int i = 0; i < n; i++) {

    if (i > 0 && arr[i] == arr[i-1]) continue;

    int j = i + 1;
    int k = n - 1;

    while (j < k) {

      int sum = arr[i] + arr[j] + arr[k];

      if (sum < 0) {
        j++;
      } else if (sum > 0) {
        k--;
      } else {
        ans.push_back({arr[i], arr[j], arr[k]});

        j++;
        k--;

        while (j < k && arr[j] == arr[j-1]) {
          j++;
        }

        while (j < k && arr[k] == arr[k-1]) {
          k--;
        }
      }
    }

  }

  return ans;
}
