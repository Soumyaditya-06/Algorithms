Aim: To find the kth smallest element in an array by first sorting the array using Merge Sort.
Algorithm:
Merge(arr, left, mid, right):
CREATE two arrays L and R
COPY left half into L
COPY right half into R
SET i = 0, j = 0, k = left
WHILE i < size(L) AND j < size(R)
  IF L[i] ≤ R[j]
    arr[k] = L[i], i++
  ELSE
    arr[k] = R[j], j++
  k++
COPY remaining elements of L
COPY remaining elements of R
MergeSort(arr, left, right):
IF left < right
  SET mid = (left + right) / 2
  CALL MergeSort(arr, left, mid)
  CALL MergeSort(arr, mid+1, right)
  CALL Merge(arr, left, mid, right)

Time & Space Complexity:
Case	     Time Complexity
Best	       O(n log n)
Average	     O(n log n)
Worst	       O(n log n)

Component	      Space Complexity
Merge Sort	         O(n)
Recursion Stack	     O(log n)

Use Cases:
1)Finding kth smallest/largest elements
2)Sorting before selection problems
3)Useful in ranking and statistics
4)Educational understanding of divide-and-conquer

Aim: To find the minimum and maximum elements in an array using the divide and conquer approach.
Algorithm:
MinMax(arr, low, high):
IF low == high
  min = max = arr[low]
  RETURN
IF high == low + 1
  IF arr[low] < arr[high]
    min = arr[low], max = arr[high]
  ELSE
    min = arr[high], max = arr[low]
  RETURN
SET mid = (low + high) / 2
CALL MinMax(arr, low, mid) → (min1, max1)
CALL MinMax(arr, mid+1, high) → (min2, max2)
min = minimum(min1, min2)
max = maximum(max1, max2)

Time & Space Complexity:
Case	     Time Complexity
All Cases	    O(n)

Component	       Space Complexity
Recursion Stack	    O(log n)
Array	              O(n)

Use Cases:
1)Efficient min-max finding in large datasets
2)Used in divide-and-conquer algorithms
3)Performance optimization over brute force method
4)Useful in data analysis and statistics
5)Educational purposes
