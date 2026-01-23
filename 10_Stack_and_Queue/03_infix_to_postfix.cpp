#include <bits/stdc++.h>
using namespace std;

/* Iterate the entire string, if an operand is encountered, imediately store it in the ans, else if it is a operator then:

- If it is a '(', store it in the stack

- If we encounter ')', then pop() all the elements and store it in ans, till we encoutner a '(' bracket. Pop and store all the elements between the brackets and pop out  the braackets as well.

- If the stack is empty or the top() has a operator with lower precedence (note: opening bracket is treated to have lowest priority), then push the operator into the stack

- If the stack on the top() has a operator with higher or equal presecedence, then pop() it out and store it in ans, till the top() operator has lower priority than the incoming operator


*/
//! Note: '^' is evaluated from right to left, while rest of the operators are evaluated from left to right

 string infixToPostfix(string& s) {
        
    map<char, int>priority;
    priority['^'] = 3;
    priority['*'] = 2;
    priority['/'] = 2;
    priority['+'] = 1;
    priority['-'] = 1;
    priority['('] = -1;
    priority[')'] = -1;
    
    string ans = "";
    stack<char>st;
    
    for (int i = 0; i < s.size(); i++) {
        
        // If the s[i] is not a operator
        if (priority.find(s[i]) == priority.end()) {
            ans += s[i];

        }
        
        // To handle opening bracket
        else if (s[i] == '(') {
            st.push(s[i]);
            continue;
        }
        
        // To handle closing bracket
        else if (s[i] == ')') {
            while(st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop(); // To remove '('
        }
        
        // If the s[i] has higher priority, just push it. 
        //! If both s[i] and top() is '^', we still push it, as '^' is evlauated right to left, hence keep on adding it, and evaluate it at the end
        else if (st.empty() || (priority[st.top()] < priority[s[i]]) || (st.top() == '^' && s[i] == '^')) {
                st.push(s[i]);
        }
        
        // If s[i] has lower or equal presecendence, store top to ans and pop till s[i] has higher
        //! If s[i] and top() has equal priority (and not equal to '^'), then keep adding the top() to asnwer, as we want to evaluate from left to right
        else {
            
            while (!st.empty() && priority[st.top()] >= priority[s[i]]) {
            ans += st.top();
            st.pop();
        }
        
        // Finally push s[i]
        st.push(s[i]);
            
        }
        
    }
    
    // Store all the remaining operands in the answer
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    
    return ans;
   
}