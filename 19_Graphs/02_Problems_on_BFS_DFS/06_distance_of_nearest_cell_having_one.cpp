#include <bits/stdc++.h>
using namespace std;

// We need to find the nearest 0 cell. So we use simple BFS. But think the problem in reverse, we put all the zero cells in the queue and then apply BFS and increase dist each time, and then simply push the dist till each cell in ans, so when we reach 1, it will be the shortest distance form the nearest zero

//. T.C -> O(n*m)
//. S.C -> O(n*m)
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

    queue<pair<int, int>>q;
    vector<vector<bool>>visited(mat.size(), vector<bool>(mat[0].size(), false));
    vector<vector<int>>ans(mat.size(), vector<int>(mat[0].size(), 0));

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            if (mat[i][j] == 0) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    int dist = 0;
    
    while(!q.empty()) {

        int size = q.size();

        for (int i = 0; i < size; i++) {

            int r = q.front().first;
            int c = q.front().second;

            ans[r][c] = dist;

            q.pop();

            int dx[4] = {1, -1, 0, 0};
            int dy[4] = {0, 0, 1, -1};

            for (int j = 0; j < 4; j++) {

                int row = r + dx[j];
                int col = c + dy[j];

                if (row < 0 || col < 0 || row >= mat.size() || col >= mat[0].size() || visited[row][col]) continue;

                q.push({row, col});
                visited[row][col] = true;
            }

        }

        dist++;
    }

    return ans;
}