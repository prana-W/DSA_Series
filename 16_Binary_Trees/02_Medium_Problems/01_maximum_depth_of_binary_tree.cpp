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

//* Method - I (Brute Force, My Method)
// Similar to BFS, count, how many layers can we go deep, that's it. Do Level Order Traversal bebfore this.

//. T.C -> O(n)
//. S.C -> O(b + h), b is the max bredth of the tree used by queue, h is the max recursive stack space height
int brute(TreeNode* root) {

    if (!root) return 0;

    int ans = 0;
    queue<TreeNode*> ds;
    ds.push(root);

    while (!ds.empty()) {
        int size = ds.size();
        while (size--) {
            TreeNode* node = ds.front();
            ds.pop();

            if (node->left) ds.push(node->left);
            if (node->right) ds.push(node->right);
        }

        ans++;
    }

    return ans;
}

//* Method - II (Optimal Approach)
// Recursively try to find the depth of left and right subtree, and total will be the max out of them + 1 (to include the current depth)

//. T.C -> O(n)
//. S.C -> O(h), better space than method - I
int optimal(TreeNode* root) {

    if (!root) return 0;

    int leftDepth = optimal(root->left);
    int rightDepth = optimal(root->right);

    return 1 + max(leftDepth, rightDepth);
        
}