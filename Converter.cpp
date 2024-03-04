#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//This function takes a binary string as input and converts it into a decimal string representation. 
//It iterates through each character of the binary string from right to left, calculating the 
//decimal value by adding the corresponding powers of 2 based on the position of '1' digits in 
//the binary string, which is then returned as a string. 
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
//This function accepts a decimal string as input and converts it into a binary string representation.
//It converts the decimal string to an integer and performs repeated division by 2, appending 
//the remainders as characters to form the binary string representation. If the input is '0', 
//it returns "0" as the binary representation.
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

//This function takes a hexadecimal string as input and converts it into a decimal string representation.
//It processes each character of the hexadecimal string from right to left, calculating the decimal 
//value by adding the corresponding values of digits ('0'-'9') or letters ('a'-'f') multiplied 
//by powers of 16. The resulting decimal value is returned as a string.
string hexadecimalToDecimal(string hexadecimal) {
    int decimal = 0;
    int base = 1;
    for (int i = hexadecimal.length() - 1; i >= 0; i--) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - '0') * base;
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (hexadecimal[i] - 'A' + 10) * base;
        }
        base *= 16;
    }
    return to_string(decimal);
}

//This function receives a decimal string as input and converts it into a hexadecimal 
//string representation. It converts the decimal string to an integer and repeatedly 
//divides it by 16, appending the remainder as characters to form the hexadecimal string 
//representation. If the input is '0', it returns "0" as the hexadecimal representation.
string decimalToHexadecimal(string decimal) {
    if (decimal == "0") return "0";
    int num = stoi(decimal);
    string hexadecimal = "";
    while (num > 0) {
        int remainder = num % 16;
        if (remainder < 10) {
            hexadecimal = char(remainder + '0') + hexadecimal;
        } else {
            hexadecimal = char(remainder - 10 + 'A') + hexadecimal;
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
    cout << "Enter the input type (bin, dec, or hex(omit the 0x at the beginning)): ";
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
