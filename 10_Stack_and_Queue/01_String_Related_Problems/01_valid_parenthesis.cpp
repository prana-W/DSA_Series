#include <bits/stdc++.h>
using namespace std;

//* Method - I (Optimal Approach)
// Use a stack to track the opening brackets, we are using stack as the opening brackert we are most concerned at any point is the last most (or top most), hence store opening brackets in stack, and whenever a cklosing bracket is encountered, check if the top opening is its complement. Also pop() the opeing bracket once its complementary closing bracket is found. Hecne at the end ideally there should be no brackets/elements left in the stack as all the opeing bracket would be ehsausted due to pairing with the closing. If it is not empty then it can't be the answer

//. T.C -> O(n)
//. S.C -> O(n), for stack
bool isOpening(char elem) {
        if (elem == '{' || elem == '(' || elem == '[') {
                return true;
        }

        return false;
    }

bool optimalApproach(string s) {

        // If the size of the string is odd, then their can't be pair of opening and closing bracket
        if(s.size()%2 != 0) return false;

        map<char, char>complement;
        complement['}'] = '{';
        complement[')'] = '(';
        complement[']'] = '[';

        stack<char>st;

        for (auto elem : s) {

            // If it is opening brackets, just push it in the stack
            if (isOpening(elem)) {
                st.push(elem);
            }
            // If it is closing bracket and either the stack is empty (no opening in it) or it has elements but not the complement of the closing bracket, then return false
            else if (st.empty() || (!st.empty() && complement[elem] != st.top())) {
                return false;
            }
            // If it is closing and its complement exists, then just pop() the complementing opening bracket
            else st.pop();
        }

        // If the size if not empty, then that bracket's pair was not formed, hence return false
        if (!st.empty()) return false;
        return true;
        
}