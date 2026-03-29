# 🚀 Custom Queue Implementation in C

## 📌 Problem Statement
When building a Queue using a fixed-size array in C, we typically encounter two main engineering challenges:
1. **Fake Overflow:** As elements are removed (`dequeue`), empty spaces form at the beginning of the array. However, the `rear` pointer continues to move towards the end of the array, eventually giving a false indication that the queue is full even when there is available space.
2. **Garbage Values:** When an element leaves the queue, its old value remains in memory as a "ghost." If we use `0` to denote an empty space, we cannot distinguish it from a user intentionally inputting the number zero as a valid value.

## 💡 The Solution
This project introduces a smart queue data structure design that resolves these issues through:
* **Circular Logic:** When the `rear` or `front` pointers reach the end of the array, they wrap around back to index `0`, effectively preventing memory waste and solving the fake overflow issue.
* **Sentinel Value:** The constant `INT32_MIN` is utilized to represent an empty space instead of `0`. This ensures it does not conflict with any standard user input.
* **Active Memory Cleaning:** During a `dequeue` operation, the program doesn't just advance the `front` pointer; it actively erases the old value from the memory slot and replaces it with `INT32_MIN`.

## 💻 Console Output (Memory Trace)
A custom `printArr` function was implemented to smartly read the memory and print `Empty` for vacant spots instead of displaying garbage numbers. 

Below is a memory trace showing the queue initialization, enqueuing the numbers (3, 5, 4), and then fully dequeuing them:

```text
Empty --Empty --Empty
3 --Empty --Empty
3 --5 --Empty
3 --5 --4
Empty --5 --4
Empty --Empty --4
Empty --Empty --Empty