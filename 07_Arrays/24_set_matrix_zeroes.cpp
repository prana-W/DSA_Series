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
void betterSolution(vector<vector<int>> arr) {
  int n = arr.size();
  int m = arr[0].size();

  vector<int> row(n, 0);
  vector<int> col(m, 0);

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

//! Solving in-place

// Instead of using seperate space, we keep the tracking inside the matrix itself. This way we optimise the space complexity.

//. T.C -> O(n*m)
//. S.C -> O(1)
void optimalSolution(vector<vector<int>> arr) {

  int n = arr.size();
  int m = arr[0].size();

  int col0 = 1; // This is to avoid collision at row[0] and col[0] tracking

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {

      if (arr[i][j] == 0) {

        // Mark the i-th row as 0
        // Mark the j-th coloumn as 0

        arr[i][0] = 0;

        if (j != 0)
          arr[0][j] = 0;
        else
          col0 = 0;
      }
    }
  }

  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m; j++) {
      if (arr[i][j] != 0) {

        // Check for col and row
        if (arr[0][j] == 0 || arr[i][0] == 0) {
          arr[i][j] = 0;
        }
      }
    }
  }

  // Now update the row[0] by looking at arr[0][0]

  if (arr[0][0] == 0) {
    for (int j = 0; j < m; j++)
      arr[0][j] = 0;
  }

  // Now update the col[0] by looking at col[0]

  if (col0 == 0) {
    for (int i = 0; i < n; i++)
      arr[i][0] = 0;
  }
}

//* Method - III.V (Optimal + Easy solution)

// Consider first row and first coloumn as tracking array. Take two variables r0 and c0 initially set to 1. If the first row has any 0, turn r0 to 0, similarly if the first coloumn as 0, turn the c0 to 0.

// Now use the two arrays as a tracker for the remaining matrix (matrix formed after removing the first row and coloumn)

// After the tracking update the matrix by using the trackers (NOTE: Don't update anything in the first row and first coloumn)

// After solving the matrix except first row and first coloumn, now it's time to solve the first row and coloumn. If r0 was 0, set the entire first row as 0, if the c0 was 0, set the entire first coloumn as 0

// Finally, we solvede the entire problem in O(n*m) Time complexity with no extra space

//. T.C -> O(n*m)
//. S.C -> O(1)
void optimalAndEasySolution(vector<vector<int>> matrix) {
  int n = matrix.size();    // row size
  int m = matrix[0].size(); // coloumn size

  int row0 = 1, col0 = 1; // For tracking '0' in first row and first coloumn respectively

  // Update row0 and col0 depending if any '0' is present in the first row or first coloumn respectively
  for (int i = 0; i < n; i++) {
    if (matrix[i][0] == 0) {
      row0 = 0;
      break;
    }
  }
  for (int j = 0; j < m; j++) {
    if (matrix[0][j] == 0) {
      col0 = 0;
      break;
    }
  }

  // Track the remaining matrix
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (matrix[i][j] == 0) {

        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }

  // Update the remaining matrix using the tracker/hash array
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (matrix[0][j] == 0 || matrix[i][0] == 0) {

        matrix[i][j] = 0;
      }
    }
  }

  // Update the first row using row0

  if (row0 == 0) {
    for (int i = 0; i < n; i++) {
      matrix[i][0] = 0;
    }
  }

  // Update the first col using col0

  if (col0 == 0) {
    for (int j = 0; j < m; j++) {
      matrix[0][j] = 0;
    }
  }

  // Finally we updated the entire matrix
}