#include <bits/stdc++.h>
using namespace std;

//! Note: A DFS + DP solution breaks, as dp calculates efforts based on a single path, and then that effort will be reused for other paths, but as we know that effort also depndes on several other paths, so we can't use DP as we can't use something from the past that also depends on the future.

//* Method - I (Dijkistra's Algorithm)
// When we find that the max of absoulute height difference between two node and the effort required for the parent node is smaller than the effort of the current node, then we udate the effort of the current node. In this way we can use Dijkistra's Algorithm to find our answer

//. T.C -> O(nm * log(nm))
//. S.C -> O(nm)
int minimumEffortPath(vector<vector<int>>& heights) {

    vector<vector<int>>efforts(heights.size(), vector<int>(heights[0].size(), INT_MAX));
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    efforts[0][0] = 0;
    pq.push({0, {0, 0}});
    
    while(!pq.empty()) {
        auto top = pq.top(); 
        int eff = top.first, r = top.second.first, c = top.second.second;
        pq.pop();

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int newR = r + dx[i];
            int newC = c + dy[i];

            if (newR < 0 || newC < 0 || newR >= heights.size() || newC >= heights[0].size()) continue;

            int effortTillNow = max(abs(heights[newR][newC] - heights[r][c]), efforts[r][c]);

            if(effortTillNow < efforts[newR][newC]) {
                efforts[newR][newC] = max(abs(heights[newR][newC] - heights[r][c]), efforts[r][c]);
                pq.push({efforts[newR][newC], {newR, newC}});
            }

        }
    }

    if(efforts.back().back() == INT_MAX) return -1;        
    return efforts.back().back();
    
}

//* Method - II (Binary Search)
// We get a range of possible answer and then check if it is possible to reach from start to end or not, if is is, try searching even smaller value of effort else try searching higher value. We use BFS to move, when we find the abs difference in heights as less than what is given as parameter, we can say that we can reach this nee node from some path, hence add that to queue and if at some point we encounter the end node, we can say there exists some path to reach here with max effort still less than or equal to given effort

// Checks if it is possible to reach from start to end with a given maximum of eff effort

//! BFS can be replaced by DFS as well

//. T.C -> O(nm*log(nm)), O(nm) for each BFS and log(1e6) at max
//. S.C -> O(nm)

bool isPossible(int eff, vector<vector<int>>& h) {

    int n = h.size(), m = h[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int,int>> q;

    q.push({0,0});
    visited[0][0] = true;

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    while(!q.empty()) {
        auto [r,c] = q.front();
        q.pop();

        if(r == n-1 && c == m-1) return true;

        for(int i = 0; i < 4; i++) {
            int nr = r + dx[i], nc = c + dy[i];

            if(nr < 0 || nc < 0 || nr >= n || nc >= m || visited[nr][nc]) continue;

            // If effort between the node is les than or equal than we can reach eff, so add it to queue
            if(abs(h[nr][nc] - h[r][c]) <= eff) {
                visited[nr][nc] = true;
                q.push({nr,nc});
            }
        }
    }

    return false;
}
int minimumEffortPath(vector<vector<int>>& heights) {

    if(heights.size() == 1 && heights[0].size() == 1) return 0;

    // Finding the lowest and highes abs difference of height
    int low = INT_MAX, high = INT_MIN;
    for (int r = 0; r < heights.size(); r++) {
        for (int c = 0; c < heights[0].size(); c++) {
            if(c+1 < heights[0].size()) {
                low = min(low, abs(heights[r][c] - heights[r][c+1]));
                high = max(high, abs(heights[r][c] - heights[r][c+1]));
            }
            if(r+1 < heights.size()) {
                low = min(low, abs(heights[r][c] - heights[r+1][c]));
                high = max(high, abs(heights[r][c] - heights[r+1][c]));
            }
        }
    }

    // BS on the possible value of max effort that makes it valid to travel from start to end
    while(low <= high) {
        int mid = (low+high)/2;

        if(isPossible(mid, heights)) high = mid-1;
        else low = mid+1;
    }
    
    return low;
    
}

//* Method - III (Binary Search + DFS)
// Same concept as above, just use DFS instead of BFS

//. T.C -> O(nm*log(nm)), O(nm) for each DFS and log(1e6) at max
//. S.C -> O(nm)

bool dfs(int r, int c, vector<vector<int>>& h, vector<vector<bool>>& vis, int eff) {
    int n = h.size(), m = h[0].size();

    if (r == n-1 && c == m-1) return true;

    vis[r][c] = true;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
        int nr = r + dx[i], nc = c + dy[i];

        if (nr < 0 || nc < 0 || nr >= n || nc >= m || vis[nr][nc]) continue;

        if (abs(h[nr][nc] - h[r][c]) <= eff) {
            if (dfs(nr, nc, h, vis, eff)) return true;
        }
    }

    return false;
}

bool isPossible(int eff, vector<vector<int>>& h) {
    int n = h.size(), m = h[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    return dfs(0, 0, h, vis, eff);
}

int minimumEffortPath(vector<vector<int>>& h) {
    int low = 0, high = 1e6;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(mid, h)) high = mid - 1;
        else low = mid + 1;
    }

    return low;
}