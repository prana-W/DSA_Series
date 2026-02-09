#include <bits/stdc++.h>
using namespace std;

// Iterate the string. If opening bracket then increase the counter, if closing bracket decrease the counter. Now store the max vlaue of the counter into our answer. Since the expression is of always of a valid parenthesis, therefore if x is the maximum number of open bracktes at any given point, then it will definielty be closed/baalanced later on, since it is valid parenthesis. This gives us a depth of x between that parenthesis

//. T.C -> O(n)
//. S.C -> O(1)
int maxDepth(string s) {

        int cnt = 0;
        int ans = 0;

        for (auto elem : s) {
            if (elem == '(') cnt++;
            else if (elem == ')') cnt--;

            ans = max(ans, cnt);
        }

        return ans;
        
}