#include <bits/stdc++.h>
using namespace std;

//? Problem: https://www.geeksforgeeks.org/problems/unique-binary-tree-requirements/1

//! Concept-1: A unique tree can be made from preorder, or postorder, or inorder, or level order traversal if we also include the nullpointers of the nodes that exist. That means to construct a unnique BT, either of the traversla will work but only if null are inlcuded in it, else,

//! Concept-2: To uniquely detemine a binary tree we need an inorder traversal and either preorder or postorder traversal 

//! We can only detemrine a unique BT from level order, if we inlcude nulls, it can't be used to determine unique BT with any other traversals

bool isPossible(int a, int b) {
    
    // If both is inorder, we can't determine a unique tree just from inorder
    if (a == 2 && b == 2) return false;
    
    if (a == 2 || b == 2) return true;
    
    return false;
    
}
