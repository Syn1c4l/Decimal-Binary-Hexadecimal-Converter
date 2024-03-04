#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string binaryToDecimal(string binary) {
    int decimal = 0;
    int base = 1;
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return to_string(decimal);
}

string decimalToBinary(string decimal) {
    if (decimal == "0") return "0";
    int num = stoi(decimal);
    string binary = "";
    while (num > 0) {
        binary = char(num % 2 + '0') + binary;
        num /= 2;
    }
    return binary;
}

string hexadecimalToDecimal(string hexadecimal) {
    int decimal = 0;
    int base = 1;
    for (int i = hexadecimal.length() - 1; i >= 0; i--) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - '0') * base;
        } else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f') {
            decimal += (hexadecimal[i] - 'a' + 10) * base;
        }
        base *= 16;
    }
    return to_string(decimal);
}

string decimalToHexadecimal(string decimal) {
    if (decimal == "0") return "0";
    int num = stoi(decimal);
    string hexadecimal = "";
    while (num > 0) {
        int remainder = num % 16;
        if (remainder < 10) {
            hexadecimal = char(remainder + '0') + hexadecimal;
        } else {
            hexadecimal = char(remainder - 10 + 'a') + hexadecimal;
        }
        num /= 16;
    }
    return hexadecimal;
}

string hexadecimalToBinary(string hexadecimal) {
    return decimalToBinary(hexadecimalToDecimal(hexadecimal));
}

string binaryToHexadecimal(string binary) {
    return decimalToHexadecimal(binaryToDecimal(binary));
}

int main() {
    string userInput;
    string inputType;

    // Take user input
    cout << "Enter the input type (bin, dec, or hex): ";
    cin >> inputType;
    cout << "Enter the number: ";
    cin >> userInput;

    // Determine the input type and perform conversions accordingly
    if (inputType == "bin") {
        cout << "Decimal: " << binaryToDecimal(userInput) << endl;
        cout << "Hexadecimal: " << binaryToHexadecimal(userInput) << endl;
    } else if (inputType == "dec") {
        cout << "Binary: " << decimalToBinary(userInput) << endl;
        cout << "Hexadecimal: " << decimalToHexadecimal(userInput) << endl;
    } else if (inputType == "hex") {
        cout << "Decimal: " << hexadecimalToDecimal(userInput) << endl;
        cout << "Binary: " << hexadecimalToBinary(userInput) << endl;
    } else {
        cout << "Invalid input type!" << endl;
    }

    return 0;
}
