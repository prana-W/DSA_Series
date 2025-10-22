#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Problem: Find the length of the longest subarray which has the sum equal to k.

//* Method - IA (Brute Force for all types of elements)
// Generate all the subarrays possible and find the sum of all of them and compare with the 'k'

// For extreme brute, we will have two pointers i and j, every element between them will be the part of our subarray, then we will find the sum of that sub-array with another loop. Giving us:

//. T.C -> O(n^3)
//. S.C -> O(1)
void extremeBruteForce (int n, int arr[], int k) {

    int ans = 0;

    // For the first pointer
    for (int i = 0; i < n; i++) {
        // For the second pointer
        for (int j = i; j < n; j++) {
            
            // Evrything within this will be the subarray

            int sum = 0;

            // Find the sum of the subarray
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            if (sum == k) {
                ans = max(ans, j-i+1);
            }
        }
    }


    cout << ans << endl;
}

//* Method - IB (Brute Force for all types of elements)

// Now we will optimise the extremebruteForce
// We will keep a track of the sum while moving j itself

//. T.C -> O(n^2)
//. S.C -> O(1)
void bruteForce (int n, int arr[], int k) {

   int ans = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                
                if (sum == k) {
                    ans = max(ans, j-i+1);
                }
            }
        }
        

        cout << ans << endl;
}


//* Method - II (Better Solution for non-negative integers and optimal for both positives and negatives)
// Hashing

//. T.C -> O(n*log(N)) for ordered map and O(n) or O(n*N) if unordered map, generally n = N, if there are no zeroes
//. S.C -> O(n) when all the elements will have a unique prefixSum

//! Below for both postives and negatives

//! The below is a better solution for non-negative numbers and optimal for both positive and negative integers

void solution (vector<int>arr, ll k) {

    map<ll, int>prefixSumMap;

    ll sum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if (sum == k) {
            maxLen = max(maxLen, i+1);
        }

        ll remaining = sum-k;

        // Check if x-k exists in the prefixMapSum, if it does, then a subarray of length k will also exist
        if (prefixSumMap.find(remaining) != prefixSumMap.end()) {

            int len = i-prefixSumMap[remaining];

            maxLen = max(maxLen, len);

        }

        //! If there are no zeroes in the array and only positive elements, we could remove the if condition and directly update the prefixSumMap, but btelow ensures the the presfixSum is updated only once when it appears, as we want the length of the prefixSum to be the smallest, so that the length of the subarray with k is largest
        if(prefixSumMap.find(sum) == prefixSumMap.end()) prefixSumMap[sum] = i;
    }


    cout << maxLen << endl;

}
 


//* Method - III (Optimal solution for non-negative)
// Two-Pointer
//! Works only for postivies and zeroes. For postives + negative elements, method-II was the optimal solution


//. T.C -> O(2*n)
//. S.C -> O(1)
void optimalForPostives (vector<int>arr, ll k) {
    int left = 0, right = 0;

    ll sum = 0;
    int maxLen = 0;

    int n = arr.size();

    while (right < n) {
        while (sum > k && left <= right) {
            sum -= arr[left];
            left++;
        }

        if (sum == k) {
            maxLen = max(maxLen, right-left+1);
        }

        right++;
        
        if (right < n) sum += arr[right];
    }


    cout << maxLen << endl;


}