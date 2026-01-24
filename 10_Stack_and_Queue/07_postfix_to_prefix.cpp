#include <bits/stdc++.h>
using namespace std;

//* Method - I (Hard)
// Convert Postfix to Infix and then infix to prefix

//* Method - II (Easy)
// Iterate in the string, if it is a operand, store it in the stack, if it is a operator, concatenate the top two elements into one, and use the operator as the prefix to the commbined string, finally return the top element of the stack at the end

bool isOperand(char s) {
        if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9'))
        return true;
        
        return false;
    }
    
string postToPre(string s) {
        
        stack<string>st;
        
        for (int i = 0; i < s.size(); i++) {
            if (isOperand(s[i])) {
                
                string temp = "";
                temp += s[i];
                
                st.push(temp);
            }
            else {
                string temp = st.top();
                st.pop();
                temp = s[i] + st.top() + temp;
                st.pop();
                
                st.push(temp);
                
            }
        }
        
        return st.top();
        
}