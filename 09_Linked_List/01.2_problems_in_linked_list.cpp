#include <bits/stdc++.h>
using namespace std;

// Problem 1: Convert an Array in a Linked List
// Problem 2: Traverse the entire Linked List
// Problem 3: Find the length of the Linked List
// Problem 4: Search or Check if an element exists in a Linked List

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

//* Problem - I (Conversion of LL)
// This function takes 'arr' as an input and returns the head (pointer to the first node) of the linked list
//. T.C -> O(n)
Node* convertArrToLL(vector<int>& arr) {

    Node* head = new Node(arr[0]); 
    Node* mover = head; // Memory address to the head

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);

        mover->next = temp; // Add the memory address of this Node to previous Node
        mover = temp; // Memory address to the current node (inside which the address of next Node will be put)
    }

    return head;
}


//* Problem - II (Traversal in LL)
//. T.C -> O(n)
void traversalInLL(Node* head) {

    Node* temp = head;

    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

}


//* Problem - III (Length of LL)
//. T.C -> O(n)
int lengthOfLL(Node* head) {

    int cnt = 0;

    Node* temp = head;

    while (temp) {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}


//* Problem - IV (Search in LL)
//. T.C -> O(n)
bool checkForPresent(Node* head, int target) {

    Node* temp = head;

    while (temp) {
        if (temp->data == target) {
            return true;
        }
        temp = temp->next;
    }

    return false;

}


int main() {

    vector<int>arr = {12, 5, 8, 7};

    Node* headToTheConvertedLL = convertArrToLL(arr);

    traversalInLL(headToTheConvertedLL);

    int totalNodesInLL = lengthOfLL(headToTheConvertedLL);
    cout << totalNodesInLL << endl;

    cout << checkForPresent(headToTheConvertedLL, 10) << endl;

}