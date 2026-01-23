#include <bits/stdc++.h>
using namespace std;

// Iterate the expresion, if it is a operand, push it to stack
// If it is a operator, combine the previous two stack strings with the operator in between, pop() the two top() elements from stack, wrap the combined string in brackets and add it to the stack.

// Repeat this and at the end, a single stack element remains with the Infix expression

//. T.C -> O(n)
//. S.C -> O(n)

bool isOperand(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return true;
        
        return false;
}

string postToInfix(string &exp) {
        
        stack<string>st;
        
        for (int i = 0; i < exp.size(); i++) {
            
            // If it is a operand, add it to stack
            if (isOperand(exp[i])) {
                string temp = "";
                temp += exp[i];
                
                st.push(temp);
            }
            else {
                string temp = "";
                
                // Concatenate the top 2 elements into one with the operator in between and pop() out both of them
                temp += st.top();
                st.pop();
                temp = st.top() + exp[i] + temp;
                st.pop();

                // Wrap the concatenated string with brackets
                temp = "(" + temp + ")";
                
                // Push the final modified string into stack
                st.push(temp);
            }
            
        }
        
        // The single element remaining in the stack is the required answer
        return st.top();
}