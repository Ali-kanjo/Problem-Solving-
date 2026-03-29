# 🚀 Linked List Intersection Finder in C

## 📌 Problem Statement
In this project, we tackle a classic data structure problem: **Finding the intersection node of two singly linked lists.** Imagine two separate linked lists that merge at a specific node and continue sharing the same nodes until the end, forming a "Y" shape in memory. The challenge is to identify the exact memory address (node) where this intersection begins, rather than just matching node values.

## 💡 The Solutions
This implementation provides two distinct algorithmic approaches to solve the problem:

* **Approach 1: Length Difference (`findIntersection`)**
  This logical approach calculates the lengths of both lists. It then advances the pointer of the longer list by the difference in lengths. Once aligned, both pointers traverse simultaneously until they meet at the intersection node. Time Complexity: `O(A + B)`.

* **Approach 2: Two-Pointer Magic (`findIntersection2`)**
  An elegant, highly optimized approach using two pointers. Each pointer traverses its respective list. When a pointer reaches the end (`NULL`), it redirects to the head of the *other* list. This swapping perfectly equalizes the traversal distance, causing both pointers to inevitably collide exactly at the intersection node or at `NULL` if they never intersect. Time Complexity: `O(A + B)`, but with much cleaner and concise code.

## 💻 Console Output (Execution Trace)
The `main` function sets up List A and List B, and merges them into a shared List C. Here is the console output demonstrating the lists and the successful identification of the intersection point:

```text
List A: 10 -> 20 -> 100 -> 200 -> 300 -> NULL
List B: 1 -> 2 -> 3 -> 100 -> 200 -> 300 -> NULL

Intersection found at Node with value: 100