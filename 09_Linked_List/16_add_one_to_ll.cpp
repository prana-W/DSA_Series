#include <bits/stdc++.h>
using namespace std;

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

//* Method - I (My Solution)
//! Difficult to code
// Find the last consecutive sequence of 9s, convert all those into 0, and add 1 to the first node from the back which is not 9. Example, 4567999 -> 4568000

//. T.C -> O(2n)
//. S.C -> O(1)
Node* mySolution(Node* head) {

        Node* temp = head;
        
        while (temp) {
            while(temp->next && temp->next->data != 9) {
                temp = temp->next;
            }
            
            Node* temp2 = temp;
            
            while(temp->next && temp->next->data == 9) {
                temp = temp->next;
            }
            
            if (!temp->next) {
                
                // Incase the entire LL is just 999..., in that case just add a new Node with value 1, and make all the other nodes of LL as 0
                if(temp2 == head && temp2->data == 9) {
                    
                    Node* newElem = new Node(1);
                    newElem->next = temp2;
                    
                    while(temp2) {
                        temp2->data = 0;
                        temp2 = temp2->next;
                    }
                    
                    return newElem;
                    
                }
                
                temp2->data = (temp2->data + 1);
                temp2 = temp2->next;
                
                while(temp2) {
                    temp2->data = 0;
                    temp2 = temp2->next;
                }
                
                return head;
            }
            
            temp = temp->next;
        }
        
        return head;
        
}

//* Method - II (Better Solution)
//! Recursive Approach
// Use a recursive funtion for carryOne, this return 1 if we reach the end of the LL, and then add the carry to the Node and returns the new Carry for the previous Node and so one. If at the end, there still remains some carry, then make a new Node, and then make it equal to carry and point it to the head and this becomes the new head

//. T.C -> O(n)
//. S.C -> O(n), due to recursive stack space
int carryOne(Node* head) {
      if (!head) return 1;
      
      int carry = carryOne(head->next);
      
      int newCarry = (head->data + carry)/10;
      head->data = (head->data + carry)%10;
      
      carry = newCarry;
      
      return carry;
}

Node* betterSolution(Node* head) {
        
        int carry = carryOne(head);
        
        if (carry) {
            Node* newNode = new Node(1);
            newNode->next = head;
            return newNode;
        }
        
        return head;
        
}

//* Method - III (Optimal Solution)
//! Iterative Solution
// Reverse the entire LL, add 1 from the beginning, if carry, carry it to next node till carry becomes 0, again reverse back the LL to get the final LL

//. T.C -> O(3n), 2 reversals and one pass for addition
//. S.C -> O(1)

Node* reverseLL(Node* head) {
        Node* prev = nullptr;
        Node* temp = head;
        
        while(temp) {
            
            Node* front = temp->next;
            
            temp->next = prev;
            
            prev = temp;
            temp = front;
        }
        
        return prev;
}

Node* optimalSolution(Node* head) {
        
        int carry = 1;

        // Reverse the original LL
        Node* headOfReversedLL = reverseLL(head);
        Node* temp = headOfReversedLL;
        
        while(temp && carry) {
            
            int newCarry = (temp->data + carry)/10;
            
            temp->data = ((temp->data + carry)%10);
            
            carry = newCarry;
            
            if(temp->next) temp = temp->next;
            else break; // so that we stay on the tail of the LL only and can later use next to add a new Node
        }
        
        // If carry still exits, then create a new Node and refernce the tail of the original LL to this Node
        if (carry) {
            Node* newElement = new Node(carry);
            temp->next = newElement;
        }
        
        // Return the final LL
        return reverseLL(headOfReversedLL);
        
}

