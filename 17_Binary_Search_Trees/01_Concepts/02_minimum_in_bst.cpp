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

//. T.C -> O(log(n)), each steps eliminates half of the tree, just like binary search, but in case of worst case (like unbalanced tree), it is O(n)
//. S.C -> O(1), as we are using iterative approach and not recursive approach
int minValue(TreeNode* root) {
    
    int ans = -1;
    
    while(root) {
        ans = root->val;
        root = root->left;
    }
    
    return ans;
    
}