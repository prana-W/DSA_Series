#include <bits/stdc++.h>
using namespace std;

// We use BFS on the rooten oranges till no traversal is possible. Also if at the end total rotten oranges is equal to total orangesm then only the ans will be valid, else not

//. T.C -> O(n*n*4), in worst case all have oranges so for each we are iterating 4 times
//. S.C -> O(n*n), for queue, if all gets rotten and entered in the queue

int orangesRotting(vector<vector<int>>& grid) {

    // totalCnt -> totalCnt oragnes, rottenCnt -> rooten oranges
    int totalCnt = 0, rottenCnt = 0;
    // Coordinates of all the rooten oranges
    queue<pair<int, int>>q; 

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] > 0) totalCnt++;
            if (grid[i][j] == 2){
                q.push({i, j});
                rottenCnt++;
            }
        }
    }

    // All the possible paths
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    // ans is the minutes passed
    int ans = 0;

    // BFS
    while(!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for (int j = 0; j < 4; j++) {

                int newRow = row + dx[j];
                int newCol = col + dy[j];

                // Checks if possible coordinate and fresh orange at the new coordinate
                if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size() || grid[newRow][newCol] != 1) continue;

                // Make the fresh as rotten and hence add to queue and count it
                grid[newRow][newCol] = 2;
                q.push({newRow, newCol});   
                rottenCnt++;             

            }

        } 

        if(!q.empty()) ans++;
    }

    // If all the oranges become rotten, then answer is valid
    if (rottenCnt == totalCnt) return ans;

    return -1;
    
}
