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

//* Method - II (Optimal Approach)
//! Turtle-Hare Algorithm or SLow-Fast Pointers
// Use slow-fast pointer to find the middle element and remove it

//. T.C -> O(n)
//. S.C -> O(1)
ListNode* optimalApproach(ListNode* head) {

        //! Don't tamper the head
        if(!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        ListNode* prevToSlow = nullptr;

        while(fast && fast->next) {

            prevToSlow = slow;

            slow = slow->next;
            fast = fast->next->next;
        }

        prevToSlow->next = slow->next;

        delete (slow);

        return head;        
}