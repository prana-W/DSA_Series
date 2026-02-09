#include <bits/stdc++.h>
using namespace std;

// Iterate the string. If the value of next char is greater than present, then subtract the value of front-present and move on, else simply add the current value

//. T.C -> O(n)
//. S.C -> o(7)
int romanToInt(string s) {

        map<char, int>mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i < s.size() && mp[s[i+1]] > mp[s[i]]) {
                ans += (mp[s[i+1]] - mp[s[i]]);
                i++;
            }
            else {
                ans += mp[s[i]];
            }
        }

        return ans;

}