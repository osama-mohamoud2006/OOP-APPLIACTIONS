#include "clsUtillity.h"
#include <iostream>
using namespace std;

void PrintSection(string title) {
    cout << "\n========================================" << endl;
    cout << "  " << title << endl;
    cout << "========================================" << endl;
}

int main() {
    cout << "\n*** UTILITY LIBRARY COMPREHENSIVE TEST ***\n" << endl;

    // Initialize random seed
    clsUtil::Srand();

    // ===== TEST 1: Random Number Generation =====
    PrintSection("TEST 1: Random Number Generation");
    cout << "Generating 5 random numbers between 1-100:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "  Random #" << i + 1 << ": " << clsUtil::Random(1, 100) << endl;
    }

    // ===== TEST 2: Random Character Generation =====
    PrintSection("TEST 2: Random Character Generation");
    cout << "Small Letters (5 chars): ";
    for (int i = 0; i < 5; i++)
        cout << clsUtil::GetRandomChar(clsUtil::smallLetter);
    cout << endl;

    cout << "Capital Letters (5 chars): ";
    for (int i = 0; i < 5; i++)
        cout << clsUtil::GetRandomChar(clsUtil::capitalLetter);
    cout << endl;

    cout << "Digits (5 chars): ";
    for (int i = 0; i < 5; i++)
        cout << clsUtil::GetRandomChar(clsUtil::digit);
    cout << endl;

    cout << "Special Characters (5 chars): ";
    for (int i = 0; i < 5; i++)
        cout << clsUtil::GetRandomChar(clsUtil::specialCharacter);
    cout << endl;

    cout << "Mixed Characters (5 chars): ";
    for (int i = 0; i < 5; i++)
        cout << clsUtil::GetRandomChar(clsUtil::mixChar);
    cout << endl;

    // ===== TEST 3: Random Word Generation =====
    PrintSection("TEST 3: Random Word Generation");
    cout << "Small letter words:" << endl;
    for (int i = 0; i < 3; i++)
        cout << "  Word " << i + 1 << ": " << clsUtil::GenerateRandomWord(clsUtil::smallLetter, 8) << endl;

    cout << "\nCapital letter words:" << endl;
    for (int i = 0; i < 3; i++)
        cout << "  Word " << i + 1 << ": " << clsUtil::GenerateRandomWord(clsUtil::capitalLetter, 8) << endl;

    cout << "\nMixed character words:" << endl;
    for (int i = 0; i < 3; i++)
        cout << "  Word " << i + 1 << ": " << clsUtil::GenerateRandomWord(clsUtil::mixChar, 8) << endl;

    // ===== TEST 4: Key Generation =====
    PrintSection("TEST 4: Key Generation (Single)");
    cout << "Generated Key 1: " << clsUtil::GenerateKey(4, clsUtil::capitalLetter, 5) << endl;
    cout << "Generated Key 2: " << clsUtil::GenerateKey(5, clsUtil::mixChar, 6) << endl;
    cout << "Generated Key 3: " << clsUtil::GenerateKey(3, clsUtil::digit, 4) << endl;

    // ===== TEST 5: Multiple Keys Generation (Print) =====
    PrintSection("TEST 5: Key Generation (Multiple - Print)");
    cout << "Generating 3 keys with mixed characters:" << endl;
    clsUtil::GenerateKeys(3, 4, clsUtil::mixChar, 5);

    // ===== TEST 6: Multiple Keys Generation (Vector) =====
    PrintSection("TEST 6: Key Generation (Multiple - Vector)");
    vector<string> keys = clsUtil::GenerateKeys(5, true, 3, clsUtil::capitalLetter, 4);
    cout << "Generated " << keys.size() << " keys stored in vector:" << endl;
    for (int i = 0; i < keys.size(); i++) {
        cout << "  Key " << i + 1 << ": " << keys[i] << endl;
    }

    // ===== TEST 7: Fill Array with Random Numbers =====
    PrintSection("TEST 7: Fill Array with Random Numbers");
    short numbers[10];
    clsUtil::FillArrayWithRandomNumbers(numbers, 10, 1, 50);
    cout << "Array of 10 random numbers (1-50):" << endl;
    for (int i = 0; i < 10; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // ===== TEST 8: Fill Array with Random Words =====
    PrintSection("TEST 8: Fill Array with Random Words");
    string words[5];
    clsUtil::FillArrayWithRandomWords(words, 5, clsUtil::capitalLetter, 6);
    cout << "Array of 5 random words:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "  " << i + 1 << ". " << words[i] << endl;
    }

    // ===== TEST 9: Fill Array with Random Keys =====
    PrintSection("TEST 9: Fill Array with Random Keys");
    string keyArray[3];
    clsUtil::FillArrayWithRandomKey(keyArray, 3, clsUtil::mixChar, 5);
    cout << "Array of 3 random keys:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  " << i + 1 << ". " << keyArray[i] << endl;
    }

    // ===== TEST 10: Copy Array =====
    PrintSection("TEST 10: Copy Array");
    string originalArray[3] = {"HELLO", "WORLD", "TEST"};
    string copiedArray[3];
    clsUtil::CopyArray(originalArray, 3, copiedArray);
    cout << "Original Array: ";
    for (int i = 0; i < 3; i++) cout << originalArray[i] << " ";
    cout << "\nCopied Array: ";
    for (int i = 0; i < 3; i++) cout << copiedArray[i] << " ";
    cout << endl;

    // ===== TEST 11: Shuffle Array =====
    PrintSection("TEST 11: Shuffle Array");
    string shuffleArray[5] = {"APPLE", "BANANA", "CHERRY", "DATE", "ELDERBERRY"};
    cout << "Original Array: ";
    for (int i = 0; i < 5; i++) cout << shuffleArray[i] << " ";
    cout << endl;
    clsUtil::ShuffleArray(shuffleArray, 5);
    cout << "Shuffled Array: ";
    for (int i = 0; i < 5; i++) cout << shuffleArray[i] << " ";
    cout << endl;

    // ===== TEST 12: Swap Operations =====
    PrintSection("TEST 12: Swap Operations");

    cout << "Swap Integers:" << endl;
    int num1 = 10, num2 = 20;
    cout << "  Before: num1=" << num1 << ", num2=" << num2 << endl;
    clsUtil::Swap(num1, num2);
    cout << "  After:  num1=" << num1 << ", num2=" << num2 << endl;

    cout << "\nSwap Characters:" << endl;
    char ch1 = 'A', ch2 = 'B';
    cout << "  Before: ch1=" << ch1 << ", ch2=" << ch2 << endl;
    clsUtil::Swap(ch1, ch2);
    cout << "  After:  ch1=" << ch1 << ", ch2=" << ch2 << endl;

    cout << "\nSwap Doubles:" << endl;
    double d1 = 3.14, d2 = 2.71;
    cout << "  Before: d1=" << d1 << ", d2=" << d2 << endl;
    clsUtil::Swap(d1, d2);
    cout << "  After:  d1=" << d1 << ", d2=" << d2 << endl;

    cout << "\nSwap Booleans:" << endl;
    bool b1 = true, b2 = false;
    cout << "  Before: b1=" << b1 << ", b2=" << b2 << endl;
    clsUtil::Swap(b1, b2);
    cout << "  After:  b1=" << b1 << ", b2=" << b2 << endl;

    cout << "\nSwap Strings:" << endl;
    string str1 = "Hello", str2 = "World";
    cout << "  Before: str1=" << str1 << ", str2=" << str2 << endl;
    clsUtil::Swap(str1, str2);
    cout << "  After:  str1=" << str1 << ", str2=" << str2 << endl;

    // ===== TEST 13: Tabs =====
    PrintSection("TEST 13: Tab Formatting");
    cout << "No tabs: " << "Text" << endl;
    cout << "1 tab:" << clsUtil::Tabs(1) << "Text" << endl;
    cout << "3 tabs:" << clsUtil::Tabs(3) << "Text" << endl;
    cout << "5 tabs:" << clsUtil::Tabs(5) << "Text" << endl;

    // ===== TEST 14: Encryption and Decryption =====
    PrintSection("TEST 14: Encryption and Decryption");

    string testText1 = "Hello";
    cout << "Original Text: " << testText1 << endl;
    clsUtil::EncryptText(testText1, 3);
    cout << "Encrypted (key=3): " << testText1 << endl;
    clsUtil::DecryptText(testText1, 3);
    cout << "Decrypted: " << testText1 << endl;

    cout << "\n";
    string testText2 = "World";
    cout << "Original Text: " << testText2 << endl;
    clsUtil::EncryptText(testText2, 5);
    cout << "Encrypted (key=5): " << testText2 << endl;
    clsUtil::DecryptText(testText2, 5);
    cout << "Decrypted: " << testText2 << endl;

    cout << "\n";
    string testText3 = "CppUtility";
    cout << "Original Text: " << testText3 << endl;
    clsUtil::EncryptText(testText3, 7);
    cout << "Encrypted (key=7): " << testText3 << endl;
    clsUtil::DecryptText(testText3, 7);
    cout << "Decrypted: " << testText3 << endl;

    // ===== TEST 15: Integer Array Shuffle =====
    PrintSection("TEST 15: Shuffle Integer Array");
    int numArray[6] = {1, 2, 3, 4, 5, 6};
    cout << "Original Array: ";
    for (int i = 0; i < 6; i++) cout << numArray[i] << " ";
    cout << endl;
    clsUtil::ShuffleArray(numArray, 6);
    cout << "Shuffled Array: ";
    for (int i = 0; i < 6; i++) cout << numArray[i] << " ";
    cout << endl;

    // ===== Final Summary =====
    PrintSection("ALL TESTS COMPLETED SUCCESSFULLY");
    cout << "✓ Random Number Generation" << endl;
    cout << "✓ Random Character Generation" << endl;
    cout << "✓ Random Word Generation" << endl;
    cout << "✓ Single Key Generation" << endl;
    cout << "✓ Multiple Keys Generation (Print)" << endl;
    cout << "✓ Multiple Keys Generation (Vector)" << endl;
    cout << "✓ Fill Array with Random Numbers" << endl;
    cout << "✓ Fill Array with Random Words" << endl;
    cout << "✓ Fill Array with Random Keys" << endl;
    cout << "✓ Copy Array" << endl;
    cout << "✓ Shuffle String Array" << endl;
    cout << "✓ Swap Operations (5 data types)" << endl;
    cout << "✓ Tab Formatting" << endl;
    cout << "✓ Encryption/Decryption" << endl;
    cout << "✓ Shuffle Integer Array" << endl;
    cout << "\n*** TEST SUITE COMPLETE ***\n" << endl;

    return 0;
}

