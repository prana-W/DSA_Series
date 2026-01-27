#include <bits/stdc++.h>
using namespace std;

// Reverse the initial expression and then just do the algorithm for Postfix to Infix and after that again reverse the ans with mirrored bracket 

//. T.C -> O(n)
//. S.C -> O(n)

bool isOperand(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return true;
        
        return false;
}
    
string preToInfix(string pre_exp) {
        
        string reversedStr = pre_exp;
        reverse(reversedStr.begin(), reversedStr.end());
        
        stack<string>st;
        
        for (int i = 0; i < reversedStr.size(); i++) {
            
            if (isOperand(reversedStr[i])) {
                string temp = "";
                temp += reversedStr[i];
                
                st.push(temp);
            }
            else {
                string temp = "";
                
                // Concatenate the top 2 elements into one with the operator in between and pop() out both of them
                temp += st.top();
                st.pop();
                temp = st.top() + reversedStr[i] + temp;
                st.pop();

                // Wrap the concatenated string with brackets
                temp = "(" + temp + ")";
                
                // Push the final modified string into stack
                st.push(temp);
            }
            
        }
        
        string ans = st.top();
        
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == '(') ans[i] = ')';
            else if (ans[i] == ')') ans[i] = '(';
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
}