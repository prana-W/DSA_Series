#include <bits/stdc++.h>
using namespace std;

//? Problem: https://www.geeksforgeeks.org/problems/alien-dictionary/1

// Just find if the cycle exits using Kahn's Alforitm, if it deos return not possible else just return the Topo Sort

// Create a graph as we move from left to right word, node exiets between first letter that differs, if left word is smaller and right word is longer and no word differs then no edge will exist, if left word is greater than right node and there is no differing letter, then the words are not in lexigraphicllay order, so just return ""

//. T.C -> O(n*k + v + e), n is total words, k is average length of each word, v is at max 26, and e is the total number of edges
//. S.C -> O(v+e)

string findOrder(vector<string> &words) {
    
    unordered_map<int, set<int>>adj;
    unordered_map<int, int>indegree;
    
    for (int i = 0; i < words.size(); i++) {
        
        // Initialising indegree in map for all the characters
        for(int j = 0; j < words[i].size(); j++) {
            indegree[words[i][j]-'a'];
        }
        
        if(i == words.size()-1) continue;
        
        // true if some character differs
        bool flag = false;
        
        for (int j = 0; j < min(words[i].size(), words[i+1].size()); j++) {
            
            int u = words[i][j] - 'a';
            int v = words[i+1][j] - 'a';
            
            // If differs
            if(u != v) {

                // If not already added, then add and increase the indegree
                if(adj[u].find(v) == adj[u].end()) {
                    adj[u].insert(v);
                    indegree[v]++;
                }
                
                // break whenver we get a differing character
                flag = true;
                break;  
                
            }
        }
        
        // If left size is greater than right and no differing character occurs then the words are not in lexigraphically increasing order and hence return false
        if(!flag && words[i].size() > words[i+1].size()) return "";
    }
    
    // Topo Sort
    
    queue<int>q;
    string ans;
    
    for (auto elem : indegree) {
        if(elem.second == 0) q.push(elem.first);
    }
    
    while(!q.empty()) {
        
        int node = q.front();
        q.pop();
        
        ans.push_back('a' + node);
        
        for(auto elem : adj[node]) {
            
            indegree[elem]--;
            if(indegree[elem] == 0) q.push(elem);
            
        }
    }
    
    // If size is not equal to indegree size (total unique characters in words) then a cycle exits and hence not a valid answer will exist
    if(ans.size() != indegree.size()) return "";
    return ans;
    
}