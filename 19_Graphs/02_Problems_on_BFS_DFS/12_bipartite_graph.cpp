#include <bits/stdc++.h>
using namespace std;

//! Bipartite Graph: Colour all the nodes with exactly one of the two colours, such that no two adjacnet nodes have the same colour.

// If any cycle has odd length cycle, then it will obvioulsy be never be bipartite graph, if we use the above property
// Rest graphs can be called bipartite graph

//* Method - I (DFS)
// We take a coloured array with initially -1 colour, also we will use the colour 0 or 1 to colour the nodes and simply do DFS for all the components of the graph which has -1 colour, if we find that my adjacent neighbiur has the same colour as me at any given moment we instantly return false

//. T.C -> O(n)
//. S.C -> O(n)

bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& color) {

    // If already visited, return true
    if (color[node] != -1) return true;

    color[node] = col;

    for (auto elem : graph[node]) {

        int nextCol = -1;
        if(color[elem] == -1 && col == 0) nextCol = 1;
        if(color[elem] == -1 && col == 1) nextCol = 0;

        // If eother the adjacent node has same color or the dfs returns false, then return a false
        if(color[elem] == col || !dfs(elem, nextCol, graph, color)) return false;

    }

    // If dfs doesn't return false at any point and also no adjancet has same colour then only return true
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {

    int n = graph.size();
    vector<int>color(n, -1);

    // If any dfs returns a false, return a false
    for(int i = 0; i < n; i++) {
        if (!dfs(i, 0, graph, color)) return false;
    }

    // If none DFS returns false, then return true
    return true;
    
}

//* Method - II (BFS)
// Same concept as above but with bfs

//. T.C -> O(n)
//. S.C -> O(n)

bool bfs(int inpNode, int col, vector<vector<int>>& graph, vector<int>& color) {

    if (color[inpNode] != -1) return true;

    queue<int>q;
    q.push(inpNode);
    color[inpNode] = col;

    while(!q.empty()) {
        
        int node = q.front();
        q.pop();

        for(auto elem : graph[node]) {

            // If adjancent node has same color return false
            if (color[node] == color[elem]) return false;

            // If adjacent is already visited (not -1), continue
            if (color[elem] != -1) continue;

            q.push(elem);
            if(color[node] == 0) color[elem] = 1;
            else color[elem] = 0;
        }
    }

    return true;
}
bool isBipartite(vector<vector<int>>& graph) {

    int n = graph.size();
    vector<int>color(n, -1);

    // BFS over all the components of graph
    for (int i = 0; i < n; i++) {
        if(!bfs(i, 0, graph, color)) return false;
    }

    return true;
    
}