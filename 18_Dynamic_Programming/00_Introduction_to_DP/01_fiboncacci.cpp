#include <bits/stdc++.h>
using namespace std;

//* Method - I (Normal Recursive)

//. T.C -> O(2^n), approx.
//. S.C -> O(n), due to recursive stack space
int fibonacci(int n) {
    if (n <= 1) return n;

    return fibonacci(n-1) + fibonacci(n-2);
}

//* Method - II (DP using Memoization)
//! Recursive Approach
// First declare a dp array of size (n+1), then store the value of each subproblem in the array, then before recalculating the result, check if it exists in the dp array and then continue 

//. T.C -> O(n)
//. S.C -> O(n + n), dp array and recursive stack space
int fib(int n, vector<int>& dp) {
    if (n <= 1) return n;

    // Check if the value  of sub-problem already exists
    if (dp[n] != -1) return dp[n];

    // Storing the value of the subproblem and then returning
    return (dp[n] = fib(n-1, dp) + fib(n-2, dp));
}

int main() {
    int n;
    cin >> n;

    // Declare a dp array of size (n+1) and initialise with -1
    vector<int>dp(n+1, -1);
    cout << fib(n, dp) << endl;
}

//* Method - III (DP using Tabulation, Naive)
//! Iterative Approach

//. T.C -> O(n)
//. S.C -> O(n), O(n) for dp array, no recursive stack space required here
int fibTabulation(int n) {

    vector<int>dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

//* Method - III.V (Tabulation, Optimised)
// Since only previous two values are required at each step, instead of storing the result in an array, just use two variables and return the final answer

//. T.C -> O(n)
//. S.C -> O(1), optimised by not using an array at all
int fibTabulationOptimised(int n) {

    int prev2 = 0;
    int prev = 1;

    for (int i = 2; i <= n; i++) {
        int curr = prev+prev2;

        prev2 = prev;
        prev = curr;
    }

    return prev;

}