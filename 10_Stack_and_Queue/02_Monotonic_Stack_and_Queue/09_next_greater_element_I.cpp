#include <bits/stdc++.h>
using namespace std;

//! NGE I

// Problem: See LeetCode for this question

//* Method - I (Brute Force)
// Iterate thorugh nums1 and look for that eklement in nums2, and then try to find the next greater element in the nums2 and report the answer

//. T.C -> O(n*m)
//. S.C -> O(n), for returning the answer only. No extra space taken apart from that

//* Method - II (Optimal Solution)

// To find the next greater element of any array, we can use Montonic stack on nums2. 
// Iterate the nums2 from right to left, if the stack has a smaller element on the top than the incoming element, then keep on poping (as these elements are a waste and can never affect our answer even later), also if the top() is greater than that is our answer, if still not possible than it is not possible, at the end push the current element to the stack
// After making a hasArray of next greater element for nums2, now iteerate the nums1 array and using lookup in the mpa for each element, get the answer (if exists)

// Example: For [1 5 2 0], we first push 0 to stack, then for '2', we remove the '0' from the stack, because for anhy element later that comes to be smaller than '2', then 2 would be the answer, if it would have been greater than '2' then neighter '2' nor all the elements smaller than '2' could be the answer. Again for '5' we need to pop '2', due to same reason and for 1, '5' is greater, hence we don't pop anhything.

//. T.C -> O(n + m), in average case if unordereed map is used
//. S.C -> O(n + 2m), O(n) for returnign the answer and O(2m) for the stack and hashMap to store NGE (next greater element) of the nusm2. NOTE: O(2m) is the only extra space used here apart from space taken for returnning the answer
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    stack<int>st; 
    unordered_map<int, int>mp;

    for (int i = nums2.size()-1; i >= 0; i--) {

        while (!st.empty() && st.top() < nums2[i]) {
            st.pop();
        }

        if (!st.empty() && st.top() > nums2[i]) mp[nums2[i]] = st.top();
        else mp[nums2[i]] = -1;

        st.push(nums2[i]);
    }

    vector<int>ans;

    for (int i = 0; i < nums1.size(); i++) {
        if (mp.find(nums1[i]) != mp.end()) {
            ans.push_back(mp[nums1[i]]);
        }
        else ans.push_back(-1);
    }

    return ans;
        
}