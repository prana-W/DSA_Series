#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Make two nested loops to create all possible windows. In each window, calculate window_size - max_freq_char and check if it is less than or equal to k

//. T.C -> O(n^2 * 26), in worst case
//. S.C -> O(26) in worst case for unordered _map

//! Note: We can also use hash array instead of unordered_map
int brute(string s, int k) {

    int n = s.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        unordered_map<char, int> mp;
        for (int j = i; j < n; j++) {
            mp[s[j]]++;

            int maxi = 0;

            for (auto elem : mp) {
                maxi = max(maxi, elem.second);
            }

            if ((j - i + 1) - maxi <= k)
                ans = max(ans, j - i + 1);
        }
    }

    return ans;
}

//* Method - II (Better Solution)
// Make a window, and check if the (window_size - freq_of_max_occuring_char) is > k, if it is, then small the window till the condition is met, adn just like that, find the max window size that satisfies the condition

//. T.C -> O(n)
//. S.C -> O(26), in the worst case
int better (string s, int k) {

        int n = s.size();
        unordered_map<char, int> mp;

        int i = 0, j = 0, ans = 0;

        int maxFreq = 0;

        while (j < n) {

            mp[s[j]]++;

            maxFreq = max(maxFreq, mp[s[j]]);

            // If required alterion is more than k, decrease the window size till it satisfies the condition
            while (i < n && ((j-i+1) - maxFreq) > k) {
                mp[s[i]]--;
                i++;

                maxFreq = max(maxFreq, mp[s[i]]);
            }

            j++;

            ans = max(ans, j-i);
        }

        return ans;
}

//* Method - III (Optimal Solution)
// Do with hash array

//. T.C -> O(n)
//. S.C -> O(26)
int characterReplacement(string s, int k) {

        int n = s.size();
        vector<int>freq(26, 0);

        int i = 0, j = 0, ans = 0;

        int maxFreq = 0;

        while (j < n) {

            freq[s[j] - 'A'] += 1;

            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            while (i < n && ((j-i+1) - maxFreq) > k) {
                freq[s[i] - 'A'] -= 1;
                i++;

                maxFreq = max(maxFreq, freq[s[i] - 'A']);
            }


            j++;

            ans = max(ans, j-i);
        }

        return ans;
}