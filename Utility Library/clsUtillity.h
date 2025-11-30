#pragma once
 #include <iostream>
#include <vector>
#include <cstdlib>
#include<string>
#include <random>
#include "clsDate.h"
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

 static void Swap(clsDate &Date1 , clsDate &Date2 ) {
  clsDate::swapDates(Date1,Date2);
 }
static void Swap(char & a  , char &b) {
  char temp = a;
  a =b ;
  b =temp ;
 }
static void Swap(int &num1 , int &num2) {
  int temp = num1;
  num1= num2 ;
  num2 = temp;
 }
 static void Swap(bool &B1 , bool &b2) {
  int temp = B1;
  B1= b2 ;
  b2 = temp;
 }
 static void Swap(double &num1 , double &num2) {
  double temp = num1;
  num1= num2 ;
  num2 = temp;
 }
 static void Swap(string &str1 , string &str2) {
  string temp = str1;
  str1= str2 ;
  str2 = temp;
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

 static string GenerateKey(short NumOfKeys=5,enCharType CharType=capitalLetter,short NumberOfCharsForEachUnit =5)
 {
  string Key ="";
  for (int i=0; i<NumOfKeys; i++ ) {
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

 static void FillArrayWithRandomNumbers(  short arr[] ,short Length ,int From , int To ) {
  for (short  i=0; i<Length; i++ )
   arr[i] = Random(From,To);
 }

 static void FillArrayWithRandomWords(string arr[] ,short Length ,enCharType CharType=capitalLetter,short NumberOfChars =5  )
 {
  for (int i=0; i<Length; i++)
  arr [i] = GenerateRandomWord(CharType , NumberOfChars) ;
 }

static void FillArrayWithRandomKey(string arr[] , short length ,enCharType CharType=capitalLetter,short NumberOfCharsForEachUnit =5)
 {
     for (short i=0; i<length; i++)
      arr[i] = GenerateKey(length,CharType,NumberOfCharsForEachUnit);
 }

 static void CopyArray(string arr[] , short length , string arr2[] ) {
  for (short i=0; i<length ; i++)
   arr2[i] = arr[i];

 }

 static void ShuffleArray(string arr[]  , short length) {
  if (arr[0] =="" ) {
   throw std::invalid_argument("your array must be filled with elements!\a");

  }
 for (short i=0; i<length; i++)
  Swap(arr[Random(1,length)-1 ] , arr[Random(1,length)-1 ]);

 }

 static void ShuffleArray(int arr[]  , short length) {
  for (short i=0; i<length; i++)
   Swap(arr[Random(1,length)-1 ] , arr[Random(1,length)-1 ]);
 }

 static string Tabs(short NumOfTabs) {
  string s ="";
  for (short i=0; i<NumOfTabs; i++)
   s+="\t";
  return s;
 }

 static void EncryptText(string &Text , short EncryptionKey) {
  string temp="";
  for (int i=0; i<Text.length(); i++) {
   temp += char (int(Text[i]) +  EncryptionKey);
  }
  Text = temp;

 }

 static  void DecryptText(string &Text , short EncryptionKey) {
  string temp="";
  for (int i=0; i<Text.length(); i++) {
   temp += char (int(Text[i]) -  EncryptionKey);
  }
  Text = temp;
 }

};