#include <bits/stdc++.h>
using namespace std;

// Problem 1: Delete the head of a DLL
// Problem 2: Delete the tail of a DLL
// Problem 3: Delete the Kth element of DLL
// Problem 4: Delete a given Node from the DLL (Node given won't be head (given))

class Node {

    public:
        int data;
        Node* next;
        Node* back;

    public:
        Node (int data1, Node* next1, Node* back1) {
            data = data1;
            next = next1;
            back = back1;
        }

    public:
        Node (int data1) {
            data = data1;
            next = nullptr;
            back = nullptr; 
        }
};

//* Problem - I
Node* deleteHeadOfDLL(Node* head) {

    // empty list
    if (!head) return nullptr; 

    // single node
    if (!head->next) {          
        delete head;
        return nullptr;
    }


    Node* temp = head;

    head = head->next;
    head->back = nullptr;

    delete temp;

    return head;
}

//* Problem - II
Node* deleteTailOfDLL(Node* head) {

    if (!head) return nullptr;

    if (!head->next) {
        delete head;
        return nullptr;
    }

    Node* temp = head;

    while(temp->next) {
        temp = temp->next;
    }

    // Here 'temp' is at tail

    temp->back->next = nullptr; // Go to the second last node and set its next to nullptr

    //! Below is just for understanding, no need as we are deleting temp afterwards
    temp->back = nullptr; // set the back of tail to nullptr

    delete temp;

    return head;
}

//* Problem - III
Node* deleteKthElementOfDLL(Node* head, int k) {

    if (!head) return nullptr;

    Node* temp = head;

    int cnt = 0;

    while(temp) {
        cnt++;

        if (cnt == k) {

            Node* prev = temp->back;
            Node* front = temp->next;

            // When there is only a single node, so delete it and return nullptr
            if (!prev && !front) {
                delete temp; 
                return nullptr;
            }

            // When the head needs to be removed
            else if (!prev) {
                head = front;
                front->back = nullptr;
            }

            // When tail needs to be removed
            else if (!front) {
                prev->next = nullptr;
            }

            // When any node in between needs to be removed
            else {
                prev->next = front;
                front->back = prev;
            }

            delete temp;

            break;

        }

        temp = temp->next;
    }

    return head;
}

//* Problem - IV
void deleteNode (Node* temp) {
    Node* prev = temp->back;
    Node* front = temp->next;

    if (!front) {
        prev->next = nullptr;
        delete temp;
        return;
    }

    prev->next = front;
    front->back = prev;

    temp->back = temp->next = nullptr; //! I think optional as we are anyway deleting it from memory in later steps

    delete temp;

    return;
}