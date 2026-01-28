#include <bits/stdc++.h>
using namespace std;

// Iterate the string, if we find stack is not empty and top() is greater than incmonig, then keep on removing the top, till incoming is greater than top and also toBeRemoved is not zero. After that push the incoming.

// At the end, if toBeRemoved is not zero, then remove the top elements from stack till toBeRemoved is 0

// After that form the string and return the answer

//. T.C -> O(n)
//. S.C -> O(n), due to stack and also for returning the answer in string
string removeKdigits(string num, int k) {

        // Case when we have to remove all digits from the number
        if (num.size() <= k) return "0";

        stack<int>st;
        int toBeRemoved = k; // Total numbers to be removed

        for (int i = 0; i < num.size(); i++) {

            int incoming = num[i] - '0';

            // If top is greater and we can remove more numbers then just remove
            while(!st.empty() && st.top() > incoming && toBeRemoved) {
                st.pop();
                toBeRemoved--;
            }

            // To avoid pushing leading 0s 
            if (st.empty() && incoming == 0) continue;

            st.push(incoming);

        }

        // If we can still remove some numbers and we have reached this stage, then it means the final number stored in the stack combine to form a increasing digit number, like 123456 in this case remove the required numbers from the end to minimise the number
        while(toBeRemoved && !st.empty()) {
            st.pop();
            toBeRemoved--;
        }

        string ans;

        // If stack is empty, then the ans is 0
        if (st.empty()) ans = "0";

        // Form the reversed number
        while(!st.empty()) {

            char ch = st.top() + '0';
            ans += ch;
            st.pop();

        }

        // Reverse the final answer
        reverse(ans.begin(), ans.end());

        return ans;
        
}