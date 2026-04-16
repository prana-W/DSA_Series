#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force, Memoization DP)
// We have three states start, end and k, and we find overlapping subproblems, we cna use simple recursion with memoization to find the answer

//. T.C -> O(n^2 * k)
//. S.C -> O(n^2 * k)

int solve(int s, int e, vector<int>& cardPoints, int k, vector<vector<vector<int>>>& dp) {

    if (s > e || k == 0) return 0;
    if(dp[s][e][k] != -1) return dp[s][e][k];

    int ans = max(cardPoints[s] + solve(s+1, e, cardPoints, k-1, dp), cardPoints[e] + solve(s, e-1, cardPoints, k-1, dp));

    return dp[s][e][k] = ans;
}
int maxScore(vector<int>& cardPoints, int k) {

    int n = cardPoints.size();

    // 3D DP (with states start, end and k remaining)
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1, -1)));

    return solve(0, n-1, cardPoints, k, dp);
    
}

//* Method - II (Optimal Solution)
// We have to find the maximum sum from combined from the ends only of size k, so we can solve this, by first finding the minimum sum of window (n-k) in the array, then just subtract that form the total sum to find the answer

//. T.C -> O(n)
//. S.C -> O(1)
int maxScore(vector<int>& cardPoints, int k) {

    int n = cardPoints.size();

    int mini = 0, totalSum = 0;

    for (int i = 0; i < n; i++) {
        if(i < (n-k)) mini += cardPoints[i];
        totalSum += cardPoints[i];
    }

    int i = 0, j = (n-k);

    int temp = mini;

    while(j < n) {
        
        temp += cardPoints[j];
        temp -= cardPoints[i];

        i++;
        j++;

        mini = min(mini, temp);
    }

    return (totalSum - mini);  
            
}