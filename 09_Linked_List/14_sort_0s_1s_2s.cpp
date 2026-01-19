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

//* Method - I (Optimal Solution)

//. T.C -> O(n)
//. S.C -> O(1)
Node* optimalSolution(Node* head) {
        
        Node* zeroHead = new Node(-1); // Pre-head of the zeroes (means head of zeroes = zeroHead->next)
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        
        Node* zeroes = zeroHead; // Tail of the zeroes
        Node* ones = oneHead;
        Node* twos = twoHead;
    
        Node* temp = head;
        
        while(temp) {
            
            if (temp->data == 0) {
                zeroes->next = temp;
                zeroes = temp;
            }
            else if (temp->data == 1) {
                ones->next = temp;
                ones = temp;
            }
            else {
                twos->next = temp;
                twos = temp;
            }
            
            temp = temp->next;
            
        }
        
        twos->next = nullptr;
        
        // If there are no ones, simply put zeroes->next to twoHead->next
        if (!oneHead->next) {
            zeroes->next = twoHead->next;
        }
        else {
            
            zeroes->next = oneHead->next;
            ones->next = twoHead->next;
            
        }
        
        return zeroHead->next;
        
}