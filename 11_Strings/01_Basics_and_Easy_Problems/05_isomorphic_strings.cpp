#include <bits/stdc++.h>
using namespace std;

//* Method - I (Better Solution)
// Make one-on-one mapping from both sides. If repeat i.e. if found one to many or many to one, return false

//. T.C -> O(n) in average and O(n^2) in worst if unordered_map or O(nlog(n)) if ordered map
//. S.C -> O(n) for the hash map
bool betterSolution(string s, string t) {

        unordered_map<char, char>mp, mp2;

        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = t[i];
            }
            else if (mp[s[i]] != t[i]) return false;

            if (mp2.find(t[i]) == mp2.end()) {
                mp2[t[i]] = s[i];
            }
            else if (mp2[t[i]] != s[i]) return false;
        }

        return true;
        
}

//* Method - II (Optimal Solution)

//! Here time complexity is the best. As even in the worst we are taking O(n)

// Just use two arrays as a hash array. Both of constant space of 256 and store the ascii values. Make two-way mapping. s to t and to to s and check if only one-to-pne pairing occurs in both ways

//. T.C -> O(n), even in worst case
//. S.C -> O(256 + 256), for the two hash Arrays
bool isIsomorphic(string s, string t) {

        int m1[256] = {0}; // To track s(key) to t(val)
        int m2[256] = {0}; // To track t to s

        for (int i = 0; i < s.size(); i++) {
            int a1 = s[i]; // ASCII of s[i]
            int a2 = t[i]; // ASCII of t[i]

            if (m1[a1] != 0 && m1[a1] != a2) return false;

            if (m2[a2] != 0 && m2[a2] != a1) return false;

            m1[a1] = a2;
            m2[a2] = a1;
        }

        return true;
        
}