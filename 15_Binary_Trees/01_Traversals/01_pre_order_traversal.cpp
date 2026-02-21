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

//* Method - I (Recursive Method)

//! Root Left Right

//. T.C -> O(n), n is the number of nodes
//. S.C -> O(height), where height is the height of the tree and when the Tree is skewed then height = n (total nodes), hence O(n) at worst case
void preOrder(Node* node) {

    if (!node) return;

    cout << node->data << " ";

    preOrder(node->left);
    preOrder(node->right);

}

//* Method - II (Iterative Method)