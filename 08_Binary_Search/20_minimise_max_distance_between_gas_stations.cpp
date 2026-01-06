#include <bits/stdc++.h>
using namespace std;

// Problem: https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

//* Method - I (Brute Force)

//. T.C -> O((k*n) + n)
//. S.C -> O(n-1)
long double bruteForce(vector<int>arr, int k) {
    int n = arr.size();

    vector<int>howMany(n-1, 0); // To keep track of number of gas stations placed between each original section (or original gas stations)

    for (int gasStation = 1; gasStation <= k; gasStation++) {
        long double maxSection = -1; // length of the maximum (each) section inside/between the two orginal gas stations
        int maxInd = -1; // tracks the index of the section (original) where the maximum value occurs

        for (int i = 0; i < n-1; i++) {
            long double diff = arr[i+1] - arr[i];
            long double sectionLength = (diff)/(long double)(howMany[i] + 1); // length of each section inside/between the two orginal gas station

            if (sectionLength > maxSection) {

                maxSection = sectionLength;
                maxInd = i;

            }
        }

        howMany[maxInd]++; // place the extra gas station between the place where the each sectionLength is maximum

    }

    // Finding the final answer after placing the k gasStations

    long double maxAns = -1;
    for (int i = 0; i < n-1; i++) {

        long double diff = arr[i+1] - arr[i];
        long double sectionLength = (diff)/(long double)(howMany[i] + 1);

        maxAns = max(maxAns, sectionLength);

    }

    return maxAns;

}




//* Method - II (Better Force)
//! Priority Queue
// push() and pop() takes O(log n), top() takes O(1)

//. T.C -> O(n*log(n) + k*log(n))
//. S.C -> O(n-1)
long double betterForce(vector<int>arr, int k) {
    int n = arr.size();

    vector<int>howMany(n-1, 0); 
    priority_queue<pair<long double, int>> pq;

    // Initially inserting all the sectionLengths in the priority quueue along with the index

    // O(n*log(n))
    for (int i = 0; i < n-1; i++) {
        pq.push({arr[i+1] - arr[i], i});
    }

    // O(k*log(n))
    for (int gasStation = 1; gasStation <= k; gasStation++) {

        auto topElement = pq.top();

        int maxSectionIndex = topElement.second;
        howMany[maxSectionIndex]++; // place a new gas station in this index

        // New section length at that index after placing a new gas station
        long double newSectionLength = (arr[maxSectionIndex+1] - arr[maxSectionIndex])/(long double)(howMany[maxSectionIndex] + 1);

        // Removing the old top maxSection element and now placing the new one at the same index
        pq.pop();
        pq.push({newSectionLength, maxSectionIndex});

    }

    return pq.top().first; // Maximum sectionLength will be at the top of the priority queue

}





//* Method - III (Optimal Solution)
//! Binary Search

//. T.C -> O(n*log(n) + n)
// Answer will lie between 0 to the maximum value of adjacent difference

// 'mid' is the required maximum distance between any to gas stations
bool isPossible(vector<int>arr, double mid, int k) {
        
        int extraGasStations = 0; // tracks total gas stations required for 'mid' max distance
        
        for (int i = 1; i < arr.size(); i++) {
            double diff = arr[i] - arr[i-1];
            
            int req = ceil(diff*1.0/mid) - 1; // number of gas stations to put in between to get a max distance between adjacent gas station as 'mid'
            
            extraGasStations += req;
        }
        
        if (extraGasStations > k) return false;
        return true;
        
}

//! Note: In question we had to check for 1e-6 decimal places, that's why we took diff as 1e-6
double minMaxDist(vector<int> &stations, int k) {
        
        int n = stations.size();
        
        // low is '0' and high is the maximum distance between any two gas stations
        double low = 0, high = 0;
        
        for (int i = 1; i < n; i++) {
            double diff = stations[i] - stations[i-1];
            if (diff > high) high = diff;
        }
        
        double ans = high;

        double diff = 1e-6; // According to the question
        
        while (high-low > diff) {

            double mid = (low + high)/2.0;
            
            if (isPossible(stations, mid, k)) {
                ans = mid;
                high = mid; // ! We don't do 'mid - 1' as that will eliminate a lot of numbers (as we want till 1e-6 decimal, hence we put high as mid)
            }
            
            else {
                low = mid;
            }
            
        }
        
        return ans;
}