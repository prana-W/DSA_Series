#include <bits/stdc++.h>
using namespace std;

// First reverse the expression (Note: opening bracket is converted into closed bracker and closed bracket is converted into open bracket)
// After the reversal, simply find the Postfix of the expressiong, but with mirror evaluation i.e. '^' from Left to right and rest from righ to left
// Hence if both incomming char and st.top() is '^', just store the top() in answer and pop the top() till otherwise, else if it is some other operator, push it in the stack and use it later.
// After the modified PostFix expression of the reveral of the initial exprssion, again reverse th final result to get our answer

// 1. Reverse expression (with mirror brackets)
// 2. Infix to Postfix (with reversion evluation side)
// 3. Modified Postfix reversal to get the final answer

//. T.C -> O(n)
//. S.C -> O(n)
string infixToPrefix(string &s) {
        
        string temp;
        
        // Reversal with brackets switching opening
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == '(') temp += ')';
            else if (s[i] == ')') temp += '(';
            else temp += s[i];
        }
        
        stack<char>st;
        
        // Same as Postfix, but the evaluation is reversed, ^ from left to right and rest from right to left
        map<char, int>priority;
        priority['^'] = 3;
        priority['*'] = 2;
        priority['/'] = 2;
        priority['+'] = 1;
        priority['-'] = 1;
        priority['('] = -1;
        priority[')'] = -1;
        
        string ans;
        
        for (int i = 0; i < temp.size(); i++) {
            
            char ch = temp[i];
            
            if (priority.find(ch) == priority.end()) {
                ans += ch;
            }
            
            else if (ch == '(') {
                st.push(ch);
            }
            
            else if (ch == ')') {
                while (st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
         
            // If ch is a operator
            else {
                
                // If top has higher priorioiity than incoming or ch and top() are same and equal to '^', store the top() in answer and pop the stack
                while(!st.empty() && ((priority[ch] < priority[st.top()]) || (ch == '^' && st.top() == '^'))) {
                    ans += st.top();
                    st.pop();
                }
                
                // Simply add ch to stack
                st.push(ch);
            }
            
        }
        
        // FLush out the remianings from the stack
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        // Final reversal
        reverse(ans.begin(), ans.end());
        
        return ans;
}