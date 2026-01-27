#include <bits/stdc++.h>
using namespace std;    

//* Method - I (Optimal Approach)
// Iterate the array. If both could collide, pop the top till top is destroyed else destroy the incoming asteroid, also at each step see if both are collidable and equal then destroy both. At the end only push the incoming into stack, if it was not destroyed

//. T.C -> O(2n)
//. S.C -> O(2n), O(n) for stack and O(n) for storing the answer
vector<int> optimalApproach(vector<int>& asteroids) {

    int n = asteroids.size();
    stack<int>st;

    for (int i = 0; i < n; i++) {

        int incoming = asteroids[i];

        // Initially incoming is not destroyed
        bool isIncomingDestroyed = false;

        // If empty stack or both can't collide, just push the asteroid and move on
        if (st.empty() || !(st.top() >= 0 && incoming <= 0)) {
            st.push(incoming);
            continue;
        }

        // If both of them can collide and top element is smaller or equal than incoming, then keep on poping the top, till couldn't
        while(!st.empty() && st.top() >= 0 && incoming <= 0 && abs(st.top()) <= abs(incoming)) {
                // If at any instant both are equal, we need to destroy the incoming
                if (abs(st.top()) == abs(incoming)) isIncomingDestroyed = true;
                st.pop(); 

                // If destoyed, just break out
                if (isIncomingDestroyed) break;              
        }
        
        // If both can collide and incoming is smaller or equal, then just destroy the incoming
        if (!st.empty() && st.top() >= 0 && incoming <= 0 && abs(st.top()) >= abs(incoming)) isIncomingDestroyed = true;

        // If incoming not destoryed, then only push the incoming asteroid
        if (!isIncomingDestroyed) st.push(incoming);


    }

    vector<int>ans;

    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
        
}