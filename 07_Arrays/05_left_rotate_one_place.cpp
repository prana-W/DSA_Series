#include <bits/stdc++.h>
using namespace std;

// Problem: Rotate an array to its left by one place

//* Optimal Solution

//* Method - I (my method)
void leftRotateOptimalMyMethod(int n, int arr[]) {
    for (int i = 0; i < n-1; i++) {
        swap(arr[i], arr[i+1]);
    }
}


//* Method - II (sir method) 
//. T.C -> O(n)
//. S.C -> O(1) as no extra space is used, but can be said O(n)
//! O(n) since actually we are using an array (but it is part of our question), so we can consider O(1) as extra space used.
//! Always be clear about this subtle difference between extra space used vs actual space used

void leftRotateOptimal(int n, int arr[]) {
    int temp = arr[0]; // store the first array element

    // Left shift all the elements
    for (int i = 1; i < n; i++) {
        arr[i-1] = arr[i];
    }

    // Place the first element at the last
    arr[n-1] = temp;
}


int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    leftRotateOptimal(5, arr);

    for (auto element:arr) {
        cout << element << " ";
    }
}