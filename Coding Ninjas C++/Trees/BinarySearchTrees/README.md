# Binary Search Trees

Work similar to the concept of Binary Search. These are trees in which searching elements/nodes is comparitively faster than normal trees.

              4
            /   \
           2     6
         /  \   /  \
        1    3 5    7

The above shown tree is a binary search tree.

What is a balanced BST?

1. This is a tree which has |height(left subtree) - height(right subtree)| <= 1
2. Height of a balanced BST is roughly **log n**.

**_PROPERTIES:_**

- Every node data left to a node, say n, is smaller than n's data.
- Every node data right to node n, is smaller than n's data.

**_TYPES OF BALANCED BST_**

- SearchNode - O(h)
- Insertion of Node - O(h)
- Deletion of Node - O(h)

## Contents

- Convert BST to sorted Linked List
- Print range of nodes that lie between user defined values
- Search for a given node.
- Check if given tree is BST.
- Defining the BST class to support insertion, deletion, printing and checking of data in nodes of BST.
