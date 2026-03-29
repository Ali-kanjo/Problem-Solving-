# 🚀 Advanced Expression Evaluator (Infix to Postfix)

## 📌 Problem Statement
Mathematical expressions are traditionally written in **Infix notation** (e.g., `(10 + 20) * 2`). While easy for humans to read, computers struggle to evaluate them directly due to operator precedence and parentheses. Furthermore, most basic implementations only handle single-digit numbers, failing when encountering multi-digit numbers like `150` or `42`.

## 💡 The Solution
This project acts as a mini-compiler for mathematical expressions. It solves the parsing and evaluation problem through a robust, multi-stage pipeline:

* **Dynamic Stack Architecture:** Instead of using fixed-size arrays, a custom Stack was built from scratch using a **Singly Linked List**. This ensures memory-efficient `push` and `pop` operations without any overflow risks.
* **Smart Tokenization:** The algorithm intelligently detects consecutive digits to form multi-digit numbers, separating them with spaces for accurate parsing down the line.
* **Shunting Yard Algorithm:** Converts the human-readable Infix expression into **Postfix notation** (Reverse Polish Notation), completely eliminating the need for parentheses and naturally handling operator precedence (`*`, `/` over `+`, `-`).
* **Postfix Evaluator:** A highly efficient stack-based evaluator that utilizes `strtok` to parse the spaced Postfix string, performing the mathematical operations and yielding the final result.

## 💻 Console Output (Execution Trace)
The program takes a full mathematical expression as string input, correctly handles multi-digit numbers and parentheses, and computes the exact result.

```text
enter your mathematical expression: (100 + 20) * 2

Result : 240