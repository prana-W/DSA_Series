#include <bits/stdc++.h>
using namespace std;

// We use similar concept of NSE and PSE

//* Method - I (Brute Force)
// Generate all the dsubarrays, find the minimum of it, and then do (mini * size of subarray). Since in a subarray, the area would be the minimum height, times the total length wihich will give the largest area of that part.

//. T.C -> O(n^2)
//. S.C -> O(1)
int bruteForce(vector<int>& arr) {
    int n = arr.size();

    int ans = 0;

    for (int i = 0; i < n; i++) {

        int minHeight = arr[i];

        for (int j = i; j < n; j++) {

            // Finding area of the rectangle in this subarray (i, j)
            minHeight = min(minHeight, arr[j]);

            int width = j-i+1;
            int area = minHeight * width;

            ans = max(ans, area);

        }
    }

    return ans;
}

//* Method - II (Optimal Approach I)
// Since we are only concerend with the minimum element in a subarray, we can use the concept of NSE and PSE. 

// For the input array, precompute the NSE and PSE (Previous smaller element), (Note: We don't need equal, as we will be calculating the equal height element as well in the area)

// All the elements in between PSE and NSE of any elements have the minimum element as the element as welll. We can determine the size of this subarray using indices and multiple that with the minimum element to find the area of rectangle in this subarray

//. T.C -> O(5n), O(2n) for each NSE and PSE and O(n) for the final pass
//. S.C -> O(4n), we can optimise this by using a single stack and then emptying that and reusing that

vector<int>nextSmaller(vector<int>& arr) {

    int n = arr.size();
    stack<int>st;

    vector<int>nse(n, n);

    for (int i = n-1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {

            st.pop();

        }

        if (!st.empty() && arr[st.top()] < arr[i]) {
            nse[i] = st.top();
        }

        st.push(i);
    }

    return nse;
        
}

vector<int>previousSmaller(vector<int>& arr) {

    int n = arr.size();
    stack<int>st;

    vector<int>pse(n, -1);

    for (int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (!st.empty() && arr[st.top()] < arr[i]) {
            pse[i] = st.top();
        }

        st.push(i);
    }

    return pse;
        
}

int optimalApproachI(vector<int>& heights) {

    int n = heights.size();

    int ans = 0;

    vector<int>nse = nextSmaller(heights);
    vector<int>pse = previousSmaller(heights);

    for (int i = 0; i < n; i++) {
        int sizeOfSubarray = (nse[i] - pse[i] - 1);

        int area = sizeOfSubarray*heights[i];

        ans = max(ans, area);
    }

    return ans;
        
}

//* Method - II.V (Most Optimal Approach II)
//! Single-Pass Solution (no pre-computation)

// Iterate the array from the left and find the PSE as usually we did.

// If st.top() is greater than incoming, then we pop the top(). In another words, incoming is the NSE with respect to st.top(). Hence for evry element we pop out beore inserting incoming, then for all those popped element, the incoming is the NSE. If already knew PSE, now we can easily compute the areas by (element * (nse-pse-1))

// Hence, while iterating from the left, we find PSE and also we can get the NSE from the previous elements when poping out. Hence we can compute the area in a single pass

//. T.C -> O(2n)
//. S.C -> O(n), O(n) only for the stack used.

//! Note: PSE is not stored in a vector for improving S.C

// PSE of any element in the stack, is the element below it.

// Here, index of PSE of any element in the stack, is the index below it
int mostOptimalApproach(vector<int>& heights) {

    int n = heights.size();
    stack<int>st;

    int ans = 0;

    for (int i = 0; i < n; i++) {

        int incoming = heights[i];

        while(!st.empty() && heights[st.top()] >= incoming) {

            // Finding answer for the top(), before popping it

            // Incoming is the NSE for top, hence index is 'i'
            int nseOfTop = i;
            int heightOfElement = heights[st.top()];

            st.pop();

            // PSE of the top is the element below it
            int pseOfTop = -1; // Initialsed by -1, if empty
            if (!st.empty()) pseOfTop = st.top();

            int area = heightOfElement * (nseOfTop - pseOfTop - 1);

            ans = max(area, ans);
        }
        
        st.push(i);

    }

    // To calculate for the remianing of the elements which were never poped
    // All these elements have the NSE at 'n', hypothetical bar
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