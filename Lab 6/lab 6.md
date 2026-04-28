Aim: To select the maximum number of non-overlapping activities using the greedy method based on finishing time.
Algorithm:
ActivitySelection(arr, n):
SORT activities based on finish time (ascending)
SELECT first activity
SET i = 0
FOR j = 1 TO n-1
  IF arr[j].start ≥ arr[i].finish
    SELECT activity j
    SET i = j
    FOR n = 10 TO 50 (step 10)
  GENERATE random activities (start, finish)
  CALL ActivitySelection(arr, n)
  PRINT selected activities

Time & Space Complexity:
Case	     Time Complexity
All Cases	  O(n log n)

Component	   Space Complexity
Sorting	        O(1)
Array	          O(n)

Use Cases:
1)Scheduling problems 
2)Resource allocation
3)CPU job scheduling
4)Event planning
5)Optimization problems

Aim: To find the shortest path from a source vertex to all other vertices in a graph using Dijkstra’s algorithm.
Algorithm:
Dijkstra(graph, start):
INITIALIZE distance array with infinity
SET distance[start] = 0
INITIALIZE visited array as false
FOR count = 0 TO V-1
  SELECT vertex u with minimum distance (not visited)
  MARK u as visited
  FOR each vertex v
    IF v is not visited AND edge exists
      IF distance[u] + weight(u,v) < distance[v]
        UPDATE distance[v]
        INPUT adjacency matrix of graph
INPUT starting vertex
CALL Dijkstra(graph, start)
PRINT shortest distances to all vertices

Time & Space Complexity:
Case	     Time Complexity
All Cases	   O(V²)

Component	      Space Complexity
Distance Array	   O(V)
Visited Array	     O(V)
Graph Matrix	     O(V²)

Use Cases:
1)Finding shortest path in networks
2)GPS navigation systems
3)Routing algorithms in networks
4)Transportation and logistics
5)Graph-based optimization problems
