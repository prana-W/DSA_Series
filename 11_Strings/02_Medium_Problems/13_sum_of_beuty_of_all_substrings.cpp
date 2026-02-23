#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Generate all the substrings and store the freq in a hash array and check for maxi and mini freq in it and add to the answer

//. T.C -> O(n^2 * 26)
//. S.C -> O(26)
int brute(string s) {

        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            vector<int>arr(26, -1);

            for (int j = i; j < n; j++) {

                int maxi = INT_MIN, mini = INT_MAX;

                int ind = s[j] - 'a';

                if(arr[ind] == -1) arr[ind] = 1;
                else arr[ind] = arr[ind] + 1;

                for (int k = 0; k < 26; k++) {
                    if (arr[k] == -1) continue;

                    maxi = max(maxi, arr[k]);
                    mini = min(mini, arr[k]);
                }

                ans += (maxi-mini);
            }

        }

        return ans;
        
}