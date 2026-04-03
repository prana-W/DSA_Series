#include <bits/stdc++.h>
using namespace std;

//? Problem-2 (according to Link): https://leetcode.com/problems/binary-search-tree-iterator/description/

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

//* Method - I (My Method)
// Make an inorder traversal and store in the array, also keep track of a index, and just using these two we can simply do the problem

//. T.C -> O(n) for initialisation and O(1) for all the other operations
//. S.C -> O(n) for initialisation and O(1) for all the other operations

class BSTIterator {
public:

    vector<int>inorder;
    int ind = 0;

    //! Can be optimised further by using Morris Traversal
    void inorderTraversal(TreeNode* root, vector<int>& arr) {

    if (!root) return;

    inorderTraversal(root->left, arr);
    arr.push_back(root->val);
    inorderTraversal(root->right, arr);
}

    BSTIterator(TreeNode* root) {   

        inorder.push_back(INT_MIN);
        inorderTraversal(root, inorder);
        
    }
    
    int next() {

        ind++;

        if (ind < inorder.size()) {
            return inorder[ind];
        }
        else return -1;        
    }
    
    bool hasNext() {

        if (ind+1 < inorder.size()) return true;
        return false;
        
    }
};

//* Method - II (LeetCode Demand, TUF Method)

// Use a stack to push all the nodes, push the root with left subtree initially, evrytinme we do next() function, pop the top element, and push all the left of the right subtree into the stack. This way ensures we traverse in an inordere manner, also at any given point our space complexity will be O(h), as it is the maximum height of the BST

//. T.C -> O(1) in average for the operations. We are pushing n elements thorugh n calls in the stack, that's make it an average of O(n/n) = O(1) avaerage per call
//. S.C -> O(h) for the operations due to stack at max.

class BSTIterator {
public:

    stack<TreeNode*>st;

    // Push all the nodes from root to left in stack
    void pushLeft(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {

        if (st.empty()) return -1; 
        TreeNode* node = st.top();
        st.pop();

        // Push all the left of the right subtree
        if(node->right){
            pushLeft(node->right);
        }
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};