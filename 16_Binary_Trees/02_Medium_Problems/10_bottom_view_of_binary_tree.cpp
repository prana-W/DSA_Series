#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    public:
        Node(int data1) {
            data = data1;
            left = nullptr;
            right = nullptr;
        }
};

// First solve vertical order traversal. Here the answer is the last element of each coloumn in vertical order traversal. So just store the last value for each colIndex

//. T.C -> O(n)
//. S.C -> O(n)
vector<int> topView(Node *root) {
    
    // (Node, pair(rowIndex, colIndex))
    queue<pair<Node*, pair<int, int>>>q;
    q.push({root, {0, 0}});
    
    // (colIndex, node_value)
    map<int, int>mp;
    vector<int>ans;
    
    // BFS
    while(q.size()) {
        int size = q.size();
        
        while(size) {
            Node* node = q.front().first;
            
            int rowIndex = q.front().second.first;
            int colIndex = q.front().second.second;
            
            mp[colIndex] = node->data;            
            
            if (node->left) q.push({node->left, {rowIndex+1, colIndex-1}});
            if (node->right) q.push({node->right, {rowIndex+1, colIndex+1}});
            
            q.pop();
            size--;
        }
    
    }
    
    for (auto elem : mp) {
        ans.push_back(elem.second);
    }
    
    return ans;
}