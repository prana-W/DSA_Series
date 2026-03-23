#include <bits/stdc++.h>
using namespace std;

// Try to move in all directions, if it is blocked, return back. Also when visiting a path, block it so it can't be traced back in the furte and backtrack at the end to make it non-visited again. 

//! Note: Here we did Down, Left, Right, Up, as the final answer was needed to be lexicographically increasing

//. T.C -> 4^(n*n), every cell has 4 possible directions
//. S.C -> O(n^2), for the matrix an d for recursive stack space

void solve(int row, int col, int& n, vector<vector<int>>& maze, string& path, vector<string>& ans) {

    if (row == n-1 && col == n-1 && maze[row][col] == 1) {
        ans.push_back(path);
        return;
    }

    // Checks if it is safe to move here
    if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0) {
        return;
    }
    
    // Block to avoid furutre re-use during this path
    maze[row][col] = 0;
    
    // Down 
    path.push_back('D');
    solve(row+1, col, n, maze, path, ans);
    path.pop_back();
    
    // Left
    path.push_back('L');
    solve(row, col-1, n, maze, path, ans);
    path.pop_back();
    
    // Right
    path.push_back('R');
    solve(row, col+1, n, maze, path, ans);
    path.pop_back();
    
    // Up
    path.push_back('U');
    solve(row-1, col, n, maze, path, ans);
    path.pop_back();
    
    // Backtracking
    maze[row][col] = 1;
}
vector<string> ratInMaze(vector<vector<int>>& maze) {
    
    int n = maze.size();
    
    if (maze[0][0] == 0 || maze[n-1][n-1] == 0) return {};
    
    string path;
    vector<string>ans;
    
    solve(0, 0, n, maze, path, ans);
    
    return ans;
    
    
}