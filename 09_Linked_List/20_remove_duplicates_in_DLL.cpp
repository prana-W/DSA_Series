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

//* Method - I (Optimal Approach)

//. T.C -> O(n)
//. S.C -> O(1)
Node *removeDuplicates(struct Node *head) {
        
        Node* previous = nullptr;
        Node* temp = head;
        
        while(temp) {
            while (temp->next && temp->data == temp->next->data) {
                Node* front = temp->next;
                
                //! Move head, if it is the to be deleted Node
                if (temp == head) {
                    head = head->next;
                }
                delete (temp);
                
                temp = front;
            }
            
            temp->back = previous;
            if(previous) previous->next = temp;
            
            previous = temp;
            temp = temp->next;
        }
        
        return head;
        
}