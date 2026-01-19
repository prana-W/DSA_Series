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
// COnvert the LL into array, sort it, then again convert it to a LL

//. T.C -> O(2n + n*log(n))
//. S.C -> O(n)

//* Method - II (Optimal Approach)
//! Modified Merge Sort

// Divide the LL into two halves recursively, and finally keep on merging each nodes just liek we did for Arrays.

// Here we won't require extra space to store, as we used to do in Arrays, here we can simply rearrange as it is a Linked List. The only space taken would be by call stack due to Recursion which is O(log n) as we are constanlty diving the LL into two halves

//. T.C -> O(n * log(n)), 'n' for merging each LL in each recursion level and log (n) due to number of times the merging occurs (total levels)
//. S.C -> O(log n), due to recursive call stack

// Function to merge two sorted linked lists
Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {
        // Create a dummy node
        Node* dummyNode = new Node(-1);
        
        // Temp pointer to build merged list
        Node* temp = dummyNode;

        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr) {
            // Choose smaller node
            if (list1->data <= list2->data) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            // Move temp pointer
            temp = temp->next;
        }

        // Attach remaining nodes
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // Return head of merged list
        return dummyNode->next;
}

// Function to find middle of linked list
Node* findMiddle(Node* head) {
        // If list empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Slow and fast pointers
        Node* slow = head;
        Node* fast = head->next;

        // Move fast twice as fast as slow
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Return middle node
        return slow;
}

//! Main Function
Node* sortLL(Node* head) {
        // Base case: empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find middle node
        Node* middle = findMiddle(head);

        // Split into two halves
        Node* right = middle->next;
        middle->next = nullptr; // Necessary to avoid going to further
        Node* left = head;

        // Recursively sort both halves
        left = sortLL(left);
        right = sortLL(right);

        // Merge sorted halves
        return mergeTwoSortedLinkedLists(left, right);
}
