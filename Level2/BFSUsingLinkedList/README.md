# 🕸️ Graph Traversal: Breadth-First Search (BFS) in C

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Topic](https://img.shields.io/badge/Topic-Data%20Structures%20%26%20Algorithms-brightgreen.svg)
![Author](https://img.shields.io/badge/Author-Ali%20Elkenco-orange.svg)

## 📌 Overview
This repository contains a complete, scratch-built implementation of the **Breadth-First Search (BFS)** algorithm in C. It demonstrates low-level memory management, dynamic data structure creation, and algorithmic problem-solving without relying on any built-in libraries for queues or graphs.

## 🚀 Key Architectural Features
This project is built with performance and clean architecture in mind:

1. **Custom Linked-List Queue:** The `Queue` used for the BFS traversal is built entirely from scratch using dynamic memory allocation (`malloc`, `free`), ensuring precise FIFO (First-In-First-Out) logic.
2. **Dynamic Adjacency List:** The Graph is represented as an Array of Linked Lists. This is highly memory-efficient compared to an Adjacency Matrix, especially for sparse graphs.
3. **$O(1)$ Hash Map Logic for Indexing:** Instead of hardcoding node positions, the graph utilizes an elegant ASCII math trick (`Character - 'a'`). This acts as a lightweight Hash Map, automatically assigning and retrieving nodes to/from their correct alphabetical indexes, completely decoupling the algorithm from data entry order.
4. **Infinite Loop Protection:** A strictly managed `Visited` array ensures that no node is enqueued twice, effectively preventing infinite loops in cyclic graphs.

## 🧠 Code Structure

- `struct Node`: The fundamental building block for both the Adjacency List and the Queue.
- `enQeueu` & `deQueue`: Custom functions to manage the traversal queue.
- `prepareAdjancencyList`: Constructs the graph network (Nodes and Edges).
- `BFS`: The core algorithm that explores the graph layer by layer, pushing discovered nodes into the queue and logging the traversal path.

## 🗺️ The Graph Model
The algorithm navigates the following directed graph connections:
* `a` → `b`, `c`
* `b` → `f`
* `c` → `e`, `f`
* `f` → `g`, `h`
* `e` → `d`, `i`, `h`
* `h` → `e`, `i`
* `g` → `b`
* `d` → `c`
* `i` → `h`

## 💻 Output / Traversal Result
When executing the code starting from node `a`, the algorithm perfectly explores the graph breadth-first, yielding the following path:

```bash
a b c f e g h d i