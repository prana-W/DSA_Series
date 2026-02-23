#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Get all the substrings and store the char in a unordered map, if the character is repeated, stop going furhte in inner loop and store the ans

//. T.C -> O(n^2) in average and O(n^2 * x) in worst case. Also x = 26 in worst when all the characters are inside unordered map
//. S.C -> O(x), x is 256 in worst case for all the characters in unordered map
int bruteForce(string s) {

        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {

            unordered_map<char, int>mp;

            for (int j = i; j < n; j++) {

                if (mp.find(s[j]) != mp.end()) {
                    ans = max(ans, j-i);
                    break;
                }

                mp[s[j]]++;

                // When the entire substring has no repetation
                if (j == n-1) ans = max(ans, j-i+1);
            }
        }

        return ans;
        
}

//* Method - II (Optimal Approach)
//! Two pointer
// Keep two pointers. Keep on moving right pointer till the freq of all chars is 1. Whenever we encounter a repeated character, reduce the left pointer till we remove the repeated character and then keep on doing this

//. T.C -> O(n) in avaerge and O(n*x), x = 256 in worst case for unordered_map
//. S.C -> O(x), x = 256 in worst case for unordered_map
int optimal(string s) {

        int n = s.size();
        int ans = 0;

        int i = 0, j = 0;
        unordered_map<char, int>mp;

        while(j < n) {


            if (mp[s[j]] == 0) {  

                mp[s[j]]++;
                j++;

                //! If we reach the end, then also update the ans
                if (j == n) ans = max(ans, j-i); 
            }
            
            // When the s[j] is already in the substring then reduce the left pointer till that removes
            else {

                ans = max(ans, j-i);

                while(mp[s[j]]) {

                    mp[s[i]]--;
                    i++;

                }

            }
        }

        return ans;
}