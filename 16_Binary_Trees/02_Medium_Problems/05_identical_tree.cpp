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

//* Method - I (Brute Force, My Method)
// Use Level Order Traversal to find the nodes (NOTE; here when node is null, use placeholder value INT_MIN), now compare the values of the matrix (for level order traversal) of both the trees

//. T.C -> O(n)
//. S.C -> O(n)

vector<vector<int>> level(TreeNode* root) {

    if (!root) return {{}};

    vector<vector<int>>ans;

    queue<TreeNode*>q;
    q.push(root);

    while(q.size()) {

        int size = q.size();
        vector<int>temp;

        while(size) {

            TreeNode* node = q.front();

            if(node) q.push(node->left);
            if(node) q.push(node->right);

            if(node) temp.push_back(node->val);
            else temp.push_back(INT_MIN);

            q.pop();

            size--;
        }

        ans.push_back(temp);
    }

    return ans;     
    
}
bool brute(TreeNode* p, TreeNode* q) {

    if (!p && !q) return true;
    if (!p || !q) return false;

    vector<vector<int>>l1 = level(p);
    vector<vector<int>>l2 = level(q);

    if ((l1.size() != l2.size()) || (l1[0].size() != l2[0].size())) return false;

    for (int i = 0; i < l1.size(); i++) {
        for (int j = 0; j < l1[i].size(); j++) {
            if (l1[i][j] != l2[i][j]) return false;
        }
    }

    return true;
    
}

//* Method - II (Optimal Approach)
// here we recursively check if both the trees are identical simulataneiuly, to check we have to meet tree conditions, one if the root->val is equal, then if the left subtree is identical and then if the right subtree is identical

bool isSameTree(TreeNode* p, TreeNode* q) {

    if (!p && !q) return true;
    if (!p || !q) return false;

    return ((p->val == q->val) 
    && (isSameTree(p->left, q->left)) 
    && (isSameTree(p->right, q->right)));
    
}