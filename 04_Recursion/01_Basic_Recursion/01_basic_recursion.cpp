#include <bits/stdc++.h>
using namespace std;

int cnt = 0; // We can also use global variable to do stuffs!


//* Recursive Function
//. T.C -> O(n)
//. S.C -> O(n)
// Space Complexity is measured by the stack space here. At the worst case, n functions were in the stack space!
void printNames(int i, int n) {
    if (i > n) return; // Base Condition/Case

    cout << "prana-W" << endl;

    printNames(i+1, n);
}

// Here Print is before the recursion call
// {5, 4, 3, 2, 1}
void linearDescendingPrint (int i, int n) {

    // Pass (n, n) in the main function call
    if (i <= 0) return;

    cout << i << endl;

    linearDescendingPrint(i-1, n);
}


//* Backtracking

// Problem: Print numbers in ascending without using the + operator

// Here print is after the recursion call
// {1, 2, 3, 4, 5}
void printNumbersBacktracking(int i, int n) {

    // Pass (n, n) in the main function call
    if (i <= 0) return;

    printNumbersBacktracking(i-1, n);

    cout << i << endl;

}

// Problem: Print numbers in descending using Backtracking (print statement after the recursive call)
void printDescendingNumbersBacktracking(int i, int n) {
    if (i > n) return; // Take (1, n) as the argument from main call
    printDescendingNumbersBacktracking (i+1, n);
    cout << i << endl;
}

int main () {

    int n;
    cin >> n;

    printNumbersBacktracking(n, n);
    printDescendingNumbersBacktracking(1, n);
}