#include <bits/stdc++.h>
using namespace std;

// Problem: Rotate the entire matrix (nxn) by clockwise 90 degrees

//* Method - I (Brute Force)

//. T.C -> O(n^2)
//. S.C -> O(n^2)
void bruteForce(vector<vector<int>> &matrix) {
 
    // To initialize the ans with the same size
  vector<vector<int>> ans = matrix;

  int n = matrix.size();

  // By observation we derived at this

  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {

      ans[col][n - row - 1] = matrix[row][col];

    }
  }

  matrix = ans;
}

//* Method - II (Optimal Solution)

//! Solving it in-place (without using any extra space)

// First, take transpose of the entire matrix, Each coloumn becomes row, after that, simply reverse each rows

// To take the transpose in-place, we simply keep swaping the elements about the main diagonal, keeping the diagonal intact

//. T.C -> O(n^2)
//. S.C -> O(1)
void optimalSolution(vector<vector<int>> matrix) {
  int n = matrix.size();

  // Taking Transpose of the matrix in-place

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  // Taking reverse of each of the row

  for (int i = 0; i < n; i++) {
    // for (int j = 0; j < n/2; j++) {
    //     swap(matrix[i][j], matrix[i][n-j-1]);
    // }
    reverse(matrix[i].begin(), matrix[i].end());
  }
}