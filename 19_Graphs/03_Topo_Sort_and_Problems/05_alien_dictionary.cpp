#include <bits/stdc++.h>
using namespace std;

//? Problem: https://www.geeksforgeeks.org/problems/alien-dictionary/1

// Just find if the cycle exits using Kahn's Alforitm, if it deos return not possible else just return the Topo Sort

// Create an adjancy list and indegree of size 26 and also a present array that keeps track of all the actual unique characrtrer present in the words array, whenver creating any adjancey list or indegree first check if the character is acutally present

// Also if the left string is greater in size than right string and there is no differing character between thee two, then such a sequence is invalid as it is not lexographically correct (if no differing chracter, then the smaller should occur first), so just return invalid

//. T.C -> O(n*k + 26 + e), n is total words, k is average length of each word ans e is the total number of edges
//. S.C -> O(26+e)
string findOrder(vector<string> &words) {
    
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);
    
        // Mark all characters in the words as present
        for (auto word : words) {
            for (char ch : word) {
                present[ch - 'a'] = true;
            }
        }
    
        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            
            string a = words[i];
            string b = words[i + 1];
            
            int len = min(a.size(), b.size());
            bool found = false;
    
            for (int j = 0; j < len; j++) {
                if (a[j] != b[j]) {
                    int u = a[j] - 'a';
                    int v = b[j] - 'a';
                    
                    adj[u].push_back(v);
                    indegree[v]++;
                    
                    found = true;
                    break;
                }
            }
    
            // If left size is greater than right and no differing character occurs then the words are not in lexigraphically increasing order and hence return false
            if (!found && a.size() > b.size()) return "";
        }
    
        // Kahn's BFS for all the present nodes
        
        queue<int> q;
        string ans;
    
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }
    
        while (!q.empty()) {
            int node = q.front();
            q.pop();
    
            ans.push_back(node + 'a');
    
            for (auto nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
    
        // Count total unique chars in words
        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i]) total++;
        }
    
        // Cycle check
        if (ans.size() != total) return "";
    
        return ans;
}