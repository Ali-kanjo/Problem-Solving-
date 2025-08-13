#include <iostream>
using namespace std;

// Convert numbers from 0 to 19 to their English words
string GetUnitsString(short number) {
    string units[] = { "", "One ", "Two ", "Three ", "Four ", "Five ", "Six ",
        "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ",
        "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };
    return units[number];
}

// Convert tens values (20,30,...90) to English words
string GetTensString(short number) {
    string tens[] = { "", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ",
        "Seventy ", "Eighty ", "Ninety " };
    return tens[number];
}

// Convert any three-digit number (0 to 999) to English words
string ConvertThreeDigitNumber(int number) {
    string result = "";

    // Get the hundreds digit
    int hundreds = number / 100;
    if (hundreds != 0) {
        result += GetUnitsString(hundreds) + "Hundred ";
        number %= 100;  // Remainder after removing hundreds
    }

    // Handle numbers from 10 to 19 directly using units array
    int tens = number / 10;
    if (tens == 1) {
        // Numbers from 10 to 19 are directly in GetUnitsString
        result += GetUnitsString(number);
        return result;
    }
    if (tens > 1) {
        result += GetTensString(tens);
        number %= 10;  // Remainder after removing tens
    }

    // Add the units digit
    result += GetUnitsString(number);

    return result;
}

// Main function to convert any number up to 2,147,483,647 into English words
string NumberToText(long long number) {
    if (number > 2147483647 || number < 0) {
        // Number is out of supported range - return fixed text
        return "Two Billion One Hundred Forty Seven Million Four Hundred Eighty Three Thousand Six Hundred Forty Seven";
    }
    else if (number >= 1000000000) {
        // Billions part
        int billions = number / 1000000000;
        number %= 1000000000;
        return ConvertThreeDigitNumber(billions) + "Billion " + NumberToText(number);
    }
    else if (number >= 1000000) {
        // Millions part
        int millions = number / 1000000;
        number %= 1000000;
        return ConvertThreeDigitNumber(millions) + "Million " + NumberToText(number);
    }
    else if (number >= 1000) {
        // Thousands part
        int thousands = number / 1000;
        number %= 1000;
        return ConvertThreeDigitNumber(thousands) + "Thousand " + NumberToText(number);
    }
    else {
        // Number less than 1000
        return ConvertThreeDigitNumber(number);
    }
}

int main() {
    long long inputNumber = 0;
    cout << "Enter a number: ";
    cin >> inputNumber;

    // Convert number to English words string
    string textNumber = NumberToText(inputNumber);

    cout << "Number in words: " << textNumber << endl;

    return 0;
}
