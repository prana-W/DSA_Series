#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Find naively the xor of the range

//. T.C -> O(r-l+1)
//. S.C -> O(1)

//* Method - II (Optimal Approach)

// Make a function that gives the output as the XOR_till_n, now do the xor_till_(l-1) ^ xor_till_r, if xor_till_(l-1) = x and xor_from_l_to_r is y, then total will be x ^ (x^y) -> y, here x^y is the xor till r

//. T.C -> O(1)
//. S.C -> O(1)

int XORtillN(int n) {
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n+1;
    if(n % 4 == 3) return 0;
    return n;
}
    
int optimal(int l, int r){			
    return XORtillN(l-1) ^ XORtillN(r);
}