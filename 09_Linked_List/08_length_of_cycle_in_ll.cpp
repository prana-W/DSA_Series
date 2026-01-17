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
// Use the 07_linked_list_cycle_II.cpp method to determine the head of the cycle. Both turtle and hare meets at the head of the cycle at then end of the previous question. Now, keep on moving hare one by one and let the turtle be at the head of the cycle only. Count the number of nodes before both hare and turtle meet at the head of the cycle again, at that point, return the count

//. T.C -> O(n)
//. S.C -> O(1)
int optimalApproach(Node *head) {
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                slow = head;
                
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                
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