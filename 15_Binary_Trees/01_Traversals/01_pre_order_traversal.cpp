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

// Root Left Right
void preOrder(Node* node) {

    if (!node) return;

    cout << node->data << " ";

    preOrder(node->left);
    preOrder(node->right);

}