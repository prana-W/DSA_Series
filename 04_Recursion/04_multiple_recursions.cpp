#include <bits/stdc++.h>
using namespace std;

// Problem 1: Fibonacci Number

// Both the recursion calls here won't be happening simulatenoulsy! First the fibonacci (n-1) will be calculated and then the fiboncci (n-2)
//. T.C -> About O(2^n) or exponential
int fibonacci (int n) {
    if (n <= 1) return n; 

    int last = fibonacci(n-1);
    int secondLast = fibonacci(n-2);

    return last + secondLast;

}


int main () {
    int n;
    cin >> n;

    cout << fibonacci (n) << endl;
}