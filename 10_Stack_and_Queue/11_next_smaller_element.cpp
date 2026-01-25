#include <bits/stdc++.h>
using namespace std;

// Same as before, but here only one condition inside if staments will change

vector<int> nextSmallerElement(vector<int>& arr) {
        
        vector<int>ans(arr.size(), -1);
        
        stack<int>st;
        
        for (int i = arr.size()-1; i >= 0; i--) {
            while(!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            
            if (!st.empty() && st.top() < arr[i]) {
                ans[i] = st.top();
            }
            
            st.push(arr[i]);
        }
        
        return ans;
        
}