#include <bits/stdc++.h>
using namespace std;

// Do a simple BFS over all the values, if we see a value, mark it seen, to avoid recomputation again, if we find a unique value, then only push it in queue, at the end, if we find our target, then return level, else return -1

//. T.C -> O(arr_size*1e5)
//. S.C -> O(1e5)
int minimumMultiplications(vector<int>& arr, int start, int end) {
    
    int MOD = 1e5, level = 0;
    
    queue<int>q;
    vector<bool>seen(1e5, false);
    
    q.push(start);
    seen[start] = true;
    
    while(!q.empty()) {
        
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            
            int node = q.front();
            q.pop();
            
            if (node == end) return level;
            
            for (int j = 0; j < arr.size(); j++) {
                int temp = (node*arr[j])%MOD;
                
                if(!seen[temp]) {
                    seen[temp] = true;
                    q.push(temp);
                }
            }
            
        }
        
        level++;
    }
    
    return -1;
    
}