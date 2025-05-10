Question Link :: 
https://leetcode.com/problems/zigzag-conversion/description/

Question:: 

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000


Solve:::----->>>>

#include<iostream>
#include<string>
using namespace std;

string Convert(string inputText, int numRows) {

    if (numRows == 1 || inputText.length() < numRows)
        return inputText;

    char zigzagGrid[1000][1000] = { 0 };

    int currentRow = -1, currentCol = 0, textIndex = 0, resultIndex = 0;
    string result = inputText;

    while (inputText[textIndex] != '\0') {

        if (currentRow < numRows) {
            currentRow++;
            while (inputText[textIndex] != '\0' && currentRow < numRows) {
                zigzagGrid[currentRow++][currentCol] = inputText[textIndex++];
            }
        }
        else {
            currentRow--;
            while (inputText[textIndex] != '\0' && currentRow > 0) {
                zigzagGrid[--currentRow][++currentCol] = inputText[textIndex++];
            }
        }
    }

    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col <= currentCol; col++) {
            if (zigzagGrid[row][col] != 0) {
                result[resultIndex++] = zigzagGrid[row][col];
            }
        }
    }

    return result;
}


int main() {

    cout << Convert("PAYPALISHIRING", 4);

    return 0;
}
