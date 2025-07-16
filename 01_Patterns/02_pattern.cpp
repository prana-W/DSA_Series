// https://www.naukri.com/code360/problems/ninja-and-the-number-pattern-i_6581959

#include <bits/stdc++.h>
using namespace std;

//* In this probelem, we first subtract all the values from n. (n - given = newValue)

// Then the newValue we get will be the minimum distance from (left, right, top and bottom of that element)

// Example: If a element is at (2, 3), 0-based indexing, then the distances are 3, 4, 3, 2, minimum of which is 2 and that's our currentValue at the index.

// https://www.youtube.com/watch?v=tNm_NNSB3_w at 1:16:11


int main () {

    int n;
    cin >> n;
    

    for (int i = 1; i <= 2*n-1; i++) {
        for (int j = 1; j <= 2*n-1; j++) {

            int top = i-1;
            int right = 2*n-1-j;
            int bottom = 2*n-1-i;
            int left = j-1;

            // int arr[4] = {top, right, bottom, left};

            // int mini = INT_MAX;
            // for (int k = 0; k < 4; k++) {

            //     if (arr[k] < mini) mini = arr[k];

            // }

            int mini = min (min (top, bottom), min (right, left)); //* This is a short-hand way to do the same as above

            //* In our mind we didi (n - given = curr), so to mini is our curr, to get our given/required, we do (n - curr)

            cout << n-mini;
            

        }
        cout << endl;
    }

}