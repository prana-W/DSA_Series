#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force, Iterative)
// Store all the elements of the stack in an array, sort the array and place all the elements back in the stack

//. T.C -> O(n + n*log(n) + n)
//. S.C -> O(n)
void iterativeBrute(stack<int> &st) {
        
        vector<int>arr;
        
        while(st.size()) {
            arr.push_back(st.top());
            st.pop();
        }
        
        sort(arr.begin(), arr.end());
        
        for (auto elem : arr) {
            st.push(elem);
        }
        
}

//* Method - II (Recursive Approach)
// Store the top value in a variable, pop it from the stack and now try to sort the remaining stack recursively, after the remaining stack is sorted, try to insert the variable we hold onto into this stack. For insertion, create another recursive function for insertion, it inserts if the top is less or equal to the incoming element, else it recursivley stores the top element and try to insert the incoming in the remaining stack and then push the top element back on top of the stack

//. T.C -> O(n^2)
//. S.C -> O(n), due to recursive stack space

// For insertion the worst time complexity is O(n) and the space complexity is O(n) for recursive stack space

// For the sortStack T(n) = T(n-1) + O(n), O(n) due to insertion, Now T(n-1) = T(n-2) + O(n-1) ..... At the end, T(n) = O(n) + O(n-1) + O(n-2) .... = O(n^2)
void insert(stack<int>&st, int temp) {
        if (st.empty() || st.top() <= temp) {
            st.push(temp);
            return;
        }
        
        int top = st.top();
        st.pop();
        
        insert(st, temp);
        
        st.push(top);
        
        return;
}
void sortStack(stack<int> &st) {
        
        if (st.size() <= 1) return;
        
        int top = st.top();
        st.pop();
        
        sortStack(st);
        
        insert(st, top);
        
}