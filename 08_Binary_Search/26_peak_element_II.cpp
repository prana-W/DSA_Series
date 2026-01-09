#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Go to each element, check for tis left, right, top and bottom element and check if its peak.

//. T.C -> O(row*col*4)
//. S.C -> O(1)

//* Method - II (Better Solution)
// Return the largest element in the matrix

//. T.C -> O(row*col)
//. S.C -> O(1)

//* Method - III (Optimal Solution)

// Use binary search on the coloumns and for any coloumn 'mid', find the largest element in that coloumn array, for the largest element, it will be greater than its top and bottom. Check if it is greater than left and right, if yes, then it is the answer, else if the left is greater, eliminate the left portion of the coloumn and simmilarly if right is greater, eliminate the left portion.

// If left element is greater than the peak element in the coloumn array, then the maximum element in the left coloumn will be greater than the right element and also greater than top and bottom, so only the left portion will be concerned and just like that we can always find some element which is greater than all the 4 adjacent elements

//. T.C -> O(row*log(col))
//. S.C -> O(1)
int maxElement(vector<vector<int>>& arr, int col) {
          int n = arr.size();
          int max_val = INT_MIN;
          int index = -1;
  
          // Iterate through each row to find the maximum element 
          // in the particular column
          for (int i = 0; i < n; i++) {
              if (arr[i][col] > max_val) {
                  max_val = arr[i][col];
                  index = i;
              }
          }
          return index;
}
  
      // Function to find a peak element in the 2D matrix 
      // using binary search
vector<int> findPeakGrid(vector<vector<int>>& arr) {
          int n = arr.size();     
          int m = arr[0].size();  
  
          // Initialize the lower and upper bounds for binary search
          int low = 0;           
          int high = m - 1;      
  
          // Perform binary search on columns
          while (low <= high) {
              int mid = (low + high) / 2;
  
              // Find the index of the row with the maximum element 
              // in the middle column
              int row = maxElement(arr, mid);
  
              // Determine the elements to the left and right of 
              // the middle element in the found row
              int left = mid - 1 >= 0 ? arr[row][mid - 1] : INT_MIN;
              int right = mid + 1 < m ? arr[row][mid + 1] : INT_MIN;
  
              // Check if the middle element is greater than its neighbors
              if (arr[row][mid] > left && arr[row][mid] > right) {
                  return {row, mid};
              } 
              else if (left > arr[row][mid]) {
                  high = mid - 1;
              } 
              else {
                  low = mid + 1;
              }
          }
  
          // Return {-1, -1} if no peak element is found
          return {-1, -1};
}