#include <bits/stdc++.h>
using namespace std;

//. T.C -> O(n)
//. S.C -> O(1)
string removeOuterParentheses(string s) {

    string ans;
    int points = 0;

    for (int i = 0; i < s.size(); i++) {

        // If points is postitive, then include it (if still '0', it means the next would be an opening and hence we won't store it)
        if (points > 0) ans += s[i];

        if (s[i] == '(') points++;
        else points--;

        if (points == 0) {
            // If points becomes 0, it means, the last character was a closing bracket ans hence needs to be removed
            ans.pop_back();
        }

    }

    return ans;
        
}