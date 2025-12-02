# clsInputAndValidation Library

A comprehensive C++ utility class for input validation, data entry, and result logging with automatic file storage.

---

## 📋 Table of Contents

- [Features](#features)
- [Dependencies](#dependencies)
- [Installation](#installation)
- [Usage](#usage)
  - [Number Input](#number-input)
  - [String Input](#string-input)
  - [Validation Functions](#validation-functions)
  - [Date Validation](#date-validation)
- [Automatic Logging](#automatic-logging)
- [Examples](#examples)

---

## ✨ Features

- **Robust Input Validation**: Handles invalid input gracefully with visual feedback
- **Range Validation**: Ensures numbers are within specified ranges
- **Date Validation**: Validates dates including leap years and month boundaries
- **Automatic Logging**: All operations are logged to file with timestamps
- **Visual Feedback**: Color-coded console output for errors
- **Multiple Data Types**: Supports int, double, float, string, and custom date objects

---

## 🔧 Dependencies
```cpp
#include "clsDate.h"  // Custom date class
#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include <fstream>
```

**Required**: Custom `clsDate` class for date operations

---

## 📦 Installation

1. Include the header file in your project:
```cpp
#include "clsInputAndValidation.h"
```

2. Ensure `clsDate.h` is in the correct path or update the include path

3. Create a writable directory for the `ResultsHistory.text` log file

---

## 🚀 Usage

### Number Input

#### Basic Number Entry
```cpp
double num = clsInputAndValidation::enter_number("Enter a number: ");
```

#### Positive Number Entry
```cpp
double positiveNum = clsInputAndValidation::enter_postive_number("Enter positive number: ");
```

#### Number in Range
```cpp
// With custom message
double score = clsInputAndValidation::enter_number_from_to(0, 100, "Enter score");

// Without message
double value = clsInputAndValidation::enter_number_from_to(1, 10);
```

---

### String Input

#### Single Word
```cpp
string name = clsInputAndValidation::read_string("Enter your name: ");
```

#### Full Line
```cpp
string address = clsInputAndValidation::read_full_line("Enter your address: ");
```

---

### Validation Functions

#### Check if Number is in Range
```cpp
// Integer version
bool valid = clsInputAndValidation::IsNumberBetween(5, 1, 10);  // true

// Double version
bool valid = clsInputAndValidation::IsNumberBetween(3.5, 1.0, 10.0);  // true
```

#### Check if Date is in Range
```cpp
clsDate date1(15, 6, 2024);
clsDate startDate(1, 1, 2024);
clsDate endDate(31, 12, 2024);

bool inRange = clsInputAndValidation::IsDateBetween(date1, startDate, endDate);  // true
```

**Note**: Automatically swaps start/end dates if provided in reverse order

---

### Date Validation
```cpp
clsDate validDate(29, 2, 2024);    // Leap year
clsDate invalidDate(31, 2, 2024);  // February has no 31st day

bool isValid1 = clsInputAndValidation::IsVaildDate(validDate);    // true
bool isValid2 = clsInputAndValidation::IsVaildDate(invalidDate);  // false
```

**Validates**:
- Month is between 1-12
- Day is between 1 and the maximum days in that month
- Handles leap years correctly

---

## 📝 Automatic Logging

All input and validation results are automatically logged to `ResultsHistory.text`:
```text
Date And time is: Tue Dec 02 14:30:45 2025
The last OutputIs: 42.5

Date And time is: Tue Dec 02 14:31:12 2025
The last OutputIs: true
```

---

## 💡 Examples

### Example 1: Age Validation
```cpp
#include "clsInputAndValidation.h"

int main() {
    double age = clsInputAndValidation::enter_number_from_to(
        1, 120, 
        "Enter your age"
    );
    
    cout << "Your age is: " << age << endl;
    return 0;
}
```

### Example 2: Grade Entry System
```cpp
double grade = clsInputAndValidation::enter_number_from_to(
    0, 100, 
    "Enter student grade"
);

if (grade >= 60) {
    cout << "Pass!" << endl;
} else {
    cout << "Fail!" << endl;
}
```

### Example 3: Booking Date Validation
```cpp
clsDate bookingDate(15, 8, 2025);
clsDate seasonStart(1, 6, 2025);
clsDate seasonEnd(30, 9, 2025);

if (clsInputAndValidation::IsVaildDate(bookingDate)) {
    if (clsInputAndValidation::IsDateBetween(bookingDate, seasonStart, seasonEnd)) {
        cout << "Booking accepted - within season!" << endl;
    } else {
        cout << "Date outside booking season." << endl;
    }
} else {
    cout << "Invalid date!" << endl;
}
```

---



### Number Input Methods

| Method | Parameters | Returns | Description |
|--------|-----------|---------|-------------|
| `enter_number()` | `string message` | `double` | Reads any number with validation |
| `enter_postive_number()` | `string text` | `double` | Reads positive numbers only |
| `enter_number_from_to()` | `double from, double to, string text` | `double` | Reads number in specified range |
| `enter_number_from_to()` | `double from, double to` | `double` | Overloaded version without message |

### String Input Methods

| Method | Parameters | Returns | Description |
|--------|-----------|---------|-------------|
| `read_string()` | `string message` | `string` | Reads single word |
| `read_full_line()` | `const string& message` | `string` | Reads entire line with spaces |

### Validation Methods

| Method | Parameters | Returns | Description |
|--------|-----------|---------|-------------|
| `IsNumberBetween()` | `int num, int start, int end` | `bool` | Checks if integer is in range |
| `IsNumberBetween()` | `double num, double start, double end` | `bool` | Checks if double is in range |
| `IsDateBetween()` | `clsDate compare, clsDate start, clsDate end` | `bool` | Checks if date is in range |
| `IsVaildDate()` | `clsDate d` | `bool` | Validates date structure |

---

## 🎨 Visual Feedback

- **Normal Input**: White on black console (0F)
- **Error State**: White on red console (4F)
- **Audio Alert**: System beep (`\a`) on invalid input

---



## ⚠️ Notes

- The library uses `system("color")` which is **Windows-specific**
- Ensure write permissions for `ResultsHistory.text`
- The `clsDate` class must implement: `CompareDates()`, `swapDates()`, `NumberOfDaysInMonth()`, `GetD()`, `GetM()`, `GetY()`
- All static methods can be called without creating an instance

---
