#include <bits/stdc++.h>
using namespace std;

// Problem: Next dictority order of the given permutation. Fallback to the first order if we are at the last order

//! NOTE: Here Permutation just means an array of elements, it has nothing to do with the permutation we are familiar from CodeForces or simlilar problems!!!

//* Method - I (Brute Force)

// Generate all the permutations in a sorted order, then iterate and search for the given permutation and return the next index if exists, else return the first index.

// Generation of the permutations can be made using Recursion  

//. T.C -> O(n! * n), n! is the total number of permutation and n is the number of elements inside it

// Since, this will reach very higher order even at small values of n, we will avoid going deeper into it. Watch L-12 and L-13 from the Recursion playlist of Striver.

//* Method - hmmm?? (Better Solution using C++ STL)

// We can use next_permutation(arr.begin(), arr.end()), which converts the arr into next_permutation, and we simply return arr. But we have to implement this algorithm, which we do in the next method

//* Method - II (Optimal Solution)

//. T.C -> O(3*n)
//. S.C -> O(1) as no extra space is used
void optimalNextPermutation(int n, int arr[]) {
    int ind = -1; // initially the index of the dip 

    for (int i = n-2; i >= 0; i--) {
        if (arr[i] < arr[i+1]) {
            ind = i;
            break;
        }
    }

    // When the permutation is at last order, or the permutation is in descending order, so we return the first permutation, since the next doesn't exist in this case
    if (ind == -1) {
        reverse(arr, arr+n);
        return;
    }

    for (int i = n-1; i >= ind; i--) {
        
        // This will be the point where an element which is smallest and also greater then arr[ind] will exist
        if (arr[i] > arr[ind]) {
            swap(arr[i], arr[ind]);
            break;
        }
    }

    reverse(arr+ind+1, arr+n); // the remaining part now will be in descending order, so simply reverse that to get the sorted order


}