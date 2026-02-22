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

//! Left Right Root

//. T.C -> o(n), n is the number of nodes 
//. S.C -> o(height), in worst case height = n, so O(n)
void postorder(TreeNode* root, vector<int>& ans) {
    if (!root) return;

    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}

//* Method - II (Iterative Approach)
//! Using Two Stacks or Single Stack + reversal of ans array

// Use two stacks, intitally add the root to st

// Iterate till st is empty. During each iteration, pop the top and push that to st2, and push that node's left and right (is exists) in st and continue. At the end, push all the elmenets of the st2 into ans and that is the answer

// Note: Instead of using the second stack, we can just store the elements directly in the ans array and at the end, just reverse the array. (This would be kind of similar to preorder traveral iterative approach)

//. T.C -> O(n)
//. S.C -> O(height)
vector<int> iterativeMethodI(TreeNode* root) {

    if (!root) return {};
    stack<TreeNode*>st, st2;
    vector<int>ans;

    st.push(root);

    while(st.size()) {

        TreeNode* top = st.top();
        st.pop();
        st2.push(top);

        if(top->left) st.push(top->left);
        if(top->right) st.push(top->right);

    }

    while(st2.size()) {
        ans.push_back(st2.top()->val);
        st2.pop();
    }

    return ans;

}

//* Method - III (Iterative Approach)
//! Using single stack (even without any reversals on ans array)