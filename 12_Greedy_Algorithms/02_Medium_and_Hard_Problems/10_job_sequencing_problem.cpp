#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)

// Concept: Try to delay the job as much as possible. Do the job on (or before) deadline.

// Make an array with profit and deadline and sort it in descending order. Make another hash array called 'jobDone', make it of size equal to maximum deadline[i] and inititalize it with -1. Now iterate in the job array (which we created) and get the deadline of each job.
// Gredily, we will do the job i on the day of its deadline or just before deadline if a job already done on that day. 

// So try to do job i on deadline of job i or just before that and make the hasArray as 1 for each day that we do the job. 

//! Quadratic Time Complexity
//. T.C -> O(n + n*log(n) + n*m), where m is a variable in each iteration, 'm' is the deadline of each job in the iteration and n is the total jobs
//! m in the worst case can be n, hence making the time complexity as O(n^2)
//. S.C -> o(2n + m), 2n for the profit+deadline array and n for the hash array
//! Here m is the maximum deadline
vector<int> bruteForce(vector<int> &deadline, vector<int> &profit) {
        
        vector<pair<int, int>>job;
        int maxDays = 0; // Maximum deadline of any job
        
        int totalJobs = 0, totalProfit = 0;
        
        for(int i = 0; i < deadline.size(); i++) {
            job.emplace_back(profit[i], deadline[i]);
            maxDays = max(maxDays, deadline[i]);
        }
        
        // Sorting in descending order
        sort(job.begin(), job.end());
        reverse(job.begin(), job.end());
        
        // Index of jobDone represents the dayth index. So ith index mean (i+1) day
        vector<int>jobDone(maxDays, -1);
        
        for (int i = 0; i < job.size(); i++) {

            // maximum deadline day'th index
            int maxInd = job[i].second - 1;
            
            while(jobDone[maxInd] != -1 && maxInd >= 0) {
                maxInd--;
            }
            
            // If no job was done on maxInd'th day
            if (maxInd >= 0 && jobDone[maxInd] == -1) {
                jobDone[maxInd] = 1;
                totalJobs++;
                totalProfit += job[i].first;
            }
        }
        
        vector<int>ans = {totalJobs, totalProfit};
        
        return ans;
        
}

//* Method - II 
//! Do the inner loop for findining the day equal to or less than deadline with DSU in O(1)

//* Method - II.V (Easier)
//! Using min-heap
// We will use the concept of min-heap to solve the problem. We will use priority_queue for implementing the min-heap

// Make an array and store the deadline and profit of each job and sort them in ascending order. After that iterate in it and if the deadline of current job is greater then the size of priority_quee(in min-heap syntax) then add the profit, else if the top (the minimum element) of the quuee is smaller then the incoming, then pop it and add the incoming profit, at the end calculate the totoal profit in the heap

// Hence, we pop the smaller profit job everytime we find a job with higher profit.

//. T.C -> O(n*log(n)), for sorting and iterating in loop and push & pop in heap
//. S.C -> O(2n + m), 2n for the array and m is maximum deadline
vector<int> optimalApproachMinHeap(vector<int> &deadline, vector<int> &profit) {
        
        vector<pair<int, int>>job;
        
        for (int i = 0; i < deadline.size(); i++) {
            job.push_back({deadline[i], profit[i]});
        }
        
        sort(job.begin(), job.end());
        
        //! Syntax for implemnting min-heap
        priority_queue<int, vector<int>, greater<int>>pq;
        // Size of the above represents total jobs. Note: Jobs can never be greater than the deadline of any job
        
        for (int i = 0; i < job.size(); i++) {

            // If deadline is more then the size, then push it
            if (job[i].first > pq.size()) pq.push(job[i].second);
            
            // Else replace the top if smaller
            else if (!pq.empty() && pq.top() < job[i].second) {
                pq.pop();
                pq.push(job[i].second);
            }
        }
        
        int totalJobs = pq.size();
        
        int totalProfit = 0;
        while(pq.size()) {
            totalProfit += pq.top();
            pq.pop();
        }
        
        vector<int>ans = {totalJobs, totalProfit};
        return ans;
        
}