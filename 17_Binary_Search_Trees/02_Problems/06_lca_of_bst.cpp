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

//* Method - I (Same as Method - I 02_lca_of_a_binary_tree)

//* Method - II (Same as Method - II of 02_lca_of_a_binary_tree)

//* Method - III (Optimal Solution, Recusive)
// We will use the properties of BST

// If both p and q ndes exist in left, then find the lca in left subtree else if both exist in right subtree then find lca in right subtree, else if p and q exist in both side, or one on the root, then thr answer will be the root itself

//. T.C -> O(h)
//. S.C -> O(h), recursive stack space
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if(!root) return root;

    if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
    if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);

    return root;

}

//* Method - IV (Most Optimal, Iterative)
// Just keep on going to either left side or right side of the tree, till both nodes lie on one side, if nodes lie on both side or either the root itslef is one of the node, stop and return the node

//. T.C -> O(h)
//. S.C -> O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    while(root) {

        if (p->val < root->val && q->val < root->val) root = root->left;
        else if (p->val > root->val && q->val > root->val) root = root->right;
        else return root;

    }

    return root;

}