Aim: To find the shortest path from source to destination in a multistage graph using dynamic programming.
Algorithm:
Multistage(arr, v):

SET dist[v-1] = 0 

FOR i = v-2 DOWNTO 0
  SET dist[i] = ∞

  FOR j = i+1 TO v-1
    IF edge exists AND arr[i][j] + dist[j] < dist[i]
      dist[i] = arr[i][j] + dist[j]
      path[i] = j

PRINT dist[0] as minimum cost

TRACE path from source (0) to destination using path[]

Time & Space Complexity:
Case	     Time Complexity
All Cases	   O(V²)

Component	     Space Complexity
Distance Array	   O(V)
Path Array	       O(V)
Graph Matrix	     O(V²)

Use Cases:
1)Shortest path in staged graphs
2)Project scheduling
3)Routing in layered networks
4)Dynamic programming problems
5)Optimization in decision-making
