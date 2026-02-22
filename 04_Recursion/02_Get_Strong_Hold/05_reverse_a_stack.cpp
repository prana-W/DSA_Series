#include <bits/stdc++.h>
using namespace std;

//* Method - I (Iterative)
// Store the elements in a array and then push the elements back into stack from the end of the array

//. T.C -> O(n)
//. S.C -> O(n)

//* Method - II (Recursive)
// Similar to previous problem, take out the top and store it and pop the stack and reverse the remaining stack recursively, after that insert the stored top element at the end of the stack (also recursively)

//. T.C -> O(n^2), explaination for this is same as in previous problem
//. S.C -> O(n) due to recursive stack space

void insertAtEnd(stack<int>& st, int temp) {
        if (st.empty()) {
            st.push(temp);
            return;
        }
        
        int top = st.top();
        st.pop();
        
        insertAtEnd(st, temp);
        
        st.push(top);
}

void reverseStack(stack<int> &st) {
        
        if (st.size() <= 1) return;
        
        int top = st.top();
        st.pop();
        
        reverseStack(st);
        insertAtEnd(st, top);
        
        return;
        
        
}