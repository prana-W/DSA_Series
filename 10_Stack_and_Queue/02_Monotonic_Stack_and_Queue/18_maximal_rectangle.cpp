#include <bits/stdc++.h>
using namespace std;

// I'am you (largest rectangle in histogram) but with a for-loop!

// Iterate in each row, and consider that row to be the base or refrerence level, taking it as a level, consider histograms of different sizes. If any element is 0, consider the height as 0, as we want histograms to be from the reference level, else use the technique of prefixSum to compute the total height of the histogram from top to this reference level.

// After finding a array which contains the heights of the histogram of different heihgt for that row number, use the same code for the previous question to find the max area in the histogram till here

//. T.C -> O(2*col * row)
//. S.C -> O(2col), as at our peak we used only O(col) space compleixty for the stack. We are discarding the stack after we used it. Another O(col) for the arr used in the main function

// Most optimal code for finding maximum area in a Histogram
int maxAreaInLinearArray(vector<int>& heights) {

    int n = heights.size();
    stack<int>st;

    int ans = 0;

    for (int i = 0; i < n; i++) {

        int incoming = heights[i];

        while(!st.empty() && heights[st.top()] >= incoming) {


            int nseOfTop = i;
            int heightOfElement = heights[st.top()];

            st.pop();

        
            int pseOfTop = -1; 
            if (!st.empty()) pseOfTop = st.top();

            int area = heightOfElement * (nseOfTop - pseOfTop - 1);

            ans = max(area, ans);
        }
        
        st.push(i);

    }

    while(!st.empty()) {

        int nseOfTop = n;
        int heightOfElement = heights[st.top()];

        st.pop();

        int pseOfTop = -1;
        if (!st.empty()) pseOfTop = st.top();

        int area = heightOfElement * (nseOfTop - pseOfTop - 1);

        ans = max(area, ans);

    }

    return ans;

}

int optimalApproach(vector<vector<char>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        int ans = 0;

        // This is the array of heights in the histogram
        vector<int> arr(col, 0);

        for (int i = 0; i < row; i++) {

            for (int j = 0; j < col; j++) {

                int elem = matrix[i][j] - '0';

                // Using the concept of Prefix sum to find the new updated height
                if (elem != 0) {
                    arr[j] = (arr[j] + elem);
                }
                else arr[j] = 0; // When the element at reference is 0, make the total height from the bottom for that histogram also as 0
            }

            ans = max(ans, maxAreaInLinearArray(arr));

        }

        return ans;
        
}