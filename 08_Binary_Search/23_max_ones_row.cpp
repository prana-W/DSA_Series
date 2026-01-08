#include <bits/stdc++.h>
using namespace std;

//! Note: In this solution we are assuming all the rows arrays are sorted!!
// Problem: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order. Your task is to find the index of the row with the maximum number of ones. Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1

//* Method - I (Brute Force)
// Simply iterate each row and track the number of ones in each row and store if maximum ones. Optimal for the unsorted row array
//. T.C -> O(n*m)
//. S.C -> O(1)


//* Method - II (Optimal Approach)
//. T.C -> O(row*log(col))
//. S.C -> O(1)

// Can also be done by finding the lower_bound of one and then using that to find total ones by (m-lower_bound(1))
vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int colSize = mat[0].size();

        int maxi = 0;
        int rowNum = -1;

        for (int row = 0; row < mat.size(); row++) {
            
            int low = 0, high = colSize - 1;

            while(low <= high) {
                int mid = (low+high)/2;

                if (mat[row][mid] == 0) low = mid+1;
                else high = mid-1;
            }

            int oneCnt = (colSize - high - 1);

            if (oneCnt > maxi) {
                maxi = oneCnt;
                rowNum = row;
            }
        }

        vector<int>ans = {rowNum, maxi};

        return ans;
        
    }