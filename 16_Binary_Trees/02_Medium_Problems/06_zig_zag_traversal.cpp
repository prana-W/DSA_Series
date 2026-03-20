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

//* Method - I
// Use simple level order traversal, and keep a track of the size of ans (if even or odd), reverse the temp array before pushing to ans in alternate manner

//. T.C -> O(n)
//. S.C -> O(n)

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

    if (!root) return {};

    queue<TreeNode*>q;
    q.push(root);

    vector<vector<int>>ans;

    while(q.size()) {

        int size = q.size();

        vector<int>temp;

        while(size) {
            TreeNode* node = q.front();

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);

            temp.push_back(node->val);

            q.pop();

            size--;
        }

        if (ans.size()%2 == 0) {
            ans.push_back(temp);
        }
        else {
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }

    }

    return ans;
    
}