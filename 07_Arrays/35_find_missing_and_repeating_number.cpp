#include <bits/stdc++.h>
using namespace std;

// Problem: Given an integer of size n, it will have all the integers from 1 to n, except one is missing and one is twice in the array. Example: n = 6; [4 3 6 2 1 1], 5 is missing and 1 is appearing twice

//* Method - I (Extreme Naive Approach)
// Pick every number from 1 to n and check in the array with the loop and check its count to get the missing and repeating number
//. T.C -> O(n^2)
//. S.C -> O(1)

//* Method - II (Better Approach)
//! Hashing
//. T.C -> O(2*n)
//. S.C -> O(n)
// Keep a hash array of size n+1 and intitialize everything to 0, then iterate the input array and incremement the count in the hash array whenever encountered, after the iteration, iterate in the hash array from index 1 to end and check the count of each element

//* Method - III (Sum Optimal Solution)
// Let 'sum' be the sum of the input array and 'sum2' be the sum of the sqaures of the input array, S be the sum of the nubers from 1 to n and S2 be the sum of the squares of the number from 1 to n.

// S = (n)(n+1)/2             
// S2 = (n)(n+1)(2n+1)/6      

// S - sum = (missing - extra)
// S2 - sum2 = (missing^2 - extra^2) = (missing - extra)(missing + extra), get (missing - extra) from equation 1 and find missing + extra

// After this, we can solve the two eqautions to find missing and extra

//. T.C -> O(n)
//. S.C -> O(1)
vector<long long>sumApproach(vector<long long>arr) {

    int n = arr.size();

    long long S = ((n)*(n+1))/ 2;
    long long S2 = ((n)*(n+1)*(2*n+1))/6;

    long long sum = 0, sum2 = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];
        sum2 += (long long)(arr[i])*(long long)(arr[i]);

    }

    long long val1 = S - sum; // (val1 = missing - extra)  ....... (i)
    long long val2 = S2 - sum2; // (val2 = missing^2 - extra^2)

    val2 = val2/val1; // (val2 = missing + extra)   ...... (ii)

    // Solving equation (i) and (ii)

    long long missing = (val1 + val2)/2; 
    long long extra = (missing - val1);

    return {missing, extra};
}

//* Method - IV (XOR Optimal Solution)

//. T.C -> O(n)
//. S.C -> O(1)
vector<long long>xorApproach(vector<long long>arr) {
    int n = arr.size();

    int xr = 0; // finally = (xor of input arr) ^ (xor of all elements from 1 to n)

    for (int i = 0; i < n; i++) {

        xr = xr ^ arr[i];
        xr = xr ^ (i+1);

    }

    int bitPos = 0; // find the first set-bit from right in xr

    while(1) {

        // When xr has a set-bit at bitPos position
        if (xr & (1 << bitPos)) {
            break;
        }
        bitPos++;
    }

    int zero = 0;
    int one = 0;

    for (int i = 0; i < n; i++) {

        //? Below is for the xor of all the i/p elements

        // When arr[i] has a set bit at bitPos position
        if (arr[i] & (1 << bitPos)) {
            one = one^arr[i];
        }
        // When arr[i] has a 0 bit at bitPos position
        else {
            zero = zero^arr[i];
        }


        //? Below, is for the (1 ^ 2 ^ 3 ... n) part

        // When i+1 has a set bit at bitPos position
        if ((i+1) & (1 << bitPos)) {
            one = one^(i+1);
        }
        // When i+1 has a 0 bit at bitPos position
        else {
            zero = zero^(i+1);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == zero) cnt++;
    }

    // If cnt is 2, it means the value inside zero variable was my repeating number
    if (cnt == 2) {
        return {zero, one};
    }
    // it means the value inside one variable was the repeating number
    else return {one, zero};
}

//! Note: We can also generate the number with a 1 bit at the differentiating bit by:

// xr & ~(xr - 1)


