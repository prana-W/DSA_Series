#include <bits/stdc++.h>
using namespace std;

// Problem: Rotate the entire matrix (nxn) by clockwise 90 degrees

//* Method - I (Brute Force)

//. T.C -> O(n^2)
//. S.C -> O(n^2)
void bruteForce(vector<vector<int>>matrix) {

	int n = matrix.size();

	vector<vector<int>>ans = matrix;

	// row0 -> coln-1
	// row1 -> coln-2
	// rown-1 -> col0

	// row0 means matrix[0][...]
	// col1 means matrix[...][1]

	for (int i = 0; i < n; i++) {
		for (int j  = 0; j < n; j++) {
			ans[j][n-i-1] = matrix[i][j];
		}
	}

}

//* Method - II (Optimal Solution)

//! Solving it in-place (without using any extra space)

// First, take transpose of the entire matrix, Each coloumn becomes row, after that, simply reverse each rows

// To take the transpose in-place, we simply keep swaping the elements about the main diagonal, keeping the diagonal intact

//. T.C -> O(n^2)
//. S.C -> O(1)
void optimalSolution(vector<vector<int>>matrix) {
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