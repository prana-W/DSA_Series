#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Problem - 1: Check if two elements from the array exists such that their sum is == target. If exists return YES else NO

// Problem - 2: We are sure that there are two such elements, we need to return the indexes of their index

//* Method - I (Brute Force)
// Pick one element, and then pick all the other elements and so on

//. T.C -> O(n^2)
void brute (int n, int arr[], int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                cout << i << " " << j << endl;
                return;
            }
        }
    }
}


//* Method - II (Better Solution)
// Hash - (elem, index) store the elem with its index in the hash
// Store every element in the hash map like this, then iterate thorugh each element once and try to find k - arr[i], if that is present in the hashMap aprt from that indx itself, it means such a pair exists and then return the answer

//. T.C -> O(n*log(N)) for an ordered map and O(n) or O(n*N) for an unordered_map depending on the number of collisions
//. S.C -> O(N)
void better (int n, int arr[], int target) {

    map<int, int>hashMap;

    // for (int i = 0; i < n; i++) {

    //     hashMap[arr[i]] = i;
        
    // }

    // for (int i = 0; i < n; i++) {
    //     int required = target - arr[i];

    //     // Check if the required element exists and also not equal to the given element for which we are looking for its pair
    //     if (hashMap.find(required) != hashMap.end() && hashMap[required] != i) {
    //         cout << hashMap[required] << " " << i << endl;
    //         return;
    //     }
    // } 

    //! A better code in a single loop
    // This will give the answer when we hit the second pair, at that time, the first pair would already be in the map
    for (int i = 0; i < n; i++) {
        int required = target-arr[i];

        if (hashMap.find(required) != hashMap.end()) {
            cout << hashMap[required] << " " << i << endl;
            return;        
        }

        hashMap[arr[i]] = i;
    }
}

//* Method - III (Slighlty Better)
// Without HashMap, using two pointer

// Sort the array and but one pointer at the start and one pointer at the end
// If the sum of elements in both the index is greater than our target, then reduce the right index, else increase the frist index, till we find our desired pair


//! Below only works for Problem-I (but if we need to return the indices of the element in the original array, before sorting, we need to use another data structure to store the indices and the element together and then do the below procedure)

//. T.C -> O(n*log(n)) + O(n), for sorting + two-pointer approach
//. S.C -> O(1) for no extra space else O(n), as we are using an array
void slightlyBetterApproach (int n, int arr[], int target) {

    // Sorting the array
    sort (arr, arr+n);

    int left = 0, right = n-1;

    while (left < right) {
        int totalSum = arr[left] + arr[right];

        if (totalSum < target) {
            left++;
        }

        else if (totalSum > target) {
            right--;
        }

        else {
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
}