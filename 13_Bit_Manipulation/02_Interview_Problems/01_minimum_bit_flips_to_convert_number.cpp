#include <bits/stdc++.h>
using namespace std;

// XORing, gives 1 bit at places where we have to reverse the bits, then just count the set bit in the resultant num using the optimal approach (Brian Kernighan's Algorithm) for counting set-bits in a number

//. T.C -> O(k), where k is the number of set-bits in start^goal
//. S.C -> O(1)
int minBitFlips(int start, int goal) {

    int num = start^goal;

    int ans = 0;

    // Optimised approach for counting set-bits
    while(num) {
        num = num&(num-1);
        ans++;
    }

    return ans;
        
}