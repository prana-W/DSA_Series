#include <bits/stdc++.h>
using namespace std;

// Just use simple DSU impmentation for the intitial configuration. Join right and bottom lands with current land initially. After that, go to each water and find the size of the ultimate parent of all the neigbhoubring islands, add them and increase it by one to include the current land and update ans if current total size is more than previous one. Also initialise ans with the largest island size that we can get from the intial given grid.

// We have used an unordered_map to get the size of the neihbouring island with key as ultimate parent and value as the size, this is to avoid recounting the size of the two neihbours that are actually conncected

//. T.C -> O(n^2)
//. S.C -> O(n^2)

class DSU {

    vector<int>parent, size;

    public:

    DSU (int n) {
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findUPar(int n) {
        if(parent[n] == n) return n;

        return parent[n] = findUPar(parent[n]);
    }

    void unionBySize(int u, int v) {
        int upU = findUPar(u);
        int upV = findUPar(v);

        if (upU == upV) return;

        if(size[upU] < size[upV]) {
            parent[upU] = upV;
            size[upV] += size[upU];
        }
        else {
            parent[upV] = upU;
            size[upU] += size[upV];
        }

        return;
    }

    int getSize(int n) {
        return size[n];
    }

};

int largestIsland(vector<vector<int>>& grid) {

    int n = grid.size();

    DSU ds(n*n);

    // Initial configuration of the DSU
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if(grid[r][c] == 0) continue;

            // Right side
            if (c+1 < n && grid[r][c] == grid[r][c+1]) {
                int currInd = r*n + c;
                int neiInd = r*n + (c+1);

                ds.unionBySize(currInd, neiInd);
            }

            // Down side
            if (r+1 < n && grid[r][c] == grid[r+1][c]) {
                int currInd = r*n + c;
                int neiInd = (r+1)*n + c;

                ds.unionBySize(currInd, neiInd);
            }
        }
    }

    // Initialise ans to the maximum island size
    int ans = 0;
    for (int ind = 0; ind < n*n; ind++) {
        int r = ind/n, c = ind%n;

        if (grid[r][c] == 0) continue;

        ans = max(ans, ds.getSize(ds.findUPar(ind)));
    }   

    // Go to each water block and try to find the total size of all the neihbouring islands using ultimate parent and at end increase by one to include the current land and updat ans if we have got maximum
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if(grid[r][c] == 1) continue;

            int currInd = r*n + c;

            int dx[4] = {1, -1, 0, 0};
            int dy[4] = {0, 0, 1, -1};

            int temp = 0;

            // (ultimate_parent, size)
            unordered_map<int, int>mp;

            for (int i = 0; i < 4; i++) {

                int newR = r+dx[i];
                int newC = c+dy[i];
                int neiInd = newR*n + newC;

                if (newR < 0 || newC < 0 || newR >= n || newC >= n || grid[newR][newC] == 0) continue;

                // Find the size of the neihbour land's ultimate parent
                int ultimateParent = ds.findUPar(neiInd);
                mp[ultimateParent] = ds.getSize(ultimateParent);

            }
            
            // Add size of all the neihbouring ultimate parents
            for (auto elem : mp) {
                temp += elem.second;
            }

            temp++; // Include the current index's land to the size

            ans = max(ans, temp);

        }
    }

    return ans;
    
}