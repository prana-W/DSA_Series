#include <bits/stdc++.h>
using namespace std;

//? Problem-1 (accoring to Docs): https://www.geeksforgeeks.org/problems/merge-two-bst-s/1

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

//* Problem - I

// Simply do inorder traversal of both to find the sorted traversals and then combine these two arrays into one to form a new sorted array, this will be the inorder of the merged BST, as inorder is always increasing

//. T.C -> O(n+m)
//. S.C -> O(n+m)

// Function to perform inorder traversal and store elements
void inorderTraversal(TreeNode* root, vector<int>& arr) {

    if (!root) return;

    inorderTraversal(root->left, arr);
    arr.push_back(root->val);
    inorderTraversal(root->right, arr);
}

// Function to merge two sorted arrays
vector<int> mergeArrays(vector<int>& arr1, vector<int>& arr2) {

    vector<int> merged;

    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) merged.push_back(arr1[i++]);
        else merged.push_back(arr2[j++]);
    }
    while (i < arr1.size()) merged.push_back(arr1[i++]);
    while (j < arr2.size()) merged.push_back(arr2[j++]);
    return merged;
}

// Function to merge two BSTs in sorted order
vector<int> mergeBSTs(TreeNode* root1, TreeNode* root2) {

    vector<int> arr1, arr2;

    inorderTraversal(root1, arr1);
    inorderTraversal(root2, arr2);

    return mergeArrays(arr1, arr2);
}