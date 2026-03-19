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

// Diameter considering the current root will be depth_of_left + depth_of_right, then find diameter of left and right node and finallhy answer will be the max of all

//. T.C -> O(n^2)
//. S.C -> O(h)

int getDepth(TreeNode* root) {
    if (!root) return 0;

    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);

    return (1 + max(leftDepth, rightDepth));
}

int brute(TreeNode* root) {

    if (!root) return 0;

    // Finding the max of depth_of_left+right, diameter of left node + diameter of right node
    int ans = getDepth(root->left) + getDepth(root->right);
    ans = max(ans, brute(root->left));
    ans = max(ans, brute(root->right));

    return ans;
    
}

//* Method - II (Optimal Approach)
// We can optimise this, by passing a ans parameter in the getDepth function, and storing the max answer in it directly and calling the funciton once

//. T.C -> O(n)
//. S.C -> O(h)

int getDepth(TreeNode* root, int& ans) {
    if (!root) return 0;

    int leftDepth = getDepth(root->left, ans);
    int rightDepth = getDepth(root->right, ans);

    ans = max(ans, leftDepth + rightDepth);

    return (1 + max(leftDepth, rightDepth));
}

int optimal(TreeNode* root) {

        if (!root) return 0;

        int ans = 0;
        getDepth(root, ans);

        return ans;
        
}