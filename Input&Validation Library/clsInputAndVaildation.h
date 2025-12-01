#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Utility Library\clsDate.h"
#include<iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <limits>
#include<fstream>



class clsInputAndValidation  {

static  string time() {

   std::time_t currentTime = std::time(0);
   std::tm* localTime = std::localtime(&currentTime);
return std::asctime(localTime) ;

   }


  static  string ReturnTrueOrFalse(int BoolFlag) {
     string arr[2]={"false","true"};
      return arr[BoolFlag];
   }

   // write to file to use it to store the last input to file
  static  void WriteTheLastResultToFile(string LastResult) {

      fstream write;
      write.open("ResultsHistory.text",ios::out | ios::app) ;
      if (write.is_open())
      {
         // write the time and the last output to file
         write<< "\nDate And time is: "<<time()
           <<"\nThe last OutputIs: "<<LastResult;
      }


   }
   static  void WriteTheLastResultToFile(int LastResult) {
     fstream write;
     write.open("ResultsHistory.text",ios::out | ios::app) ;
     if (write.is_open())
     {
        // write the time and the last output to file
        write<< "\nDate And time is: "<<time()
           <<"\nThe last OutputIs: "<<to_string(LastResult);
     }


  }
   static  void WriteTheLastResultToFile(double LastResult) {
     fstream write;
     write.open("ResultsHistory.text",ios::out | ios::app) ;
     if (write.is_open())
     {
        // write the time and the last output to file
        write<< "\nDate And time is: "<<time()
        <<"\nThe last OutputIs: "<<to_string(LastResult);
     }


  }
   static  void WriteTheLastResultToFile(float LastResult) {
     fstream write;
     write.open("ResultsHistory.text",ios::out | ios::app) ;
     if (write.is_open())
     {
        // write the time and the last output to file
        write<< "\nDate And time is: "<<time()
        <<"\nThe last OutputIs: "<<to_string(LastResult);
     }


  }
   static  void WriteTheLastResultToFile(bool LastResult) {
      fstream write;
      write.open("ResultsHistory.text",ios::out | ios::app) ;
      if (write.is_open())
      {
         // write the time and the last output to file
         write<< "\nDate And time is: "<<time()
         <<"\nThe last OutputIs: "<<ReturnTrueOrFalse(LastResult);
      }


   }

public:
   // enter normal number without any validation
  static double enter_number(string message){
     cout<<message;
     int TheInput=0;
     double number;
     cin>>number;
     while(cin.fail()){
        cin.clear(); // to claer cin>> to reuse it
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << '\a';
        system("color 4f"); //red console screen
        cout<<"\n\nplease enter correct number!: ";
        cin>>number;
     }

     system("color 0F"); // rest the screen to original color
     WriteTheLastResultToFile(number);
     return number;
  }

  static bool IsNumberBetween(int num , int start , int end) {
     for (int i=start; i<=end; i++) {
        if (num ==i ) return true;
     }
     return false;
  }

};