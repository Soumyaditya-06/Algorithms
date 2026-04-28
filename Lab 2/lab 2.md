Aim: To search for an element in a sorted array using Binary Search and analyze its execution time for different input sizes.
Algorithm: 
BinarySearch(arr, n, key):

SET low = 0
SET high = n - 1

WHILE low ≤ high
  SET mid = (low + high) / 2

  IF arr[mid] == key
    RETURN mid
  ELSE IF arr[mid] < key
    SET low = mid + 1
  ELSE
    SET high = mid - 1

RETURN -1

Time & Space Complexity:
Case	    Time Complexity
Best	        O(1)
Average	    O(log n)
Worst	      O(log n)

Component	    Space Complexity
Binary Search	    O(1)
Array           	O(n)

Use Cases:
1)Searching in sorted datasets
2)Efficient lookup in large data
3)Used in databases and search systems
4)Foundation for advanced searching algorithms
5)Competitive programming

Aim: To sort an array using the Insertion Sort algorithm and analyze its execution time for different input sizes.
Algorithm:
InsertionSort(arr, n):

FOR i = 1 TO n-1
  SET key = arr[i]
  SET j = i - 1

  WHILE j ≥ 0 AND arr[j] > key
    arr[j+1] = arr[j]
    j = j - 1

  arr[j+1] = key

  Time & Space Complexity:
Case    	Time Complexity
Best	           O(n)
Average        	O(n²)
Worst         	O(n²)

Component	       Space Complexity
Insertion Sort	    O(1) — in-place
Array               	O(n)

Use Cases:
1)Efficient for small datasets
2)Works well when data is nearly sorted
3)Used in hybrid sorting algorithms
4)Educational purposes
5)Simple implementation
