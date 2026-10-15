# Q1 · Complexity analysis of searching & sorting algorithms

## 1. Bubble Sort 

CASE          Time Complexity           Input 
Best              O(n)                  Already sorted
Average          O(n^2)                  Randomly ordered
Worst            O(n^2)                  Reverse sorted

Space: O(1)
Stable: Yes
In-place: Yes
Reason: Repeatedly compares adjacent elements and swaps them when needed; an optimized version detects an already sorted array in one pass.

## 2. Insertion Sort

CASE          Time Complexity           Input 
Best              O(n)                   Already sorted
Average          O(n^2)                  Randomly ordered
Worst            O(n^2)                  Reverse sorted


Space: O(1)
Stable: Yes
In-place: Yes
Reason: Builds the sorted portion one element at a time; an already sorted array needs only one comparison per element, while a reverse-sorted array requires maximum shifting.

## 3. Selection Sort

CASE          Time Complexity           Input 
Best             O(n^2)                  Already sorted
Average          O(n^2)                  Randomly ordered
Worst            O(n^2)                  Reverse sorted

Space: O(1)
Stable: No
In-place: Yes
Reason: It scans the remaining unsorted portion to find the minimum on every pass, regardless of the input order.

## 4. Merge Sort

CASE          Time Complexity           Input 
Best             O(n logn )              Any input
Average          O(nl og n )                  Randomly ordered
Worst            O(n log n)                  Any input

Space: O(n)
Stable: Yes
In-place: No
Reason: The array is repeatedly divided into halves and the sorted halves are merged; the division and merging take O(n log n) time for every input.

## 5. Quick Sort

CASE          Time Complexity          Input
Best          O(n log n)              Pivot divides array into nearly equal halves
Average       O(n log n)              Randomly ordered
Worst         O(n²)                   Pivot is always smallest/largest

Space: O(log n) average, O(n) worst due to recursion stack
Stable: No
In-place: Yes
Reason: It partitions the array around a pivot and recursively sorts the two partitions; performance depends on how balanced the partitions are.

### O / Ω / Θ

- O(n²)
- Ω(n log n)
- Θ(n log n) for the average case

## 6. Linear Search

CASE          Time Complexity          Input
Best          O(1)                    Target is at the first position
Average       O(n)                    Target is somewhere in the middle
Worst         O(n)                    Target is at the last position or not present

Space: O(1)
Stable: N/A
In-place: Yes
Reason: It checks each element sequentially until the target is found or the array ends.

## 7. Binary Search

CASE          Time Complexity          Input
Best          O(1)                    Target is at the middle position
Average       O(log n)                Target is at a random position
Worst         O(log n)                Target is at the deepest position or not present

Space: O(1) iterative, O(log n) recursive
Stable: N/A
In-place: Yes
Reason: It repeatedly divides the sorted search range into half, eliminating half of the elements at each step.