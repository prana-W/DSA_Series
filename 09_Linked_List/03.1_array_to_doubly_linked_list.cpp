#include <bits/stdc++.h>
using namespace std;

// Problem 1: Convert an array into a doubly linked list

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
Node* convertArrayToDLL(Node* head, vector<int>& arr) {

    Node* ans = new Node(arr[0]);

    Node* prev = ans;

    for (int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);

        newNode->back = prev; // 'back' of current node points the previous node
        prev->next = newNode; // 'next' of previous node points to current node

        prev = newNode; // move the prev to newNode (current node)
    } 

    return ans;

}