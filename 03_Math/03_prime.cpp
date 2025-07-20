#include <bits/stdc++.h>
using namespace std;

//* Prime Number
// A number which has exactly only two factors, one and itself.

// Check if a number is a prime number

//* Method-I (Brute Force)
//. T.C -> O(n)
void checkPrimeBruteForceApproach(int n) {

    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (n%i == 0) count++;
    }

    if (count == 2) cout << "Prime!" << endl;
    else cout << "Not a Prime!" << endl;

}

//* Method-II (Optimised Approach)
// Look till sqrt(n) and count all the factors
//. T.C -> O(sqrt(n))
void checkPrimeOptimised(int n) {

    int cnt = 0;

    for (int i = 1; i <= sqrt(n); i++) {

        if (n%i == 0) {
            cnt++;
            if (n/i != i) cnt++; // If the other factor is different, then count that as well
        }   

    }

    if (cnt == 2) cout << "Prime!" << endl;
    else cout << "Not a Prime!" << endl;
}
