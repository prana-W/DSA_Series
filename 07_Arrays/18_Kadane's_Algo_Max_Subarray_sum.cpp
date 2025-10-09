#include <bits/stdc++.h>
using namespace std;

// Problem: Give me the maximum subarray (contiguos part of the array) sum

//* Method - I (Brute Force)
// Iterate thorugh two pointers, between which we will have all the possible subarrays, and then iterate between those two points to get the sum of that sub array. This could be further optimised as we did in Better Solution, to have only two loops

//. T.C -> O(n^3)
//. S.C -> O(1)
void bruteSolution(int n, int arr[]) {

    int maxSum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;

            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum << endl;
}



//* Method - II (Better Force)
// Get all the possible subarrays and calculate their sum, then find the maximum out of them all


//. T.C -> O(n^2)
//. S.C -> O(1)
void betterSolution(int n, int arr[]) {

    int maxSum = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {

            sum += arr[j];

        }

        maxSum = max(sum, maxSum);
    }

    cout << maxSum << endl;
}

//* Method - III (Optimal Solution)
//! Kandane's Algorithm

//. T.C -> O(n)
//. S.C -> O(1)
//? To find the maximum subarray sum
void optimalFirstVariation(int n, int arr[]) {
    int sum = 0, maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        maxi = max(maxi, sum);

      // Don't carry negativity with you! It's better to be at 0, then be at negativity
        if (sum < 0) {
            sum = 0;
        }


    }

    cout << maxi << endl;
}

//? To find the subarray that has maximum subarray sum
void optimalSecondVariation(int n, int arr[]) {

     int sum = 0, maxi = INT_MIN;
     int start = -1, ansStart = -1, ansEnd = -1;

    for (int i = 0; i < n; i++) {

        // Start the subarray, when the sum becomes zero
        if (sum == 0) start = i;

        sum += arr[i];

       if (sum > maxi) {
        maxi = sum;

        // To keep a track of the subarray
        ansStart = start;
        ansEnd = i;
       }

      // Don't carry negativity with you! It's better to be at 0, then be at negativity
        if (sum < 0) {
            sum = 0;
        }


    }

    cout << ansStart << " " << ansEnd << endl;

}