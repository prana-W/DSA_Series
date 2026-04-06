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

//* Method - I (Brute Force)
// USe inorder traversal to get the elments in ascending order and just use simple Two Sum on an array concept to find such a pair

//. T.C -> O(n)
//. S.C -> O(n)

void inorder(TreeNode* root, vector<int>& in) {
    if(!root) return;

    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}
bool findTarget(TreeNode* root, int k) {

    vector<int>in;
    inorder(root, in);

    int i = 0, j = in.size()-1;

    while(i < j) {

        int sum = in[i] + in[j];
        
        if(sum < k) i++;
        else if (sum > k) j--;
        else return true;
    }

    return false;
    
}

//* Method - II (Optimal Approach)
// Use the concept of BSTIterator for better space optimisation. We can modify the previous problem's solution slightly, to make it work for reverese iterator as well (from the end, i.e. bigger to smaller element)

// We will keep on moving the iterator for l and r, till we find our required answer

//. T.C -> O(n)
//. S.C -> O(h), there won't be elements greater than the height in a single stack

// next() takes O(1) average time and O(h) space at max
class BSTIterator {
public:

    stack<TreeNode*>st;
    bool isReverse; // if false, next points to bigger element else points to smaller element

    // Pushes all the elements in left or right of the root
    void pushAll(TreeNode* root){

        if (!isReverse) {
            while(root){
                st.push(root);
                root = root->left;
            }
        }

        else {
            while(root){
                st.push(root);
                root = root->right;
            }
        }
        
    }

    // Returns the element at current iterator and moves to the next iterator
    int next() {

        if (st.empty()) return -1; 
        TreeNode* node = st.top();
        st.pop();

        if(!isReverse) {
            // Push all the left of the right subtree
            if(node->right){
                pushAll(node->right);
            }
        }
        else {
            if(node->left){
                pushAll(node->left);
            }
        }

        return node->val;
    }

    BSTIterator(TreeNode* root, bool reverse) {
        isReverse = reverse;
        pushAll(root);
    }
    
};

bool findTarget(TreeNode* root, int k) {
    
    BSTIterator l(root, false); // this is the normal iterator
    BSTIterator r(root, true); // This is the reverse Iterator

    int i = l.next();
    int j = r.next();

    while(i < j) {
        if(i+j < k) i = l.next();
        else if (i+j > k) j = r.next();
        else return true;
    }

    return false;
    
}