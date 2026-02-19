#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Find all the possible substrings and then check for each generated substring if it is a palindrome

//. T.C -> O(n^3)
//. S.C -> O(1), no extra space apart from returning answer

//* Method - II (Better Solution)
//! Center-expansion

// Step 1 (Longest Odd length): Treat each index as the center of the palindrome and make two pointers 'left' adn 'right', and check if both are equal, if equal then keep on moving else continue ton necxt index, in this way we can find the longest odd lenght palindrome
// Step 2 (Longest Even Length): Now find two equla adjancent characters and make two pointers left and right around the two characters similarlhy as above and find the liongest answer

//. T.C -> O(n^2)
//. S.C -> O(1), no extra space apart from returning answer
string betterSolution(string s) {

        string ans;

        int n = s.size();

        // Longest Odd Length Palindrome

        for (int i = 0; i < n; i++) {
            int left = i-1;
            int right = i+1;

            string temp;
            temp += s[i];

            while(left >= 0 && right < n) {

                if (s[left] == s[right]) {
                    temp = s[left] + temp + s[right];
                    left--;
                    right++;
                }
                else break;

            }

            if (temp.size() > ans.size()) ans = temp;
        }

        // Longest Even Length Palindrome

        for (int i = 0; i < n-1; i++) {

            if (s[i+1] == s[i]) {

            int left = i-1;
            int right = i+2;

            string temp;
            temp += s[i];
            temp += s[i+1];

            while(left >= 0 && right < n) {

                if (s[left] == s[right]) {
                    temp = s[left] + temp + s[right];
                    left--;
                    right++;
                }
                else break;

            }

            if (temp.size() > ans.size()) ans = temp;

            }

        }

        return ans;
        
}

//* Method - II.V (DP Solution)
// Todo: Do after completing DP

//* Method - III (Optimal Solution)
//! Manacher's Algorithm
// Todo: Maybe at the end?