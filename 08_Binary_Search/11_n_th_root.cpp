#include <bits/stdc++.h>
using namespace std;

// Problem: Find the nth root of m. If the value is not integer, return -1

//* Method - I (Brute Force)

// O(m*log(n))
int bruteForce(int n, int m) {

    for (int i = 0; i <= m; i++) {

        // pow() takes log(n) time. We can also make a custom function to work in O(n) time for calculationg the power to further increase the TC
        if (pow(i, n) == m) return i;
        else if (pow(i, n) > m) break; // we have exceeded our answer
    }

    return -1;
}

//! NOTE: pow(a, b) takes log(b) time complexity in most complilers!!!

//* Method - II (Better Solution)
//! Binary Search on answer

//. T.C -> O(log(m) * log(n))
int betterSolution(int n, int m) {

     int low = 0, high = m;
        
        while (low <= high) {
            int mid = (low+high)/2;
            
            int val = pow(mid, n); //! this uses log(n)
            
            if (val == m) return mid;
            else if (val < m) low = mid+1;
            else high = mid-1;
        }
        
        return -1;
}

// if n = 10 and m = 10^9, then using the pow() function or even custom binary exponenetila funciton: mid1 =(approx.) (10^9 / 2)^10, which =(approx.) 10^90!!
// So there are cases we are calculating powers so hgih, it can't be stored in any variable!!! Hence instead of pow() or binary exponentiation, we could use a simple linear search on n trying to raise the power one by one, and the moment it exceeds our desired result, we break and simply eliminate the right part

//* Method - III (Best Solution)

// if mid^n exceeds m, it return 2
// if mid^n ==  m, it returns 1
// if mid^n < m, it returns 0

//. T.C of entire solution -> O(x * log(m)), x = Total TC of customCheckFunction 


int customCheckFunction(int mid, int n, int m) {
    long long ans = 1;

    for (int i = 1; i <= n; i++) {
        ans *= mid;
        if (ans > m) return 2;
    }

    if (ans == m) return 1;
    return 0;
}
int bestSolution(int n, int m) {
    int low = 0, high = m;

    while (low <= high) {
        int mid = (low + high)/2;

        int checkFlag = customCheckFunction(mid, n, m);

        if (checkFlag == 1) return mid;
        else if (checkFlag == 0) low = mid+1;
        else high = mid-1; // if checkFlag = 2
    }

    return -1;
}