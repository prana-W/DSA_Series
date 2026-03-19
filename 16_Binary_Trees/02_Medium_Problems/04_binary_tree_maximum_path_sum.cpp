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
// Make a helper function that takes a root, and gives the maximum sum that can be made using the root + left or root + right, in other words, maxSum gives the maximum sum of a subtree; also make sure if the sum is negativev, turn it to 0. Then do it for every sub tree and finally find the maximum sum. This is similar to dimameter quetion, where we found the max diametere for a current node and then for everhy other node, until we found the globally maximum

//. T.C -> O(n^2)
//. S.C -> O(h)

int maxSum(TreeNode* root) {
    if (!root) return 0;

    int leftSum = maxSum(root->left);
    int rightSum = maxSum(root->right);

    return max(0, (root->val + max(leftSum, rightSum)));
}
int maxPathSum(TreeNode* root) {

    if (!root) return 0;

    int ans = maxSum(root->left) + root->val + maxSum(root->right);

    if(root->left) ans = max(ans, maxPathSum(root->left));
    if(root->right) ans = max(ans, maxPathSum(root->right));

    return ans;

}

//* Method - II (Optimal Approach)
// Similar to diameter problem's optimal approach, here we pass a ans parameter, and calculate the answer by calling maxSum once

//. T.C -> O(n)
//. S.C -> O(h)

int maxSum(TreeNode* root, int& ans) {
    if (!root) return 0;

    int leftSum = maxSum(root->left, ans);
    int rightSum = maxSum(root->right, ans);

    ans = max(ans, leftSum + root->val + rightSum);

    return max(0, (root->val + max(leftSum, rightSum)));
}
int optimal(TreeNode* root) {

    if (!root) return 0;

    int ans = root->val;
    maxSum(root, ans);

    return ans;

}