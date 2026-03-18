#include <bits/stdc++.h>
using namespace std;

//* Method - I (Bit Masking Method)
// Create a bit mask from 0 till less than 1 << n, each bit represents if a particular element is included or not

//. T.C -> O(2^n * n)
//. S.C -> O(2^n), for storing ans else O(1), excluding space for answer
vector<int> bitMaskingMethod(vector<int>& arr) {
        
    vector<int>ans;
    int n = arr.size();
    
    for (int i = 0; i < (1 << n); i++) {
        
        int sum = 0;
        int num = i;
        
        for (int j = 0; j < n; j++) {
            if (num&1) sum += arr[j];
            
            num = num >> 1;
            
            if (!num) break;
            
        }
        
        ans.push_back(sum);
        
    }
    
    return ans;
        
}


//* Method - II (Recursive Method)
// Simple exclude, include approach. Here there is no need to form a subsequence, we will just creatre a variable sum and use that

//. T.C -> O(2^n), total subsequences (here we are not forming any subsequnce)
//. S.C -> O(n) + O(2^n), first for recurisve stack space and second for storing the answer
void solve(int index, int& sum, vector<int>& arr, vector<int>& ans) {
    if (index == arr.size()) {
        ans.push_back(sum);
        return;
    }
    
    solve(index+1, sum, arr, ans);
    
    sum += arr[index];
    solve(index+1, sum, arr, ans);
    sum -= arr[index];
}

vector<int> recursiveMethod(vector<int>& arr) {
        
    vector<int>ans;
    int sum = 0;
    
    solve(0, sum, arr, ans);
    
    return ans;
        
}