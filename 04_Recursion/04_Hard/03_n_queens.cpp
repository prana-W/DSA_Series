#include <bits/stdc++.h>
using namespace std;

//* Method - I (Brute Force, My Method, Hard Solution)
// Exclude, Include concept used for each sqaure, then makr all the attacking blocks to non-zero number and before placing the queen at a particular block, make sure it is non-attacking block, then only proceed. But this solution adds unncessary complexity, as when we place a queen at a partiuclar row, we can simply move to the next row instead of again trying in that same block. Hence ignore this solution.

void solve(int index, int n, vector<pair<int, int>>& coordinates, vector<vector<int>>& board, vector<vector<pair<int, int>>>& ans) {

    int row = index/n;
    int col = index%n;

    // If n queens are placed
    if (coordinates.size() == n) {
        ans.push_back(coordinates);
        return;
    }
    if (row >= n || col >= n) {
        return;
    }

    // Exclude
    solve(index+1, n, coordinates, board, ans);

    // Checking if current square is not blocked
    if (board[row][col] > 0) return;

    // Include
    coordinates.push_back({row, col});

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == row) ||
                (j == col) ||
                (i - j == row - col) ||
                (i + j == row + col)) board[i][j]++;
        }
    }

    board[row][col] = -1;

    solve(index+1, n, coordinates, board, ans);

    // Backtracking
    coordinates.pop_back();  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == row) ||
                (j == col) ||
                (i - j == row - col) ||
                (i + j == row + col)) board[i][j]--;
        }
    } 

    // Turning the current block back to 0
    board[row][col] = 0;

}
vector<vector<string>> solveNQueens(int n) {

    vector<pair<int, int>>coordinates;
    vector<vector<pair<int, int>>>ans;
    
    vector<string>templat;
    vector<vector<string>>fAns;

    vector<vector<int>>board;

    string tempStr(n, '.'); 

    for (int i = 0; i < n; i++) {
        vector<int>temp;
        vector<string>temp2;
        for (int j = 0; j < n; j++) {
            temp.push_back(0);
        }
        board.push_back(temp);
        templat.push_back(tempStr);
    }

    solve(0, n, coordinates, board, ans);

    vector<string>template2 = templat;

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            int qRow = ans[i][j].first;
            int qCol = ans[i][j].second;

            cout << qRow << " " << qCol << endl;

            templat[qRow][qCol] = 'Q';
        }
        cout << endl;
        fAns.push_back(templat);
        templat = template2;
    }

    return fAns;        
}

//* Method - I.V (Brute Force, Easy solution)

// Make a recursive funciton that takes the row number. Start with first row and inside each row, try placing queen at a particular col, if it is safe (that is no other queen is on the same row, col and diagonals as this sqaure), and then call the recursive funciton for next row (as this row will be satisified), try this with all coloumn to get all the combiantions

//. T.C -> O(n! * n^2), n! states and each state is taking n^2 for checking if it is safe each time
//. S.C -> O(n^2 + k*n^2 + n), O(n^2) for board matrix, O(k*n^2) for storing the ans that has k solutions and O(n) for recursive stack space

bool isSafe(int row, int col, vector<string>& board) {

    int n = board.size();

    // Check given row
    for (int colIndex = 0; colIndex < n; colIndex++) {
        if (board[row][colIndex] == 'Q') return false;
    }

    // Check given col
    for (int rowIndex = 0; rowIndex < n; rowIndex++) {
        if (board[rowIndex][col] == 'Q') return false;
    }

    // Check diagonal and anti-diagonal
    for (int rowIndex = 0; rowIndex < n; rowIndex++) {
        for (int colIndex = 0; colIndex < n; colIndex++) {
            if ((rowIndex - colIndex == row - col) && board[rowIndex][colIndex] == 'Q') return false;
            if ((rowIndex + colIndex == row + col) && board[rowIndex][colIndex] == 'Q') return false;
        }
    }

    return true;
}
void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans) {

    // If we reach row == n, it means, we were able to place all the n quuens in safe manner in n rows
    if (row == n) {
        ans.push_back(board);
        return;
    }

    // Trying queen at all the coloumn of this particular row (if only safe)
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board)) {

            board[row][col] = 'Q';

            solve(row+1, n, board, ans);

            // Backtracking
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {

    vector<string>board(n, string(n, '.'));
    vector<vector<string>>ans;

    solve(0, n, board, ans);

    return ans;
}

//* Method - II (Optimal Solution)
// Make three hash arrays, one for col, one for diagonal and one for anti-diagonal. There is no need for hash array for row, as we are only placing one Queen in a single row by logic. This imprioove the isSafe logic from O(n^2) to O(1) due to hash arrays

// For col, make a hash array of size n, for anti-diagonal, make it of size 2n-1, as formula is row+col for the index of any diagonal, so max. value of row+col is 2n-2.

// For diagonal, formula to get index for the diaognal is row - col or to make it postive always, n - 1 + row - col, max value is 2n-2, therfore size will be 2n-1

//. T.C -> O(n!), better as now checking isSafe takes O(1) time compleixty
//. S.C -> O(n^2 + k*n^2 + n), same reason as above

void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans, vector<int>& colCheck, vector<int>& diagonalCheck, vector<int>& antiDiagonalCheck) {

    // If we reach row == n, it means, we were able to place all the n quuens in safe manner in n rows
    if (row == n) {
        ans.push_back(board);
        return;
    }

    // Trying queen at all the coloumn of this particular row (if only safe)
    for (int col = 0; col < n; col++) {

        if (colCheck[col] == 0 && diagonalCheck[n-1+row-col] == 0 && antiDiagonalCheck[row+col] == 0) {

            board[row][col] = 'Q';
            colCheck[col] = 1;
            diagonalCheck[n-1+row-col] = 1;
            antiDiagonalCheck[row+col] = 1;

            solve(row+1, n, board, ans, colCheck, diagonalCheck, antiDiagonalCheck);

            board[row][col] = '.';
            colCheck[col] = 0;
            diagonalCheck[n-1+row-col] = 0;
            antiDiagonalCheck[row+col] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {

    vector<string>board(n, string(n, '.'));
    vector<vector<string>>ans;

    vector<int>colCheck(n, 0);
    vector<int>diagonalCheck(2*n-1, 0);
    vector<int>antiDiagonalCheck(2*n-1, 0);

    solve(0, n, board, ans, colCheck, diagonalCheck, antiDiagonalCheck);

    return ans;
}