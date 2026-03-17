#include <bits/stdc++.h>
using namespace std;

// Burst time is the execution time. All the process were started at t = 0, so priotise shortest burst time tasks first. Calculate start time of each task. Sort the array to get the order of tasks. Then first task at t = 0, second task at t = 0+bt[0], third task start time at t = 0+bt[0]+bt[1] and so on. Find the average of these start times

//. T.C -> O(n*log(n))
long long solve(vector<int>& bt) {
        
        sort(bt.begin(), bt.end());
        
        long long ans = 0;
        int n = bt.size();
        
        long long sum = 0; // This is the start time of ith job
        
        for (int i = 0; i < n-1; i++) {
            
            sum += bt[i];
            
            ans += sum;
            
        }
        
        ans /= n;
        
        return ans;
        
}