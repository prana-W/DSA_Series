#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Recursive Approach)
// Generate all possible strings and then check for each at the end.

// Start with a empty string, then recursviely first push opening bracket and closing bracket. When the size hits 2*n, check using another function if it is valid (opening == closing and opening >= closing at any given point)

// Check if a string has valid parentheses

//. T.C -> O(2^(2n) * (2n + 2n)), length of string is 2n, total strings generated is 2^(2n) and to copy each string into ans it takes O(2n) TC and also to check if valid or not it takes O(2n)
//. S.C -> O(2n), due to recursive stack space (excluding space taken to store the answer)

bool isValid(string s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else balance--;
        if (balance < 0) return false;
    }
    return balance == 0;
}

void generateAll(string curr, int n, vector<string>& res) {
    if (curr.length() == 2 * n) {
        if (isValid(curr)) res.push_back(curr);
        return;
    }
    generateAll(curr + '(', n, res);
    generateAll(curr + ')', n, res);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    generateAll("", n, res);
    return res;
}

//* Method - II (Optimised Recursive Approach)
// Only generate further opening, if have less than n opening bracket already
// Only generate further closing, if have closing less than opening
// At the end, add the string directly into the ans array without the need to check if possible or not, as all the strings creaated is a valid

//! Total number of valid parentheses is equal to the Catalan Number
// To create each string it takes O(2n) time complexity (length of string)
// C(n) = (2n)! / (n! * (n+1)!)
//. T.C -> O(C(n) * (2n)), there are C(n) answer and O(2n) to copy (push_back) the string into ans
//. S.C -> O(2n), due to recursive stack space (excluding answer), to store the answer in ans array, it takes an additional (C(n) * n) space

void generate(int n, string s, int opening, int closing, vector<string>& ans) {
        if (s.size() == 2*n) {
            ans.push_back(s); //! O(2n)
            return;
        } 

        // Generate opening further if possible
        if (opening < n) generate(n, s+"(", opening+1, closing, ans);

        // Generate closing further only if possible
        if (closing < opening) generate(n, s+")", opening, closing+1, ans);

}

vector<string> optimalRecursive(int n) {

        vector<string>ans;

        generate(n, "", 0, 0, ans);
        
        return ans;
        
}