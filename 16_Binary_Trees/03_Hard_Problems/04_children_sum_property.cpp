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

//? Problem-1 Link: https://www.geeksforgeeks.org/problems/children-sum-parent/1
//? Statement: check if all the nodes follow the children sum property

// Check three condition for each node, first, if root's val is equal to sum of left and right node values, then check if isSumPriperty is validd for leftSubTree, and then for rightSubTree, if all are valid, then return it

//. T.C -> O(n)
//. S.C -> O(h), due to recursive stack space
bool isSumProperty(TreeNode *root) {
    
    // If no root, or leaf-node, then it will follow isSumProperty
    if (!root || !(root->left || root->right)) return true;
    
    int leftSum = 0, rightSum = 0;
    
    if(root->left) leftSum = root->left->val;
    if(root->right) rightSum = root->right->val;
    
    return ((root->val == leftSum + rightSum) &&
            (isSumProperty(root->left)) &&
            (isSumProperty(root->right)));
    
}

//? Problem-2 Link: https://www.naukri.com/code360/problems/childrensumproperty_790723
//? Statement: Modify a tree to follow Children Sum Property

// If the root value is smaller than sum of left and right nodes, then update the root value to match the sum, else add the remaining to the carry and pass it to next function. In next function call, instantly add the incoming carry to the root value and do this. Also after chagingLeft and right tree, again chnage the root value, if in case left and right sum has changed

//. T.C -> O(n)
//. S.C -> O(n)

void solve(TreeNode* root, int& carry) {
    if (!root) return;
    if (!(root->left || root->right)) {
        root->val += carry;
        carry = 0;
        return;
    }

    int currNode = 0, leftNode = 0, rightNode = 0;

    root->val += carry;
    currNode = root->val;
    carry = 0;
    if (root->left) leftNode = root->left->val;
    if (root->right) rightNode = root->right->val;

    if (currNode <= leftNode+rightNode) {
        root->val = (leftNode+rightNode);
    }
    // Adding the remianing to the carry to be passed in next call
    else {
        carry += (currNode - (leftNode+rightNode));
    }

    solve(root->left, carry);
    solve(root->right, carry);

    // Recalculating left and right sum and make the necessary change to the root's value
    leftNode = 0, rightNode = 0;
    if (root->left) leftNode = root->left->val;
    if (root->right) rightNode = root->right->val;

    root->val = leftNode + rightNode;
}

void changeTree(TreeNode* root) {
    int carry = 0;
    solve(root, carry);
}