#include <bits/stdc++.h>
using namespace std;

//* Method - I (Optimal Approach)
// Just do n | (n+1)

//. T.C -> O(1)
//. S.C -> O(1)
int optimal(int n) {
        
        n = n | (n+1);
        
        return n;
    }