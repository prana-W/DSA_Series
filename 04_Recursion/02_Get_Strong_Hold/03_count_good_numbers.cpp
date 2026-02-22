#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force, Recursive Approach)
// Make a recursive function that take the index of the string. It goes to that index and considers all the option for that index and calls the recursive function to calculate the total possiblityies in next index

// Example: for n = 3

// Initially, i = 0: ___, first it considers 0 at index 0, then calculates for the next index and adds the result, then it considers 2 at index 0 and calculates total result for next index and so on.

// One Line: Go to each index. If index if even, then there are 5 possiblity for that index, multiply it with the result for i+1 index. If index is odd, there are 4 possiblity for that index and multiply that with the next index result

//. T.C -> O(n)
//. S.C -> O(n), due to recursive stack space

int count(long long index, long long n) {

        long long MOD = 1e9 + 7;

        // If index reaches the end, just return 1 for it to be multiplied with rpevious results to maintain the answer
        if (index == n) return 1;

        long long result;
        
        // Get the result for the next index
        long long nextCount = count(index+1, n);

        if (index%2 == 0) result = (5*nextCount)%MOD;
        else result = (4*nextCount)%MOD;

        return result%MOD;
}

int brute(long long n) {
        return count(0, n);    
}

//* Method - II (Optimal, non-recursive approach)
//! Fast Exponentiation - Binary Exponentiation
// Use PnC, for every odd index we have 4 possiblity and for every even index we have 5 possiblity. Note: Leading zeroes is allowed

// Use previous problem's iterative optimal approach to calculate the power() of any number in the most optimal way

//. T.C -> O(log(n)), for calculating power
//. S.C -> O(1)

long long power(long long x, long long n) {

        long long modulo = 1e9 + 7;

        if (n == 0) return 1;

        long long ans = 1;

        while(n) {
            if (n%2 == 0) {
                x = (x*x)%modulo;
                n /= 2;
            }
            else {
                ans = (ans*x)%modulo;
                n--;
            }
        } 

        return ans%modulo;
}

int iterativeOptimal(long long n) {

        long long modulo = 1e9 + 7;

        long long odd = n/2;
        long long even = n-odd;

        long long ans = (power(4, odd)%modulo) * (power(5, even)%modulo);

        return ans%modulo;
        
}

//* Method - III (Recursive Approach)
//! Fast Exponentiation - Binary Exponentiation
// Just calculate power using Recursive optimal approach, rest is same
//. T.C -> O(log(n))
//. S.C -> O(log(n)), due to recursive space for calculating the power
