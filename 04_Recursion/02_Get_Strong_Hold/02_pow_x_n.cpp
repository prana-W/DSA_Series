#include <bits/stdc++.h>
using namespace std;

//* Method - I (Iterative and Brute)
// If n is negative, make it postive and take the reciprocal of x. If n is INT_MIN, we ight face problem in making it positive directly, hence in that case we handle it seperately. Also handle cases when x is 1 or -1. At the end, just make a loop and multiply ans with x for n times

//. T.C -> O(n)
//. S.C -> O(1)
double bruteIterative(double x, int n) {

        if (x == 1) return 1;
        if (x == -1 && n&1) return -1;
        if (x == -1 && n&1 == 0) return 1;

        if (n == INT_MIN) {
            x = (1/x) * (1/x);

            n = (n+1);
            n = -n;
        }
        else if (n < 0) {
            x = 1/x;
            n = -n;
        }

        double ans = 1;

        while(n) {

            ans *= x;
            n--;

            //! For improving time complexity
            if (ans == 0) return ans;

        }

        return ans;
        
}

//* Method - II (Iterative and Optimal)
//! Fast Exponentiation - Binary Exponentiation
// Concept: 5^10 == (5^2)^5 == 25^5
// If n is even, we can make x = (x*x) and half our n (n = n/2), this can save us a lot of iterations, as the n becomes half instantly.
// If n is odd, just do like the above method 5^9 = 5 * 5^8

//. T.C -> O(log(n)), due to n becoming half each time
//. S.C -> O(1)
double iterativeOptimal(double x, int n) {

        if (x == 1 || (x == -1 && n%2 == 0)) return 1;
        if (x == -1 && n&1) return -1;

        if (n == INT_MIN) {
            x = (1/x) * (1/x);

            n = (n+1);
            n = -n;
        }
        else if (n < 0) {
            x = 1/x;
            n = -n;
        }

        double ans = 1;

        while(n) {

            // If n is even, make x = x*x i.e. square the x and half the power
            if (n%2 == 0) {
                x *= x;
                n /= 2;
            }

            ans *= x;
            n--;

            // To avoid unncessary iterations, when ans becomes already 0
            if (ans == 0) return ans;

        }

        return ans;
        
}

//* Method - III (Recursive and Optimal)
//! Fast Exponentiation - Binary Exponentiation
// Do the above iterative approach using recursion

//. T.C -> O(log(n)), due to n becoming half each time
//. S.C -> O(log(n)), due to recurisve stack space

double recursiveFun(double x, int n) {

        // Edge case
        if (n == 0) return 1;

        // When n is odd, we just multiply normally with a lower power
        if (n&1) return (x * pow(x, n-1));

        // For even power, we do our trick
        return pow(x*x, n/2);
}

double recursiveOptimal(double x, int n) {

        // Sanitation of x and n (Handling edge cases and making n always positive)

        if (x == 1 || (x == -1 && n%2 == 0)) return 1;
        if (x == -1 && n&1) return -1;
        if (n == INT_MIN) {
            x = (1/x) * (1/x);

            n = (n+1);
            n = -n;
        }
        else if (n < 0) {
            x = 1/x;
            n = -n;
        }

        return recursiveFun(x, n);
        
}