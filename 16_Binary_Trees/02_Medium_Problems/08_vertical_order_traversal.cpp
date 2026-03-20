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

// Use simple BFS, and store the nodes according to colIndex in a map. Instead of directly storing the ndoe value, store the rowIndex and value in a pair in map, at the end sort all these arrays and then insert in fnal answer. This sorts it according to rowIndex and then value (if rowIndex is same)

//. T.C -> O(n*log(n))
//. S.C -> O(n)
vector<vector<int>> verticalTraversal(TreeNode* root) {

    if (!root) return {};

    // key: coloumnIndex, value: pair(rowIndex, node_value)
    map<int, vector<pair<int, int>>>mp;
    vector<vector<int>>ans;

    // For BFS (node, pair(rowIndex, colIndex))
    queue<pair<TreeNode*, pair<int, int>>>q;
    q.push({root, {0, 0}});

    while(q.size()) {
        int size = q.size();

        while(size) {
            TreeNode* node = q.front().first;

            int rowIndex = q.front().second.first;
            int colIndex = q.front().second.second;

            mp[colIndex].push_back({rowIndex, node->val});

            if (node->left) q.push({node->left, {rowIndex+1, colIndex-1}});
            if (node->right) q.push({node->right, {rowIndex+1, colIndex+1}});

            q.pop();
            size--;
        }
    }

    // elem -> (colIndex, vector(pair))
    for (auto elem : mp) {

        vector<int>temp;

        // Sorting the array of pair (rowIndex, value)
        sort(elem.second.begin(), elem.second.end());
        
        for (auto elem2 : elem.second) {
            temp.push_back(elem2.second);
        }

        ans.push_back(temp);
    }

    return ans;
    
}