#include <bits/stdc++.h>
using namespace std;

// Check/Print all the divisors/factors of a given number in sorted order

//* Method-I (Brute Force)
//. T.C -> O(n)

void bruteForce(int n) {

  for (int i = 1; i <= n; i++) {
    if (n % i == 0)
      cout << i << " ";
  }
}

//* Method-II (Optimsied Approach)
//. T.C for the entire function: O(sqrt(n)) + O(nf*log(nf)) + O(nf)

void optimisesApproach(int n) {

  //* Method-II (Optimised Way)
  // See obsidian notes

  // Use vector to store the data and then sort!

  vector<int> arr;

  int squareRoot = sqrt(n); // storing the result in a varible, so that the function sqrt(n) is not called again and again in the loop, thus optimising the code a little bit

  // T.C for the loop -> O(sqrt(n))
  for (int i = 1; i <= squareRoot; i++) {
    if (n % i == 0) {
      arr.push_back(i);
      if (n / i != i)
        arr.push_back(n / i);
    }
  }

  // T.C for sort: O(nf*log(nf))
  sort(arr.begin(), arr.end());

  // T.C for this loop: O(nf), where nf is the number of factors
  for (auto element : arr) {
    cout << element << " ";
  }

}