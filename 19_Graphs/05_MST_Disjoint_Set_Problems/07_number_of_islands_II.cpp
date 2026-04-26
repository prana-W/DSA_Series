#include <bits/stdc++.h>
using namespace std;

//? Problem Link: https://www.naukri.com/code360/problems/number-of-islands-ii_1266048

//* Method - I (Brute, My Method, Avoid this method)
// Make all the blocks in matrix into index, then just do take union and at the end find total leaders for all the matrix. We have used unordered_map in order to optimise the code as size can be very high.

//. T.C -> O(Q^2), due to recounting of the total leaders during each query
//. S.C -> O(n*m + Q)

class DSU {

    // (node, parent)
    unordered_map<int, int>parent;

    public:

        int findUPar(int n) {
            if (parent.find(n) == parent.end()) parent[n] = n;
            if (parent[n] == n) return n;

            return parent[n] = findUPar(parent[n]);
        }

        void unite(int u, int v) {
            int upU = findUPar(u);
            int upV = findUPar(v);

            if(upU == upV) return;

            parent[upV] = upU;
        }

        int findTotalLeaders() {

            int leaders = 0;

            for (auto elem : parent) {
                if (elem.first == elem.second) leaders++;
            }

            return leaders;
        }
};


vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){

    vector<vector<int>>mat(n, vector<int>(m, 0));
	vector<int>ans;

	DSU ds;

	for (auto elem : q) {

		int r = elem[0], c = elem[1];
        int currIndex = r*m + c;

        if(mat[r][c] == 1) {
            ans.push_back(ds.findTotalLeaders());
            continue;
        }

        mat[r][c] = 1;

        //! Done to add the current index to the ds as we have used mapping
        ds.findUPar(currIndex);

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {

            int newR = r+dx[i];
            int newC = c+dy[i];
            int neiIndex = newR*m + newC;

            if (newR < 0 || newC < 0 || newR >= n || newC >= m || mat[newR][newC] == 0) continue;

            ds.unite(neiIndex, currIndex);
        }

        int totalIslands = ds.findTotalLeaders();
        ans.push_back(totalIslands);
		
	}

	return ans;	

}

//* Method - II (Optimal Approach, TUF Method)

// Just use simple DSU implementation. Maintain a count that keeps track of total islands, initially keep it at zero, and each time a water is turned into island, then increase the counter, also after each succesfull union of two islands, decrese the cnt and at the end push the cnt which is the total islands till that query. If the two land is already part of the same island, then we can't decrese the counter

//. T.C -> O(Q)
//. S.C -> O(n*m + Q)

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


vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){

    vector<vector<int>>mat(n, vector<int>(m, 0));
	vector<int>ans;

	DisjointSet ds(n*m);

    int cnt = 0;

	for (auto elem : q) {

		int r = elem[0], c = elem[1];
        int currIndex = r*m + c;

        if(mat[r][c] == 1) {
            ans.push_back(cnt);
            continue;
        }

        cnt++;

        mat[r][c] = 1;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {

            int newR = r+dx[i];
            int newC = c+dy[i];
            int neiIndex = newR*m + newC;

            if (newR < 0 || newC < 0 || newR >= n || newC >= m || mat[newR][newC] == 0) continue;

            bool isUnited = ds.unite(neiIndex, currIndex);

            if(isUnited) cnt--;
        }

        ans.push_back(cnt);
		
	}

	return ans;	

}