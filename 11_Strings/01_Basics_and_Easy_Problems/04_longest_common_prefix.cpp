#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)
// Get the smallest lenght of the string, this could the maximum length of the common prefix string, then just choose a target for each character and check if it exists in the entire array of string, else just return the answer

//. T.C -> O(x * n), x is the length of the smallest string
//. S.C -> O(1), no extra space taken. If considering the sapce taken to store answer then O(x)
string bruteForce(vector<string>& strs) {

        int maxLength = INT_MAX;
        string ans = "";

        for (auto elem : strs) {
            int size = elem.size();
            maxLength = min(maxLength, size);
        }

        int i = 0;
        while(i < maxLength) {

            char target = strs[0][i];

            for (auto elem : strs) {
                if (elem[i] != target) {
                    return ans;
                }
            }

            ans += target;
            i++;
        }

        return ans;
        
}

//* Method - II (Optimal Solution)

// First sort the array and simply compare the first and the last element. If both has x common prefix, all the elements in between would also have it, as they would be lexigraphically sorted

//. T.C -> O(n*log(n) + m), n is the size of array and m is the size of the smallest string element
//. S.C -> O(1) as no extra space or O(x) for the answer string
string optimalSolution(vector<string>& strs) {

        if (strs.size() <= 1) return strs[0];

        sort(strs.begin(), strs.end());

        int i = 0;
        string ans = "";

        while(i < strs.front().size()) {

            if (strs.front()[i] == strs.back()[i]) {
                ans += strs.front()[i];
                i++;
            }
            else break;

        }

        return ans;
        
}