#include <bits/stdc++.h>
using namespace std;

//? Pg: 77

//* Method - I (Brute Force)
// Check all possible substrings and check if it is possible or valid

//. T.C -> O(3*n^2)
//. S.C -> O(3)

bool isValid(vector<int>& freq) {

    bool isAllThreePresent = true;
    for (auto elem : freq) {
        if(elem == 0) isAllThreePresent = false;
    }
    return isAllThreePresent;
}
int brute(string s) {

    int ans = 0, n = s.size();

    for (int i = 0; i < n; i++) {
        vector<int>freq(3, 0);
        for (int j = i; j < n; j++) {
            freq[s[j] - 'a']++;

            // Checks if all the characters are present in it
            if (isValid(freq)) ans++;
        }
    }

    return ans;        
}

//* Method - II.I (Better Solution, My Method, Hard Solution)
//! naah, i'd skip this method, because wtf?

// Kind of similar to my better solution in binary subarrays. I am trying to find the minimum window with three unique chracteres, then I am finding all the substrings I can make using this window, so using the elements in right and left, but during left, we have to make suree to not overlap with some other substring that we already counterd before. That's why we keep a lastIndex, which we will use to find total elements in the leftSide of our winodw to avoid overalpping substrings, for right, consider all of them, and just use the formula (1+ leftSide + rightSide + leftSide*rightSide) or simply (1+leftSide)*(1+rightSide)

//. T.C -> O(n)
//. S.C -> O(3)

bool isValid(vector<int>& freq) {
    bool isAllThreePresent = true;
    for (auto elem : freq) {
        if(elem == 0) isAllThreePresent = false;
    }
    return isAllThreePresent;
}
int betterI(string s) {

    int ans = 0, n = s.size();

    int lastIndex = -1;

    int left = 0, right = 0;
    vector<int>freq(3, 0);

    while(left < n && right < n) {

        while(right < n) {
            freq[s[right] - 'a']++;
            if (isValid(freq)) break;
            right++;
        }

        while(left < right) {
            freq[s[left] - 'a']--;
            if (!isValid(freq)) {
                break;
            }
            left++;
        }

        int rightSide = n-right-1;
        int leftSide = left-lastIndex-1;

        ans += (1+leftSide)*(1+rightSide);

        lastIndex = left;

        left++;
        right++;
    }

    return ans;        
}

//* Method - II.II (Better Solution, My Method, Easy Solution)
// Find the total substrings that have atMost3Characters and subtract it from total substrings atMost2Characters

//. T.C -> O(n)
//. S.C -> o(3)

// Helper function that gives total unique chracters in stored in freq
int totalChar(vector<int>& freq) {
    int cnt = 0;

    for (auto elem : freq) {
        if (elem != 0) cnt++;
    }

    return cnt;
}

int atMost2Characters(string s) {

    vector<int>freq(3, 0);
    int ans = 0, left = 0, n = s.size();

    for (int right = 0; right < n; right++) {

        freq[s[right]-'a']++;
        while(left < n && totalChar(freq) > 2) {
            freq[s[left]-'a']--;
            left++;
        }
        
        ans += (right-left+1);

    }

    return ans;

}

int betterII(string s) {

    long long ans = 0, n = s.size();

    // (n*(n+1))/2 -> atMost3Characters, here since only 3 characters in s, so all possible substrings will be atMost3Characters
    ans = (n*(n+1))/2 - atMost2Characters(s);

    return ans;     
}

//* Method - II.III (Optimal Solution, TUF Method, Easiest Method)
//? Pg: 77

// A pointer iterates the entire string, and index of lastSeen is trackerd by a hashMap called lastSeen, iterate and once we find all the three chracters in lastSeen, total substrings for the current element at end will be the min(of all lastSeen) + 1 and so on

//. T.C -> O(n), single pass
//. S.C -> O(1)
int optimal(string s) {

    int ans = 0, n = s.size();

    vector<int>lastSeen(3, -1);

    for (int i = 0; i < n; i++) {
        lastSeen[s[i]-'a'] = i;
        
        // Checks if all chracters seen
        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {

            // Find the lowest index of all
            int mini = min(lastSeen[0], lastSeen[1]);
            mini = min(mini, lastSeen[2]);

            // Form all the substrings from the left of the loswest index + the window itself
            ans += (mini + 1);
        }
    }

    return ans;
    
}