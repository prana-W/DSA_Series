#include <bits/stdc++.h>
using namespace std;

//! Note: Leaf Node: Any node that has no children

/* Follow the below steps:

1. Left Boundary excluding Leaves

Start traversal from root and try to go left nodes, if no left node then try to go right node. Store all the values in the ans. If we encounter a leaf node, then stop this traversal.

2. Leaf Nodes

Add leaf nodes from left to right, therefore we can use any DFS like preorder and store all the leaf nodes in our ans

3. Right Boundary in the reverse excluding Leaves

Start traversal from root's right (if available) and keep on going to right and storing, if no right then only use left. If a leaf node is found, stop the traversal. Also reverse the result formed during the traversal of right boundary

*/

//. T.C -> O(n)
//. S.C -> O(n)

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    public:
        Node(int data1) {
            data = data1;
            left = nullptr;
            right = nullptr;
        }
};

// Checks if a node is leaf node or not
bool isLeaf(Node* root) {
    
    if (!root) return false;
    
    return (!root->left && !root->right);
}

// Adds the left boundary
void leftBoundary(Node* root, vector<int>& ans) {
    
    Node* curr = root->left;
    
    while(curr) {
        
        if (isLeaf(curr)) break;
        
        ans.push_back(curr->data);
        
        if (curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

// Adds the right boundary (in reverse)
void rightBoundary(Node* root, vector<int>& ans) {
    Node* curr = root->right;
    
    vector<int>temp;
    
    while(curr) {
        
        if (isLeaf(curr)) break;
        
        temp.push_back(curr->data);
        
        if (curr->right) curr = curr->right;
        else curr  = curr ->left;
        
    }
    
    for (int i = temp.size()-1; i >= 0; i--) {
        ans.push_back(temp[i]);
    }
}

// Adds the leaf nodes
void addLeaves (Node* root, vector<int>& ans) {
    
    if (!root) return;
    
    if(isLeaf(root)) ans.push_back(root->data);
    
    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
    
}

// Actual function
vector<int> boundaryTraversal(Node *root) {
    
    if(!root) return {};
    
    vector<int>ans;
    ans.push_back(root->data);
    
    if (isLeaf(root)) return ans;
    
    leftBoundary(root, ans);
    addLeaves(root, ans);
    rightBoundary(root, ans);
    
    
    return ans;
    
}