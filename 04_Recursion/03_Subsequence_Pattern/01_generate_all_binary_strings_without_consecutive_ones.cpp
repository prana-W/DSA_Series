#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.

//* Method - I (Recursive Approach)
// Start with a empty string, then first generate the string with 0 at the back of the string and another function that adds 1 to the back, also make sure the previous index didn't had already '1', becuase then generating a string with 1 at current position would make it not possible.
// At the end when the size of the string reaches n, then count it

//. T.C -> O(2^n), as there are n positions and either we will have 0 or 1 at the position, giving a TC of 2^n
//. S.C -> O(n), due to recursive stack space

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
