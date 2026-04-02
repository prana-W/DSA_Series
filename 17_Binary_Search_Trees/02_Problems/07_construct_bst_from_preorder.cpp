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
// Take the element from the preorder, try to find where it can be inserted, then insert it in the BST and continue creating the bST manually

//. T.C -> O(n*n)

//* Method - II (Better Solution)
// We are given with preorder, sort it to get the inorder traversal (as inorder traversal of a BST will always be in ascedning order), after that simply use the concept of 09_construct_bt_from_preorder_traveral to form the BT

//. T.C -> O(n*log(n) + n)
//. S.C -> O(n)

//* Method - III (Optimal Solution, My Method)
// We treat the currIndex of the preorder as root, and all the elements smaller than it in the roght as the leftSubtree and all the elements greater than it as the rightSubtree and recrusively solve it.

// So we use NGE concept to find the indices of the element from which the element is greater thn our root, using this we can easily treat the 's' index as the root, (s+1, nge[s]-1) as the leftSubtree and (nge[s], e) as the rightsubtree

//. T.C -> O(n)
//. S.C -> O(h + 2n), O(h) for recursion and O(2n) extra space due to the stack and nge used
TreeNode* solve(int s, int e, vector<int>& preorder, vector<int>& nge) {

    if(s > e || s >= preorder.size() || e >= preorder.size()) return nullptr;

    // Consider this as root
    TreeNode* root = new TreeNode(preorder[s]);

    // (s+1, nge[s]-1) elements will be smaller, so act as leftsubtree
    root->left = solve(s+1, nge[s]-1, preorder, nge);

    // (nge[s], e) will be greater, so act as rightSubtree
    root->right = solve(nge[s], e, preorder, nge);

    return root;        

}
TreeNode* bstFromPreorder(vector<int>& preorder) {

    vector<int>nge(preorder.size(), preorder.size());
    stack<pair<int, int>>st;

    for (int i = preorder.size()-1; i >= 0; i--) {

        while(!st.empty() && st.top().first < preorder[i]) {
            st.pop();
        }

        if (!st.empty() && st.top().first > preorder[i]) {
            nge[i] = st.top().second;
        }

        st.push({preorder[i], i});
    }

    TreeNode* root = solve(0, preorder.size()-1, preorder, nge);

    return root;
    
}   

//* Method - IV (Optimal Solution, TUF Method)
// Use the min-max range concept just like in 05_validate_a_bst.cpp problem

//. T.C -> O(n)
//. S.C -> O(h)

TreeNode* solve(int& ind, int bound, vector<int>& preorder) {
    
    if (ind == preorder.size() || preorder[ind] > bound) return nullptr;

    // Store the current index value and increase the index for further use
    int val = preorder[ind++];
    TreeNode* root = new TreeNode(val);

    // Left subtree → values < val, for the leftsubtree the current root value becomes max
    root->left = solve(ind, val, preorder);

    // Right subtree → values < bound, for rightsubtree, the preivous bound will still be valid
    root->right = solve(ind, bound, preorder);

    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int ind = 0;
    return solve(ind, INT_MAX, preorder);
}