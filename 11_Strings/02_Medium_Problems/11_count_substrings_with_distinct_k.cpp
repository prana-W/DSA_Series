#include <bits/stdc++.h>
using namespace std;

//. T.C -> O(n)
//. S.C -> O(26)

// Concept: To calculate exactly k easily, we make a helper funciton that calculates at most k. Now find atMostK for k and k-1, and their difference would be the total substrings with exactly k.

//! Note: Max number of substrings can be approximately near to n^2, that's why we have used long long int (just in case)

//! Note: Here we have used a hash array instead of hash map to further optimise the solution as earlier hash map was giving TLE at very large test cases

// Helper Function to count substrings with at most k distinct characters 
long long atMostK(string& s, int k) {
    // Left pointer and result
    long long int left = 0;
    long long res = 0;
    // Frequency map
    vector<char>freq(26, 0);
    int distinct = 0;

    // Iterate through string with right pointer
    for (long long int right = 0; right < s.size(); right++) {
        
        int ind = s[right] - 'a';
  
        if (freq[ind] == 0) distinct++;
        freq[ind] += 1;

        // Shrink window if distinct characters exceed k
        while (distinct> k) {
            
            int ind2 = s[left] - 'a';
            
            freq[ind2] -= 1;
            if (freq[ind2] == 0) distinct--;
            left++;
        }

        // Count substrings in current window ending at right
        res += (right - left + 1);
    }
    return res;
}
    
int countSubstr(string& s, int k) {
        
        long long x1 = atMostK(s, k);
        long long x2 = atMostK(s, k-1);
        
        return (x1-x2);
        
}