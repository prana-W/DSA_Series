#include <bits/stdc++.h>
using namespace std; 

// Loop through all the characters in the amtrix in the grid and call the dfs recursiv function. This function recursively checks firtly if the current character matches the character with the given index of word, and then checks all the four directions for next character, also while finding a match, it marks the visited character to any other random character, so it is not used again. THis is turn back to original character at the end, if path was not found for the particular search

//. T.C -> O(4^L*m*n), L is the number of letters in word, m*n is the total elements in the matrix (grid)
//. S.C -> O(L)

bool dfs(int row, int col, int index, vector<vector<char>>& board, string& word) {

    if (index == word.size()) return true;
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;
    if (word[index] != board[row][col]) return false;

    // Store current character and mark as visited
    char temp = board[row][col];
    board[row][col] = '#';

    // Explore all four directions
    bool isFound = (dfs(row, col+1, index+1, board, word)) ||
                   (dfs(row+1, col, index+1, board, word)) ||
                   (dfs(row, col-1, index+1, board, word)) ||
                   (dfs(row-1, col, index+1, board, word));

    // Restore the character (backtracking)
    board[row][col] = temp;

    return isFound;
}
bool exist(vector<vector<char>>& board, string word) {

    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {
            if (dfs(row, col, 0, board, word)) return true;
        }
    }

    return false;
    
}