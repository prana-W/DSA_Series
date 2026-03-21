#include <bits/stdc++.h>
using namespace std; 

//? Pg: 75 

//! Note: Here question is asking to partition the string such that every partition is a palindrome. It is not saying all substrings of the partition should be palindrome, it is saying all the parittion should be palindrome

//. T.C -> O(2^n * n * n), O(2^n) as there are n possible partitions and it either can or cannot be split from that partition. O(n) is taken to build each string and push it to ds and ans and also O(n) is taken for each due to palindrome check
//. S.C -> O(n), for recurive stack space

bool isPalindrome(string s) {
    int i = 0, j = s.size()-1;

    while(i <= j) {
        if (s[i] != s[j]) return false;

        i++;
        j--;
    }

    return true;
}
void solve(int index, string& s, vector<string>& ds, vector<vector<string>>& ans) {

    if (index == s.size()) {
        ans.push_back(ds);
        return;
    }

    // Acumulator that holds the substring that might be partioned
    string str;

    for (int i = index; i < s.size(); i++) {

        str += s[i];

        // If str accumulated is not palindrome, don't push it to partition, simply move on
        if (!isPalindrome(str)) continue;

        ds.push_back(str);
        solve(i+1, s, ds, ans);
        ds.pop_back(); 
    }


}
vector<vector<string>> partition(string s) {

    vector<string>ds; // It stores the partition of the strings
    vector<vector<string>>ans;

    solve(0, s, ds, ans);

    return ans;
    
}