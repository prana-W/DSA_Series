#include <bits/stdc++.h>
using namespace std;

//? Problem: Given a number n. Find its unique prime factors in increasing order.

//. T.C -> O(sqrt(n))
//. S.C -> O(log(n)), for storing ans
vector<int> primeFac(int n) {
    
    vector<int>ans;

    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) ans.push_back(i);
        while(n%i == 0) {
            n /= i;
        }
    }
    
    if (n > 1) ans.push_back(n);
    
    return ans;
}

//! Insight: If we want to find the prime factors of many numbers, then isntead of doing this method for n times, we can precompute spf for the largest number out of all and use that to quickly find the prime factors of all numbers. This method is much more faster

//! For SPF:

// Precompute: O(n * log(log(n))), n is the largest number out of all, or the maximum bound of all numbers
// Each query (or prime factors of each number): O(log(k)), k is the indivisual number, for N elements, is will take roughly O(N * log(k)), where k is the number in each time 

// Total T.C -> O(n*log(log(n))) + O(total_elements * log(k))

int MAX = 1e6;
vector<int>spf(MAX+1);
 
void computeSPF() {
    
    // Initialise all spf to itslef
	for (int i = 0; i < MAX+1; i++) {
		spf[i] = i;
	}
 
	for (int i = 2; i*i < MAX+1; i++) {
        
        // If i is prime
		if (spf[i] == i) {
			for (int j = i*i; j < MAX+1; j += i) {
                // If j is not assgined any spf
				if (spf[j] == j) spf[j] = i;
			}
 
		}
		
	}
 
}

// Calculating prime factors of all the numbers
int main() {

    vector<int>arr;
    int n = arr.size();

    for (int i = 0; i < n; i++) {

        unordered_map<int, int>mp;

        int elem = arr[i];

        while(elem != 1) {

            mp[spf[elem]]++;
            elem /= spf[elem];

        }

    }


}

