#include <bits/stdc++.h>
using namespace std;

// Problem: n*m Binary matrix is given and only contains 0s and 1s. You have to find all the indexes where the zero exists and at all those indexes, fill all those indexes, fill the entire row and coloumn containgin the index as zero

//* Method - I (Brute Force)

void markRow(int rowNum, vector<vector<int>> &arr) {

  int col = arr[0].size();

  for (int j = 0; j < col; j++) {
    if (arr[rowNum][j] != 0) {
      arr[rowNum][j] = -1;
    }
  }
}

void markCol(int colNum, vector<vector<int>> &arr) {

  int row = arr.size();

  for (int i = 0; i < row; i++) {
    if (arr[colNum][i] != colNum) {
      arr[colNum][i] = -1;
    }
  }
}

//. T.C -> O((n*m)*(n+m) + n*m) -> Cubic solution
//. S.C -> O(1)
void bruteForce(vector<vector<int>> &arr) {

  int n = arr.size();    // rows
  int m = arr[0].size(); // coloums

  // O(n*m) for outer loop. Total (considering the inner TC) -> O(n*m * (n+m))
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 0) {

        // O(n)
        markRow(i, arr); // turn all 1s into (-1)s

        // O(m)
        markCol(j, arr); // turn all 1s into (-1)s
      }
    }
  }

  // Turn all the (-1)s into 0s

  // O(n*m)
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == -1) {
        arr[i][j] = 0;
      }
    }
  }

}

//* Method - II (Better Solution)


//. T.C -> O(2*(n*m))
//. S.C -> O(n + m)
void betterSolution(vector<vector<int>>arr) {
    int n = arr.size();
    int m = arr[0].size();

    vector<int>row(n, 0);
    vector<int>col(m, 0);

    // Adding the flag to the row and col array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (arr[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }

        }
    }

    // Updating the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (row[i] == 1 || col[j] == 1) {
                arr[i][j] = 0;
            }

        }
    }
}

//* Method - III (Optimal Solution)

// TODO: Optimal Solution