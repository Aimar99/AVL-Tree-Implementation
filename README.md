# **AVL Tree Implementation**

## **Overview**
This project implements an AVL (Adelson-Velsky and Landis) Tree in C++, which is a self-balancing binary search tree. The main feature of the AVL tree is its ability to maintain balance through rotations (left and right) after each insertion or deletion operation, ensuring that the tree remains balanced and efficient. This guarantees that search, insertion, and deletion operations can be performed in logarithmic time.

## **Features**
- **Self-Balancing**: Automatically balances the tree after each insertion or deletion using rotations.
- **Efficient Operations**: Provides O(log n) time complexity for search, insert, and delete operations.
- **Binary Search Tree Properties**: Maintains binary search tree properties where each node’s left subtree contains smaller values, and the right subtree contains larger values.

## **How It Works**
1. **Insertions**: After each insertion, the tree checks if the balance factor of any node becomes unbalanced. If unbalanced, rotations (left or right) are performed to restore balance.
2. **Deletions**: After each deletion, the balance factor of affected nodes is checked and adjusted using rotations as needed.
3. **Rotations**: The tree uses **left rotation** and **right rotation** to maintain balance, ensuring that the difference in heights between the left and right subtrees of any node is at most 1.

## **Technologies Used**
- **Language**: C++
- **Data Structure**: AVL Tree (Self-balancing binary search tree)

