# HashMaps

HashMaps can be implemented by using two integral components which form the basis of HashMaps:

- HashCode
- Compression Function

In case of collisions while assigning values in our unordered / hashmap, we have to look into collision handling techniques.
These techniques are :

- Closed Hashing -> Make each element of our bucket list / map as a head pointer to a Linked List, and store our colliding elements in the Linked List.
- Open Addressing -> Involves finding an alternate space for incoming entry using

  - Linear Probing -> f(i) = i
  - Quadratic Probing -> f(i) = i^2
  - Double Hashing -> f(i) = i\*h'(a)

HashMaps can be defined in a simple manner to be key-value pairs.
HashMaps can be implemented in three ways:

- Using Linked Lists. All operations will take O(n) complexity. However, this is the worst case, and in HashMaps the worst case is rarely achieved. On an average/mostly, the complexity comes out to be O(n/b) [ where n/b is the 'load factor'] where b is bucket size. We generally keep the load factor < 0.7.
- Using BST (or ordered maps). All operations take O(log n).
- Using Hash tables. All operations take O(1).

Functions in a hashmap :

- insert(K key, V value)
- getValue(K key)
- delete key(K key)

## Contents

- Iterators logic in C++
- HashMap implementation
- HashTables
- Remove Duplicates program using unordered_map STL
