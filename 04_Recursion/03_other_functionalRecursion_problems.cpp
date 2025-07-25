#include <bits/stdc++.h>
using namespace std;

// Problem 1: Reverse an Array
 
//* Two Pointer with Functional Recursion
void reverseArrayDoublePointer (int *arr, int l, int r) {

    if (l >= r) return; // l is the first index and r is the right index

    swap (arr[l], arr[r]);

    reverseArrayDoublePointer(arr, l+1, r-1);

}

//* Single Pointer with Functional Recursion
void reverseArraySinglePointer (int arr[], int n, int i = 0) {

    if (i >= n/2) return;


    swap (arr[i], arr[n-i-1]);

    reverseArraySinglePointer (arr, n, i+1);

}


// Problem 2: Check if the string is Palindrome

//* Single Pointer with Functional Recursion
//. T.C -> O(n/2)
//. S.C -> O(n/2)
// internal stack space beacuse some operations will be waiting in the stack
bool isPalindrome (string &s, int n, int i = 0) {

    if (i >= n/2) return true;

    if (s[i] != s[n-i-1]) return false;

    return isPalindrome(s, n, i+1);
}

int main () { 

    int myArray[5] = {5, 2, 10, -5, 6};

    reverseArraySinglePointer(myArray, 5);
    // reverseArrayDoublePointer (myArray, 0, 4);

    for (auto element : myArray) {
        cout << element << endl;
    }



    string s = "abba";

    if (isPalindrome(s, s.length())) cout << "Palindrome!" << endl;
    else cout << "Not Palindrome!" << endl;
            
}