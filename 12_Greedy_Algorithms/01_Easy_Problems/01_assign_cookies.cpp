#include <bits/stdc++.h>
using namespace std;

// Each child can take a cookie of size >= greed[i], hence we give the smallest size of cookie which is >= greed[i], so that the larger size cookies are left for later

//. T.C -> O(g*log(g) + s*log(s) + s)
//. S.C -> O(1)
int findContentChildren(vector<int>& g, vector<int>& s) {

    int ans = 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    // 'j' is tracking the cookie
    int j = 0; 

    // 'i' is iterating the greed of children

    //! Here the max time complexity will be O(s)

    // If greed is not satified then entire s will be iterated and broken once outside s
    // If greed is satisfied beforehand, we might still end up taking the entire s array
    for (int i = 0; i < g.size(); i++) {

        // If greed is more, try going at larger size in cookie
        while(j < s.size() && g[i] > s[j]) {
            j++;
        }

        if (j >= s.size()) break;

        if (g[i] <= s[j]) {
            ans++;
            j++;
        }
    }

    return ans;        
}