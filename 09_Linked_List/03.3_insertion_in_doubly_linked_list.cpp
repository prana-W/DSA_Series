#include <bits/stdc++.h>
using namespace std;

// Problem 1: Insert a Node before a Head of a DLL
// Problem 2: Insert a Node before a Tail of a DLL
// Problem 3: Insert a Node before Kth element of the DLL
// Problem 4: Insert a Node before a given Node of a DLL

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
Node* insertNodeBeforeHead(Node* head, int element) {
    
    Node* newNode = new Node(element);

    newNode->next = head;
    head->back = newNode;

    return newNode;
}

//* Problem - II
Node* insertNodeBeforeTail(Node* head, int element) {

    Node* temp = head;

    while(temp->next) {
        temp = temp->next;
    }

    // here tail and head is same
    if (temp == head) {

    Node* newNode = new Node(element);

    newNode->next = temp;
    temp->back = newNode;

    return newNode;

    }

    // here the node is tail

    Node* prev = temp->back;
    Node* front = temp->next;

    Node* newNode = new Node(element);

    newNode->next = temp;
    newNode->back = prev;
    
    prev->next = newNode;
    temp->back = newNode;

    return head;

}

//* Problem - III
Node* insertBeforeKthElement(Node* head, int k, int element) {

    if (k == 1) {
        Node* newNode = new Node(element);

        newNode->next = head;
        head->back = newNode;

        return newNode;
    }

    Node* temp = head;
    int cnt = 0;

    while(temp) {
        cnt++;

        if (cnt == k){
            Node* prev = temp->back;
            Node* front = temp->next;

            Node* newNode = new Node(element);

            newNode->back = prev;
            newNode->next = temp;

            prev->next = newNode;
            temp->back = newNode;

            break;


        }

        temp = temp->next;
    }

    return head;
}

//* Problem - IV
Node* insertNodeBeforeANode(Node* head, Node* target, int element) {

    if (head == target) {

        Node* newNode = new Node(element);

        newNode->next = head;
        head->back = newNode;

        return newNode;

    }


    Node* prev = target->back;

    Node* newNode = new Node(element);
    newNode->next = target;
    newNode->back = prev;

    prev->next = newNode;
    target->back = newNode;
        
    return head;
}