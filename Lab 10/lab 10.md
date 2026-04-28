Aim: To find the shortest paths between all pairs of vertices in a graph using the Floyd–Warshall algorithm and also reconstruct the path.
Algorithm:
FloydWarshall(dist, next):
FOR k = 0 TO n-1
  FOR i = 0 TO n-1
    FOR j = 0 TO n-1
      IF dist[i][k] + dist[k][j] < dist[i][j]
        dist[i][j] = dist[i][k] + dist[k][j]
        next[i][j] = next[i][k]
        PrintPath(next, i, j):
IF next[i][j] == -1
  PRINT "No path"
WHILE i ≠ j
  PRINT i
  i = next[i][j]

PRINT j

Time & Space Complexity:
Case	      Time Complexity
All Cases	    O(n³)

Component	      Space Complexity
Distance Matrix	   O(n²)
Next Matrix	       O(n²)

Use Cases:
1)Finding shortest paths between all nodes
2)Network routing and optimization
3)Graph analysis
4)Used in transportation and communication systems
5)Dynamic programming applications


Aim: To find the minimum cost of visiting all cities exactly once and returning to the starting city using dynamic programming.
Algorithm:
TSP(dist, n):
CREATE dp table of size (2ⁿ × n)
INITIALIZE all values as ∞
SET dp[1][0] = 0 
FOR each mask from 1 to (2ⁿ - 1)
  FOR each city u in mask
    FOR each city v not in mask
      newMask = mask OR (1 << v)
      dp[newMask][v] = min(dp[newMask][v],
        dp[mask][u] + dist[u][v])
SET answer = ∞
FOR each city i from 1 to n-1
  answer = min(answer, dp[(2ⁿ - 1)][i] + dist[i][0])
RETURN answer

Time & Space Complexity:
Case	      Time Complexity
All Cases	    O(n² × 2ⁿ)

Component	      Space Complexity
DP Table	        O(n × 2ⁿ)
Distance Matrix	   O(n²)

Use Cases:
1)Route optimization
2)Logistics and delivery systems
3)GPS navigation
4)Circuit design
5)Optimization problems
