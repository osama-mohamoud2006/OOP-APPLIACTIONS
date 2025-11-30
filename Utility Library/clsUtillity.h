#pragma once
 #include <iostream>
#include <cstdlib>
#include<string>
#include <random>
#include <ctime>

class clsUtil{

 enum enCharType
 {
  smallLetter = 1,	  // Represents lowercase letters (ASCII 97 to 122).
  capitalLetter = 2,	  // Represents uppercase letters (ASCII 65 to 90).
  specialCharacter = 3, // Represents special characters (ASCII 33 to 47).
  digit = 4			  // Represents digits (ASCII 48 to 57).
 };

public:
 static  int random(int from, int to) {
  return rand() % (to - from + 1) + from;
 }

 // generate random values according to enum
 char get_random_stuff(enCharType CharType)
 {
  // Use a switch-case to handle the different character types.
  switch (CharType)
  {
   case enCharType::smallLetter:
    return char(random(97, 122));
    break;
   case enCharType::capitalLetter:
    return char(random(65, 90));
    break;
   case enCharType::specialCharacter:
    return char(random(33, 48));
    break;
   case enCharType::digit:
    return char(random(48, 57));
    break;
   default:
    return '\0';
  }
 }



};