#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.

//* Method - I (Brute Recursive Approach)
// Generate all the strings possible using similar technique as below and check at the end if valid, this take additional O(n) at the end for checking

//! Total strings that can be created (valid + non-valid) is 2^n and O(n) time taken to create them (as we are iterating to each index) and O(n) for checking if valid or not at the end
//. T.C -> O(2^n * (n + n))
//. S.C -> O(n)

//* Method - II (Optimised Recursive Approach)
// Start with a empty string, then first generate the string with 0 at the back of the string and another function that adds 1 to the back, also make sure the previous index didn't had already '1', becuase then generating a string with 1 at current position would make it not possible.
// At the end when the size of the string reaches n, then count it

//! Total valid strings that will be generated will be less than 2^n and to generate a string it takes n T.C, as we need to iterate to all the indices, hence about TC is less than 2^n * n
//. T.C -> O(1.618^n * n), as this is fibonacci growth so total valid strings is about 1.618^n (obviously less than 2^n)
//. S.C -> O(n), due to recursive stack space (excluding the space for storing the ans)

void generate(int n, string curr, vector<string>& ans) {
    // Base case: if length is n, add to result
    if (curr.length() == n) {
        ans.push_back(curr);
        return;
    }

    // Always try adding '0'
    generate(n, curr + "0", ans);

    // Add '1' only if previous char is not '1'
    if (curr.empty() || curr.back() != '1') {
        generate(n, curr + "1", ans);
    }
}
