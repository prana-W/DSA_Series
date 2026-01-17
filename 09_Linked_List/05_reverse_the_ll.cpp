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
//! Iterative Approach (In-place approach)

//. T.C -> O(n)
//. S.C -> O(1)
ListNode* optimalApproach(ListNode* head) {

        if (!head || !head->next) return head;

        ListNode* prev = nullptr;
        ListNode* temp = head;

        while(temp) {

            // Store the next node
            ListNode* front = temp->next;         
            
            // Modify the next of current node to previous node
            temp->next = prev;

            // current node become prev
            prev = temp;

            // temp moves to the next element of the LL before tampering
            temp = front;
            
        }

        return prev;     
        
}
