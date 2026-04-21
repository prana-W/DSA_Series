#include <bits/stdc++.h>
using namespace std;

//* Method - I (My Method)
// The intuition is that we connect all the coordinates in same row and col in the same component, so lets say (a, b) and (a, c) has same row, so they get attached to same component, (a, b) and (c, b) has same col, so they also get attached in a same component. We can remove all stones till only ultimate parents remainn, so subtract total from total ultimate leader/parents. In other words make a DSU and cound the total leaders/ultimate parents at the end i.e. count the total sets, and subtract it from total stones.

// So we use to hashmaps, one for col and one for row, whenever we encounter any first element in a row or col, they get mapped to that particular row and col in the hashmap and starts acting as the base/ultimate leader for that particular row and col, so all subsequent coordinates in the same row or component gets attached to this supreme leader!

//. T.C -> O(n * alpha(n)) in average as unorderd map
//. S.C -> O(n)

class DSU {

    vector<int>size, parent;

    public:
        
        DSU(int n) {
            for (int i = 0; i < n+1; i++) {
                parent.push_back(i);
                size.push_back(1);
            }
        }

        int findUPar(int n) {
            if (parent[n] == n) return n;

            return parent[n] = findUPar(parent[n]);
        }

        void unionBySize(int u, int v) {
            int upU = findUPar(u);
            int upV = findUPar(v);

            if(upU == upV) return;

            if(size[upU] < size[upV]) {
                parent[upU] = upV;
                size[upV] += size[upU];
            }
            else {
                parent[upV] = upU;
                size[upU] += size[upV];
            }
        }
};

int removeStones(vector<vector<int>>& stones) {

    int n = stones.size();

    DSU ds(n);
    unordered_map<int, int> row;
    unordered_map<int, int> col;
    
    for(int i = 0; i < n; i++){

        int x = stones[i][0], y = stones[i][1];
        
        // If already a supreme leader for this row, then attach to that
        if(row.find(x) != row.end()){
            int leader = row[x];
            ds.unionBySize(leader, i);
        }

        // Map the stone with the row, if no stone binded for this row
        else row[x] = i;
        
        if(col.find(y) != col.end()){
            int leader = col[y];
            ds.unionBySize(leader, i);
        }
        else col[y] = i;
        
    }
    
    int leaders = 0;
    for(int i = 0; i < n;i++){
        if(ds.findUPar(i) == i){
            leaders++;
        }
    }
    
    return (n - leaders);
    
}

//* Method - II (TUF Method)
// This is also similar approach, we treat row and col index as the element in DSU, but since row and col indices can collied, we treat row index as normal, but col index as (max_row_coordinate +  1 + colIndex), so as to shift and avoid collision

// So for every element, we unite the row and col

// But if we implement DSU naively, we have to make it of size 2*1e4 + 2 to tackle row and col seperately without collisions, therefore we use unordered_map and only lazily add values that gets added, also during union, we don't care about size and just combine it as it is. Also, // Since row is treated as ultimate leaders, size of row element will always be greater than that of col, hence we don't even need to have a size array or hashmap and can directly infer that our col will be attached to row

// We also count total ultimate leaders inside the class itself. Also no need of constructor here

//. T.C -> O(n * alpha(n)) in average as unorderd map
//. S.C -> O(n)

class DisjointSet {

    // Mapping node and its parent to optimise for size
    unordered_map<int, int>parent;

    public:
        
        int findUPar(int n) {

            //! Lazily loading the parent of new node as itself
            if (parent.find(n) == parent.end()) parent[n] = n;
            if (parent[n] == n) return n;

            // Path compression
            return parent[n] = findUPar(parent[n]);

        }

        void unite(int u, int v) {
            int upU = findUPar(u);
            int upV = findUPar(v);

            // Coloumn is attached to row, as row is acting as the ultimate leaders and will have greater size
            parent[upV] = upU;

        }

        // Finding total leaders or ultimate parents
        int findTotalLeaders() {
            int ans = 0;

            for (auto elem : parent) {
                if (elem.first == elem.second) ans++;
            }

            return ans;
        }
};

int removeStones(vector<vector<int>>& stones) {

    int n = stones.size();

    DisjointSet ds;
    
    for(int i = 0; i < n; i++){
        int x = stones[i][0], y = stones[i][1];
        ds.unite(x, 10001 + y);           
    }
    
    int leaders = ds.findTotalLeaders();
    
    return (n - leaders);
    
}