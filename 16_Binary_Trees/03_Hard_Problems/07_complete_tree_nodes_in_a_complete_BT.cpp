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
// Simple DFS traversal and count all the ans

//. T.C -> O(n)
//. S.C -> O(h), for recursive stack space. Here O(h) = O(log(n)) as here it is complete binary tree

void pre(TreeNode* root, int& ans) {
    if (!root) return;

    ans++;

    pre(root->left, ans);
    pre(root->right, ans);
    
}
int countNodes(TreeNode* root) {

    int ans = 0;
    pre(root, ans);
    return ans;        
    
}

//* Method - II (Optimal Approach)
// There are few properties of a complete binary tree that we must keep in mind.

// All levels are completely filled except last. All the nodes are in as much left as possible (in last level)

// Calculate the left and right height, if they are same, all noes ar present, so simply use the forunmla to calculate the total nodes

// If they are not same, then split the tree into two subtrees and try to find their indivisual node count and add them together with the current root node (recursively)

//. T.C -> O(log(n) * log(n)), calculating height takes log(n), and we are going to each level recursively
//. S.C -> O(h)) or O(log(n)) recursive stack space as it is complete binary tree

int getLeftHeight(TreeNode* root) {

    int height = 0;

    while(root) {
        root = root->left;
        height++;
    }

    return height;

}

int getRightHeight(TreeNode* root) {
    int height = 0;

    while(root) {
        root = root->right;
        height++;
    }

    return height;
}

int countNodes(TreeNode* root) {

    int leftH = getLeftHeight(root);
    int rightH = getRightHeight(root);

    if (leftH == rightH) {
        return pow(2, leftH) - 1;
    }

    else {
        return (1 + countNodes(root->left) + countNodes(root->right));
    }
    
}