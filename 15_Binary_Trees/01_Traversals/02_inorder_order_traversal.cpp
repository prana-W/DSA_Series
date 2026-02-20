#include <bits/stdc++.h>
using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;

    public:
        Node(int val) {
            data = val;
            left = nullptr;
            right = nullptr;
        }
};

//! Left Root Right

//. T.C -> O(n), n is the number of nodes
//. S.C -> o(height), in worst case of skewed O(n)
void inorder(Node* node) {
    if (!node) return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}