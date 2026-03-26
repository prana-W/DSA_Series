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

//* Method - I (Iterative Approach)

//. T.C -> O(log(n)), eash steps eleiminate half of the tree, just like binary search, but in case of worst case (like unbalanced tree), it is O(n)
//. S.C -> O(1), as we are using iterative approach and not recursive approach
TreeNode* searchBST(TreeNode* root, int val) {

    while(root && root->val != val) {
        if (root->val > val) root = root->left;
        else if (root->val < val) root = root->right;
    }

    return root;
    
}