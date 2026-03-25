#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Loop from 1 to N, and check which are divisible by n
//. T.C -> O(n)
//. S.C -> O(divisors)

//* Method - II (Optimal Approach)
// Only loop till sqrt(n), and find both the diviors in once

//. T.C -> O(sqrt(n))
//. S.C -> O(divisors)
void print_divisors(int n) {
    
    vector<int>ans;
    
    for (int i = 1; i*i <= n; i++) {
        if (n%i == 0) {
            ans.push_back(i);
            if(n/i != i) ans.push_back(n/i);
        }
    }
    
    for (auto elem : ans) {
        cout << elem << " ";
    }
}