#include <bits/stdc++.h>
using namespace std;

// Go to each index (0 to 80) and if it is empty, try to place all possible elements in it. Also I have used three hashes, row, col and block, each tracking elements in a particular row, col and block respectuvely, this is done to optimise the lookup for is it safe to place a element at position x, y, else isSafe helper function would have take a large time each time

//. T.C -> O(9^81)
//. S.C -> O(300), O(100) for each hash matrixes

bool solve(int index, vector<vector<char>>& board, vector<vector<bool>>& rowHash, vector<vector<bool>>& colHash, vector<vector<bool>>& blockHash) {

    if (index == 81) return true;

    int row = index/9;
    int col = index%9;

    // If not empty, just call for the next index
    if (board[row][col] != '.') {
        return solve(index+1, board, rowHash, colHash, blockHash);
    }

    // Try to place all the elements
    for (int elem = 1; elem <= 9; elem++) {

        // Checking if possible to place elem at this position
        if (rowHash[row][elem] || colHash[col][elem] || blockHash[(row/3)*3 + (col/3)][elem]) continue;

        board[row][col] = (elem + '0');

        rowHash[row][elem] = true;
        colHash[col][elem] = true;
        blockHash[(row/3)*3 + (col/3)][elem] = true;

        // If we find the answer, just return back instantly to avoid backtracking (as we backtrack only when we don't find the correct answer)
        if(solve(index+1, board, rowHash, colHash, blockHash)) return true;

        // Backtracking
        rowHash[row][elem] = false;
        colHash[col][elem] = false;
        blockHash[(row/3)*3 + (col/3)][elem] = false;

        board[row][col] = '.';
    }


    return false;
    
}
void solveSudoku(vector<vector<char>>& board) {

    vector<vector<bool>>rowHash(10, vector<bool>(10, false));
    vector<vector<bool>>colHash(10, vector<bool>(10, false));
    vector<vector<bool>>blockHash(10, vector<bool>(10, false));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {

                int elem = (board[i][j] - '0');
                rowHash[i][elem] = true;
                colHash[j][elem] = true;
                blockHash[(i/3)*3 + (j/3)][elem] = true;
            }
        }
    }

    solve(0, board, rowHash, colHash, blockHash);
    
}