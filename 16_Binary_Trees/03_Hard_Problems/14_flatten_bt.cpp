#include <bits/stdc++.h>
using namespace std;

//? Pg: 107 (for Better Solution, TUF Method)

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
// Do preorder traversal and store it in an array, then use this to modify the BT to follow a Linked List pattern

//. T.C -> O(n + n)
//. S.C -> O(n + h)

void pre(TreeNode* root, vector<TreeNode*>& preorder) {

    if(!root) return;

    preorder.push_back(root);
    pre(root->left, preorder);
    pre(root->right, preorder);

}
void flatten(TreeNode* root) {

    if (!root) return;

    vector<TreeNode*>preorder;
    pre(root, preorder);

    for (int i = 0; i < preorder.size()-1; i++) {
        preorder[i]->left = nullptr;
        preorder[i]->right = preorder[i+1];
    }
    
}

//* Method - II (Better Solution)
// Recursively flatten right first, then left, then attach the current node's right to prev, and left to null and update the prev to current node

//. T.C -> O(n)
//. S.C -> O(h)

void solve(TreeNode* root, TreeNode*& prev) {

    if (!root) return;

    solve(root->right, prev);
    solve(root->left, prev);

    root->right = prev;
    root->left = nullptr;

    prev = root;

}
void flatten(TreeNode* root) {
    TreeNode* prev = nullptr;
    solve(root, prev);
}

//* Method - II.V (Better Solution, Iterative)

//. T.C -> O(n)
//. S.C -> O(n)

void flatten(TreeNode* root) {

    if (!root) return;

    stack<TreeNode*>st;
    st.push(root);

    TreeNode* curr = nullptr;

    while(!st.empty()) {

        curr = st.top();
        st.pop();

        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);

        if(!st.empty())curr->right = st.top();
        curr->left = nullptr;

    }
    
}

//* Method - III (Optimal Solution, Morris Traversal)
// Use Modified Morris Traversal

// If curr has a left, then go to the rightmost node in the left subtree and attach that to the curr's right node, then attach the curr's right to the curr's left and curr's left to the nullptr and move to curr's right, (which btw is the original curr's left)

//. T.C -> O(n)
//. S.C -> O(1)
void flatten(TreeNode* root) {

    TreeNode* curr = root;

    while(curr) {

        if (curr->left) {

            TreeNode* nextNode = curr->left;

            while(nextNode->right) {
                nextNode = nextNode->right;
            }

            nextNode->right = curr->right;

            curr->right = curr->left;
            curr->left = nullptr;

        }

        curr = curr->right;

    }
    
}