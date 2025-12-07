#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Similar to Method I of 27_count_subarrays_sum_equal_k

//. T.C -> O(n^3)
//. S.C -> O(1)

//* Method - II (Better Solution)
// Similar to Method II of 27_count_subarrays_sum_equal_k

//. T.C -> O(n^2)
//. S.C -> O(1)

//* Method - III (Optimal Solution)
// Similar to Method III of 27_count_subarrays_sum_equal_k

//. T.C -> O(n*log(n)) for ordered map
//. S.C -> O(n)

// If xor of a portion is x and we need to find a subarray with xor k, then find a portion with xor x^k, because in total (x^k) ^ k => x, which is the total portion xor
long optimalSolution(vector<int> &arr, int k) {
        
        map<long long, int>mp;
        
        long long int xoro = 0;
        long long int cnt = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            
            xoro ^= arr[i];
            
            if (xoro == k) cnt++;
            
            if (mp.find(xoro^k) != mp.end()) {
                cnt += mp[xoro^k];
            }
            
            mp[xoro]++;
            
        }
        
        return cnt;
        
    }