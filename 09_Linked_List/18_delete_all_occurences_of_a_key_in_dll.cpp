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

//! Note: Always use delete() keyword to free mememory created using new keyword

// Here head_ref is the pointer pointing to the address block containing the address iof the actual head. This is pointer-to-pointer. Normally we return Node* in pointer, hence we can move head pointer and return the new pointer, but here we have void function hence to actually cause the head pointer of the LL, we need to use this way. *head would just be the copy of the address of the actual head. Hence we do **head_ref. To access the actual head address we do *head_ref

//. T.C -> O(n)
//. S.C -> O(1)
void deleteAllOccurOfX(struct Node** head_ref, int x) {
        
        Node* previous = nullptr;
        Node* temp = (*head_ref);
        
        while(temp) {
            
            Node* front = temp->next;
            
            if (temp->data == x) {
                
                if(previous) previous->next = front;
                if(front) front->back = previous;
                
                if (temp == (*head_ref)) {
                    (*head_ref) = (*head_ref)->next;
                }
            
                delete (temp);
                
            }
            
            else previous = temp;

            temp = front;
        }
        
}