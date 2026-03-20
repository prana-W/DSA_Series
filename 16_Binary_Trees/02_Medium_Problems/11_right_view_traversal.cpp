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

// Just use BFS and store the last node of each level

//. T.C -> O(n)
//. S.C -> O(n), due to queue
vector<int> rightSideView(TreeNode* root) {

    if (!root) return {};

    queue<TreeNode*>q;
    vector<int>ans;

    q.push(root);

    while(q.size()) {

        int size = q.size();
        int req = -1;

        while(size) {
            TreeNode* node = q.front();

            req = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);

            q.pop();
            size--;
        }
        
        ans.push_back(req);
    }

    return ans;
    
}

//* Method - II (Optimal Approach)

// USe DFS, to go to the right subtree first and then left subtree. Also pass the level as a paramter to the function and only store the value if the ans array size is equal to the level, to avoid adding adding another answer for the same level

//. T.C -> O(n)
//. S.C -> O(h), only recursive stack space and no extra data structure is used

void dfs(TreeNode* root, vector<int>& ans, int level) {
    if (!root) return;

    if(ans.size() == level) ans.push_back(root->val);

    if(root->right) dfs(root->right, ans, level+1);
    if(root->left) dfs(root->left, ans, level+1);
}
vector<int> rightSideView(TreeNode* root) {

    vector<int>ans;

    dfs(root, ans, 0);

    return ans;
    
}