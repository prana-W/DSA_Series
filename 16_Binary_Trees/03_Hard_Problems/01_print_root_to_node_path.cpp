#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    public:
        TreeNode(int data1) {
            data = data1;
            left = nullptr;
            right = nullptr;
        }
};

// Make a helper function that searches and keeps on storing elements in a path array, if the node is found, it instantly returns true, it also returns true if any of its path thorugh left or right also returns true

bool getPath(TreeNode* root, int x, vector<int>& path) {
	if (!root) return false;

	path.push_back(root->data);

	if ((root->data == x) ||
        (getPath(root->left, x, path)) || 
        getPath(root->right, x, path)) 
        return true;

    // Backtracking
	path.pop_back();

	return false;
}

vector<int> pathInATree(TreeNode* root, int x)
{

	vector<int>path;

	getPath(root, x, path);

	return path;

}