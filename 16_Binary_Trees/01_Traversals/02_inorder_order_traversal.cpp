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

//! Left Root Right

//* Method - I (Recursive Approach)

//. T.C -> O(n), n is the number of nodes
//. S.C -> o(height), in worst case of skewed O(n)
void inorder(TreeNode* root, vector<int>& ans) {
    if (!root) return;

    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

//* Method - II (Iterative Approach)
//! TUF Approach
// Push the root into the stack and iterate till stack is empty. Try to push first all the left most nodes, till the top is nullptr, at the end store the top (if not null) and pop it, then store the node on the top now (this is the root) and pop it and then push the right of the root (which was popped just now)
// This way we try to get to the leftmost node, store it, then store the root and then pop the root and go to the root's right node and do the same thing on that sub-tree

//. T.C -> O(n)
//. S.C -> O(height), as the stack might store nodes equal to the ehight of the tree 
vector<int> iterativeApproachI(TreeNode* root) {

        if (!root) return {};

        vector<int>ans;

        stack<TreeNode*>st;
        st.push(root);

        while(st.size()) {

            // Try to go to the leftmost nodes of the subtree
            while(st.top()) {
                st.push(st.top()->left);
            }

            // Store the leftmose node
            if(st.top()) ans.push_back(st.top()->val);
            st.pop();

            // Break if case there is no node left now
            if (st.empty()) break;

            TreeNode* node = st.top();

            // Store the root of the subtree
            if(st.top()) ans.push_back(st.top()->val);
            st.pop();

            // Push the right side of the sub-tree in the stack, to further apply the inorder in it
            if(node) st.push(node->right);

        }

        return ans;
}

//* Method - II.V (Iterative + My Approach)
//! My Approach
// Use a stack with a pair (TreeNode and bool value, bool represents if the node acts as the root), now push the root with root as false as of now. Now iterate till the stack is empty

// During each iteration, pop the top and push its left, then the top itself again (with root set to true) and its right (all if its exists), also push left and right nodes if the top is not root.

// If a node is set as root, its left and right chidleren were already inserted, hence don't reinsert

// Also, if no new node was inserted in the iteration, it means this must be included in the answer

// Dry run the code with an example or two, and you will understand why the code runs. Yes, I coded this myself. Even I am surprised...

vector<int> iterativeApproachII(TreeNode* root_tree) {

    if (!root_tree) return {};

    vector<int>ans;

    stack<pair<TreeNode*, bool>>st;
    st.push({root_tree, false});

    while(st.size()) {

        int size = st.size();

        TreeNode* root = st.top().first;
        bool isRoot = st.top().second;

        st.pop();
        
        if(root->right && !isRoot) st.push({root->right, false});
        st.push({root, true});
        if(root->left && !isRoot) st.push({root->left, false});

        if (size == st.size()) {
            ans.push_back(st.top().first->val);
            st.pop();
        }
    }

    return ans;
        
}