Aim: To find the Minimum Spanning Tree (MST) of a graph using Kruskal’s algorithm with Union-Find (Disjoint Set).
Algorithm:
FindSet(i):
IF parent[i] ≠ i
  parent[i] = FindSet(parent[i])
RETURN parent[i]
UnionSet(u, v):
FIND root of u and v
IF roots are different
  ATTACH smaller rank tree under larger rank
  IF ranks are equal
    MAKE one root and increase its rank
    Kruskal(edges, n):
SORT all edges by weight (ascending)
INITIALIZE parent and rank arrays
SET minCost = 0

FOR each edge (u, v, w)
  IF FindSet(u) ≠ FindSet(v)
    INCLUDE edge in MST
    ADD weight to minCost
    CALL UnionSet(u, v)
STOP when (n-1) edges are selected
PRINT MST edges and total cost

Time & Space Complexity:
Case	       Time Complexity
All Cases	    O(E log E)

Component   	Space Complexity
Parent Array    	O(V)
Rank Array	      O(V)
Edge List       	O(E)

Use Cases:
1)Network design (roads, cables, pipelines)
2)Minimum cost spanning trees
3)Clustering problems
4)Graph optimization
5)Used in real-world routing systems

Aim: To find the Minimum Spanning Tree (MST) of a graph using Prim’s algorithm.
Algorithm: 
Prim(graph, n):
REPLACE all 0 values with INF (no edge)
FIND minimum edge (k, l) in graph
ADD edge (k, l) to MST
SET mincost = cost[k][l]
INITIALIZE near array
FOR each vertex i
  SET near[i] = closest of k or l
MARK k and l as included
FOR i = 1 TO n-2
  FIND vertex j such that cost[j][near[j]] is minimum
  ADD edge (j, near[j]) to MST
  ADD cost to mincost
  MARK j as included
  UPDATE near[] array
PRINT MST edges and total cost

Time & Space Complexity:
Case	     Time Complexity
All Cases	    O(V²)

Component	     Space Complexity
Cost Matrix	     O(V²)
Near Array	     O(V)
MST Storage	     O(V)

Use Cases:
1)Network design (roads, cables, pipelines)
2)Minimum cost spanning tree problems
3)Graph optimization
4)Used in communication networks
5)Efficient for dense graphs
