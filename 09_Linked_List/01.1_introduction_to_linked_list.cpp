#include <bits/stdc++.h>
using namespace std;

// We used 'class' instead of 'struct' to benefit the OOPs concept

// Here Node is a class
class Node {

    public:
        int data;
        Node* next;

// This is a constructor
    public:
        Node (int data1, Node* next1) {
            data = data1;
            next = next1;
        }

// This is another constructor when no nullptr is passed, so automatically assign it
    public:
        Node (int data1) {
            data = data1;
            next = nullptr; 
        }
};

int main() {

    // 'y' is an actual object in the Stack Memory that stores contains the Node
    Node y = Node(2, nullptr);

    // Prefer this to create Node
    // 'x' contains the memory address to the Node object (created in Heap Memory)
    Node* x = new Node(3, nullptr);
    // Data stored in Heap Memory as object created using 'new' keyword, and hence needs to be manually freed using 'delete' keyword

    cout << y.data << endl;
    cout << x->data << endl;
    cout << (*x).data << endl;

    // To free the heap memory
    delete x;


}