This file contains additional implementation details of minheap priority queue and smooth sort algorithms

Smooth sort alogrithm starts with building heap which contains maitaining the sequence property and heap property
The sequence property needs the root to be sorted so that the last heap always contains the maximum element. 
When a new element is inserted if the previous two heaps are of size L(x-1) and L(x-2) we combine previous two heaps 
to form the heap of size L(X). Now we will perform sequence operation by swapping the root. We will swap the current heap
with two previous heap , if its root is bigger than current heap and its children. In this way the property is maintained at all the heaps except the last heap where we heapify. We use bitset to store the information about the heap structures formed.We also add an optimisation , where if new element added forms the part of some heap, no need of sequence property , we will just proceed with heapify of the current heap.The extract min consists of popping out the right element and we get two trees of left and right. We first perform the sequence and heap property on left child tree and then right tree. This completes the algirthm after we extarct all the elements.

The minheap algorithm contains a single heap where the parent is less than both the children. This is maitained at each root.
After we do build heap in O(n) time where we perform heapify fro n/2 th element to zero. Extract min extracts 0th element removes it, replaces it with last element to heapify again. This way min always exists at the root.

Reference for smoothsort:
http://www.keithschwarz.com/interesting/code/?dir=smoothsort
