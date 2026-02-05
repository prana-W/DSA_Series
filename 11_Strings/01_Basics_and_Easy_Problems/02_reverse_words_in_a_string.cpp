#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force)

// Convert the given string into an array of words, reverse the order of words and at alst form back a integrated string with spaces in between

//. T.C -> O(3n)
//. S.C -> O(n), we create a array of strings, n is the number of characters
string bruteForce(string s) {

    vector<string>ans;

    // Forming an array of all the words (no spaces)
    string temp;
    for (auto elem : s) {

        if (elem != ' ') temp += elem;
        else if (temp != "") {
            ans.push_back(temp);
            temp = "";
        }

    }
    if (temp != "") ans.push_back(temp);

    // Reversing the order of words
    reverse(ans.begin(), ans.end());

    // Forming back a integrated string with spaces in between
    string fAns;
    for (auto elem : ans) {
        fAns += elem;
        fAns += " ";
    }
    fAns.pop_back(); // to remove the last space

    return fAns;
        
}

//* Method - II (Better Solution)

// Start from the end and store the word in temp string, rreverse the temp and add to answer string

//. T.C -> O(2n)
//. S.C -> O(n) for the temp string
string betterSolution(string s) {

    string ans;

    string temp;
    for (int i = s.size()-1; i >= 0; i--) {

        char elem = s[i];

        if (elem == ' ' && temp.size() > 0) {
            reverse(temp.begin(), temp.end());

            ans += temp;
            ans += ' '; 

            temp = "";
        }

        // Ignore if whitespace and temp is empty
        else if (elem == ' ') continue;
        else temp += elem;
    }


    // To flush the residual
    reverse(temp.begin(), temp.end());
    if (temp.size() > 0) {
        ans += temp;
        ans += ' '; // To maintain consistency
    }

    // Remove the last unncessary space
    ans.pop_back();

    return ans;
        
}

//* Method - II.V (Better Solution)

// Using pointers and the same logic as above, we can get the start and end pointere of each word, use substr built in function to create the word and add it to the answer

// Here still, .substr takes a max of O(n) space as a temp string is created for this

//. T.C -> O(n)
//. S.C -> O(n), due to .substr, but apart from that no extra space
string betterSolutionII(string s) {

        int n = s.size();

        string ans;

        int i = n-1;
        int end = n-1;

        while (i >= 0) {

            while(end >= 0 && s[end] == ' ') {
                end--;
            }

            i = end;

            while(i >= 0 && s[i] != ' ') {
                i--;
            }

            if (end < 0) break;

            string word = s.substr(i+1, end-i);
            ans += word;

            ans += ' ';

            end = i;
        }

        ans.pop_back();

        return ans;
        
}

//* Method - III (Optimal Solution)

// Mnaully iterate to extract the word, isntead of using .substr and store it directly in the ans

// Here no extra space is needed

//. T.C -> O(n)
//. S.C -> O(1), no extra space is required
string optimalSolution(string s) {

        int n = s.size();

        string ans;

        int i = n-1;
        int end = n-1;

        while (i >= 0) {

            while(end >= 0 && s[end] == ' ') {
                end--;
            }

            i = end;

            while(i >= 0 && s[i] != ' ') {
                i--;
            }

            if (end < 0) break;

            //! Manual Iteration
            for (int j = i+1; j <= end; j++) {
                ans += s[j];
            }

            // string word = s.substr(i+1, end-i);
            // ans += word;

            ans += ' ';

            end = i;
        }

        ans.pop_back();

        return ans;
        
}