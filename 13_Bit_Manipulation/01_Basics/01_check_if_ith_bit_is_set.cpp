#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Convert the numer into binary string and check for the ith position from the end

//. T.C -> O(log(n)), integer to binary conversion
//. S.C -> O(log(n)), due to storing the binary string

//* Method - II (Optimal Approach I)
// Make the ith bit come at first end. Now if it was set, its AND with 1 would be 1 else 0

//. T.C -> O(1)
//. S.C -> O(1)
bool optimalI(int n, int k) {
        
        n = n >> k;
        
        if (n&1) return true;
        
        return false;
}

//* Method - II.V (Optimal Approach II)
// Simply shift the '1' bit to k th position and AND with the original number, if it is 1, then the kth bit was set

//. T.C -> O(1)
//. S.C -> O(1)
bool optimalII(int n, int k) {
        
        if (n & (1 << k)) return true;
        
        return false;
}