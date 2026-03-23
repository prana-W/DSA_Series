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

//* Method - I (My Method)
//! this ain't tuf gng... (literally, Method-II is the TUF method, this is mine method)
// We can't go back in tree, so I did something clever. We will always check downwards, bbut how to get all the answers?

// Find the path to the target
// Select each node from the path and try to go downwards to find the relative_kth node, that's it, also never go in the direction of the original path. 

// So in this way we can find th kth node from the target

//? Pg: 101

//. T.C -> O(n)
//. S.C -> O(n)

// Helper function to find the path from root to the target
void findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path, bool& isFound) {
    if (!root || isFound) return;
    if (root == target) {
        path.push_back(root);
        isFound = true;
        return;
    }

    path.push_back(root);
    findPath(root->left, target, path, isFound);
    findPath(root->right, target, path, isFound);

    if (isFound) return;
    path.pop_back();
}

// Helper function to find the kth node downwards from a root to target
void findKthNode(TreeNode* root, int index, int& k, vector<int>& ans) {

    if (!root) return;

    if (index == k) {
        ans.push_back(root->val);
        return;
    }

    findKthNode(root->left, index+1, k, ans);
    findKthNode(root->right, index+1, k, ans);
}

// Actual function
vector<int> myMethod(TreeNode* root, TreeNode* target, int k) {

    if (!root) return {};

    vector<TreeNode*> path;
    vector<int>ans;
    bool isFound = false;

    findPath(root, target, path, isFound);

    if (!isFound) return {};

    int size = path.size();

    // Go to each node in the path, get relative k, and try to find the kth node from that downwards in opposite direction to the path
    for (int i = 0; i < size-1; i++) {

        int relativeK = k - (size-1-i);
        if (relativeK == 0) {
            ans.push_back(path[i]->val);
            continue;
        }

        TreeNode* nextNode;

        if (path[i]->left == path[i+1]) {
            nextNode = path[i]->right;
            relativeK--;
        }
        else if (path[i]->right == path[i+1]) {
            nextNode = path[i]->left;
            relativeK--;
        }

        if (relativeK < 0) continue;
        findKthNode(nextNode, 0, relativeK, ans);

    }

    findKthNode(target, 0, k, ans);

    return ans;

}

//* Method - II (TUF Method)
// Turn Binary Tree into undirected graph

// Do a BFS, and during iteration, store the parent of each node using a map, so in this manner we can also get a parent node of a node, this enables us to travel in the upward manner as well

// Stay at the target node, and go radially outwards in upward, leftward aand downward direction, while keeping a single distance varaible, which increases each time. Also make a visited hash array that keeps track of all the nodes that we have visited, which prevents going back to the same node thaat we came from, do this same thing of going radially outward till we reach the diattance k, and then we will have our answer

//. T.C -> O(n), considereing average for unordered_map
//. S.C -> O(n)

void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node->left) {
            q.push(node->left);
            parent[node->left] = node;
        }
        if (node->right) {
            q.push(node->right);
            parent[node->right] = node;
        }
    }
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

    // Marking all the parents for the nodes
    unordered_map<TreeNode*, TreeNode*>parent;
    markParents(root, parent);

    unordered_map<TreeNode*, bool>visited; // Tracks visited nodes
    queue<TreeNode*>q;

    // Push target and mark visited
    q.push(target);
    visited[target] = true;

    int distance = 0;

    // Go radially outwards till distance reaches k
    while(distance != k && !q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {

            TreeNode* node = q.front();
            q.pop();

            // Go left, is possible
            if (node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
            }

            // Go right, if possible
            if (node->right && !visited[node->right]){ 
                q.push(node->right);
                visited[node->right] = true;
            }

            // Go Up, if possible
            if(parent[node] && !visited[parent[node]]) {
                q.push(parent[node]);
                visited[parent[node]] = true;
            }

        }

        distance++;
    }

    vector<int>ans;

    // Answer remains inside q
    while(!q.empty()) {
        ans.push_back(q.front()->val);
        q.pop();
    }

    return ans;
    
}