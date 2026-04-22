# Disjoint Set

NOTE: See Pg: 153

- A Disjoint Set (also called Union-Find) is a data structure used to manage a collection of non-overlapping sets.

- It helps you quickly answer:

“Are these two elements in the same group?”
“Merge these two groups”

Inorder to create the data structure we have two function, one is findParent which finds the parent and the othe is union, which unites the two elements

# Self Notes

- Consider it has many different sets, to find the set of an element, just find its ultimate parent, we might be asked if two elements belong to same set or not. We might also have to find the union of two sets, and in both these tasks, disjoint set data structure is used.

- Size array or rank array is only used for further optimisation, we can do simply union the two elements even without them, although that would be slightly unoptimised

# Implementation of Union (u, v)

- Find the ultimate parent of u and v called pu and pv
- Find rank of pu and pv
- We connect the ultimate parent (root) of smaller rank to the ultimate parent of the higher rank.

# Why is the smaller rank set is attached to larger rank set?

- If larger is attached to the smaller, then the height increases and hence rank needs to be incremented, and then longer distance needs to be travelled for finding ultimate parent (even for path compression), hence this makes the code slightly slower

# Why use UnionBySize?

- During path compression, the tree gets distorted and the rank doesn't even make sense, as it doesn't give us any useful information, that's why we try to do now UnionBySize, because after path compression, new size can be calculated by simply adding the size of both the combined set

# Graph and DSU (Disjoint Set (Union-Find))

- Graph is just a graphical representaion of how each nodes are connected and arranged and DSU is just a tool or a data structure that helps us to answer questions like if the two nodes belong to the same component in the graph (or to the same set if we are talking in terms of DSU) in about constant time complexity opposed to the brute force of DFS or BFS in graph which would take linear time complexity.

# Code

- We have made a class that can be used for both 0-based and 1-based indexed disjoint set