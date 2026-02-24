#include <bits/stdc++.h>
using namespace std;

//* Method - I (Recursive Approach)
// Go to each index, either exclude that or include that recursively in a temp variable. All the varibales we use is with pass by reference to optimise space complexity by avoiding copy again and again

//. T.C -> O(2^n * n), There are approx. (2^n) subsequences, and copying (push_back) each subsequene into the ans array takes in average O(n) time. Also to sort N=2^n elements, it takes O(2^n * log(2^n)) -> O(2^n * n) again
//. S.C -> O(n + 2^n * n), O(n) due to recursive stack space and O(2^n * n) for storing the answer and then sorting the array and then returning the answer
void subsequence(int index, string& s, string& temp, vector<string>& ans) {
        if (index == s.size()) {
            ans.push_back(temp); //! O(n)
            return;
        }
        
        // Exclude index i
        subsequence(index+1, s, temp, ans);
        
        // Include index i
        temp.push_back(s[index]);
        subsequence(index+1, s, temp, ans);
        
        // For backtracking (to remove the added char for use further)
        temp.pop_back();
        
}

vector<string> recursiveApproach(string s) {
        
        vector<string>ans;
        string temp = "";
        
        subsequence(0, s, temp, ans);
        
        sort(ans.begin(), ans.end());
        
        return ans;  
        
}

//* Method - II (Using Bit Masking approach, similar to Power Set problem in Bit Manipulation)

// Each character can be either included or excluded, so we can represent it in bits.
// Hence if the size of the string is let's say 3, then the following are the possiblities, 0: excluded, 1: included

// 000, 001, 010, 011, 100, 101, 110, 111

// There initialise i = 0 and go till less thab (1 << n), this 'i' would represent the inclusion and exclusion of a particular character

// Now inside this make another loop from j = 0 till n and check if (i & (1 << j)) is set or not, it means we are checking whether a particular character is included or not and including if it is, else not including it, at the end, sort the final answer and return

//. T.C -> O(2^n * n)
//. S.C -> O(2^n * n), for storing the answer in vector 
vector<string> bitMasking(string s) {
        
        int n = s.size();
        
        vector<string>ans;
        
        for (int i = 0; i < (1 << n); i++) {
            
            string temp;
            
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j))) {
                    temp += s[j];
                }
            }
            
            if(temp.size()) ans.push_back(temp);
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    
}