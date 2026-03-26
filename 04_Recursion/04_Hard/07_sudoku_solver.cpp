#include <bits/stdc++.h>
using namespace std;

//* Method - I (Better Solution)

// Go to each index (0 to 80) and if it is empty, try to place all possible elements in it. Also I have used three hashes, row, col and block, each tracking elements in a particular row, col and block respectuvely, this is done to optimise the lookup for is it safe to place a element at position x, y, else isSafe helper function would have take a large time each time

//. T.C -> O(9^E), E is the number of empty cells
//. S.C -> O(270), O(9 * 10) for each hash matrixes

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

    vector<vector<bool>>rowHash(9, vector<bool>(10, false));
    vector<vector<bool>>colHash(9, vector<bool>(10, false));
    vector<vector<bool>>blockHash(9, vector<bool>(10, false));

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

//* Method - II (Optimised Space Complexity Approach)
// Insteaad of making there hash array of each 90 size (9x10), we can optimise the space by using three 1-D hash arrays of each 9 size. We will store which elements are present in it by using bit masking

// Initially all numbers of these hash arrays is 0, then to add a number, say number x exist in the row 0, then we create a mask and modify the number of the 0th row such that the xth bit from the end is set.

//! Concept: To place any element in the has, just set the bit from the end for that row, col and block

// Set: rowMask[row] |= (1 << (elem - 1));
// Unset (for backtrack): rowMask[row] ^= (1 << (elem - 1));
// Check: if (rowMask[row] & (1 << (elem - 1)))

//. T.C -> O(9^E), E is  the number of empty cells
//. S.C -> O(27), since only three 1-D hash arrays
bool solve(int index, vector<vector<char>>& board, 
           int rowMask[], int colMask[], int blockMask[]) {

    if (index == 81) return true;

    int row = index / 9;
    int col = index % 9;

    if (board[row][col] != '.') {
        return solve(index + 1, board, rowMask, colMask, blockMask);
    }

    int block = (row / 3) * 3 + (col / 3);

    for (int elem = 1; elem <= 9; elem++) {

        int mask = (1 << (elem - 1));

        // Check if safe
        if ((rowMask[row] & mask) || 
            (colMask[col] & mask) || 
            (blockMask[block] & mask)) continue;

        // Place
        board[row][col] = elem + '0';
        rowMask[row] |= mask;
        colMask[col] |= mask;
        blockMask[block] |= mask;

        if (solve(index + 1, board, rowMask, colMask, blockMask))
            return true;

        // Backtrack
        board[row][col] = '.';
        rowMask[row] ^= mask;
        colMask[col] ^= mask;
        blockMask[block] ^= mask;
    }

    return false;
}

void solveSudoku(vector<vector<char>>& board) {

    int rowMask[9] = {0}, colMask[9] = {0}, blockMask[9] = {0};

    // Initialize masks
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int elem = board[i][j] - '0';
                int mask = (1 << (elem - 1));
                int block = (i / 3) * 3 + (j / 3);

                rowMask[i] |= mask;
                colMask[j] |= mask;
                blockMask[block] |= mask;
            }
        }
    }

    solve(0, board, rowMask, colMask, blockMask);
}