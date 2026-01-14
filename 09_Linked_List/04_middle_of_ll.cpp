#include <bits/stdc++.h>
using namespace std;

class ListNode {

    public:
        int data;
        ListNode* next;
        ListNode* back;

    public:
        ListNode (int data1, ListNode* next1, ListNode* back1) {
            data = data1;
            next = next1;
            back = back1;
        }

    public:
        ListNode (int data1) {
            data = data1;
            next = nullptr;
            back = nullptr; 
        }
};

//* Method - I (Brute Force)
//. T.C -> O(n + n/2)

// Iterate the entire LL and find the number of nodes and then iterate for half the LL and then return the answer

ListNode* bruteForce(ListNode* head) {

        ListNode* temp = head;
        int cnt = 0;

        // O(n)
        while (temp) {
            cnt++;
            temp = temp->next;    
        }

        int req = (cnt/2) + 1;

        temp = head;

        // O(n/2)
        while(req != 1) {
            req--;
            temp = temp->next;
        }

        return temp;        
}

//* Method - II (Optimal Approach)
//! Turtle-Hare Approach
//. T.C -> O(n/2)

// Have two pointers (fast and slow), both inititally at head. Move fast  pointer by two places while slow pointer by one place. When the fast reaches the end, the slow pointer will be at the middle. 
// or, Turtle and Hare are in a race. Hare has double the speed of Turtle. When Hare reaches the finish line, the Turtle would be in the middle of the race.

ListNode* optimalApproach(ListNode* head) {

        ListNode* turtle = head;
        ListNode* hare = head;

        while(hare && hare->next) {
            hare = hare->next->next;
            turtle = turtle->next;
        }

        return turtle;
        
}
