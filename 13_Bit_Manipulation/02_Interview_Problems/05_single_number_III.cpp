#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Use map to find the freq and then find the required numbers

//* Method - II (Optimal Solution)
// Find the XOR of all the elements and find the position of the first set-bit from the end in the result. Then divide the numbers on the basis of set-bit at that position. Find the xor of these both divisions, since same numebrs will cancel out each other and the single number will be left out

//. T.C -> O(n)
//. S.C -> O(1)
vector<int> singleNumber(vector<int>& nums) {

    int XOR = 0;
    for (auto elem : nums) {
        XOR ^= elem;
    }

    // Position of the first set-bit from the end
    int diffBit = 0;
    while(!(XOR&1)) {

        XOR = XOR >> 1;
        diffBit++;

    }

    int num1 = 0, num2 = 0;
    for (auto elem : nums) {
        if ((elem & (1 << diffBit)) != 0) num1 ^= elem;
        else num2 ^= elem;
    }

    return {num1, num2};
    
}