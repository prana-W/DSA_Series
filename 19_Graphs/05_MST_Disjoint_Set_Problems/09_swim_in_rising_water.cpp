#include <bits/stdc++.h>
using namespace std;

//* Method - I (Better Solution, Binary Search, My Method)
// Low will be 0 and high will be n^2-1, then just use binary search to find a candidate, and then check using BFS if that is possible to reach the end, if yes, then search even smaller potential candidate else search for higher

//. T.C -> O(n^2 * log(n))
//. S.C -> O(n^2)

bool isPossible(int time, vector<vector<int>>& grid) {

    int n = grid.size();
    vector<bool>visited(n*n, false);
    queue<pair<int, int>>q;

    if (grid[0][0] > time) return false;
    
    q.push({0, 0});
    visited[0] = true;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while(!q.empty()) {
        int r = q.front().first, c = q.front().second;
        int currInd = r*n + c;

        if (r == n-1 && c == n-1) return true;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r+dx[i];
            int nc = c+dy[i];

            int neiInd = nr*n + nc;

            if(nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] > time || visited[neiInd]) continue;

            q.push({nr, nc});
            visited[neiInd] = true;
        }
    }

    return false;

}
int swimInWater(vector<vector<int>>& grid) {

    int n = grid.size();

    // low and high for time or maximum elevation
    int low = 0, high = n*n - 1;

    // Checking if we can reach the end with the current time or maximum elevation
    while(low <= high) {
        int mid = (low+high)/2;

        if (isPossible(mid, grid)) high = mid-1;
        else low = mid+1;
    }

    return low;
    
}

//* Method - II (Better Solution, Dijstra's Algorithm)
// Find the path with the smallest elevation and try to reach the end

// We have to minimise the maximum elevation along the path

//. T.C -> O(n^2 * log(n))
//. S.C -> O(n^2)
int swimInWater(vector<vector<int>>& grid) {

    int n = grid.size();

    // Min-Heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int>time(n*n, INT_MAX);

    pq.push({grid[0][0], 0});
    time[0] = grid[0][0];

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while(!pq.empty()) {

        int elevation = pq.top().first;
        int ind = pq.top().second;

        //! Skip stale values
        if (elevation > time[ind]) continue;

        //! Early exit
        if (ind == n*n -1) return elevation;

        int r = ind/n, c = ind%n;

        pq.pop();

        for (int i = 0; i < 4; i++) {

            int nr = r+dx[i];
            int nc = c+dy[i];

            int neiInd = nr*n + nc;

            if(nr < 0 || nc < 0 || nr >= n || nc >= n || time[neiInd] <= max(elevation, grid[nr][nc])) continue;

            pq.push({max(elevation, grid[nr][nc]), neiInd});
            time[neiInd] = max(elevation, grid[nr][nc]);
        }
    }

    return time.back();
    
}

//* Method - III (Optimal Solution, DSU)

// Make a loop from 0 to n^2-1, then at each time unite the block that had elevation equal to this with all its neighbour that has less than or equal to this elevation, in this manner we are making it into conncected component, at the end of each loop check if both the first block and the last block belong to the same ultimate parent, if they do instantly return the answer

//! Note: This works as each block is unique and value is from 0 to n^2 - 1

//. T.C -> O(n^2)
//. S.C -> O(n^2)

class DisjointSet {

    vector<int>parent, size;

    public:

        DisjointSet(int s) {
            for (int i = 0; i <= s; i++) {
                parent.push_back(i);
                size.push_back(1);
            }
        }

        int findUPar(int n) {
            if (parent[n] == n) return n;
            return parent[n] = findUPar(parent[n]);
        }

        bool unite(int u, int v) {
            int upU = findUPar(u);
            int upV = findUPar(v);

            if(upU == upV) return false;

            if (size[upU] < size[upV]) {
                parent[upU] = upV;
                size[upV] += size[upU];
            }
            else {
                parent[upV] = upU;
                size[upU] += size[upV];
            }
            
            return true;
        }
};

int swimInWater(vector<vector<int>>& grid) {

    int n = grid.size();

    DisjointSet ds(n*n);

    // pos[x] == {x, y}, it gives the coordinate of the block with elevation as x
    vector<pair<int, int>>pos(n*n);

    // Initialising pos
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            pos[grid[r][c]] = {r, c};
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // Going for time t = 0 to t = n*n - 1, and taking union of the block with that elevation and all its neighbours with less than or equal elevation, if at end, first and last block belong to same set, then there exists a path
    for (int t = 0; t < n*n; t++) {

        int r = pos[t].first, c = pos[t].second;
        int currInd = r*n + c;

        for (int i = 0; i < 4; i++) {
            int nr = r+dx[i];
            int nc = c+dy[i];

            int neiInd = nr*n + nc;

            if(nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] > t) continue;

            ds.unite(currInd, neiInd);
        }

        if (ds.findUPar(0) == ds.findUPar(n*n - 1)) return t;

    }

    return -1;
    
}