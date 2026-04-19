#include <bits/stdc++.h>
using namespace std; 

//? Problem: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

//! Used for MultiSource Shortest Path and detecting negative cycles

//! Note: Floyd Warshall Algorithm is used for directed, for undirected, convert the undirected into directed

//! For a negative cycle, it will  

/*

- Create an adjancncey matrix cost matrix, where the element represents the weight for edge u to v, also put cost[x][x] as 0 and the rest are set to INFINITE

- If we are solving via node x, then for all the elements in adjanceny matrix [i][j], solve for cost[i][j] = cost[i][x] + cost[x][j], and minimise this

*/

//. T.C -> O(V^3)
//. S.C -> O(V^2), for dist or cost matrix
// dist -> 0 for node i to i, some constant for nodes from i to j and INF for not rechable nodes
void floydWarshall(int V, vector<vector<long long>>& dist) {

    const long long INF = 1e18;

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {

                if (dist[i][k] == INF || dist[k][j] == INF) continue;

                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

            }
        }
    }

    //! Negative Cycle Detection
    // If we find that the distance to travel from one node to itself has become negative, it means there must exist some negative cycles
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative cycle exists" << endl;
        }
    }
}

//! Note: If there are no negative weights, then Dijstra can be applied for evry node, giving a Time complexithy off O(V*E*log(V)), if E is about V^2 in a very dense graph, then it will consume more time, but if graph is sparse, then it might be a better solution than Floyd.