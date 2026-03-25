#include <bits/stdc++.h>
using namespace std;

//? Problem: https://www.geeksforgeeks.org/problems/unique-binary-tree-requirements/1

//! Concept: To uniquely detemine a binary tree we need an inorder traversal and either preorder or postorder traversal

bool isPossible(int a, int b) {
    
    // If both is inorder, we can't determine a unique tree just from inorder
    if (a == 2 && b == 2) return false;
    
    if (a == 2 || b == 2) return true;
    
    return false;
    
}
