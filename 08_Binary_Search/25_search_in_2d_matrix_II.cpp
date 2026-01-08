#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Iterate thorugh each element

//. T.C -> O(row*col)
//. S.C -> O(1)

//* Method - II (Better Solution)
// Iterate thorugh each row and use Binary Search on each row array

//. T.C -> O(row * log(col))
//. S.C -> O(1)

//* Method - III (Optimal Solution)
// Start from the top-right element, if target is smaller than this, move left else move down. If ever found return true. Similarly we can start from the bottom-left corner element as well and similarly implement the algorithm to eliminate till e find our target element. Note: No other corners than these two will work. Just think about it!

//. T.C -> O(row + col)
//. S.C -> O(1)

// Function to search for target in matrix using staircase search
bool searchElement(vector<vector<int>>matrix, int target) {
        int n = matrix.size();       // Number of rows
        int m = matrix[0].size();    // Number of columns

        int row = 0;        // Start from first row
        int col = m - 1;    // Start from last column (top-right corner)

        // Traverse the matrix
        while (row < n && col >= 0) {
            if (matrix[row][col] == target) {
                return true; // Found target
            } 
            else if (matrix[row][col] < target) {
                row++; // Move down to next row
            } 
            else {
                col--; // Move left to previous column
            }
        }

        return false; // Target not found
}