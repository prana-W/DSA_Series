#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
//! Using Recursion (Backtracking)

//! Try to do with DP as wellpppppp


// Todo:














//* Method - II (Better Solution)
//! Using stacks and Greedy Approach

// Make two stacks, one for opening bracket and one for star. Also store index of both. Iterate the string. If opening bracket is encountered, store in st. If star is encountered store in st2. If closing bracket is encountered, first try to utilise the opening bracket to fulfill the matching else use the star. At the last all the possible pairs would be formed with the closing brakcet.

// At the end only opening bracket and the star would remain in the seperate stacks. If the opening bracket index is less than the index of the star, then the star can behave as the closing bracket and just like that try to utilise all the opening brackets. If still any opening bracket is left at the end, then return false else return true

//. T.C -> O(n)
//. S.C -> O(n), due to two stacks
bool betterSolution(string s) {

    stack<pair<char, int>>st, st2;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (ch == '(') st.push({ch, i});
        else if (ch == '*') st2.push({ch, i});
        else {
            if (st.size()) st.pop();
            else if (st2.size()) st2.pop();
            else return false;
        } 
    }

    while(st.size() && st2.size()) {
        if (st.top().second > st2.top().second) return false;

        st.pop();
        st2.pop();
    }

    if (st.size()) return false;

    return true;
        
}

//* Method - III (Optimal Approach)
//! Greedy Approach

// Treat ( as +) and ) as -. 
//! Note: While iterating the count shoiuld reach 0 at the end and also it should go to negative direction at any given instant, else such a string would be not a valid parenthesis

// In this method we keep a range (mini and maxi counter) while iterating. * will do both -1 and +1 and will integrate the result in min and max both.

// If the maxi becomes negative at any point, then the net can never be 0, so return false

// Also, we will never let mini get below 0 at any point.

// mini -> Total minimum nuber of opening possible
// maxi -> Total maximum number of opening possible

// Check if mini == 0 at the end

//. T.C -> O(n)
//. S.C -> O(1)
bool optimalSolution(string s) {

    int mini = 0;
    int maxi = 0;

    for (auto elem : s) {

        if (elem == '(') {
            mini++;
            maxi++;
        }
        else if (elem == ')') {
            mini--;
            maxi--;
        }
        else {
            mini--;
            maxi++;
        }

        // Never let mini go below 0
        mini = max(mini, 0);

        // If maxi is negative, then it is not possible
        if (maxi < 0) return false;
    }

    // mini must be exactly 0, as we are clamping the mini back to 0 for negative values
    if (mini == 0) return true;

    return false;
        
}