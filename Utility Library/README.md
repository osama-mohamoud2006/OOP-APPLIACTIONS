# Utility Library

A comprehensive C++ utility library providing helpful functions for random number generation, string manipulation, text encryption/decryption, array operations, and date handling.

## Overview

This project is part of an Object-Oriented Programming (OOP) course, demonstrating practical applications of OOP principles in a reusable utility library. The library encapsulates common utility functions into a static class (`clsUtil`) for easy access throughout C++ applications.

## Project Structure

```
Utility_Library/
├── clsUtillity.h       # Main utility class with static utility functions
├── clsDate.h           # Date handling class with date operations
├── main.cpp            # Demo/test file with example usage
├── CMakeLists.txt      # CMake configuration for building the project
└── README.md           # This file
```

## Features

### 1. Random Number Generation
- **Srand()**: Seeds the random number generator with the current time
- **Random(int from, int to)**: Generates a random integer between two values (inclusive)
- **GetRandomChar(enCharType)**: Generates random characters of specified types:
  - Small letters (a-z)
  - Capital letters (A-Z)
  - Digits (0-9)
  - Special characters
  - Mixed case letters

### 2. String & Word Generation
- **GenerateRandomWord()**: Creates random words of specified length and character type
- **GenerateKey()**: Generates formatted random keys (e.g., "ABCDE-FGHIJ-KLMNO")
- **GenerateKeys()**: Generates multiple keys with options to store in a vector
- **Tabs()**: Creates tab strings for formatting

### 3. Array Operations
- **FillArrayWithRandomNumbers()**: Fills an array with random integers
- **FillArrayWithRandomWords()**: Fills an array with random words
- **FillArrayWithRandomKey()**: Fills an array with random keys
- **CopyArray()**: Copies contents from one array to another
- **ShuffleArray()**: Randomly shuffles array elements

### 4. Swapping Operations
Overloaded Swap() methods for multiple data types:
- `clsDate` objects
- `char` values
- `int` values
- `bool` values
- `double` values
- `string` values

### 5. Encryption & Decryption
- **EncryptText()**: Encrypts text using a simple Caesar cipher with a numeric key
- **DecryptText()**: Decrypts text encrypted with EncryptText()

### 6. Date Handling
- Integration with `clsDate` class for date-related operations
- Date manipulation and swapping support

## Character Type Enumeration

```cpp
enum enCharType {
    smallLetter = 1,      // Lowercase letters (a-z)
    capitalLetter = 2,    // Uppercase letters (A-Z)
    specialCharacter = 3, // Special characters
    digit = 4,            // Digits (0-9)
    mixChar = 5           // Mixed case letters
};
```

## Usage Examples

### Basic Random Number Generation
```cpp
clsUtil::Srand(); // Seed the random generator
int randomNum = clsUtil::Random(1, 100); // Random number between 1-100
```

### Generate Random Words and Keys
```cpp
string word = clsUtil::GenerateRandomWord(clsUtil::capitalLetter, 5);
string key = clsUtil::GenerateKey(4, clsUtil::capitalLetter, 5); // "ABCDE-FGHIJ-KLMNO-PQRST"
```

### Array Operations
```cpp
string arr[5];
clsUtil::FillArrayWithRandomWords(arr, 5, clsUtil::smallLetter);
clsUtil::ShuffleArray(arr, 5);
```

### Text Encryption & Decryption
```cpp
string text = "hello";
clsUtil::EncryptText(text, 5);   // Encrypt with key 5
cout << text << endl;             // Encrypted text
clsUtil::DecryptText(text, 5);   // Decrypt
cout << text << endl;             // "hello"
```

### Swapping Values
```cpp
int a = 5, b = 10;
clsUtil::Swap(a, b);
// Now a = 10, b = 5

string s1 = "hello", s2 = "world";
clsUtil::Swap(s1, s2);
// Now s1 = "world", s2 = "hello"
```

## Building & Running

### Prerequisites
- C++ compiler supporting C++26 standard
- CMake 4.0 or higher

### Build Instructions

```bash
# Navigate to project directory
cd "path/to/Utility Library"

# Create build directory
mkdir cmake-build-debug
cd cmake-build-debug

# Generate build files
cmake ..

# Build the project
cmake --build . --config Debug

# Run the executable
./Utility_Library.exe
```

### On Windows (Alternative)
```powershell
cd "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Utility Library"
mkdir cmake-build-debug -Force
cd cmake-build-debug
cmake ..
cmake --build . --config Debug
.\Utility_Library.exe
```

## Dependencies

- **Standard C++ Library**: `<iostream>`, `<vector>`, `<string>`, `<cstdlib>`, `<random>`, `<ctime>`
- **Custom Dependencies**: `clsDate.h` (Date handling class)

## Class Structure

### clsUtil (Static Utility Class)

All methods are static, meaning they can be called directly on the class without instantiating an object:

```cpp
clsUtil::Random(1, 10);        // Direct access without creating instance
clsUtil::GenerateRandomWord(); // Convenient utility access
```

## Notes

- All methods are **static**, promoting a utility/helper design pattern
- The class uses simple algorithms suitable for educational purposes
- Encryption/Decryption uses a basic Caesar cipher (suitable for educational purposes only)
- Array operations assume properly sized arrays to avoid buffer overflows


## License

This is an educational project created for learning OOP principles in C++.

## Author

Created as part of a C++ OOP course - "OOP as it Should Be (Applications)"

---


