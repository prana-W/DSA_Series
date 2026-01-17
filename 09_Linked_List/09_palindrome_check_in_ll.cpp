#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;       
    Node* next;    

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

//* Method - I (Brute Force)
// Convert the LL values into array and check if it is palindrome
// or, put all the values in stack, compare each stack value with the element
//. T.C -> O(n)
//. S.C -> O(n)

//* Method - II (Optimal Approach)
// Reverse the second half of the LL and compare the node values of the first half and second half. 

//. T.C -> O(n)
//. S.C -> O(1)

Node* reverseLinkedList(Node* head) {
    
    if (!head || !head->next) return head;

        Node* prev = nullptr;
        Node* temp = head;

        while(temp) {

            // Store the next node
            Node* front = temp->next;         
            
            // Modify the next of current node to previous node
            temp->next = prev;

            // current node become prev
            prev = temp;

            // temp moves to the next element of the LL before tampering
            temp = front;
            
        }

        return prev;     
}

// Function to check if the linked list is a palindrome
bool optimalApproach(Node* head) {
    // Check if the linked list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return true;  
    }

    // Initialize two pointers, slow and fast, to find the middle of the linked list
    Node* slow = head;
    Node* fast = head;

    // Traverse the linked list to find the middle using slow and fast pointers
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;       
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list starting from the middle
    Node* newHead = reverseLinkedList(slow->next);

    // Pointer to the first half
    Node* first = head;

    // Pointer to the reversed second half
    Node* second = newHead;

    // Compare data values of nodes from both halves
    while (second != NULL) {
        if (first->data != second->data) {
            // If values do not match, the list is not a palindrome
            reverseLinkedList(newHead);  // Reverse the second half back to its original state
            return false;
        }

        first = first->next;  // Move the first pointer
        second = second->next; // Move the second pointer
    }

    // Reverse the second half back to its original state (if question is asking to not tamper the LL)
    reverseLinkedList(newHead);

    return true;
}