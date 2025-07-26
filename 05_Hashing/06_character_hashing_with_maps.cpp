#include <bits/stdc++.h>
using namespace std;

//! Here the key will be the character and the value will be its frequency

int main() {

  string s;
  cin >> s;

  // Pre-compute

  map<char, int> mpp;

  for (int i = 0; i < s.size(); i++) {

    mpp[s[i]]++;

  }

  int q; // Number of queries
  cin >> q;

  while (q--) {
    char character;
    cin >> character;

    cout << character << ": " << mpp[character] << endl;
  }
}

//! HW: Do the sheet hashing problem