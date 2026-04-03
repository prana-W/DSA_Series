#include <bits/stdc++.h>
using namespace std;

//? Problem: https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

//* Method - I (Brute Force)

// Use inorder to find the inorder traverrsal, store thr nodes in a vector and then search the vector using linear search, or we can use binary search for better optimisation

//. T.C -> O(n)
//. S.C -> O(n)
void inorder(Node* root, vector<Node*>& in) {
    
    if(!root) return;
    
    inorder(root->left, in);
    in.push_back(root);
    inorder(root->right, in);
    
}
vector<Node*> findPreSuc(Node* root, int key) {
    
    vector<Node*>in;
    inorder(root, in);
    
    Node* pred = nullptr;
    Node* succ = nullptr;
    
    for (int i = 0; i < in.size(); i++) {
        Node* curr = in[i];
        
        if (curr->data < key) pred = curr;
        if (curr->data > key && !succ) succ = curr;
    }
    
    return {pred, succ};
    
}

//* Method - II (Better Solution)
// Use Morris Traversal to find the inorder and then seqarch for predeseccor and successor during the traversal. Keep on updating pre4d as we are mvoing, if found the first successor, there is no need to update it, as it will be the closest

//. T.C -> O(n)
//. S.C -> O(1)
vector<Node*> findPreSuc(Node* root, int key) {
    
    Node* pred = nullptr;
    Node* succ = nullptr;
    
    Node* curr = root;
    
    while(curr) {
        if (curr->left) {
            Node* nextNode = curr->left;
            
            while(nextNode->right && nextNode->right != curr) {
                nextNode = nextNode->right;
            }
            
            if (nextNode->right) {
                nextNode->right = nullptr;
                
                // inorder
                if(curr->data < key) pred = curr;
                if(curr->data > key && !succ) succ = curr;
                
                curr = curr->right;
            }
            else {
                nextNode->right = curr;
                curr = curr->left;
            }
        }
        else {
            
            // inorder
            if(curr->data < key) pred = curr;
            if(curr->data > key && !succ) succ = curr;
            
            curr = curr->right;
        }
    }
    
    
    return {pred, succ};
    
}



//* Method - III (Optimal Solution)

// If curr value is lower than key, then save it as pred and try to move right (to find greater pred closer to key), if curr value is higher than key, then save it as succ and try to move left (to find the smaller pred closer to key), if key and curr value is equal, pred is the maximum node in the left subtree and succ is the smallest node in the right subtree

//. T.C -> O(h)
//. S.C -> O(1)
vector<Node*> findPreSuc(Node* root, int key) {
    
    Node* pred = nullptr;
    Node* succ = nullptr;
    
    // Finding predecessor
    Node* curr = root;

    while (curr) {
        if (curr->data < key) {
            pred = curr;
            curr = curr->right;
        }
        else if (curr->data > key) {
            succ = curr;
            curr = curr->left;
        }
        else {
            // Found the key
            
            // Find predecessor (max in left subtree)
            if (curr->left) {
                Node* temp = curr->left;
                while (temp->right) temp = temp->right;
                pred = temp;
            }
            
            // Find successor (min in right subtree)
            if (curr->right) {
                Node* temp = curr->right;
                while (temp->left) temp = temp->left;
                succ = temp;
            }
            
            break;
        }
    }
    
    return {pred, succ};
    
}