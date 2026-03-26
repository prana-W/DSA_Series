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

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);
}