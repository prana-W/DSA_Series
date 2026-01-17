#include <bits/stdc++.h>
using namespace std;

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

//* Method - I (Brute Force)
// Use a Stack to store the elements of the Node and then use it to create a new DLL

//. T.C -> O(2n)
//. S.C -> O(n)
Node *bruteForce(Node *head) {
        
        Node* temp = head;
        
        stack<Node*>nodes;
        
        while(temp) {
            nodes.push(temp);
            temp = temp->next;
        }
        
        
        Node* newHead = nodes.top();
        
        Node* prev = nullptr;
        temp = newHead;
        
        nodes.pop();
        
        while(nodes.size()) {
            
            Node* nextNode = nodes.top();
            
            temp->next = nextNode;
            temp->back = prev;
            
            prev = temp;
            temp = nextNode;
            
            nodes.pop();
            
        }
        
        temp->next = nullptr;
        temp->back = prev;
        
        return newHead;
        
}

//* Method - II (Optimal Approach)
// Iterate the DLL once. 'next' of a node would become its 'back' and 'back' of a node becomes its 'next'
//. T.C -> O(n)
//. S.C -> O(1)

Node *optimalApproach(Node *head) {
        Node* temp = head;
        Node* prev = nullptr;
        
        while(temp) {
            Node* front = temp->next;
            Node* back = temp->back;
            
            temp->next = prev;
            temp->back = front;
            
            prev = temp;
            temp = front;
            
        }
        
        return prev;
        
    }