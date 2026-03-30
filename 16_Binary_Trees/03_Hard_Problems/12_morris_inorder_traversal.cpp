#include <bits/stdc++.h>
using namespace std;

//? Pg: 105  

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

//. T.C -> O(n + n), O(n) as we are going to each node and O(n) for amortized as we are going to last node of each leftsubtree
//. S.C -> O(1), extra space, as if we were to print the valuees, we won't have to store anything

vector<int>getInorder(TreeNode* root) {
    vector<int>inorder;

    TreeNode* curr = root;

    while(curr) {

        // Case 1, when no left subtree existed, then simply print the root and go to right subtree
        if (!curr->left) {
            inorder.push_back(curr->val);
            curr = curr->right;
        }

        // Try to go to lastNode (rightmost node) of left subtree and make the threded connection between that node and the root if doesn't exist, else break the thread and push the root and move to right subtree
        else {

            TreeNode* nextNode = curr->left;

            // Try to move till the lastNode, also check if we don't come back to curr using the thread node
            while(nextNode->right && nextNode->right != curr) {
                nextNode = nextNode->right;
            }

            // Case 2: it means we are actually at a non-threaded lastNode (of the left subtree), simply make a threaded connection from last node of left subtree and root and then only enter the curr to left subtree
            if (!nextNode->right) {

                nextNode->right = curr;
                curr = curr->left;

            }

            // Case 3: if right node exists for this which is actually pointing to curr, it means there already exist a threaded connection, so break the connection, push the root and move to right subtree
            else {

                nextNode->right = nullptr;
                inorder.push_back(curr->val);
                curr = curr->right;

            }

        }

    }

    return inorder;
}