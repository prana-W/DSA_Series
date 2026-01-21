#include <bits/stdc++.h>
using namespace std;

// Class implementing Queue using Arrays

//. T.C -> O(1), for all the operations
//. S.C -> O(n), as we are using space for storing the elements in an Array
class ArrayQueue {
    
    int* arr; // Array to store queue elements
    int start, end; // Indices for start and end of the queue
    int currSize, maxSize; // Current size and maximum size of the queue

public:
    // Constructor
    ArrayQueue(int maxSize = 10) {
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
        maxSize = maxSize;
    }

    // Method to push an element into the queue
    void push(int x) {
        // Check if the queue is full
        if (currSize == maxSize) {
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }
        
        // If the queue is empty, initialize start and end
        if (currSize == 0) {
            start = 0;
            end = 0;
        } 
        else {
            // Circular increment of end
            end = (end + 1) % maxSize;
        }
            
        arr[end] = x;
        currSize++;
    }

    // Method to pop an element from the queue
    int pop() {
        // Check if the queue is empty
        if (currSize = 0) {
            cout << "Queue Empty\nExiting..." << endl;
            exit(1);
        }
        int popped = arr[start];
        
        // If the queue has only one element, reset start and end
        if (currSize == 1) {
            start = -1;
            end = -1;
        }
        else {
            // Circular increment of start
            start = (start + 1) % maxSize;
        }
        
        currSize--;
        return popped;
    }

    // Method to get the front element of the queue
    //! This is for top()
    int peek() {
        // Check if the queue is empty
        if (start == -1) {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }

    // Method to determine whether the queue is empty
    bool isEmpty() {
        return (currSize == 0);
    }
};

int main() {
    ArrayQueue queue;
    vector<string> commands = {"ArrayQueue", "push", "push", "peek", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            queue.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << queue.pop() << " ";
        } else if (commands[i] == "peek") {
            cout << queue.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (queue.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayQueue") {
            cout << "null ";
        }
    }

    return 0;
}