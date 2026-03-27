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
// Since left elements are smallest, then root and then rightt. So use the inorder traversal to find the elements in increasing order, then simply return the kth element

//. T.C -> O(n), as we are traversing each and every nodes
//. S.C -> O(n + h), O(n) for inorder array and O(h) for recursive stack space

void inorder(TreeNode* root, vector<int>& in) {
    if (!root) return;

    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}
int brute(TreeNode* root, int k) {

    vector<int>in;
    inorder(root, in);

    if ((k-1) >= in.size()) return -1;
    return in[k-1];
    
}

//* Method - II (Better Solution)
// Instead of storing the inorder traversal, we can just keep track of a number that starts with k and after going to leftmost corner, it starts decrementing each time, hence when it hits zero, we will be at kth smallest element

//. T.C -> O(n), in worst case when k is eqaual to number of nodes in the tree, then we have to go till the rightmost node
//. S.C -> O(h), only recursive stack space, no inorder array used here

bool inorder(TreeNode* root, int& index, int& ans) {

    if (!root) return false;

    if(inorder(root->left, index, ans)) return true;
    index--;
    if (index == 0) {
        ans = root->val;
        return true;
    }
    return inorder(root->right, index, ans);

}
int better(TreeNode* root, int k) {

    int ans = -1;
    inorder(root, k, ans);

    return ans;
}

//* Method - III  (Optimal Approach)

//! Follow Up: Optimise space using Morris traversal. Also solve the follow up in Leetcode