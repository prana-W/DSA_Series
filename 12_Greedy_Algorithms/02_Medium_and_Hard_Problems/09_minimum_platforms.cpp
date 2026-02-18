#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force) 
// Make an array of size 2400 and each element as 0. Now make a loop that iterates from 0 to 2399, this loop represents an instant of time. Now for every instant of time, iterate in the input array and check if the train is in station at that given point, if yes, then increase the counter for that instant of time. This way at the end we loop for the time instant at which the counter (number of trains) is maximum, this is the minimum platforms required

//. T.C -> O(2400 * n)
//. S.C -> O(2400)
int bruteForce(vector<int>& arr, vector<int>& dep) {
        
        int n = arr.size();
        
        vector<int>time(2400, 0);
        
        for (int i = 0; i < time.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (i >= arr[j] && i <= dep[j]) {
                    time[i] = time[i] + 1;
                }
            }
            
        }
        
        int ans = INT_MIN;
        
        for (auto elem : time) {
            ans = max(ans, elem);
        }
        
        return ans;
        
}


//* Method - II (Better Solution)
// Iterate according to time, if we find arrival, increase the counter, else decrease the counter, find the maximum counter was at any given instant.

// So, create an array with arrival and deptrtutre time in it, and make it sorted (NOTE: If arrival and departure time is at same time, first put arrival and then deparrture, now if arrival, icnrease counter by 1, else decrease by 1)

//! 'static' is necessary for sort to work in Solution Class

// This sorts pair which has first element smaller than the second, also if both are same, allow the arrival first

//. T.C -> O(n + (2n)*log(2n) + 2n)
//. S.C -> O(2n)
static bool comp(pair<int, int>p1, pair<int, int>p2) {
      if (p1.first < p2.first) return true;
      if (p1.first == p2.first && p1.second > p2.second) {
        return true;
      } 
      
      return false;
  }

  int better(vector<int>& arr, vector<int>& dep) {
        
        int n = arr.size();
        
        vector<pair<int, int>>train;
        
        for (int i = 0; i < n; i++) {
            train.push_back({arr[i], 1}); // '1' is for arrival
            train.push_back({dep[i], -1}); // '-1' is for departure
        }
        
        sort(train.begin(), train.end(), comp);
        
        int ans = 0;
        int cnt = 0;
        
        for (int i = 0; i < train.size(); i++) {
            cnt += train[i].second;
            ans = max(ans, cnt);
        }
        
        return ans;
        
}

//* Method - III (Optimal Solution)
// Do the above solution but without extra space

//. T.C -> O(2*n*log(n) + 2n)
//. S.C -> O(1)
int optimalApproach(vector<int>& arr, vector<int>& dep) {
        
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 0, j = 0;
        
        int cnt = 0;
        int ans = 0;
        
        while(i < n && j < n) {
            if (arr[i] <= dep[j]) {
                cnt++;
                i++;
            }
            else {
                cnt--;
                j++;
            }
            
            ans = max(ans, cnt);
            
        }
        
        while(i < n) {
            cnt++;
            i++;
            
            ans = max(ans, cnt);
        }
        while(j < n) {
            cnt--;
            j++;
            
            ans = max(ans, cnt);
        }
        
        return ans;
}