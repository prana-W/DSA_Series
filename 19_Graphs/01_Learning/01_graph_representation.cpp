#include <bits/stdc++.h>
using namespace std;

//! Type-1: Undirected Grapgh

//? Represent a undirected grapgh with nodes 1, 2, 3 ... n and m edges 

//* Method - I (Adjancency Matrix)

//. T.C -> O(m)
//. S.C -> O(n^2)
void grapghRepresentationByMatrix() {
    
    // n -> nodes, m -> edges
    int n, m;
    cin >> n >> m;

    // Adjancency Matrix to represnt the Graph
    int adj[n+1][n+1];

    // Take input about m edges that exist between nodes u an v
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Edge between node u and v
        adj[u][v] = 1;
        adj[v][u] = 1; // Only required if undirected

    }
}

//* Method - II (Adjancency List, Better Complexity)

//. T.C -> O(m)
//. S.C -> O(2*m)
void grapghRepresentationByList() {

    int n, m;
    cin >> n >> m;

    // Adjenency List for 1, 2, 3 ... n nodes
    vector<int> adj[n+1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // Only required if undirected
    }

}

//! Type-2: Directed Grapgh
// If edge from u -> v, then only do adj[u][v] = 1 in method - I or adj[u].push_back(v) in method - II, as second line is required only when undirected

//? Problem: Represent a directed graph with nodes 1, 2, 3 ... n and m edges 

//* Method - II (Adjancency List, Better Complexity)

//. T.C -> O(m)
//. S.C -> O(m)
void grapghRepresentationByList() {

    int n, m;
    cin >> n >> m;

    // Adjenency List for 1, 2, 3 ... n nodes
    vector<int> adj[n+1];

    for (int i = 0; i < m; i++) {

        // Edge from u to v
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

}

//! Type-3: Weighted Graph
// Here there is some weight of each edge

//* Method - I (Adjancency Matrix)

//. T.C -> O(m)
//. S.C -> O(n^2)
void grapghRepresentationByMatrix() {
    
    // n -> nodes, m -> edges
    int n, m;
    cin >> n >> m;

    // Adjancency Matrix to represnt the Graph
    int adj[n+1][n+1];

    // Take input about m edges that exist between nodes u an v
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Weight of the edge
        int w;
        cin >> w;

        // Edge between node u and v of w
        adj[u][v] = w;
        adj[v][u] = w; // Only required if undirected

    }
}

//* Method - II (Adjancency List, Better Complexity)

//. T.C -> O(m)
//. S.C -> O(2*m)
void grapghRepresentationByList() {

    int n, m;
    cin >> n >> m;

    // Adjenency List for 1, 2, 3 ... n nodes
    vector<pair<int, int>> adj[n+1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Weight  of the edge
        int w;
        cin >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Only required if undirected
    }

}
