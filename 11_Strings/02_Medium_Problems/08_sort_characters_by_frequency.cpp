#include <bits/stdc++.h>
using namespace std;

// Make a array of pair, that stores the frequency and the character's acii value. At the end sort and reverse the array, this sorts the array according to decreasing order of the freq. of characters. Now loop in this array and form the final answer

//! Note: In this question characters could be lowercase, uppercase or digit, hence 128 is enough to hahndle the ascii of all the characters

//. T.C -> O(n + k), here k is 128
//. S.C -> O(k), here k is 128
string frequencySort(string s) {

        // O(128 * 2)
        vector<pair<int, int>> arr (128, {0, -1});

        // O(n)
        for (int i = 0; i < s.size(); i++) {
            int ascii = s[i];

            arr[ascii] = {arr[ascii].first + 1, ascii};
        }

        // O(128 log (128) + 128)
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());

        string ans;

        // O(n)
        for (int i = 0; i < 128; i++) {

            char ch = arr[i].second;
            int freq = arr[i].first;

            if (freq == 0) break;

            for (int j = 1; j <= freq; j++) {
                ans += ch;
            }

        }

        return ans;

}