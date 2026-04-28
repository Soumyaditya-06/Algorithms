Aim: To determine the minimum number of scalar multiplications required to multiply a chain of matrices using dynamic programming.
Algorithm:
MatrixChain(p, n):

CREATE matrix m[n][n]

FOR i = 1 TO n
  m[i][i] = 0

FOR chain length L = 2 TO n
  FOR i = 1 TO n-L+1
    SET j = i + L - 1
    m[i][j] = ∞

    FOR k = i TO j-1
      cost = m[i][k] + m[k+1][j] + p[i-1] × p[k] × p[j]

      IF cost < m[i][j]
        m[i][j] = cost

RETURN m[1][n]

Time & Space Complexity:
Case	       Time Complexity
All Cases       	O(n³)

Component	     Space Complexity
DP Table 	        O0(n²)

Use Cases:
1)Optimizing matrix multiplication order
2)Compiler optimization
3)Scientific computing
4)Database query optimization
5)Dynamic programming applications
