Aim: To sort an array of integers in ascending order using an optimized Bubble Sort algorithm and measure the execution time using the chrono library.
Algorithm: 
BubbleSort(arr, n):
FOR i = 0 TO n-2
  SET swapped = false
  FOR j = 0 TO n-i-2
    IF arr[j] > arr[j+1]
      SWAP(arr[j], arr[j+1])
      SET swapped = true
  IF swapped == false
    BREAK     
    PrintArray(arr, n):
FOR i = 0 TO n-1
  PRINT arr[i]

  Time & Space Complexity:
Case	      Time Complexity
Best	      O(n) 
Average	    O(n²)
Worst	      O(n²)

Component	   Space Complexity
Bubble Sort	 O(1) 
Array	       O(n)
Use Cases:
1) Educational purposes to understand sorting algorithms
2) Efficient for small datasets
3) When input data may already be sorted (optimization helps)
4) Performance measurement using execution time


Aim: To sort an array of integers in ascending order using the Selection Sort algorithm and measure the execution time using the chrono library.
Algorithm:
SelectionSort(arr, n):
FOR i = 0 TO n-2
  SET minIndex = i
  FOR j = i+1 TO n-1
    IF arr[j] < arr[minIndex]
      SET minIndex = j
  IF minIndex ≠ i
    SWAP(arr[i], arr[minIndex])
  PrintArray(arr, n):
FOR i = 0 TO n-1
  PRINT arr[i]

  Time & Space Complexity:
  Case	    Time Complexity
  Best	      O(n²)
  Average   	O(n²)
  Worst	      O(n²)

 Component	     Space Complexity
Selection Sort	  O(1) — in-place sorting
Array           	O(n)

Use Cases:
1)Educational purposes to understand sorting fundamentals
2)Suitable for small datasets
3)When memory usage must be minimal (in-place sorting)
4)Useful when number of swaps needs to be minimized

Aim: To compute (x^n) using an iterative method (Horner’s Rule style multiplication) and analyze its execution time for different values of exponent (n).
Algorithm:
HornersPower(x, n):
SET result = 1
FOR i = 0 TO n-1
  result = result × x
RETURN result

Time & Space Complexity:
Case	      Time Complexity
All Cases	    O(n)

Component	      Space Complexity
Power Function	   O(1)
Main Program	     O(1)

Use Cases:
1)Efficient evaluation of powers using iterative multiplication
2)Understanding time growth of linear algorithms
3)Performance analysis using chrono library
4)Used as a base concept for polynomial evaluation (Horner’s Rule)
5)Educational and academic purposes

Aim: To search for an element in an array using the Linear Search algorithm and measure the execution time using the chrono library.
Algorithm:
LinearSearch(arr, n, key):
FOR i = 0 TO n-1
  IF arr[i] == key
    RETURN i
RETURN -1

Time & Space Complexity:
Case	    Time Complexity
Best	       O(1)
Average	     O(n)
Worst	       O(n)

Component	    Space Complexity
Linear Search	   O(1)
Array	           O(n)

Use Cases:
1)Searching elements in an unsorted array
2)Simple and easy implementation
3)Suitable for small datasets
4)Useful when data is not sorted
5}Educational purposes

Aim: To find the missing number from a sequence of integers from 1 to n using the XOR operation.
Algorithm:
MissingNumber(n, arr):
SET xorAll = 0
SET xorArr = 0
FOR i = 1 TO n
  xorAll = xorAll XOR i
FOR i = 0 TO n-2
  xorArr = xorArr XOR arr[i]
RETURN xorAll XOR xorArr

Time & Space Complexity:
Case	    Time Complexity
All Cases	  O(n)

Component	    Space Complexity
XOR Variables	  O(1)
Array	          O(n)

Use Cases:
1)Finding missing elements in a sequence
2)Efficient computation without extra memory
3)Useful in competitive programming
4)Works when numbers are in range 1 to n with one missing
5)Demonstrates bitwise operations

Aim: To generate all permutations of a string using recursion and analyze the execution time for different string lengths.
Algorithm:
swapChar(a, b):
SET temp = a
SET a = b
SET b = temp
Permute(str, l, r):
IF l == r
  RETURN
FOR i = l TO r
  SWAP(str[l], str[i])
  CALL Permute(str, l+1, r)
  SWAP(str[l], str[i]) 

  Time & Space Complexity:
Case	     Time Complexity
All Cases	    O(n!)

Component	      Space Complexity
Recursion Stack	     O(n)
String Storage	     O(n)

Use Cases:
1)Generating all possible arrangements
2)Solving combinatorial problems
3)Backtracking problems
4)Useful in puzzles and optimization problems
5)Educational understanding of recursion

Aim: To generate all possible binary combinations using backtracking and analyze the execution time for different input sizes.
Algorithm:
BTT(k, n):

IF k > n
  RETURN

SET a[k] = true
CALL BTT(k + 1, n)

SET a[k] = false
CALL BTT(k + 1, n)

Time & Space Complexity:
Case	      Time Complexity
All Cases	    O(2ⁿ)

Component	      Space Complexity
Recursion Stack	   O(n)
Array	             O(n)

Use Cases:
1)Generating all subsets of a set
2)Solving combinatorial problems
3)Used in problems like subset generation, binary sequences
4)Foundation for advanced backtracking problems
5)Educational understanding of recursion and decision trees

Aim: To determine the number of recursive steps required to reduce a given velocity below 1 using a recursive function.
Algorithm:
findTips(v):
IF v < 1
  RETURN 0
RETURN 1 + findTips(v - 0.425 × v)

Time & Space Complexity:
Case      	Time Complexity
All Cases    	O(log v)

Space Complexity:
All Cases          O(log v)

Use Cases:
1)Modeling exponential decay processes
2)Recursive reduction problems
3)Physics-based simulations (velocity decay)
4)Understanding logarithmic recursion
5)Educational purposes

Aim: To compute (x^n) efficiently using an optimized method called exponentiation by squaring.
Algorithm:
Power(x, n):

SET result = 1

WHILE n > 0
  IF n is odd
    result = result × x
  x = x × x
  n = n / 2

RETURN result

Time & Space Complexity:
Case	     Time Complexity
All Cases   	O(log n)

Component   	 Space Complexity
Power Function	  O(1)

Use Cases:
1)Efficient computation of large powers
2)Cryptography (modular exponentiation)
3)Competitive programming
4)Scientific and mathematical computations
5)Performance-critical applications
