#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Go to each element in the matrix and store that in a 1D array, sort the array and find the middle element

//. T.C -> O(row*col + (row*col)*(log(row*col)))
//. S.C -> O(row*col)

//* Method - II (Optimal Approach)

// The main concept is the final answer will lie between the minimum element and the maximum element. Also, the median is the element which has the number of element <= that element as greater than (n*m)/2. So if '9' is the median of the matrix, the number of elmenets <= 9 would be greater than (n*m)/2

// Simply use binary search to choose a mid and count the total number of elements <= that element in the matrix using the concept of upper bound in the row-wise array

//. T.C -> O(O(log(max - min) * row * log(cols)))
//. S.C -> O(1)

// Function to count elements less than or equal to mid in a row
int countLessEqual(vector<int>& row, int mid) {
    // Using upper_bound to find count efficiently
    return upper_bound(row.begin(), row.end(), mid) - row.begin();
}

    // Function to find median
int findMedian(vector<vector<int>>& matrix) {
        // Number of rows and columns
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Minimum possible element in matrix
        int low = matrix[0][0];

        // Maximum possible element in matrix
        int high = matrix[0][cols - 1];
        for (int i = 1; i < rows; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][cols - 1]);
        }

        // Binary search over the value range
        while (low < high) {
            int mid = (low + high) / 2;

            // Count elements ≤ mid
            int count = 0;
            for (int i = 0; i < rows; i++) {
                count += countLessEqual(matrix[i], mid);
            }

            // If count is less than half, median is greater
            if (count < (rows * cols + 1) / 2)
                low = mid + 1;
            else
                high = mid;
        }

        // Final low is the median
        return low;
}
