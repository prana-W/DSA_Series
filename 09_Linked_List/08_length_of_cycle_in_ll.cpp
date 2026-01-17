#include <bits/stdc++.h>
using namespace std;

class Node {

    public:
        int data;
        Node* next;

    public:
        Node (int data1, Node* next1) {
            data = data1;
            next = next1;
        }

    public:
        Node (int data1) {
            data = data1;
            next = nullptr; 
        }
};

//* Method - I (Brute Force)
// Use the 'set' method as in previous question to determine the head of the cycle, then again iterate from the start of the cycle tilll it reaches the sgtart of the cycle again, count the number of the nodes/elements in the cycle

//. T.C -> O(n*log(x)), if ordered set is used
//. S.C -> O(n), for storing the Node is set data structure

//* Method - II (Optmial Approach) 
//! Turtle and Hare Approach
// Use Turtle and Hare Approach to first find a point where turtle and hare meets at a point after that keep the turtle fixed at that point and move hare in the cycle in x speed (or 1 step at a time) till it meets the turtle again. Count the nunber of nodes in the entire iteration.

//. T.C -> O(n)
//. S.C -> O(1)
int optimalApproach(Node *head) {
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            // When slow and head meet each other inside the cycle, keep the slow pointer fixed and keep on moving fast pointer one by one, till it meets the slow pointer again
            if (slow == fast) {
                                
                int cnt = 1;
                
                fast = fast->next;
                
                while(slow != fast) {
                    cnt++;
                    fast = fast->next;
                }
                
                return cnt;
            }
            
            
        }
        
        return 0;
        
}