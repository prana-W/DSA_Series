#include <bits/stdc++.h>
using namespace std;

//! NGE II

//* Method - I (Brute Force)

//. T.C -> O(n^2)
vector<int> bruteForce(vector<int> arr) {
       
        int n = arr.size(); 
        
        // To store the next greater elements
        vector<int> ans(n, -1);
        
        for(int i=0; i < n; i++) {
            
            // Get the current element
            int currEle = arr[i];
             
            /* Nested loop to get the 
            next greater element */
            for(int j=1; j < n; j++) {
                
                // Getting the hypothetical index
                int ind = (j+i) % n;
                
                // If the next greater element is found
                if(arr[ind] > currEle) {
                    
                    // Store the next greater element
                    ans[i] = arr[ind];
                    break;
                }    
            }
        }
       
        return ans;
}

//* Method - II (Optimal Solution)
// Loop the input array twice (both times from the end, the first time, we don't need to store the answer as the first time loop is only to establish the stack for the next loop), during second loop we store the answers. The first loop was only to repleneish the stack for the starting elements

//. T.C -> O(2n)
//. S.C -> O(2n), O(n) for storing the elements in the stack and O(n) for returning the answer. So extra space is just O(n)
vector<int> optimalApproach(vector<int>& nums) {

        stack<int>st;
        vector<int>ans(nums.size());

        // First loop to establish the stack
        for (int i = nums.size()-1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            st.push(nums[i]);
        }

        // Second loop for storing the answer
        for (int i = nums.size()-1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            if (!st.empty() && st.top() > nums[i]) {
                ans[i] = st.top();
            }
            else ans[i] = -1;

            st.push(nums[i]);
        }

        return ans;
        
}