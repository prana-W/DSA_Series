#include <bits/stdc++.h>
using namespace std;

//* Method - I (Sorting)
// Sort both and check if equal

//. T.C -> O(n*log(n))
//. S.C -> O(1)
bool CheckAnagrams(string str1, string str2) {
    
    if (str1.length() != str2.length()) return false;  

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if (str1 == str2) return true;

    return false; 
}

//* Method - II (Using Hash Array)
// Check if size equal or not. Then make a hash array of size 26 and initialise with 0, iterate thorugh the string, for each char in s, increment in arr and for each char in t, decremenet in arr. If it would have been anagram, the net would be 0 at the end, else not

//. T.C -> O(n)
//. S.C -> O(26)
bool lowercase(string s, string t) {

    if (s.size() != t.size()) return false;

    int arr[26] = {0};

    for (int i = 0; i < s.size(); i++) {
        int a1 = s[i] - 'a';
        int a2 = t[i] - 'a';

        arr[a1] = (arr[a1] + 1);
        arr[a2] = (arr[a2] - 1);
    }

    for (auto elem : arr) {
        if (elem != 0) return false;
    }

    return true;
        
}

//! For any unicode characters, amke a hash array of size 256 and do the same algo as above.

//! We can also implement a hash map