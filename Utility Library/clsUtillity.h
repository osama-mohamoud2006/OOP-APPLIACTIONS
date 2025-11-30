#pragma once
 #include <iostream>
#include <vector>
#include <cstdlib>
#include<string>
#include <random>
#include <ctime>
using namespace std;

class clsUtil{

public:

 static void Srand() {
  // Seed the random number generator with the current time.
  // This ensures that the sequence of random numbers is different on each run.
  srand((unsigned)time(NULL));
 }

 enum enCharType
 {
  smallLetter = 1,	  // Represents lowercase letters (ASCII 97 to 122).
  capitalLetter = 2,	  // Represents uppercase letters (ASCII 65 to 90).
  specialCharacter = 3, // Represents special characters (ASCII 33 to 47).
  digit = 4			  // Represents digits (ASCII 48 to 57).
  , mixChar =5
 };

 static  int Random(int from, int to) {
  return rand() % (to - from + 1) + from;
 }

 // generate random values according to enum
 static char GetRandomChar(enCharType CharType)
 {
  // Use a switch-case to handle the different character types.
  switch (CharType)
  {
   case enCharType::smallLetter:
    return char(Random(97, 122));
    break;

   case enCharType::capitalLetter:
    return char(Random(65, 90));
    break;

   case enCharType::mixChar:
 if (Random(1,2)==1)  return char(Random(97, 122)); //capital
    else return char(Random(65, 90)); // small

    break;

   case enCharType::specialCharacter:
    return char(Random(33, 48));
    break;

   case enCharType::digit:
    return char(Random(48, 57));
    break;

   default:
    return '\0';
  }
 }

static string GenerateRandomWord(enCharType CharType,short NumberOfChars =5) {
  string Word ="";
       for (short i=0; i<NumberOfChars; i++ )
        Word+=GetRandomChar(CharType);

  return Word;
 }

 static string GenerateKey(short LengthOfKey=5,enCharType CharType=capitalLetter,short NumberOfCharsForEachUnit =5)
 {
  string Key ="";
  for (int i=0; i<LengthOfKey; i++ ) {
  Key+= GenerateRandomWord(CharType , NumberOfCharsForEachUnit)+"-";
  }
  Key.pop_back();
 return Key;
 }

 static void GenerateKeys(short numOfKeys,short LengthOfKey=5,enCharType CharType=capitalLetter,short NumberOfCharsForEachUnit =5) {
  for (short i=0; i<numOfKeys; i++)
   cout<< GenerateKey(LengthOfKey,CharType,NumberOfCharsForEachUnit) <<endl;
 }

 static vector<string> GenerateKeys(short numOfKeys,bool StoreKeysInVector,short LengthOfKey=5,enCharType CharType=capitalLetter,short NumberOfCharsForEachUnit =5 )
 {
  vector<string> Keys ;
  for (short i=0; i<numOfKeys; i++ )
  Keys.push_back( GenerateKey(LengthOfKey,CharType,NumberOfCharsForEachUnit) );

  return Keys;
 }

};