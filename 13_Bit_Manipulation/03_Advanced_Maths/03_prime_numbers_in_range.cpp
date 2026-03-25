#include <bits/stdc++.h>
using namespace std;

//? Problem: Given an integer n, return the number of prime numbers that are strictly less than n.

//! Sieve of Erthosthenes

//. T.C -> O(n * log(log(n)))
//. S.C -> O(n)
int countPrimes(int n) {

    int ans = 0;
    vector<bool>sieve(n, true);

    for (int i = 2; i*i < n; i++) {
        for (int j = i*i; j < n; j += i) {
            sieve[j] = false;
        }
    }

    for (int i = 2; i < n; i++) {
        if(sieve[i]) ans++;
    }

    return ans;
    
}