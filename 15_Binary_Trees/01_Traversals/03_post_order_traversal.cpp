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

//! Left Right Root

//. T.C -> o(n), n is the number of nodes 
//. S.C -> o(height), in worst case height = n, so O(n)
void postorder(Node* node) {
    if (!node) return;

    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}