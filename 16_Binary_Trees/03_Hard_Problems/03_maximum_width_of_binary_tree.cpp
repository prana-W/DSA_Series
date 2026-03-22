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

// We think of 0-based indexign as we go level-by-level, we also assign index to nodes that are not available, this brings us to a observation for the 0-based indexing

// Left node: index = 2*root_index + 1 and right node: index = 2*root_index + 2

// We do the above and find the lastIndex - fristIndex of each level

// Also to not go out of bounds, we use relative indexing in each level, by considering the first index of the level as a reference, and making the further indexes on the basis of this (considering this as the 0), this is becaise all that matters is the difference in indexes of last and first nodes, so differnce would be same, if the refrence is same

//. T.C -> O(n)
//. S.C -> O(n), for queue
int widthOfBinaryTree(TreeNode* root) {

    if (!root) return 0;

    queue<pair<TreeNode*, long long>>q;
    q.push({root, 0});

    int ans = 0;

    while(!q.empty()) {
        
        int size = q.size();
        int minIndex = q.front().second;

        int first = 0, last = 0;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front().first;
            long long index = q.front().second - minIndex;

            if (i == 0) first = index;
            if (i == size-1) last = index;

            if (node->left) q.push({node->left, 2*index+1});
            if (node->right) q.push({node->right, 2*index+2});

            q.pop();
        }

        ans = max(ans, (last - first + 1));
    }

    return ans;
    
}