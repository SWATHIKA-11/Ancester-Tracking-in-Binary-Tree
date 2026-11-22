# Ancestor Tracking in Binary Tree

A C program to print all ancestors of a given node in a binary tree.

## How to run

```
gcc main.c -o main
./main
```

## Example

```
Enter the target node to find its ancestors: 4
Ancestors of node 4 are: 2 1
```
## Time Complexity

- Time: O(n), because every node may be visited once
- Space: O(h), where h is the height of the tree (recursion stack)