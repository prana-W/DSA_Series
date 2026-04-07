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
// Store the inorder traversal and sort it to get the BST of the ideal BST, then just do inorder traversal again and if the node value is different from its ideal state, then update it. Also increase index of the in array

//. T.C -> O(2n + n*log(n)), due to sorting
//. S.C -> O(2n)

void inorder(TreeNode* root, vector<int>& in) {
    if(!root) return;
    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}

void solve(int& ind, vector<int>& in, TreeNode* root) {
    if(!root) return;

    solve(ind, in, root->left);

    if (root->val != in[ind]) root->val = in[ind];
    ind++;

    solve(ind, in, root->right);
}

void recoverTree(TreeNode* root) {

    vector<int>in;
    inorder(root, in);

    sort(in.begin(), in.end());

    int ind = 0;
    solve(ind, in, root);        
}

//* Method - II (Optimal Solution)
// Do a simple inordere traversal using Morris Traversal and keep track of the previous element, if the ucrrent element is smaller than the previous element, then store the previous element as first, the current element as middle and move on. If we find another such index where the problem occurs, swap the first and that elmenet, else just swap the first and middle element

//. T.C -> O(n)
//. S.C -> O(1)

class Solution {
public:

TreeNode* prev = nullptr;

TreeNode* first = nullptr;
TreeNode* middle = nullptr;
TreeNode* last = nullptr;

void inorder(TreeNode* root) {

    TreeNode* curr = root;

    while(curr) {

        if (!curr->left) {

            // Store into first and middle if first is null
            if (!first && prev && prev->val > curr->val) {
                first = prev;
                middle = curr;
            }
            // Store in last if first already found
            else if (!last && prev && prev->val > curr->val) {
                last = curr;
            }
            prev = curr;
            curr = curr->right;
        }

        else {

            TreeNode* nextNode = curr->left;

            while(nextNode->right && nextNode->right != curr) {
                nextNode = nextNode->right;
            }

            if (!nextNode->right) {

                nextNode->right = curr;
                curr = curr->left;

            }
            else {

                nextNode->right = nullptr;

                // Store into first and middle if first is null
                if (!first && prev && prev->val > curr->val) {
                    first = prev;
                    middle = curr;
                }
                // Store in last if first already found
                else if(!last && prev && prev->val > curr->val) {
                    last = curr;
                }

                prev = curr;
                curr = curr->right;

            }

        }

    }

}

    void recoverTree(TreeNode* root) {

        inorder(root);

        // If there is no last, then simply swap the first and middle node
        if(!last) {
            int temp = first->val;
            first->val = middle->val;
            middle->val = temp;
        }
        // If there is first and last, then swap these values of these two
        else {
            int temp = first->val;
            first->val = last->val;
            last->val = temp;
        }
      
    }
};