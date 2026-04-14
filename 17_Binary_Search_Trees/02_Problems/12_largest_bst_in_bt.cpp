#include <bits/stdc++.h>
using namespace std;

//? https://www.geeksforgeeks.org/problems/largest-bst/1

//? Pg: 109 

//! Note: In sheet, problem discussed is this, but the link provided is of 12.5_maximum_sum_bst

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//* Method - I (Brute Force)
// Try to find the inorder of current BT, and also during the inorder itself, find the size of the BT, if the inorder is not strictly increasing, then find the max answer in left or right subtree, if it is sorted the current BT is BST and hence it will have the maximum size

//. T.C -> O(n^2)
//. S.C -> O(n)

void inorder(Node* root, vector<int>& in, int& size) {
    if(!root) return;

    inorder(root->left, in, size);
    size++;
    in.push_back(root->data);
    inorder(root->right, in, size);
}
int largestBst(Node *root) {
    
    if(!root) return 0;

    vector<int>in;
    int size = 0;

    inorder(root, in, size);

    // If not sorted, then current BT is not BST, so try to find the maximum size of left and right subtree
    for (int i = 0; i < in.size()-1; i++) {
        if (in[i] >= in[i+1]) return max(largestBst(root->left), largestBst(root->right));
    }

    // If inorder is sorted, then current BT is BST, so it will have maximum size
    return size;
    
}

//* Method - II (Optimal Solution)
//! Bottom Up Approach

// We will do postorder traversal and keep track of min_element, max_element and size of each BT, if it is a BST (max_of_left < curr < min_of_right), then size is 1+left_size+right_size and max and min is updated, if not a BST, new_size is max(left_size, right_size) and max_element is INT_MAX and min_element is INT_MIN 

//. T.C -> O(n), due to postorder traversal
//. S.C -> O(h), due to recursive stack space

class TreeProperty {

    public:
    int maxNode, minNode, maxSize;

    TreeProperty(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }

};

TreeProperty solve(Node* root) {

    // For a null node, it's min will be INT_MAX and max would be INT_MIN, so its parent would form always a valid BST
    if(!root) return TreeProperty(INT_MAX, INT_MIN, 0);

    auto left = solve(root->left);
    auto right = solve(root->right);

    // If it is a BST

    //! Note: We do min() and max() in finding min and max element, as the left or gith might have null node, in which case null's min would be INT_MAX and max would be INT_MIN, so to cater to that we have this
    if(left.maxNode < root->data && root->data < right.minNode) return TreeProperty(min(root->data, left.minNode), max(root->data, right.maxNode), (1 + left.maxSize + right.maxSize));

    // If not a BST
    return TreeProperty(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBst(Node *root) {
    return solve(root).maxSize;
}