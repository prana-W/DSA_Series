#include <bits/stdc++.h>
using namespace std;

//* Method - I (Using Bit Manipulation)
// Each element can be either included or excluded, so we can represent it in bits.
// Hence if the size of the array is let's say 3, then the following are the possiblities, 0: excluded, 1: included

// 000, 001, 010, 011, 100, 101, 110, 111

// There initialise i = 0 and go till less thab (1 << n), this 'i' would represent the inclusion and exclusion of a particular element

// Now inside this make another loop from j = 0 till n and check if (i & (1 << j)) is set or not, it means we are checking whether a particular element is included or not and including if it is, else not including it.

//. T.C -> O(2^n * n)
//. S.C -> O(1) extra space, or O(2^n * n) for storing the answer in a result array
vector<vector<int>> bitMasking(vector<int>& nums) {

        int n = nums.size();
        
        vector<vector<int>>ans;
        
        for (int i = 0; i < (1 << n); i++) {
            
            vector<int>temp;
            
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j))) {
                    temp.push_back(nums[j]);
                }
            }
            
            ans.push_back(temp);
        }
        
        return ans;
        
}

//* Method - II (Recursive Way)
// Look for 03_power_set question in recursion directory 
//. //. T.C -> O(2^n * n)
//. S.C -> O(n) space due to recursive stack space, and O(2^n * n) for storing the answer in a result array