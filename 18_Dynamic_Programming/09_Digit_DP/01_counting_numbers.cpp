#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//? Problem: https://cses.fi/problemset/task/2220

//. T.C -> O(total_states * work_per_states) = O(20x11x2x2 x 10) = O(1e4)

// Taking inspiration from prefix sum, to find the count from range a to b, we do (solve(b) - solve(a-1)), where solve(x), solves from start to x, and by subtracting like this, we can find the count in our range

// index of the digit from left to right in a number is treated as one of the state in DP

// If x = 31485, then we can never fill > 3 at the 0th index. There fore we ar ebound to select 0, 1, 2, 3 at the 0th index only

// tight is the second state, if it is 1, it means we can only fill the index with only certain digit, if it is 0, we can fill the index with any digit

// previous is the third state, which keeps track of the previous digit

// leading zerores don't take part in answer, there if have 0 in the 0th index, then prev will be 0 for 1st index, and it will not allow us to place 0 in 1st index, which is actually incorrect, as we can actually fill 0 in the first index, since leading zeroes can be there, so we don't consider them as same digit in adjacent. Example: 00121 is valid, but it can't be formed, as 1st index has digit equal to previous. 00300 is not valid, as the last two zeroes are same and are counted. So to tackle type of situation, sometimes consiedering leading zeroes and sometimes not, we would require another state

// lz is our fourth state, which determines if leading zeroes are present or not

// Threrefore in total, there are four states for this problem: index, tight, previous and lz

// Max number is 10^18, so we need 19 digits, hence a size of 20 for index
// For prev, thre are 9 digits, and 10 for invalid, so a size of 11
// tight and lz has only two states (true and false), so a size of 2

//! Global static array, initially with 0, so set to -1 in the main function both times before using
//! Note: memset can only handle 0 and -1 as indended, don't use it to set the initial size of the dp to anything else

// alternate: auto dp = vector(20, vector(11, vector(2, vector<ll>(2, -1)))); in main function
ll dp[20][11][2][2];

ll dpFunc(ll ind, ll prev, bool tight, bool lz, string& s) {

    // When we reach the end of our string, count it in our answer
    if(ind == s.size()) return 1;

    if (dp[ind][prev][tight][lz] != -1) return dp[ind][prev][tight][lz];

    ll ans = 0;

    // Finding lower and upper bound for the digit and current ind, if tight is true, then the maximum digit can be whatever digit is in the string at that index, else it can be up to 9
    ll lb = 0;
    ll ub = (tight == true) ? (s[ind] - '0') : 9;

    for (ll dig = lb; dig <= ub; dig++) {

        // If dig is equal to prev and lz is false then only continue, if dig and previous is equal and lz was true, it means previous was also zero, so and it is leading zero, so we will consider this
        if(dig == prev && !lz) continue;

        // If tight condition is broken once, we can choose any digit to all the indices in the right. Tight is only continued, if it was already tight, adnd also the current dig is equal to upper bound, so next digit will also have boundation, so tight is true
        // If lz was true and also the current digit is 0, then only lz will still remain true
        ans += dpFunc(ind+1, dig, (tight && dig == ub), (lz && dig == 0), s);

    }

    return dp[ind][prev][tight][lz] = ans;

}

ll solve(ll a, ll b) {

    // We solve for [0, b] and [0, a-1] and subtract both to get for [a, b]
    string l = to_string(a-1);
    string r = to_string(b);

    // Intially, index is 0; we choose 10 as the prev for the 0th index (which means no prev); tight is true as for 0th index we can't explore all the digits due to max limit from string; also we put true as lz, as for 0th index, lz is allowed.

    memset(dp, -1, sizeof(dp));
    ll leftAns = dpFunc(0, 10, true, true, l);
    memset(dp, -1, sizeof(dp));
    ll rightAns = dpFunc(0, 10, true, true, r);

    return (rightAns - leftAns);
}
void countNumbers() {
    ll a, b;
    cin >> a >> b;

    cout << solve(a, b) << endl;
}

int main() {
    countNumbers();
}