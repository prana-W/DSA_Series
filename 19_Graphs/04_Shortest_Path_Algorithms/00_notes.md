# Single Source Shortest Path

- Weighted DAG
    - If we use queue based Algo, it will take O(V*E), due to same nodes being reprocessed multiple times
    - We can also use Dijstra's Algo with PQ or set to find answer in O(E*log(V))
    - Use Topo Sort for the most optimal approach of O(V+E)

- Unweighted Graph
    - Dijstra's Algorithm with PQ will take extra time due to PQ, and is completely unnncessary. 
    - Use Queue Based search (BFS) instead for most optimal approach O(V+E), no nodes are reproccessed, so it is better than Dijstra with PQ

- Postive Weighted Graph
    - Queue based BFS will work, but multiple nodes will be reproccessed, giving us a O(V*E) complexity
    - Use Dijstra's Algorithm with PQ (or set) to greddily process nodes and reduce reprocessing and hecne getting a O(E*log(V)) solution

- Negative Weighted Graph
    - All previous methods fail and we have to use Bellman Ford Approach
    - If we find a negative cycle in the graph (by checking for one more relaxation after Bellman Ford Algorithm), then we can't find the shortest path.
    - Also any undirected graph with negative weights, when converted into directed graph gets a negative cycle, hence we can't find the shortest path for such graph.

# Multi Source Shortest Path

- Floyd Warshall Algorithm
    - We have a time complexity of O(V^3)
    - Also helps in detecting negative cycles
    
- Dijstra's Algorithm over all the nodes iff all weights are postive
    - Takes O(V*E*log(V)) time complexity, so this can be better solution if grtaph deosn't have negative weights and also the graph is sparse, if graph is very dense, then E can reach about V^2, making it more time complex than Floyd Warshall Algorithm