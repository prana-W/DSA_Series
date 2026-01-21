#include <bits/stdc++.h>
using namespace std;

//! Two-stack method

//* Method - I (push() takes O(n))

// Queue implementation using stack

//. T.C -> O(2n) for pushing and O(1) for rest
//. S.C -> O(n) for storing the elements in the other stack
class StackQueue {
private:
    stack <int> st1, st2;

public: 
    // Empty Constructor
    StackQueue () {
        
    }
    
    // Method to push elements in the queue
    void push(int x) {
        /* Pop out elements from the first stack 
        and push on top of the second stack */
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        
        // Insert the desired element
        st1.push(x);
        
        /* Pop out elements from the second stack 
        and push back on top of the first stack */
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    // Method to pop element from the queue
    int pop() {
        // Edge case
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }
        
        // Get the top element
        int topElement = st1.top();
        st1.pop(); // Perform the pop operation
        
        return topElement; // Return the popped value
    }
    
    // Method to get the front element from the queue 
    int peek() {
        // Edge case
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }
        
        // Return the top element
        return st1.top();
    }
    
    // Method to find whether the queue is empty
    bool isEmpty() {
        return st1.empty();
    }
};


//* Method - II (push() takes O(1))

//. T.C -> O(1) for push and O(n) for pop() and peek()/top()
//. S.C -> O(n) for storing the elements in the other stack
class StackQueue2 {
  public:
    stack<int> input, output;

    // Initialize your data structure here
    StackQueue2() {}

    // Push element x to the back of queue
    void push(int x) {
        input.push(x);
    }

    // Removes the element from in front of queue and returns that element
    int pop() {
        // Shift input to output if output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        // If queue is still empty, return -1 (or throw an error if preferred)
        if (output.empty()) {
            cout << "Queue is empty, cannot pop." << endl;
            return -1;
        }

        int x = output.top();
        output.pop();
        return x;
    }

    // Get the front element
    int peek() {
        // Shift input to output if output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        // If queue is still empty, return -1 (or throw an error if preferred)
        if (output.empty()) {
            cout << "Queue is empty, cannot peek." << endl;
            return -1;
        }

        return output.top();
    }

    // Returns true if the queue is empty, false otherwise
    bool isEmpty() {
        return input.empty() && output.empty();
    }
};