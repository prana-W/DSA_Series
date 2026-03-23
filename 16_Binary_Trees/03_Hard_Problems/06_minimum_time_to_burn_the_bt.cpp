#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// This solution uses the same approach as in the second method of prevcious problem (nodes_at_k_distance), here we keep on going radially outwards as much as possible, till all the nodes are exhausted, this is the minimum time to burn the entire BT

// Helper function to find the Node form the node valu
Node* findTarget(Node* root, int targetValue) {
      
      if (!root || root->data == targetValue) return root;
      
      Node* left = findTarget(root->left, targetValue);
      Node* right = findTarget(root->right, targetValue);
      
      if (left && left->data == targetValue) return left;
      if (right && right->data == targetValue) return right;
      
}

// Mark the parents of all the nodes
void markParents(Node* root, unordered_map<Node*, Node*>& parent) {

    queue<Node*>q;
    q.push(root);

    while(!q.empty()) {
        Node* node = q.front();
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

int mainFunction(Node* root, int targetValue) {
    
// First find target
Node* target = findTarget(root, targetValue);


    // Marking all the parents for the nodes
unordered_map<Node*, Node*>parent;
markParents(root, parent);

unordered_map<Node*, bool>visited; // Tracks visited nodes
queue<Node*>q;

    // Push target and mark visited
    q.push(target);
    visited[target] = true;

    int distance = 0;

    // Go radially outwards as much as we can
    while(!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {

            Node* node = q.front();
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

return --distance;
    
}