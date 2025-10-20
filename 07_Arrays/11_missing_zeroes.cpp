#include <bits/stdc++.h>
using namespace std;

// Problem:1 Find the number missing in the array (n-1 elements in the array, Total element should have been n, find the missing one)

//* Method - I (Brute Force)
// Brute force through all the possible values and again loopo through the array, if found toggle the flag and move on, else break and report that as the answer

void bruteForceFindMissing (int n, int arr[]) {

    // Iterate thorugh all the values that the array should had
    for (int i = 1; i <= n; i++) {
        bool flag = false;

        // Iterate through the entire array
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                flag = true; // If found, put flag as true
                break;
            }
        }

        if (!flag) {
            cout << i << endl;
            break;
        }
    }
}


//* Method - II (Better Solution) 
// Use Hashing. Make an array of N size, and then iterate thorugh the given array, whatever value is found, make it true or 1 in the Hash Array, the one with false or 0 value in the Hash is the missing element

//. T.C -> O(2*n)
//. S.C -> O(n), extra space for the hashArr
void betterFindMissing (int n, int arr[]) {
    vector<int>hashArr(n+1, 0);

    for (int i = 0; i < n; i++) {
        hashArr[arr[i] - 1] = 1;
    }

    for (int i = 0; i < n+1; i++) {
        if (hashArr[i] == 0) {
            cout << i+1 << endl;
            break;
        }
    }
}


//* Method - III (Optimal Solution)

//* Sum Method
// Find the total sum of the ideal array using maths, and then subtract the total sum of the actual array, whatever we get is the answer

//. T.C -> O(n)
//. S.C -> O(1)
void optimalSumMethod (int n, int arr[]) {
    int expectedSum = (n)*(n+1)/2;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int ans = expectedSum - sum;

    cout << ans << endl;
    
}

//* XOR Method
// Find the total XOR of the ideal array along with all the elements of the array, the final result will be the answer

//! Slightly better than the Sum method
// As if the number is very big, and we multiply it by n+1 in the sum method, it might overflow from the limit of the int. Hence, XOR method is much more better approach

void optimalXORMethod (int n, vector<int>arr) {

    int xor1 = 0; // total xor of the ideal array

    for (int i = 1; i <= n; i++) {
        xor1 ^= i;
    }

    int xor2 = 0; // total xor of the given array

    for (auto elem : arr) {
        xor2 ^= elem;
    }

    int ans = xor1 ^ xor2;

    cout << ans << endl;

    // We can also make a single loop and xor the entire into one and improve the time complexity


}