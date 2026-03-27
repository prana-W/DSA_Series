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

// Simply reach the position where the node finally becomes null, and insert the new node there

//! Follow Up: Try to keep the tree balanced. Also what if value does exist?

TreeNode* insertIntoBST(TreeNode* root, int val) {

    if (!root) {
        return new TreeNode(val);
    }

    TreeNode* node = root;

    while(node) {
        if (node->val < val) {
            if (!node->right) {
                node->right = new TreeNode(val);
                break;
            }
            node = node->right;
        }
        else {
                if (!node->left) {
                node->left = new TreeNode(val);
                break;
            }
            node = node->left;
        }
    }

    return root;        
}