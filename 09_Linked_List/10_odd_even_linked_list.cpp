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
// Simply traverse, form two arrays or stacks (for odd and even indices), then create a new Linked List

//. T.C -> O(3n)
//. S.C -> O(2n)

//* Method - II (Optimal Approach)
// Iterate in the Linked list and insert any odd indexed Node between the lastOdd and the firstEven Node, after that readjust the Nodes carefully.

//. T.C -> O(n)
//. S.C -> O(1)
ListNode* optimalApproach(ListNode* head) {

    if (!head || !head->next || !head->next->next) return head;

    int cnt = 1;

    ListNode* firstEven = head->next;
    ListNode* lastOdd = head;

    ListNode* temp = head->next;
    ListNode* prev = head;

    while(temp) {
        cnt++;

        // If odd indexed Node
        if (cnt%2 != 0) {

            // Store the next element (as the Node will get tampered later)
            ListNode* front = temp->next;

            prev->next = temp->next;

            lastOdd->next = temp;
            temp->next = firstEven;

            lastOdd = temp;

            prev = prev;
            temp = front;
        }

        else {
            prev = prev->next;
            temp = temp->next;
        }
    }

    return head;
        
}