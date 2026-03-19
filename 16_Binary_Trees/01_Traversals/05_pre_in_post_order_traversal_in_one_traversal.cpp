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

//* Method - I (Recursive Approach)

void traversal(TreeNode* root, vector<int>& pre, vector<int>& in, vector<int>& post) {

    if(!root) return;

    pre.push_back(root->val);
    traversal(root->left, pre, in, post);
    in.push_back(root->val);
    traversal(root->right, pre, in, post);
    post.push_back(root->val);

}

//* Method - II (Iterative Approach)
// Using a single stack

//. T.C -> O(3n)
//. S.C -> O(4n), O(n) for stack and O(n+n+n) for storing the answer
void iterativeTraversal(TreeNode* root) {

    if (!root) return;

    vector<int> pre, in, post;

    stack<pair<TreeNode*, int>>st;
    st.push({root, 1});

    while(!st.empty()) {

        auto it = st.top();
        st.pop();

        // This is part of pre-order, increment 1 to 2 and push the left side of the tree
        if (it.second == 1) {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);

            if (it.first->left) st.push({it.first->left, 1});
        }

        // This is part of in-order, increment 2 to 3 and push the right part of the tree
        else if (it.second == 2) {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);

            if (it.first->right) st.push({it.first->right, 1});
        }
        
        // This is part of post-order, simply store the value (as this is the root)
        else {
            post.push_back(it.first->val);
        }

    }
    
}