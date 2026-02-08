#include <bits/stdc++.h>
using namespace std;

//* Problem - 1: Integer (Decimal) to Binary

//. T.C -> O(log(n))
//. S.C -> O(log(n))
string decimalToBinary(int num) {
    string ans;

    while(num) {
        int rem = num%2;

        ans += (rem + '0'); // Add the remainder

        num /= 2;
    }

    // Reverse the final string
    reverse(ans.begin(), ans.end());

    return ans;
}

//* Problem - II Binary to Decimal

//. T.C -> O(n)
//. S.C -> O(1)

//! If the most significant bit is signed (i.e. it is 1), then we first need to convert it into its 2s complment and then convert it to decimal and report the answer with the negative sign with that number
int binaryToDecimal(string s) {
    reverse(s.begin(), s.end());

    int ans = 0;

    for (int i = 0; i < s.size(); i++) {

        int bit = s[i] - '0';

        ans += (bit * pow(2, i));
    }

    return ans;
}