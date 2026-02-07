#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Generate all possible variation of string by rotation and compare

//. T.C -> O(n^2), n rotation and n time by substr
//. S.C -> O(n), to store rotated string
bool bruteForce(string& s, string& goal) {
        // Strings must be same length to be rotations of each other
        if (s.length() != goal.length()) {
            return false;
        }
        // Try all possible rotations of 's'
        for (int i = 0; i < s.length(); i++) {
            string rotated = s.substr(i) + s.substr(0, i);  
            if (rotated == goal) {
                return true;
            }
        }
        return false;
}

//* Method - II (Better Solution)

// Check if size is same. If not same, then even after any rotation we can't find goal. After that concatenate s twice and find goal inside it. If found return true

//! Note: If not found, it will return string::npos

//. T.C -> O(n^2), as doing find() take O(n * m) time 
//! Doubt: According to TUF, T.C -> O(n)
//. S.C -> O(n) due to s+s
bool rotateString(string s, string goal) {

        if (s.size() != goal.size()) return false;

        string temp = s + s;

        if (temp.find(goal) != string::npos) return true;

        return false;
        
}