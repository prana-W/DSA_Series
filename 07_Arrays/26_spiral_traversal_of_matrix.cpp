#include <bits/stdc++.h>
using namespace std;

// Problem: Do spiral traversal of the matrix

// right -> bottom -> left -> top (repeat)

//. T.C -> O(n*m)
//. S.C -> O(n*m), for storing the answer
vector<int> spiralOrder(vector<vector<int>> &matrix) {

  int rs = 0, re = matrix.size() - 1;
  int cs = 0, ce = matrix[0].size() - 1;

  vector<int> ans;

  int n = matrix.size();
  int m = matrix[0].size();

  while (ans.size() < n * m) {
    for (int j = cs; j <= ce; j++) {
      ans.push_back(matrix[rs][j]);
    }

    rs++;

    if (ans.size() == n * m)
      break;

    for (int i = rs; i <= re; i++) {
      ans.push_back(matrix[i][ce]);
    }

    ce--;

    if (ans.size() == n * m)
      break;

    for (int j = ce; j >= cs; j--) {
      ans.push_back(matrix[re][j]);
    }

    re--;

    if (ans.size() == n * m)
      break;

    for (int i = re; i >= rs; i--) {
      ans.push_back(matrix[i][cs]);
    }

    cs++;

    if (ans.size() == n * m)
      break;
  }

  return ans;
}