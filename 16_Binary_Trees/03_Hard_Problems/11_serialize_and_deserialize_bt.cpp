#include <bits/stdc++.h>
using namespace std;

//! Concept: A unique tree can be made from preorder (or postorder or inorder) traversal if we also include the nullpointers of the nodes that exist

//! HW: Further optimise by not using directing converting to string, instead of the intermediate vector for preorder. Also solve it using BFS traversal instead of DFS

//* Method - I (DFS, Slightly unoptimised)

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

// Here we serialise using by first finding the e preorder along with nulls, then creating the string. 
// Example: [1, -5, 200, INT_MIN, -99] -> "1,-5,200,#,-99,"

// For deserialisation, form the preorder from the string and then recursively construct a unique Tree

//? Important conventions used:

// INT_MIN -> nullptr
// # -> nullptr

//. T.C -> O(n)
//. S.C -> O(n)

class Codec {

private: // Helper functions

    void pre(TreeNode* root, vector<int>& ans) {
        if (!root) {
            ans.push_back(INT_MIN);
            return;
        }

        ans.push_back(root->val);
        pre(root->left, ans);
        pre(root->right, ans);
    }

    TreeNode* solve(int& index, vector<int>& pre) {

        if (pre[index] == INT_MIN) return nullptr;

        TreeNode* root = new TreeNode(pre[index]);
    
        index++;
        root->left = solve(index, pre);

        index++;
        root->right = solve(index, pre);

        return root;        

    }

public: // Actual functions

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        vector<int>preorder;
        pre(root, preorder);

        string s;

        // Create a string 
        for (auto elem : preorder) {
            if (elem == INT_MIN) s += '#';
            else {
                string temp;

                int num = abs(elem);

                while(num) {

                    int digit = num%10;
                    temp.push_back(digit + '0');
                    num /= 10;
                }

                if (elem < 0) temp.push_back('-');

                reverse(temp.begin(), temp.end());

                s += temp;
            }

            s += ',';
        }

        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector<int>preorder;
        int i = 0;
        while(i < data.size()) {
            string temp;

            while(data[i] != ',') {
                temp += data[i];
                i++;
            }

            int num = 0;

            for (int j = 0; j < temp.size(); j++) {
                if (temp[j] == '#') {
                    num = INT_MIN;
                    break;
                }
                if (temp[j] == '-') continue;
                int digit = (temp[j] - '0');

                num = (num*10 + digit);
            }

            if (temp[0] == '-') num = -1*num;

            preorder.push_back(num);
            i++;
        }

        int index = 0;
        TreeNode* root = solve(index, preorder);

        return root;      
        
    }
};

//* Method - II (BFS, Optimised)
// Try to solve without using vector, directly convert into string and back into tree. Aslo solve the using BFS