#include <bits/stdc++.h>
using namespace std;

//! Hamming Weight

//* Method - I (Brute Force)
// Go to each bit and count it

//. T.C -> O(log(n))
//. S.C -> O(1)
int bruteForce(int n) {

        int ans = 0;

        while (n) {
            if (n&1) ans++;
            n = n >> 1;
        }

        return ans;
        
}

//* Method - II (Optimal Approch)
//! Brian Kernighan's Algorithm

// If we do n&(n-1) then it will make all the bits from the first set bit (from the right) till the end as 0, hence if we do this k times, the final number would become 0, where k is the number of set bit.

// Hence just do n&(n-1) each time till n becomes 0, this is the number of times '1' bit is present in the number

//. T.C -> O(k), where k is the number of set-bit, which will definitely be less than log(n)
//. S.C -> O(1)
int optimalApproach(int n) {

        int ans = 0;

        while(n) {
            n = (n&(n-1));
            ans++;
        }

        return ans;
        
}

//! If number of set bits is only one, then it is of power of 2, this is what we did for the previous question. We do n&(n-1) once and check if it becomes 0, if it does, it mean that only one '1' bit was in the nummber, hence making the number of the power of two, else it ain't that.