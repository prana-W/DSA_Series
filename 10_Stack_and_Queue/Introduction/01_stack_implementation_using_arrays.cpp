#include <bits/stdc++.h>
using namespace std;

//* Method - I (Using Fixed size) -> Size decided when initialising the stack

//. T.C -> O(1), all operations takes constant time
//. S.C -> O(n), this is the total size
class ArrayStack {
private:
    
    int* stackArray; // Array to hold elements
    int capacity; // Maximum capacity
    int topIndex; // Index of top element

public:

    // Constructor
    ArrayStack(int size = 1000) {
        capacity = size;
        stackArray = new int[capacity];
        
        topIndex = -1; // Initialize stack as empty
    }

    // Destructor
    ~ArrayStack() {
        delete[] stackArray;
    }

    // Pushes element x 
    void push(int x) {
        if (topIndex >= capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        stackArray[++topIndex] = x;
    }

    // Removes and returns top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            // Return invalid value
            return -1; 
        }
        return stackArray[topIndex--];
    }

    // Returns top element
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return stackArray[topIndex];
    }

   /* Returns true if the 
   stack is empty, false otherwise*/
    bool isEmpty() {
        return topIndex == -1;
    }
};

//* Method - II (Using Dynamic Array) -> Size is resizable

class myStack {
    vector<int> arr;

public:

    // push operation
    void push(int x) {
        arr.push_back(x);
    }

    // pop operation
    int pop() {
        if (arr.empty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int val = arr.back();
        arr.pop_back();
        return val;
    }

    // peek operation
    int peek() {
        if (arr.empty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr.back();
    }

    // check if stack is empty
    bool isEmpty() {
        return arr.empty();
    }
    
    // current size
    int size() {
        return arr.size();
    }
};