#include <bits/stdc++.h>
using namespace std;

//? Pg: 100

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
// Use the concept of the previous problem to find the path for the two given nodes, then simply iterate and find the last common node, which will be the last common ancestor of both nodes and return that

//. T.C -> O(n)
//. S.C -> O(2n + 2h), to store the paths and recursive stack space

bool getPath(TreeNode* root, TreeNode* x, vector<TreeNode*>& path) {
	if (!root) return false;

	path.push_back(root);

	if ((root == x) ||
        (getPath(root->left, x, path)) || 
        getPath(root->right, x, path)) 
        return true;

	path.pop_back();

	return false;
}
vector<TreeNode*> pathInATree(TreeNode* root, TreeNode* x)
{

	vector<TreeNode*>path;

	getPath(root, x, path);

	return path;

}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*>path1 = pathInATree(root, p);
        vector<TreeNode*>path2 = pathInATree(root, q);
        
        TreeNode* ans;

        for (int i = 0; i < min(path1.size(), path2.size()); i++) {
            if (path1[i] == path2[i]) ans = path1[i];
        }

        return ans;
    
}

//* Method - II (Optimal Approach)
// Do DFS by Left, then right, if we find a node equal to one of the input ndoe, return it, else check what we are getting from left and right subtree respectively. If both give some node, it measn, the current node (or root) is acting as the common ancestor, if only one of them is returning something, then return only that node which is either being returned by left or right subtree

//. T.C -> O(n)
//. S.C -> O(h), only recursive stack space
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if (root == p || root == q || !root) return root;

    TreeNode* leftSubtree = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightSubtree = lowestCommonAncestor(root->right, p, q);

    if (leftSubtree && rightSubtree) return root;
    if (leftSubtree) return leftSubtree;
    if (rightSubtree) return rightSubtree;

    return nullptr;
    
}

