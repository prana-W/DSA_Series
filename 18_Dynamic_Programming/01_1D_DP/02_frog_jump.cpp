#include <bits/stdc++.h>
using namespace std;

// Problem: https://www.geeksforgeeks.org/problems/geek-jump/1

// Problem Statement: Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the last stair. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the last stair.

//* Method - I (Recursive Method)
// Let's consider 0-based indexing. Forg is on th stair and wants to reach n-1th stair. To reach xth stair, calculate total cost to reach x-1th stair and add with cost to reach xth stair from x-1th stair, and also calculate total cost to reach x-2th stair and add with the cost to reach xth stair directly from x-2th stair; consider the minimum of the two

// To reach the 0th step, cost is 0 (as already present their) and to reach 1st step, they can reach only from 0 to frist sttep, so absolute differnce of the two

// n -> step-index :>
//. T.C -> O(2^n), approx. (similar to fibonacci)
//. S.C -> O(n), due to recursive stack space
int cost(int n, vector<int>& height) {
        
        if (n == 0) return 0;
        if (n == 1) return (abs(height[1] - height[0]));
        
        // Cost to reach n-1th step plus to reach nth step from n-1th step
        int cost1 = cost(n-1, height) + (abs(height[n] - height[n-1]));

        int cost2 = cost(n-2, height) + (abs(height[n] - height[n-2]));
        
        return (min(cost1, cost2));
        
}

int bruteRecursive(vector<int>& height) {
        return cost(height.size()-1, height);   
}

//* Method - II (DP, Memoization)

//. T.C -> O(n)
//. S.C -> O(n + n), O(n) for DP array and O(n) for recursive stack space
int betterMemoization(int n, vector<int>& height, vector<int>& dp) {
        
        if (n == 0) return 0;
        if (n == 1) return (abs(height[1] - height[0]));
        if (dp[n] != -1) return dp[n]; //! Return if result was memoized
        
        int cost1 = betterMemoization(n-1, height, dp) + (abs(height[n] - height[n-1]));
        int cost2 = betterMemoization(n-2, height, dp) + (abs(height[n] - height[n-2]));
        
        //! Store the result for future utilisation
        dp[n] = min(cost1, cost2);
        
        return dp[n];
        
}

int minCost(vector<int>& height) {
        
        vector<int>dp(height.size(), -1);
        
        return betterMemoization(height.size()-1, height, dp);
        
}

//* Method - III (DP, Tabulation, Unoptimized)

//. T.C -> O(n)
//. S.C -> O(n), only O(n) for DP array 
int betterTabulation(vector<int>& height) {
        
        vector<int>dp(height.size(), -1);
        
        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);
        
        for (int i = 2; i < height.size(); i++) {
            
            int cost1 = dp[i-1] + (abs(height[i] - height[i-1]));
            int cost2 = dp[i-2] + (abs(height[i] - height[i-2]));
            
            dp[i] = min(cost1, cost2);
        }
        
        return dp[height.size()-1];
        
}

//* Method - IV (DP, Tabulation, Optimised)
// Optimise for space complexity by using two varibales instead of a DP array

//. T.C -> O(n)
//. S.C -> o(1)
int optimal(vector<int>& height) {
        
        if (height.size() == 1) return 0;
        
        int prev2 = 0;
        int prev = abs(height[1] - height[0]);
    
        for (int i = 2; i < height.size(); i++) {
            
            int cost1 = prev + (abs(height[i] - height[i-1]));
            int cost2 = prev2 + (abs(height[i] - height[i-2]));
            
            int curr = min(cost1, cost2);
            
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
        
}