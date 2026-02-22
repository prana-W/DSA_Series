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

//* Method - I (Queue + Matrix Method; Iterative Approach)
// Use a queue data structure to implement this. First push the root of the tree, then iterate till the queue is empty. For each iteration, keep on poping the nodes of that level and then pushing the left and right of that node on the top, also store all the values of that particular level into a temp array and then at last insert that into the matrix

//. T.C -> O(n), for iterating over all the nodes
//. S.C -> O(n), for queue (extra space considered here)
vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*>q;
        vector<vector<int>>ans;

        if (!root) return ans;

        q.push(root);

        // Till the entire queue is empty, that means all the levels are iterated
        while (q.size()) {

            vector<int> temp;

            int size = q.size();

            // To iterate the particular level
            while (size) {

                TreeNode* tree = q.front();

                if (tree->left)
                    q.push(tree->left);
                if (tree->right)
                    q.push(tree->right);

                temp.push_back(tree->val);

                q.pop();

                size--;
            }

            // Push the result of this level
            ans.push_back(temp);
        }

        return ans;
}

//* Method - II (Recursive Approach)
// Use a simple matrix of nodes to store all the nodes of each level. Inside the function, iterate the array of nodes of previous level and push get their left and right nodes and store them in an array of currLevel and store it in an array and finally push in the ans array (matrix of nodes). At the end since we have to return matrix of values, create the matrix of values from the matrix of nodes

//. T.C -> O(2n)
//. S.C -> O(n + height), O(n) for the matrix of nodes and O(height) for the recursive stack

// Recursive Function
void levelorder(vector<vector<TreeNode*>>& ans) {

        vector<TreeNode*>currLevel;

        // Iterating on the nodes of previous level
        for (auto elem : ans.back()) {
            if(elem->left) currLevel.push_back(elem->left);
            if(elem->right) currLevel.push_back(elem->right);
          
        }

        // Base condition
        if (currLevel.empty()) return;

        ans.push_back(currLevel);

        levelorder(ans);
       
}

vector<vector<int>> revursiveApproach(TreeNode* root) {

        if (!root) return {};

        // Manually doing for level 1
        vector<vector<TreeNode*>>ans;
        ans.push_back({root});

        levelorder(ans);

        // Converting the matrix of nodes to simply matrix of values
        vector<vector<int>>fAns;
        for (auto elem : ans) {
            vector<int>temp;
            for (auto node : elem) {
                temp.push_back(node->val);                
            }
            fAns.push_back(temp);
        }

        return fAns;

}