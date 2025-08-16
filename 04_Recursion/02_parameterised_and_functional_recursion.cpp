#include <bits/stdc++.h>
using namespace std;

//! Recursion
// There are two types of recursion: Parameterised and Functional

// Problem1: Sum of first n natural numbers
// Problem2: Factorial of a number

//* Parameterised Recursion
// Parameterized recursion is a technique where a recursive function includes additional parameters to manage and track the state or progress of the computation.

//! Here sum is the parameter that is storing the result of the problem
void printSumParameterisedRecursion (int i, int sum = 0) {

    // We have passed n in the main function
    if (i < 1) {
        cout << sum << endl;
        return;
    }

    printSumParameterisedRecursion(i-1, sum+i);

}

//! Here fact is the parameter that is storing the result of the problem
void factorialParameterisedRecursion (int i, int fact = 1) {

    // We pass n
    if (i == 0) {
        cout << fact << endl;
        return;
    } 

    factorialParameterisedRecursion(i-1, fact*i);
}

//* Functional Recursion
// Functional recursion is a programming technique where a function calls itself to solve a problem, often breaking it down into smaller, self-similar subproblems.
// Use this if we have to actually return a value. Instead of printing anything
int printSumFunctionalRecursion(int n) {
    if (n == 0) return 0; // Base Condition

    return (n + printSumFunctionalRecursion(n-1));
}

//. T.C -> O(n)
//. S.C/Auxiallary Space ->  O(n)
// In stack space n space will be taken.
int factorialFunctionalRecursion(int n) {
    if (n == 0) return 1;

    return n * factorialFunctionalRecursion(n-1);
}

int main () {
    int n;
    cin >> n;

    printSumParameterisedRecursion(n, 0);
    cout << printSumFunctionalRecursion(n) << endl;

    factorialParameterisedRecursion(n);
    cout << factorialFunctionalRecursion(n) << endl;

}
