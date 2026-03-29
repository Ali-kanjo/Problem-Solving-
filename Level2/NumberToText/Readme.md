# 🚀 Number to English Words Converter in C++

## 📌 Problem Statement
Translating numerical digits into human-readable text (e.g., converting `1042` to "One Thousand Forty Two") is a classic algorithmic challenge, frequently used in financial applications for printing checks or generating reports. The complexity arises from parsing positional values (billions, millions, thousands) and handling linguistic irregularities, such as the unique naming of numbers between 11 and 19 in the English language.

## 💡 The Solution
This C++ program provides an elegant, scalable, and recursive solution to translate any positive integer up to `2,147,483,647` (the maximum 32-bit signed integer) into its English word equivalent. 

* **Modular String Mapping:** Utilizes pre-defined string arrays to instantly map base units (1-19) and tens (20-90), eliminating the need for massive `switch` statements.
* **Chunk Processing:** The `ConvertThreeDigitNumber` function breaks the problem down by processing numbers in manageable three-digit chunks (hundreds, tens, units). This perfectly mirrors how humans naturally read large numbers.
* **Recursive Scale Handling:** The core `NumberToText` function employs recursion to gracefully peel off the Billions, Millions, and Thousands, passing the remainder down the execution chain until the entire sequence is translated.
* **Boundary Safeguards:** Includes hardcoded protection to prevent integer overflow errors, securely handling inputs that exceed standard 32-bit limits.

## 💻 Console Output (Execution Trace)
The program takes a numeric input from the user and outputs the properly formatted English string.

```text
Enter a number: 123456789
Number in words: One Hundred Twenty Three Million Four Hundred Fifty Six Thousand Seven Hundred Eighty Nine