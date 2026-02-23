#include <bits/stdc++.h>
using namespace std;

// Same problem as fibonacci, here just f(0) = f(1) = 1, rest is same

// To reach the top, it has n stiars, so calculate ways to reach the n-1 th step and n-2th step. Move 1 step from n-1th step and 2 steps from n-2th step. Hence f(n) = f(n-1) + f(n-2)

// Also to reach the top with 2 stairs, there is 2 way and to reach the top with 1 stiar, it will 1 way

//* Method - I (Brute)
// Use Naive Recursion
//. T.C -> O(2^n), approx.
//. S.C -> O(n)

//* Method - II (DP, Memoization)
//. T.C -> O(n)
//. S.C -> O(n)

int steps(int n, vector<int>& dp) {

        if (n <= 2) return n;
        if (dp[n] != -1) return dp[n];

        return (dp[n] = (steps(n-1, dp) + steps(n-2, dp)));
}

int memoizationDP(int n) {
        vector<int>dp(n+1, -1);
        return steps(n, dp);
}

//* Method - III (DP, Tabulation, Optimised)
// Use two variables just like in previous problem
//. T.C -> O(n)
//. S.C -> O(1)
int optimisedTabulationDP(int n) {

        if (n <= 2) return n;

        int prev = 2;
        int prev2 = 1;

        for (int i = 3; i <= n; i++) {
            int curr = prev + prev2;

            prev2 = prev;
            prev = curr;
        }

        return prev;
        
}