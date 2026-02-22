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

//* Method - I (Recursive Method)

//! Root Left Right

//. T.C -> O(n), n is the number of nodes
//. S.C -> O(height), where height is the height of the tree and when the Tree is skewed then height = n (total nodes), hence O(n) at worst case
void preorder(TreeNode* root, vector<int>& ans) {
    if (!root) return;

    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

//* Method - II (Iterative Method)
// Use a stack data structure for iterative method. Push the root first and iterate till stack is empty. During each iteration push the top node value to answer and then pop it and push its right and then left nodes (if exists) and let the cycle continue.

//. T.C -> O(n)
//. S.C -> O(height), O(height) is the maximum size of the stack at any point. (Here S.C is extra space, excluding the space for returing the answer)
vector<int> iterativeApproach(TreeNode* root) {

        if (!root) return {};

        stack<TreeNode*>st;
        st.push(root);

        vector<int>ans;

        while(st.size()) {

            TreeNode* top = st.top();

            ans.push_back(top->val);

            st.pop();
            if(top->right) st.push(top->right);
            if(top->left) st.push(top->left);
        }

        return ans;
        
}