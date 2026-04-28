Aim: To find the convex hull of a set of points using the Graham Scan algorithm.
Algorithm:
Orientation(a, b, c):
COMPUTE value = (b.y - a.y) × (c.x - b.x) − (b.x - a.x) × (c.y - b.y)
IF value == 0
  RETURN collinear
ELSE IF value > 0
  RETURN clockwise
ELSE
  RETURN counterclockwise

Time & Space Complexity:
Case	    Time Complexity
All Cases	    O(n log n)

Component	      Space Complexity
Stack (Hull)	     O(n)
Auxiliary Space	   O(n)

Use Cases:
1)Computational geometry problems
2)Computer graphics (boundary detection)
3)Robotics (path planning)
4)GIS (geographical mapping)
5)Collision detection systems

Aim: To maximize profit using the Fractional Knapsack problem by applying different greedy strategies (profit, weight, and profit/weight ratio).
Algorithm:
Knapsack(arr, n, capacity, type):
IF type == 1
  SORT items by profit (descending)
ELSE IF type == 2
  SORT items by weight (ascending)
ELSE
  SORT items by profit/weight ratio (descending)
SET totalProfit = 0
FOR each item
  IF capacity ≥ item.weight
    capacity -= item.weight
    totalProfit += item.profit
  ELSE
    ADD fractional profit
    BREAK
RETURN totalProfit

Time & Space Complexity:
Case	    Time Complexity
All Cases  	O(n log n)

Component	  Space Complexity
Sorting	     O(1) (in-place)
Variables	   O(1)

Use Cases:
1)Resource allocation problems
2)Maximizing profit with limited capacity
Used in logistics and optimization
Greedy algorithm applications
Real-world scenarios like cargo loading

Aim: To perform multiplication of two 4×4 matrices and display the resultant matrix.
Algorithm:
FOR i = 0 TO 3
  FOR j = 0 TO 3
    SET C[i][j] = 0
    FOR k = 0 TO 3
      C[i][j] = C[i][j] + A[i][k] × B[k][j]
      NPUT matrix A (4×4)
INPUT matrix B (4×4)
INITIALIZE result matrix C with 0
CALL MatrixMultiplication(A, B, C)
PRINT matrix C

Time & Space Complexity:
Case	     Time Complexity
All Cases   	O(n³)

Component	     Space Complexity
Matrices A, B	    O(n²)
Result Matrix C	  O(n²)

Use Cases:
1)Computer graphics transformations
2)Scientific and engineering computations
3)Machine learning and data processing
4)Image processing
5)Mathematical modeling

Aim: To multiply two square matrices efficiently using Strassen’s algorithm
Algorithm:
Strassen(A, B):
IF size of matrix == 1
  RETURN A × B
DIVIDE matrices A and B into 4 submatrices:
  A11, A12, A21, A22
  B11, B12, B21, B22
COMPUTE:
  M1 = (A11 + A22)(B11 + B22)
  M2 = (A21 + A22)(B11)
  M3 = (A11)(B12 − B22)
  M4 = (A22)(B21 − B11)
  M5 = (A11 + A12)(B22)
  M6 = (A21 − A11)(B11 + B12)
  M7 = (A12 − A22)(B21 + B22)
COMBINE results:
  C11 = M1 + M4 − M5 + M7
  C12 = M3 + M5
  C21 = M2 + M4
  C22 = M1 + M3 − M2 + M6
MERGE submatrices into result matrix C
RETURN C

Time & Space Complexity:
Case	    Time Complexity
All Cases  	O(n^2.81)

Component	       Space Complexity
Recursive Calls	    O(log n)
Temporary Matrices	O(n²)

Use Cases:
1)Works only when matrix size is power of 2
2)Faster than standard method for large matrices
3)Uses 7 recursive multiplications instead of 8
4)More complex implementation than normal method
