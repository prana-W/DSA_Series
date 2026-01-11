#include <bits/stdc++.h>
using namespace std;

// Problem 1: Delete the head of a Linked List (and make the next Node as head)
// Problem 2: Delete the tail of the Linked List (and free the memory obviously)
// Problem 3: Delete the kth element (node) of the Linked List
// Problem 4: Delete the element whose value is given

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

//* Problem - I

//! Remember to manually free the memory after deleting Head, as C++ needs manual garbage collection unlike Java, where we don't need to do that.
Node* deleteHead(Node* head) {

    if (head == NULL) return head; // if (!head) return head;

    Node* temp = head;
    head = head->next;

    //! To remove the earlier head from the memory
    delete temp; // free(temp)

    return head;
}

//* Problem - II

Node* deleteTail(Node* head) {

    // When there is no element or only single element
    if  (!head || !(head->next)) return nullptr;

    Node* temp = head;

    while (temp->next->next) {
        temp = temp->next;
    }

    // temp is now at the second last node, so remove the last node (free the memory) and make the temp (second last node) point to nullptr

    delete temp->next;
    temp->next = nullptr;

    return head;

}

//* Problem - III 

//. T.C -> O(k)
Node* removeKthElement(Node* head, int k) {
    if (!head) return head;

    if (k == 1) {
        Node* temp = head;
        head = head->next;

        delete temp;

        return head;
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;

    while(temp) {
        cnt++;

        if (cnt == k) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;

    }

    return head;
     
}

//* Problem - IV
Node* deleteElement(Node* head, int target) {
    Node* temp = head;
    Node* prev = nullptr;

    if (!head) return head;

    // When the head has the required value
    if (head->data == target) {

            Node* temp = head;

            head = head->next;

            delete temp;
            return head;
    }

    while(temp) {


        if (temp->data == target) {

            prev->next = prev->next->next;

            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;

    }

    return head;
}


