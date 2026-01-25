#include <bits/stdc++.h>
using namespace std;

//* Method - I (Hard)
// Convert Prefix to Infix and then infix to Postfix

//* Method - II (Easy)
// Reverse the expression, then use the method of Postfix_to_prefix to get the expression which is again reversed back

bool isOperand(char s) {
        if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9'))
        return true;
        
        return false;
}

string preToPost(string pre_exp) {
        // reverse the string, use postfix to prefix on this, reverse it again
        
        string s = pre_exp;
        reverse(s.begin(), s.end());
    
        
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
        
        
        string ans = st.top();
        reverse(ans.begin(), ans.end());
        
        return ans;
}