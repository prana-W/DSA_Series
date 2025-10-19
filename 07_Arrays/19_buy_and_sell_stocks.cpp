#include <bits/stdc++.h>
using namespace std;

// Problem: An array containing prices of stocks from 0th to n-1th days. We need to buy the stock at one day and then sell it on later day such the profit obtained is maximum.

// Intuition: If we sell the stock on ith day, then we had to buy it from 0 - i-1th day. Also, the day which we buy it must be minimum in the range of 0th to i-1th.

// After that we check for which combination the profit is maximum

//. T.C -> O(n)
//. S.C -> O(1)
void solve(int n, int arr[]) {
    int mini = arr[0];
    int profit = 0;

    for (int i = 1; i < n; i++) {

        int cost = arr[i] - mini; // Cost to sell the stock when we bought at minimum price from 0th to i-1 th

        profit = max(profit, cost); // Storing if we obtain greater profit

        mini = min(mini, arr[i]); // Updating the mini value if arr[i] is smaller
    }

    int maxProfit = profit;

    cout << maxProfit << endl;
}