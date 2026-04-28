Aim: To sort an array using the Merge Sort algorithm and analyze its execution time for different input sizes.
Algorithm:
Merge(arr, l, m, r):

CREATE two arrays L and R
COPY left half into L
COPY right half into R

SET i = 0, j = 0, k = l

WHILE i < size(L) AND j < size(R)
  IF L[i] ≤ R[j]
    arr[k] = L[i], i++
  ELSE
    arr[k] = R[j], j++
  k++

COPY remaining elements of L (if any)
COPY remaining elements of R (if any)
MergeSort(arr, l, r):

IF l < r
  SET m = (l + r) / 2
  CALL MergeSort(arr, l, m)
  CALL MergeSort(arr, m+1, r)
  CALL Merge(arr, l, m, r)

  Time & Space Complexity:
  Case         	Time Complexity
  Best	           O(n log n)
Average	           O(n log n)
 Worst	           O(n log n)

Component	       Space Complexity
Merge Sort	       O(n)
Recursion Stack	   O(log n)

Use Cases:
1)Efficient sorting for large datasets
2)Used in divide-and-conquer algorithms
3)Stable sorting algorithm
4)Used in external sorting (large data processing)
5)Preferred when consistent performance is needed

Aim: To sort an array using the Quick Sort algorithm and analyze its execution time for different input sizes.
Algorithm:
Partition(arr, low, high):
SET pivot = arr[high]
SET i = low - 1
FOR j = low TO high-1
  IF arr[j] < pivot
    i++
    SWAP(arr[i], arr[j])
SWAP(arr[i+1], arr[high])
RETURN i + 1
QuickSort(arr, low, high):
IF low < high
  SET pi = Partition(arr, low, high)
  CALL QuickSort(arr, low, pi-1)
  CALL QuickSort(arr, pi+1, high)

Time & Space Complexity:
Case	      Time Complexity
Best	        O(n log n)
Average	      O(n log n)
Worst	        O(n²)

Component	         Space Complexity
Recursion Stack	   O(log n) (average)
Worst Case	       O(n)

Use Cases:
1)Efficient sorting for large datasets
2)Widely used in practice due to average-case performance
3)Suitable for in-place sorting
4)Used in system libraries and real-world applications
5)Divide-and-conquer based algorithm
