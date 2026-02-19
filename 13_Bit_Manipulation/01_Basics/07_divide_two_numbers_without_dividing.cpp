#include <bits/stdc++.h>
using namespace std;

//! Remeber: INT_MIN = -2^31 and INT_MAX = 2^31 - 1

//* Method - I (Brute Force)
//! Repetitive Subtraction

// First decide the sign, make both dividend and divisor as absolute and then do repetitive subtraction and then make it of required sign and then return the final answer. Keep some edge cases in mind, like check for INT_MIN before converting to absoloute values etc.

//. T.C -> O(dividend/divisor)
//. S.C -> O(1)
int bruteForce(int dividend, int divisor) { 

        int sign = -1;
        int ans = 0;

        // Decide sign
        if ((dividend >= 0 && divisor > 0) || (dividend < 0 && divisor < 0)) sign = 1;

        // Before making dividend and divisor to absolute value, checking if they are not INT_MIN

        // Do this, to subtract one time divisor and make it possible for abs(dividend) to exist in 'int'
        if (dividend == INT_MIN && divisor != INT_MIN) {
            dividend += abs(divisor);
            ans++;
        }
        else if (divisor == INT_MIN && dividend != INT_MIN) return 0;
        else if (divisor == INT_MIN && dividend == INT_MIN) return 1;

        dividend = abs(dividend);
        divisor = abs(divisor);

        // Repetitive Subtraction
        while(dividend >= 0 && dividend >= divisor) {
            dividend -= divisor;
            if (ans == INT_MAX && sign == 1) return INT_MAX;
            else if (ans == INT_MAX && sign == -1) return INT_MIN;
            ans++;
        }

        if (sign == -1) ans = -ans;

        return ans;        
}

//* Method - II (Optimal Solution)

// dividend = quotient*divisor + remainder. We need to find quotient. In repititve subtraction, we find quotient one-by-one. quotient is the number of divisors removed from the dividend

// Since any number can be represented as the summation of the terms in the powers of 2 (binary to integer), we can try to remove divisor in powers of 2, and during each step we will try to remove the largest power of two.

// Instead of removing divisor at each step, we remove divisor in terms of power of 2. So find the maximum multiple of divisor with power of 2 that can be done to still make dividend greater than or equal to that number and then reduce the dividend and also we remove divisor by that power of two times, hence making the divison much more quicker

// Outer loop for log(n), as dividend is decresing in powers of two, also the inner loop will run for log(n) to find the maximum power

//. T.C -> O((log(n))^2), approximate
//. S.C -> O(1)

// To not use long long int, we have to use multiple if-else statements to bypass the abs() at INT_MIN edge case and other edge cases as well
int optimalApproach(int dividend, int divisor) {

    bool isPositive = false;

    long long ans = 0;

    long long num = dividend;
    long long den = divisor;

    if ((num >= 0 && den > 0) || (num < 0 && den < 0)) isPositive = true;

    num = abs(num);
    den = abs(den);

    while(num >= den) {

        // This is what will be subtracted (removed) from the dividend
        long long temp = den;

        // This is the power of 2, which is removed from the dividend
        int removed = 0;

        while(temp <= num) {
            temp = temp << 1;
            removed++; 
        }

        // To get back to track
        temp = temp >> 1;
        removed--;

        num -= temp;

        // If removed == 31, it means to be removed power of two will be at max (-2^31), hence just clamp at the extremes
        if (removed >= 31 && isPositive) return INT_MAX;
        if (removed >= 31 && !isPositive) return INT_MIN;

        // To find the power of 2
        ans += (1 << removed);
        
    }

    if (!isPositive) ans = -ans;

    if (ans >= INT_MAX) return INT_MAX;
    if (ans <= INT_MIN) return INT_MIN;

    return ans;
        
}