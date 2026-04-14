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
// Try to find the inorder traversal of the BT, if it is in sorted, then find the maximum sum of this BST and left and right subtree (as there are negative nodes), if not sorted, then current BT is not a BST, so only try to find the maxium possible in left and right subtree. Also at the end if we get negative value, jusrt return 0, as we won't take any B, if the max. sum is negative

//. T.C -> O(n^2)
//. S.C -> O(n)
void inorder(TreeNode* root, vector<int>& in, int& sum) {
    if(!root) return;

    inorder(root->left, in, sum);
    sum += root->val;
    in.push_back(root->val);
    inorder(root->right, in, sum);
}
int maxSumBST(TreeNode* root) {

    if(!root) return 0;

    vector<int>in;
    int sum = 0;

    inorder(root, in, sum);

    int leftSubTree = maxSumBST(root->left);
    int rightSubTree = maxSumBST(root->right);

    // If not sorted, then current BT is not BST, so try to find the maximum of left and right subtree
    for (int i = 0; i < in.size()-1; i++) {
        if (in[i] >= in[i+1]) return max(leftSubTree, rightSubTree);
    }

    // If inorder is sorted, then current BT si also BST, so try to find the maximum sum of the current BST and left and right subtrees

    int ans = max(sum, leftSubTree);
    ans = max(ans, rightSubTree);
    ans = max(ans, 0);

    return ans;
}

//* Method - II (Optimal)
// Similar to previous problem, trck the maxSum of all the BSTs, also due to negative we won't be able to simply return the maxSum of the top most BT, instead we will store our answer in another variable to store maximum

//. T.C -> O(n)
//. S.C -> O(h), due to recursive stack space in postorder traversal

class TreeProperty {

    public:
    int maxNode, minNode, maxSum;

    TreeProperty(int minNode, int maxNode, int maxSum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
    }

};

TreeProperty solve(TreeNode* root, int& ans) {

    if(!root) return TreeProperty(INT_MAX, INT_MIN, 0);

    auto left = solve(root->left, ans);
    auto right = solve(root->right, ans);

    // if BST, return the TreeProperty for this BT, also update ans to left+curr+right, if greater than already set ans
    if(left.maxNode < root->val && root->val < right.minNode) {

        //! Do this to avoid reducing ans due  to negatives
        ans = max(ans, root->val + left.maxSum + right.maxSum);

        return TreeProperty(min(root->val, left.minNode), max(root->val, right.maxNode), (root->val + left.maxSum + right.maxSum));
    }

    // if not a BST, return the TreeProperty such that it won't be treated as a BST later on
    return TreeProperty(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));

}

int maxSumBST(TreeNode* root) {

    int ans = 0;

    solve(root, ans);
    return ans;
    
}