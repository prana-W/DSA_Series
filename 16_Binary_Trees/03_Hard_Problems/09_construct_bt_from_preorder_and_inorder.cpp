#include <bits/stdc++.h>
using namespace std;

//? Pg: 102 

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

//! Note: Here unique node values are given, hence a simple map<int, int> can be used to hash the indices of node values in inorder traversal

// Store the inordere node values wioth their index in a hash map, to quickly find the indices. THen choose the first element of preorder as the root, and the elements in the left of that root in inorder as left subtree and elements in the righr of the root in inorder as right subtree and recursively solve it. In base condition check if both the indices are ok.

//! Doubt: What to do incase of dupliacte node values, in such a case simple map implementation will fail, and so will something like map<int, queue<int>>, i have checked it, so what to do in that case?? (Do GFG quetion for this)

//. T.C -> O(n), for unordered map in average
//. S.C -> O(n) for hash map and recursive stack space

TreeNode* solve(vector<int>& preorder, int preIndexStart, int preIndexEnd, vector<int>& inorder, int inIndexStart, int inIndexEnd, unordered_map<int, int>& mp) {

    if (preIndexStart > preIndexEnd || inIndexStart > inIndexEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preIndexStart]);

    // Size of left subtree
    int lsize = mp[root->val] - inIndexStart;

    root->left = solve(preorder, preIndexStart+1, preIndexStart+lsize, inorder, inIndexStart, mp[root->val]-1, mp);

    root->right = solve(preorder, preIndexStart+lsize+1, preIndexEnd, inorder, mp[root->val]+1, inIndexEnd, mp);

    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    // Creating hash map
    unordered_map<int, int>mp;
    for (int i = 0; i < inorder.size(); i++) {
        mp[inorder[i]] = i;
    }

    TreeNode* root = solve(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);

    return root;
    
}