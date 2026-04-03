#include <bits/stdc++.h>
using namespace std;

//? Pg: 107

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

//* Method - I (Brute Force)
// Brute force to find the inorder traversal, if it is strictly increasing it means, it is a BST

//* Method - II (Better Solution)
//! Min-Max Concept

//. T.C -> O(n)
//. S.C -> o(h), due to recursive stack space

bool check(TreeNode* root, long long minVal, long long maxVal) {

    if (!root) return true;

    long long rootVal = root->val;
    
    // Checking current node
    if (rootVal <= minVal || rootVal >= maxVal) return false;

    // Checking left and right subtrees
    return (check(root->left, minVal, min(maxVal, rootVal)) && check(root->right, max(minVal, rootVal), maxVal));

}
bool isValidBST(TreeNode* root) {

    if (!root) return true;
    return check(root, LLONG_MIN, LLONG_MAX);
    
}

//* Method - II (Optimal Approach)
//! Morris Inorder Traversal
// Inorder traversal must be strictly increasing in order for it to be BST. So use Morris Traversal for Inorder traversal and check if prevNodeVal < currNodeVal for each node

//. T.C -> O(n)
//. S.C -> O(1), no extra space due to Morris Traversal

//! Note: Here we don't instantly return as, there might be some threads existing in the BST and if e return early those thread will not be broken and destory the original BT given in the problem. So we simply let our Morris traversal get completed and then at the end we return our ans

bool isValidBST(TreeNode* root) {

    long long prev = LLONG_MIN;
    TreeNode* curr = root;

    bool ans = true;

    while(curr) {

        if (!curr->left) {
            long long currVal = curr->val;
            if (currVal <= prev) ans = false;

            prev = curr->val;
            curr = curr->right;
        }
        else {
            TreeNode* nextNode = curr->left;

            while(nextNode->right && nextNode->right != curr) {
                nextNode = nextNode->right;
            }

            if (!nextNode->right) {
                nextNode->right = curr;
                curr = curr->left;
            }
            else {
                nextNode->right = nullptr;

                long long currVal = curr->val;
                if (currVal <= prev) ans = false;

                prev = curr->val;
                curr = curr->right;
            }
        }

    }
    

    return ans;
    
}