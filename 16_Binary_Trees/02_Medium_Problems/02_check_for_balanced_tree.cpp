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

//* Method - I (Brute Force)
// Three conditions must be satisfied for the entire Binary tree to be balanced. First the depth of left and right node of current node must not differ more than one, then the left subtree must be balanced and also right subtree must be balanced, if all these three conditions are true, then only the given balanced tree is balanced

//. T.C -> O(n^2), depth calculation in worst case takes O(n) and we are doing it on an average of n times
//. S.C -> O(h)

// Similar to max depth of Binary Tree
int getDepth(TreeNode* root) {
    if (!root) return 0;

    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);

    return (1 + max(leftDepth, rightDepth));
}
bool brute(TreeNode* root) {

    if (!root) return true;

    // First condition checks if the current node is balanced, the next two conditions check if the left and right nodes are also balanced, if all are true, then only the complete tree will be balanced
    if ((abs(getDepth(root->left) - getDepth(root->right)) <=  1) && (brute(root->left)) && ( brute(root->right))) return true;

    return false;
    
}

//* Method - II (Optimal Approach)
// Instead of finding height repetedly, find height of the main binary tree once, inside the getDepth helper funciotn that calculates the height of the tree, add a condition that will return -1, if leftDepth or rightDepth is -1 or the diffrernce in depths is greater than 1, hence if in any node, depth is returnded as -1, it mean that ndoe is not balanced, ultimately, reuring -1 at the end

//. T.C -> O(n)
//. S.C -> O(h), for recurisve stack space

int getDepth(TreeNode* root) {
    if (!root) return 0;

    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);

    if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1) return -1;

    return (1 + max(leftDepth, rightDepth));
}
bool isBalanced(TreeNode* root) {

    if (!root) return true;

    if(getDepth(root) == -1) return false;

    return true;
    
}
