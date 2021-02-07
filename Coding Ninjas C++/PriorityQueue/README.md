# Priority Queues

Priority Queues are basically queues which have an additional related factor which is priority.

The functions in this data structure are :

- insert
- getMax / getMin -> top
- removeMax / removeMin -> pop

Priority Queues are implemented using **Heap data structure**.
**Heap** is a data structure that can be implemented using complete binary trees, which in turn can be generalized through dynamic arrays or vectors.

**Explanation for implementation of heaps using dynamic arrays**:

The children for the ith element can be found at position 2i+1, 2i+2 in array. Also to get the parent we can perform the operation - (parent_index - 1)/2

There are two types of heaps :

1. MinHeap - All childrens are greater than root value.
2. MaxHeap - All childrens are smaller than root value.

**Complexity of functions in Heaps**:

- Insert function = O(h) = O(log n) [This process also called up-heapify]
- Delete function = O(h) = O(log n) [This process also called down-heapify]
- Get function = O(1)+

## Contents
