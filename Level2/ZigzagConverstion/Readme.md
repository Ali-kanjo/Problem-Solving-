

```
# 🚀 Zigzag Conversion (LeetCode #6)

## 📌 Problem Statement
The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this:

```text
P     I     N
A   L S   I G
Y A   H R
P     I
```
And then read line by line: `"PINALSIGYAHRPI"`. 
The challenge is to write a function that takes a string and the number of rows, simulates this zigzag writing process, and returns the newly formatted string read row-by-row.

## 💡 The Solution
This C++ implementation uses a **2D Matrix Simulation** approach to physically trace the zigzag pattern in memory before reconstructing the final string.

* **Grid Initialization:** A 2D character array (`zigzagGrid`) is initialized to zeros. This acts as our blank canvas to "draw" the characters.
* **Directional Traversal:** The algorithm utilizes a `while` loop that toggles between two states:
  1. **Moving Down:** Iterating vertically down the rows while keeping the column constant.
  2. **Moving Diagonally Up:** Decrementing the row index while incrementing the column index to simulate the diagonal upward stroke of the zigzag.
* **String Reconstruction:** After the pattern is completely drawn into the grid, a nested `for` loop scans the grid strictly row by row. It ignores the empty spots (`0`) and appends the valid characters to the result string in the correct zigzag order.
* **Edge Cases Handled:** Instantly returns the original string if `numRows` is `1` or if the string length is shorter than the requested rows, saving execution time.

## 💻 Console Output (Execution Trace)
The program takes the input `"PAYPALISHIRING"` with `4` rows and outputs the exact converted string:

```text
PINALSIGYAHRPI
```
```

---
