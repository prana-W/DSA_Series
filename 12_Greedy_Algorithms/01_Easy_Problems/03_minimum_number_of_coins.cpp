#include <bits/stdc++.h>
using namespace std;

// Really? You need solution for this??

//. T.C -> O(1)
//. S.C -> O(1)
int findMin(int num) {
        
        int n = num;
        
        int ans = 0;
        
        ans += n/10;
        n = n%10;
        
        ans += n/5;
        n = n%5;
        
        ans += n/2;
        n = n%2;
        
        ans += n/1;
        
        return ans;
        
    }