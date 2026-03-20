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

//* Method - I (Optimal Approach)
//! DFS
// Make a helper function that take stwo nodes as input and recursively check if symmetric. Check three condition: frist, if the value of left root node is equla to right root node, then check if left's root's left subtree is symmeteric with right's root's right subtree and finally check if left root's right subtree is symmetric with right's root's left subtree

//. T.C -> O(n)
//. S.C -> O(h), only recursive stack space

bool check(TreeNode* leftNode, TreeNode* rightNode) {
    if (!leftNode && ! rightNode) return true;
    if (!leftNode || !rightNode) return false;

    return ((leftNode->val == rightNode->val)
    && (check(leftNode->left, rightNode->right))
    && (check(leftNode->right, rightNode->left)));
}

bool optimal(TreeNode* root) {

    if (!root) return true;

    return check(root->left, root->right);
    
}