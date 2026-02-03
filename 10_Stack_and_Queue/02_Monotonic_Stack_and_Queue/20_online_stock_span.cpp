#include <bits/stdc++.h>
using namespace std;

// We find the PGE of each element. We use an aditional 'ind' variable to keep track of the index and using a simple pair<int, int> stack for storing the element and the index for find the PGE of a element

//. T.C -> O(n), total time taken after finding all the spans
//. S.C -> O(n) for stack
class StockSpanner {
public:

    stack<pair<int, int>>st;
    int ind = -1;

    StockSpanner() {
        
    }

    
    int next(int price) {

        int pge = -1;
        ind++;

        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }

        if (!st.empty() && st.top().first > price) {
            pge = st.top().second;
        }

        st.push({price, ind});
        int ans = ind - pge;

        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */