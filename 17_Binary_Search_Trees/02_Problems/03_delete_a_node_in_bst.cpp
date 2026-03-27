#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

    public: 
        TreeNode(int val1) {
            val = val1;
            left = nullptr;
            right = nullptr;
        }
};

// We first find the location of the node that needs to be removed, then using the helper funciton we get the valid node that needs to be attached to previous node of the target node, that is replacemnet of the target node. Also it adjusts the returned node such that the BST conditions are still valid

// Also I have made sure to free the memory after deleting the node from the Tree

//. T.C -> O(h), height of the tree
//. S.C -> O(1)

// Helper function to find the biggest node of root
TreeNode* findRightMost(TreeNode* root){

    while(root->right) {
        root = root->right;
    }
    
    return root;
}

// If no left subtree, then it returns the right subtree.
// If no right subtree, then it returns the left subtree.
// If both subtree exists, then it returns the left subtree and inserts the root of right subtree at the righmost end of the leftsubtree, such, that is root of right subtree is inserted to the biggest node's right in the left subtree. This is done to keep the BST conditions satisfied and return some node
TreeNode* helper(TreeNode* root){

    if(!root->left) return root->right;
    if(!root->right) return root->left;

    TreeNode* node = findRightMost(root->left);
    node->right = root->right;

    return (root->left);
}

// Actual function
TreeNode* deleteNode(TreeNode* root, int key) {

    if(!root) return NULL;
    if(root->val == key) {
        TreeNode* newRoot = helper(root);
        delete root;
        return newRoot;
    }

    TreeNode* node = root;

    while(node){
        if(node->val < key){
            if(node->right && node->right->val == key){

                TreeNode* toBeDeletedNode = node->right;

                node->right = helper(node->right);

                delete(toBeDeletedNode);
                break;
            } else {
                node = node->right;
            }
        }
        else{
            if(node->left && node->left->val == key){

                TreeNode* toBeDeletedNode = node->left;

                node->left = helper(node->left);

                delete(toBeDeletedNode);
                break;
            } else{
                node = node->left;
            }
        }
    }

    return root;
}
