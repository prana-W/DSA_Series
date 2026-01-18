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

//* Method - II (Better Solution)
// Iterate once to find the total number of nodes, then calculate the actual node number to be deleted and hence delete that simply as we used to do.

//. T.C -> O(2n)
//. S.C -> O(1)

//* Method - III (Optimal Approach)
//! Slow and Fast Pointers
// Initially fast pointer ahead by N nodes from slow, and after that both move one step at a time, till the fast node reaches the end
// Put the first pointer at the head and the second pointer @ the nth node from start (1-based indexing).
// In each iteration, move both first and second pointer by one step.
// If the second pointer would be the last node (or tail) of the linked list, then first pointer would be pointing to the target node.

//. T.C -> O(n), in a single pass
//. S.C -> O(1)
ListNode* optimalApproach(ListNode* head, int n) {

        // Edge Cases
        if (!head) return nullptr;
        if (!head->next && n == 1) {
            delete (head);
            return nullptr;
        }

        ListNode* prevOfExpectedTarget = nullptr;
        ListNode* expectedTarget = head; // this is the first pointer
        ListNode* temp = head; // this is the second pointer

        int cnt = 1;

        // This makes the distance between first and second pointer as 'n'
        while(cnt != n) {
            cnt++;
            temp = temp->next;
        }

        // Edge case: When we have to remove the 'head' of the Linked List
        // If we need to remove the head (i.e, we are at the end of the LL and expectedTarget is head)
        if (!temp->next && expectedTarget == head) {

            ListNode* newHead = head->next;

            delete (head);

            return newHead;
        }

        while(temp->next) {
            temp=temp->next;
            prevOfExpectedTarget=expectedTarget;
            expectedTarget = expectedTarget->next;
        }

        prevOfExpectedTarget->next = expectedTarget->next;

        delete (expectedTarget);

        return head;        
        
}