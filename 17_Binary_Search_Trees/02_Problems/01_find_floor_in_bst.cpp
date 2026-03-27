#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//. T.C -> O(h), ususaaly h = log(n)
//. S.C -> O(1)
int findFloor(Node* root, int x) {
    
    int ans = -1;
    
    while(root) {
        
        if (root->data > x) {
            root = root->left;
        }
        else {
            ans = root->data;
            root = root->right;
        }
    }
    
    return ans;
    
}