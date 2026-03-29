
#include <iostream>
#include <string>
using namespace std;

string Convert(string inputText, int numRows)
{

    if (numRows == 1 || inputText.length() < numRows)
        return inputText;

    char zigzagGrid[1000][1000] = {0};

    int currentRow = -1, currentCol = 0, textIndex = 0, resultIndex = 0;
    string result = inputText;

    while (inputText[textIndex] != '\0')
    {

        if (currentRow < numRows)
        {
            currentRow++;
            while (inputText[textIndex] != '\0' && currentRow < numRows)
            {
                zigzagGrid[currentRow++][currentCol] = inputText[textIndex++];
            }
        }
        else
        {
            currentRow--;
            while (inputText[textIndex] != '\0' && currentRow > 0)
            {
                zigzagGrid[--currentRow][++currentCol] = inputText[textIndex++];
            }
        }
    }

    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col <= currentCol; col++)
        {
            if (zigzagGrid[row][col] != 0)
            {
                result[resultIndex++] = zigzagGrid[row][col];
            }
        }
    }

    return result;
}

int main()
{

    cout << Convert("PAYPALISHIRING", 4);

    return 0;
}
