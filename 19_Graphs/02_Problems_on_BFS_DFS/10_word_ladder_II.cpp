#include <bits/stdc++.h>
using namespace std;

//? Pg: 145 

//! Note: Brute Force is enough for Interviews but it will only pass testcases in GFG and will give MLE in LeetCode

//* Method - I (Brute Force, For Interview)
// Slight modification to the previous problem's solution. Take a queue DS and store th list of words in it. Start with the begin word, try to find all its next word, and add the new added word along with this list into the queue and pop the first level element. Also, only pop from the set, when we have dealt with the entire level lists. Also try to find the next word of the last added word in the list.

//. T.C -> cannot determine

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

    vector<vector<string>> ans;

    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>>q;
    q.push({beginWord});

    while(!q.empty()) {
        int size = q.size();

        // Keep track of used words to be removed after the entire elements of the level is used
        vector<string>toBeRemoved;

        for (int i = 0; i < size; i++) {
            
            // Base array
            vector<string>arr = q.front();
            string str = q.front().back();
            // When we encounter the end word in the level
            if (str == endWord) {
                while(!q.empty()) {
                    if(q.front().back() == endWord) ans.push_back(q.front());
                    q.pop();
                }
                break;
            }

            q.pop();


            for (int ind = 0; ind < str.size(); ind++) {
                for (char ch = 'a'; ch <= 'z'; ch++) {

                    if(ch == str[ind]) continue;

                    string temp = str;
                    temp[ind] = ch;

                    // Add temp string to base array and add to the queue, then tranform base array back to original and add temp to toBeRemoved 
                    if (st.find(temp) != st.end()) {
                        arr.push_back(temp);
                        q.push(arr);
                        arr.pop_back();
                        toBeRemoved.push_back(temp);
                    }
                }
            }

        }

        // Remove all the toBeRemoved strings (srings already used) from the set
        for(auto elem : toBeRemoved) {
            if (st.find(elem) != st.end()) st.erase(elem);
        }
    }

    return ans;
    
}

//* Method - II (Optimal Solution, Not Ideal for Interviews)

// Todo soon!