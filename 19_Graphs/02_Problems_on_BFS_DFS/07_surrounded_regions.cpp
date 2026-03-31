#include <bits/stdc++.h>
using namespace std;

// Do a simple DFS from the boundary cells containing O, and mark all the traversed O's into S (meaning safe) at the end, traverse the matrix once and all the cells marked with S are safe and hence convert them back to O, and all the O in the matrix are not-safe and hence convert them into X

//. T.C -> O(n*m)
//. S.C -> O(n*m) in worstt case for recursion due to all zeroes

//! Note: In the TUF method, visited array used, which is not requirede at all, because if we mark the matrix in-place S, that's ultimately saying that hey, I have already visited this cell, so there is no need and hence we don't take any extra time

void dfs(int r, int c, vector<vector<char>>& board) {

    if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == 'X' || board[r][c] == 'S') return;

    board[r][c] = 'S';

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
        int newR = r + dx[i];
        int newC = c + dy[i];

        dfs(newR, newC, board);
    }

}

void surroundedRegion(vector<vector<char>>& board) {

    // Do for Row-0 and Row-end
    for(int j = 0; j < board[0].size(); j++) {
        dfs(0, j, board);
        dfs(board.size()-1, j, board);
    }

    // Do for Col-0 and Col-end
    for(int i = 1; i < board.size()-1; i++) {
        dfs(i, 0, board);
        dfs(i, board[0].size()-1, board);
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == 'S') board[i][j] = 'O';
            else if(board[i][j] == 'O') board[i][j] = 'X';
        }
    }
    
}