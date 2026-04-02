#include <bits/stdc++.h>
using namespace std;

//? Pg:144 

//* Method - (BFS)

// First make an unordered_set and include all the wordList words in it, then push the beginWord in queue and delte it from set (if exists), each time, we consider the queue string, try to modify the character index by index from a to z, and if it exists in set, include it in queue and remove from set, to avoid reusing ang going thorugh the same path, then at any point if we enocunter our endWord, then simply return the level or at the end, return 0

//. T.C -> O(wL*26*n*1) in average for unordered set; wL is each wordLength, n is the number of words in wordList or O(wL*26*n*log(n)) ffor ordered set 
//. S.C -> O(2n), for queue and set
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    unordered_set<string>st(wordList.begin(), wordList.end());

    queue<string>q;
    q.push(beginWord);
    if (st.find(beginWord) != st.end()) st.erase(beginWord);

    int level = 1;

    while(!q.empty()) {

        int size = q.size();

        for (int i = 0; i < size; i++) {
            // search differing character from the  first to last word with all combination

            string s = q.front();
            q.pop();

            if (s == endWord) {
                return level;
            }
            
            for (int ind = 0; ind < s.size(); ind++) {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    string temp = s;
                    temp[ind] = ch; // Get the modified string

                    // If exists in set, just add to queue and delete the string from set to avoid reusing it again later
                    if (st.find(temp) != st.end()) {
                        q.push(temp);
                        st.erase(temp);
                    }
                }
            }
        }

        level++;

    }

    return 0;
    
}