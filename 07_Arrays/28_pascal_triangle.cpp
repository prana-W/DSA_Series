#include <bits/stdc++.h>
using namespace std;

// Problem 1: Given row number and element (coloumn) number, find the element of the Pascal Triangle. Example: If r = 5 and c = 3, Answer would be 6

// Problem 2: Print nth row of the Pascal Triangle. Example, n = 5, answer: 1, 4, 6, 4 , 1

// Problem 3: For a given n, print the entire traingle (n = number of rows)

//! Concept:
// Element: (r-1)C(c-1), for the element in rth row and cth coloumn

//. T.C -> O(min(r, n-r))
//. S.C -> O(1)
int nCr(int n, int r) {
  long long res = 1;

  //! Using Property nCr = nC(n-r) for optimising
  r = min(r, n-r);

  // Other way could be to get numberator and denominator and then divide them both
  for (int i = 0; i < r; i++) {
    res *= (n - i);
    res /= (i + 1);
  }

  return res;
}

//! Problem - 1

//* Method - I (Optimal Solution)
// Simply find (r-1) C (c-1) and return that

//. T.C -> O(r)
//. S.C -> O(1)
int problemOneSolution(int row, int col) {
  return nCr(row - 1, col - 1);
}

//! Problem - 2

//* Method - I (Brute Force)
// nth row has n elements. Therefore simply find the n elements of the nth row using nCr formula

//. T.C -> O (n*r), n is the row number and r changes from 1 to n
//. S.C -> O(n) for storing the answer
vector<int> problemTwoBrute(int row) {
  vector<int> ans;

  for (int col = 1; col <= row; col++) {

    // T.C -> O(col-1)
    int elem = nCr(row - 1, col - 1);

    ans.push_back(elem);
  }

  return ans;
}

//* Method - II (Optimal Solution)
// We are seeing a pattern in the row

//. T.C -> O(n), n is the number of rows
//. S.C -> O(n) for storing the answer and O(1), if we don't consider the space for storing (when we directly print the answer)
vector<int> optimisedSolutionRowGeneration(int row) {
  vector<int> ans;

  int elem = 1;

  ans.push_back(1);

  for (int col = 2; col <= row; col++) {

    elem *= (row - col + 1);
    elem /= (col - 1);

    ans.push_back(elem);
  }

  return ans;
}

//! Problem - 3

//* Method - I (Brute Force)
// Use two nested loop, one for rows and another for col and then use the nCr i.e. (row-1)C(col-1) formula to calculate each element and then store it in the matrix
//. T.C -> O(n^3)

//* Method - II (Optimal Solution)
// Make a single loop for the rows and use the Method II for Problem 2, to generate the entire elements for that given row
//. T.C -> O(n^2)

vector<vector<int>> optimalSolutionPascal(int n) {

  vector<vector<int>> ans;

  for (int rowNum = 1; rowNum <= n; rowNum++) {

    // Using Method II for Problem 2 to generate the array of elements for a given row number
    vector<int> particularRow = optimisedSolutionRowGeneration(rowNum);

    ans.push_back(particularRow);
  }

  return ans;
}