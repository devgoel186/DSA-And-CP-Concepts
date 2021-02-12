# General Tips and Flow of programs in C++

## Compilation & Execution

```C++
g++ <codefile_name>.cpp -o <output_file_name>
```

By default, this file is named to a.exe (executable)

## General Tips

- In case of graphs, adjacency matrix is most easy and quick to implement. However, this does pose drawbacks, like space complexity. The space complexity rises to O(n^2).

- Values when declared but not initialized default to a garbage value (**may or may not be zero**) which might be affected by previous executions of programs on the same machine causing data to remain in the stack. However, when declaring a map, the values in the map are automatically defaulted to 0. Read more about this here -
  - [Link1 - StackOverflow](https://stackoverflow.com/questions/6032638/default-variable-value)
  - [Link2 - GFG](https://www.geeksforgeeks.org/default-values-in-a-map-in-c-stl/#:~:text=By%20default%2C%20In%20Primitive%20datatypes,when%20the%20map%20is%20declared.)
  - [Link3 - Quora](https://www.quora.com/What-is-the-initial-value-of-an-int-variable-in-C-if-it-has-no-initializer)
