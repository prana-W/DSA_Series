#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Iterate though every element
//. T.C -> O(row*col)
//. S.C -> O(1)

//* Method - II (Better Solution)
// Iterate through each row and check if the target lies in that row (by comparing the target with the first and last element of the row array), if target lies in the row array, then only use Binary search on the sorted row array

//. T.C -> O(row + log(col)), as we are using Binary Search only once when the target lies inside the row
//. S.C -> O(1)

//* Method - III (Optimal Approach and sir solution)
// We can see if we somehow flatten the entire matrix, we can find the target. So we will take low as 0 and high as row*col-1 and apply binary search on it. For each 'mid', we convert it to respective rowNum and colNum and then compare it with the target
//. T.C -> O(log(row*col))
//. S.C -> O(1)

bool optimalApproach(vector<vector<int>>& matrix, int target) {

        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        int low = 0, high = rowSize*colSize - 1;

        while (low <= high) {
            int mid = (low+high)/2;

            int rowNum = mid/colSize;
            int colNum = mid%colSize;

            if (matrix[rowNum][colNum] < target) low = mid+1;
            else if  (matrix[rowNum][colNum] > target) high = mid-1;
            else return true;
        }

        return false;

}

//* Method - III.V (Optimal Approach and My Solution)

// Use Binary Search to find in which row the target could lie and then use Binary Search on that row array
//. T.C -> O(log(row) + log(col)) or O(log(row*col))
//. S.C -> O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        int low = 0, high = rowSize-1;

        while (low <= high) {
            int mid = (low+high)/2;

            if (matrix[mid][0] <= target) low = mid+1;
            else high = mid-1;
        }

        int rowNum = high;

        if (rowNum < 0 || rowNum >= rowSize) return false;
        
        low = 0, high = colSize-1;

        while (low <= high) {
            int mid = (low+high)/2;

            if (matrix[rowNum][mid] > target) {
                high = mid-1;
            }
            else if (matrix[rowNum][mid] < target) {
                low = mid+1;
            }
            else return true;
        }

        return false;
        
    }