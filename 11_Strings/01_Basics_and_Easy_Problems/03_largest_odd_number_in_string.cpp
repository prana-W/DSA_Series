#include <bits/stdc++.h>
using namespace std;

// Find the first indexx from the end with the odd number, the substring from start till this index will be the answer

//. T.C -> O(n)
//. S.C -> O(1)
string largestOddNumber(string s) {

        string ans = "";

        for (int i = s.size()-1; i >= 0; i--) {
            int digit = s[i] - '0';

            if (digit&1) {

                // Or use .substr instead of a loop
                for (int j = 0; j <= i; j++) {
                    ans += s[j];
                }
                return ans;
            }
        }
        
        return ans;
}