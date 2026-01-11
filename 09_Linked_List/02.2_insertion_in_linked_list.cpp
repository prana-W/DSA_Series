#include <bits/stdc++.h>
using namespace std;

// Problem 1: Insert an element at the head of a Linked List (not to be replaced but actually create a new node with the value and make it the head of the LL)
// Problem 2: Insert an element at the last (or tail) Linked List (and free the memory obviously)
// Problem 3: Insert an element at the kth element (node) of the Linked List (k = 1 to n+1)
// Problem 4: Insert an element before the value 'target'

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
//. T.C -> O(1)
Node* insertAtTheHead(Node* head, int element) {

    Node* newElement = new Node(element, head);

    return newElement;
}

//* Problem - II
//. T.C -> O(n)
Node* insertElementAtTheLast(Node* head, int element) {

    if (!head) {
        return new Node(element);
    }

    Node* temp = head;

    while (temp->next) {
        temp = temp->next;
    }

    Node* newElement = new Node(element);
    temp->next = newElement;

    return head;
}

//* Problem - III
//. T.C -> O(n)
Node* insertAtKthPosition(Node* head, int element, int k) {

    int cnt = 0;
    Node* temp = head;

    if (k == 1) return new Node(element, head);  

    while(temp) {
        cnt++;

        if (cnt == k-1) {

            Node* newElement = new Node(element, temp->next);

            temp->next = newElement;
            break;
        }

        temp = temp->next;
    }

    return head;
}

//* Problem - IV
//. T.C -> O(n)
Node* insertBeforeTarget(Node* head, int element, int target) {
    Node* temp = head;

    if (head->data == target) {
        return new Node(element, head);
    }

    while (temp) {

        if (temp->next->data == target) {
            Node* newElement = new Node(element, temp->next);
            temp->next = newElement;
            break;
        }

        temp = temp->next;
    }


    return head;

}
