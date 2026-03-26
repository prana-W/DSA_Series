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

// Reverse Postorder, so it becomes root, right, left, now just like in previous problem, constuct it recursively by passing the indices

//. T.C -> O(n), for unordered map in average
//. S.C -> O(n) for hash map and recursive stack space

TreeNode* solve(vector<int>& postorder, int postIndexStart, int postIndexEnd, vector<int>& inorder, int inIndexStart, int inIndexEnd, unordered_map<int, int>& mp) {

if (postIndexStart > postIndexEnd || inIndexStart > inIndexEnd) return NULL;

TreeNode* root = new TreeNode(postorder[postIndexStart]);

// Size of right subtree
int rsize = inIndexEnd - mp[root->val];

root->right = solve(postorder, postIndexStart+1, postIndexStart+rsize, inorder,  mp[root->val]+1, inIndexEnd, mp);

root->left = solve(postorder, postIndexStart+rsize+1, postIndexEnd, inorder, inIndexStart, mp[root->val]-1, mp);

return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    reverse(postorder.begin(), postorder.end());

    // Now postorder will be root, right, left

    unordered_map<int, int>mp;
for (int i = 0; i < inorder.size(); i++) {
    mp[inorder[i]] = i;
}

TreeNode* root = solve(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);

return root;
}