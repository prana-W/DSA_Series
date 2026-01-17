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
// Convert the entire LL into array, reverse the array, convert the array into LL

//! Can be also done using Stack instead of an Array

//. T.C -> O(3n)
//. S.C -> O(n), for creating the array

//* Method - II (Better Approach)
//! Recursive Approach
//. T.C -> O(n)
//. S.C -> O(n), due to recursive stack space

ListNode* reverseList(ListNode* head) {

    if (!head || !head->next) return head;

    ListNode* reversedLL = reverseList(head->next);

    ListNode* tailOfNewLL = head->next;
    tailOfNewLL->next = head;

    head->next = nullptr; // to delink the last node of the New LL

    return reversedLL;
        
}

//* Method - III (Optimal Solution)
//! Iterative Approach
// Iterate thorugh the LL, store the prev Node, also called by newHead here (of the new LL), and make a new LL with the link of newly create Node (with same value as current node) pointing to the prev node (of this newly created LL), return the head of this newly created LL, when the main (input) LL is exhausted. 
// We are basically making a LL in reverse sequence (from tail to head) and returing it

//. T.C -> O(n)
//. S.C -> O(1), no extra space apart from the answer LL

ListNode* optimalApproach(ListNode* head) {

        if (!head) {
            return head;
        }

        ListNode* newHead = nullptr; // This is the head of the newly created LL
        ListNode* temp = head; // This is for iterating in the input LL

        while(temp) {

            ListNode* newNode = new ListNode(temp->data);

            newNode->next = newHead;

            newHead = newNode;
            temp = temp->next;         

        }

        return newHead;
        
}
