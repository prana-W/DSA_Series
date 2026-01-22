#include <bits/stdc++.h>
using namespace std;

//* Method - I (My Method, Brute Force)
// Using two arrays to implement the min stack

//. T.C -> O(1), in average for all operations. But due to resizing of vector (once it reaches out of size), it can take O(n)
//. S.C -> O(2n), one for elements and one for tracking minimum
class myStack {
public:

//! Due to sometime resizing of vector, push_back() might take O(n) in some cases

    vector<int>arr;
    vector<int>mini;

    myStack() {     
        
    }
    
    void push(int val) {


        arr.push_back(val);

        if (mini.empty() || (mini.back() >= val)) mini.push_back(val);
    }
    
    void pop() {

        if (!mini.empty() && mini.back() == arr.back()) mini.pop_back();
        if (!arr.empty()) arr.pop_back();

        return;
        
    }
    
    int top() {

        if (!arr.empty()) return arr.back();

        return -1;
        
    }
    
    int getMin() {

        if (!mini.empty()) return mini.back();

        return -1;
        
    }
};

//* Method - II (Better Solution)
// (Using two stacks instead of array), hence we achieve O(1) for all operations, even in worst case
//. T.C -> O(1) for all operations
//. S.C -> O(2n), as we have two stacks (one for elements and one for tracking minimum)

//* Method - II.V (Another Better Solution)
// (Use a single stack with pair<>, to store the current element and the minimum value till that element)
//. T.C -> O(1)
//. S.C -> O(2n), as we are using stack with pair<>, hence double the n
class MinStack {
public:

    stack<pair<int, int>>st;

    MinStack() {
        
    }
    
    void push(int val) {

        if(st.empty()) st.push({val, val});

        else {
            int mini = min(val, st.top().second);

            st.push({val, mini});
        }
        
    }
    
    void pop() {

        if (!st.empty()) st.pop();

        return;
        
    }
    
    int top() {

        if(!st.empty()) return st.top().first;

        return -1;
        
    }
    
    int getMin() {

        if(!st.empty()) return st.top().second;
        
        return -1;
        
    }
};

//* Method - III (Optimal Solution)
//! Very Important
// Here we will use a stack that stores the elements and one single varible that tracks the minimum element, hence achieving exactly O(n) space complexity

//! Concept: (We can't track the past, hence we do something clever)
// If at any point we encounter a val minimum than the min. value stored in the varible, then we modify the val into (2*val - mini) and store it inside the stack and update the mini variable to the actual val.
// That is, if val < mini, insert a modified val and store the actual val to update the mini varible. So here the mini is storing both the top() and the mini value

// When we pop() a value from the stack, then to get the previous mini = 2*val - newVal, newVal was inserted and val is the current mini.

// Remember: After modification, the mini becomes the top()

// If the value inside stack is smaller than the mini variable, it means that the value in the stack was Modified. Hence to get the top(), return the mini. Incase of pop() of this value, update the mini variable using the approproate formula

//. T.C -> O(1)
//. S.C -> O(n), a single stack with 'int' values

// Todo: See what to do if val is INT_MIN, how to sotre without using (long long int), i.e. make this solution work in LeetCode
//! If we can't store 2*val - prevMini in the val i.e. in the 'int' data type, then we have to take (long long int) which will agian double our space complexity!!! Hence this solution is optimal if the constraninsts allow the 2*val-prevMini to be stored in 'int'
class optimalMinStack {
public:

    stack<int>st;
    int mini = INT_MAX;

    optimalMinStack() {
        
    }
    
    void push(int val) {

        // If val is smaller than mini, then modify val
        if (!st.empty() && val < mini) {

            int prevMini = mini;

            mini = val;
            val = 2*val - prevMini;
        }

        if (st.empty()) mini = val;

        st.push(val);
        
    }
    
    void pop() {

        if (st.empty()) return;

        // If it is true, then the st.top() was modified and was used to make the mini, hence update mini to show the previous smaller element
        if (st.top() < mini) {
            mini = 2*mini - st.top();
        }

        st.pop();
        
    }
    
    int top() {

        if (st.empty()) return -1;

        // If it is true then the mini is the actual top() element
        if (st.top() < mini) {
            return mini;
        }

        return st.top();        
    }
    
    int getMin() {

        return mini;
        
    }
};