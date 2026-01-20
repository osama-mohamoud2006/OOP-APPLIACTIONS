#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <random>
#include "clsDate.h"
#include <ctime>

class clsUtil
{

public:
    static void Srand()
    {
        // Seed the random number generator with the current time.
        // This ensures that the sequence of random numbers is different on each run.
        srand((unsigned)time(NULL));
    }

    enum enCharType
    {
        smallLetter = 1,      // Represents lowercase letters (ASCII 97 to 122).
        capitalLetter = 2,    // Represents uppercase letters (ASCII 65 to 90).
        specialCharacter = 3, // Represents special characters (ASCII 33 to 47).
        digit = 4             // Represents digits (ASCII 48 to 57).
        ,
        mixChar = 5
    };

    static int Random(int from, int to)
    {
        return rand() % (to - from + 1) + from;
    }

    static void Swap(clsDate &Date1, clsDate &Date2)
    {
        clsDate::swapDates(Date1, Date2);
    }

    template <typename T>
    static void Swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    // generate random values according to enum
    static char GetRandomChar(enCharType CharType)
    {
        // if mix chars then return digit or ca or sma
        if (CharType == enCharType::mixChar)
        {
            CharType = (enCharType)Random(1, 4);
        }

        // Use a switch-case to handle the different character types.
        switch (CharType)
        {
        case enCharType::smallLetter:
            return char(Random(97, 122));
            break;

        case enCharType::capitalLetter:
            return char(Random(65, 90));
            break;

        case enCharType::specialCharacter:
            return char(Random(33, 47));
            break;

        case enCharType::digit:
            return char(Random(48, 57));
            break;

        default:
            return '\0';
        }
    }

    static std::string GenerateRandomWord(enCharType CharType, short NumberOfChars = 5)
    {
        std::string Word = "";
        for (short i = 0; i < NumberOfChars; i++)
            Word += GetRandomChar(CharType);

        return Word;
    }

    static std::string GenerateKey(short NumOfKeys = 5, enCharType CharType = capitalLetter, short NumberOfCharsForEachUnit = 5)
    {
        std::string Key = "";
        for (int i = 0; i < NumOfKeys; i++)
        {
            Key += GenerateRandomWord(CharType, NumberOfCharsForEachUnit) + "-";
        }
        Key.pop_back();
        return Key;
    }

    static std::vector<std::string> GenerateKeys(short numOfKeys, short LengthOfKey = 5, enCharType CharType = capitalLetter, short NumberOfCharsForEachUnit = 5)
    {
        std::vector<std::string> Keys;
        for (short i = 0; i < numOfKeys; i++)
            Keys.push_back(GenerateKey(LengthOfKey, CharType, NumberOfCharsForEachUnit));

        return Keys;
    }

    static void FillArrayWithRandomNumbers(short arr[], short Length, int From, int To)
    {
        for (short i = 0; i < Length; i++)
            arr[i] = Random(From, To);
    }

    static void FillArrayWithRandomWords(std::string arr[], short Length, enCharType CharType = capitalLetter, short NumberOfChars = 5)
    {
        for (int i = 0; i < Length; i++)
            arr[i] = GenerateRandomWord(CharType, NumberOfChars);
    }

    static void FillArrayWithRandomKey(std::string arr[], short NumOfKeys, short length, enCharType CharType = capitalLetter, short NumberOfCharsForEachUnit = 5)
    {
        for (short i = 0; i < length; i++)
            arr[i] = GenerateKey(NumOfKeys, CharType, NumberOfCharsForEachUnit);
    }

    static void CopyArray(std::string arr[], short length, std::string arr2[])
    {
        for (short i = 0; i < length; i++)
            arr2[i] = arr[i];
    }

    template <typename A>
    static void ShuffleArray(A arr[], short length)
    {
        for (short i = 0; i < length; i++)
            Swap(arr[Random(1, length) - 1], arr[Random(1, length) - 1]);
    }

    static std::string Tabs(short NumOfTabs)
    {
        std::string s = "";
        for (short i = 0; i < NumOfTabs; i++)
            s += "\t";
        return s;
    }

private:
    static std::string GenerateRandomEncryptionKey(short NumOfChars)
    {
        std::string Key = "";
        for (short i = 0; i < NumOfChars; i++)
            Key += GetRandomChar(enCharType::smallLetter);
        return Key;
    }

    static std::string RandomEncryptionKey; // it is shared between Encrypt and Decrypt

public:
    static void EncryptText(std::string &Text, short EncryptionKey)
    {
        std::string temp = "";
        for (int i = 0; i < Text.length(); i++)
        {
            temp += char(int(Text[i]) + EncryptionKey);
        }
        Text = temp;
    }

    static void DecryptText(std::string &Text, short EncryptionKey)
    {
        std::string temp = "";
        for (int i = 0; i < Text.length(); i++)
        {
            temp += char(int(Text[i]) - EncryptionKey);
        }
        Text = temp;
    }

    static std::string EncryptOrDecryptUsingXor(std::string Text)
    {
        for (char &c : Text)
        {
            c = c ^ 'd';
        }
        return Text;
    }

    static std::string NumberToText(int Number)
    {
        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            std::string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
            return arr[Number] + " ";
        }

        if (Number >= 20 && Number <= 99)
        {
            std::string arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
            return arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 999)
        {
            return NumberToText(Number / 100) + "Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 999999)
        {
            return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 999999999)
        {
            return NumberToText(Number / 1000000) + "Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000)
        {
            return NumberToText(Number / 1000000000) + "Billion " + NumberToText(Number % 1000000000);
        }

        return "";
    }
};
