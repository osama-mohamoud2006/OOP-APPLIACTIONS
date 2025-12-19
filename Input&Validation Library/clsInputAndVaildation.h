#pragma once
#pragma warning(disable : 4996)
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Utility Library\clsDate.h"
#include<iostream>
#include <string>
#include <ctime>
#include <limits>
#include<fstream>
using namespace  std;

class clsInputAndValidation  {

static  string time() {
   std::time_t currentTime = std::time(0);
   std::tm* localTime = std::localtime(&currentTime);
        return std::asctime(localTime) ;
   }

   // write to file to use it to store the last input to file
  static  void WriteTheLastResultToFile(string LastResult) {

      fstream write;
      write.open("ResultsHistory.text",ios::out | ios::app) ;
      if (write.is_open())
      {
         // write the time and the last output to file
         write<< "\nDate And time is: "<<time() <<"\nThe last input is:  "<<LastResult<<endl;
         write.close();
      }

   }
   static  void WriteTheLastResultToFile(int LastResult) {
     fstream write;
     write.open("ResultsHistory.text",ios::out | ios::app) ;
     if (write.is_open())
     {
        // write the time and the last output to file
        write<< "\nDate And time is: "<<time() <<"\nThe last  input  is:  "<<to_string(LastResult)<<endl;
        write.close();
     }

  }
   static  void WriteTheLastResultToFile(double LastResult) {
     fstream write;
     write.open("ResultsHistory.text",ios::out | ios::app) ;
     if (write.is_open())
     {
        // write the time and the last output to file
        write<< "\nDate And time is: "<<time()<<"\nThe last input is:  "<<to_string(LastResult)<<endl;
        write.close();
     }


  }
   static  void WriteTheLastResultToFile(float LastResult) {
     fstream write;
     write.open("ResultsHistory.text",ios::out | ios::app) ;
     if (write.is_open())
     {
        // write the time and the last output to file
        write<< "\nDate And time is: "<<time()<<"\nThe last input is:  "<<to_string(LastResult)<<endl;
        write.close();
     }


  }

   static  string PrintTrueOrFalse(bool BoolFlag) {
   string arr[]={"false","true"};
   return arr[BoolFlag];
}

   static  void WriteTheLastResultToFile(bool LastResult) {
      fstream write;
      write.open("ResultsHistory.text",ios::out | ios::app) ;
      if (write.is_open())
      {
         // write the time and the last output to file
         write << "\nDate And time is: " << time()
        << "\nThe last OutputIs: "
        << PrintTrueOrFalse(LastResult);

         write.close();
      }


   }

public:
   // enter normal number without any validation
  static double enter_number(string message){
     cout<<message;
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
    bool res = (num>=start && num<=end);
     WriteTheLastResultToFile(res);
     return res;
  }
   static bool IsNumberBetween(double num , double start , double end) {
     bool res = (num>=start && num<=end);
     WriteTheLastResultToFile(res);
     return res;
  }
static bool IsDateBetween(clsDate DtoCompare , clsDate d2 , clsDate d3) {
     if (clsDate::CompareDates(d2,d3)==clsDate::After) clsDate::swapDates(d2,d3); // if d2>d3

     bool  res = (clsDate::CompareDates(DtoCompare , d3)!=clsDate::After
        && clsDate::CompareDates(DtoCompare,d2)!=clsDate::Before);

   WriteTheLastResultToFile(res);

      return res;
  }

   // enter postive number
  static double enter_postive_number(string text) {
     bool vaild = false ;
     double n=0;
     do {
        cout << text;
        cin >> n;
        if(cin.fail()){
           cin.clear(); // to reuse cin>>
           cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
           cout << "\a";
           system("color 4F"); // red if number isn't in range
        }

        else if (0>=n  ) {
           cout << "\a";
           system("color 4F"); // red if number isn't in range
           cout << "\nplease enter postive number!\n ";

        }

        else{
           vaild = true ;
        }

     } while (vaild == false );

     system("color 0F"); //rest screen color
     WriteTheLastResultToFile(n);
     return n;
  }

   // enter nunmber in range
   static double enter_number_from_to(double from,double to,string text) {

     double number=0;
       string mess = text+ " (" +to_string(from) + " to "  +  to_string(to) + "):  ";
        number = enter_number(mess);
       while (!IsNumberBetween(number,from,to)) {
           cout << "\a";
           system("color 4F"); // red if number isn't in range
           cout << "\nplease enter correct number which in range you assigned!\n";
          number = enter_number(text);
        }

     WriteTheLastResultToFile(number);
     return number;
  }

   // enter nunmber in range (overloaded )
   static double enter_number_from_to(double from, double to) {
     double number = 0;
     number = enter_number("");
     while (! IsNumberBetween(number,from,to)) {
        system("color 0F"); //rest screen color
        cout<<"\nEnter correct number within range you assigned ! \n";
        cout<<"\a";
        number = enter_number("");
     }

     WriteTheLastResultToFile(number);
     return number;
  }

   // read string
  static string read_string(string message) {
     cout << message;
     string str;
     cin >> str;
     WriteTheLastResultToFile(str);
     return str;
  }

  //read char 
  static char EnterChar() {
      char c;
      cin >> c;
      WriteTheLastResultToFile(to_string(c));
      return toupper(c);
  }

   // read full line
   static string read_full_line(const string& message) {
     cout << message;
     if (cin.peek() == '\n') {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
     }

     string line="";
     getline(cin, line);
     WriteTheLastResultToFile(line);
     return line;
  }

   static bool IsVaildDate(clsDate d) {
bool res = ! (    (d.GetD()  <=0 )|| ( d.GetD()  > d.NumberOfDaysInMonth( d.GetY(),d.GetM() ) )  ||
   (d.GetM() >12 )|| (d.GetM() <=0 ) )  ;
     WriteTheLastResultToFile(res);
     return res;
  }


   static string NumberToText(int Number)
   {
       if (Number == 0)
       {
           return "";
       }

       if (Number >= 1 && Number <= 19)
       {
           string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
           return arr[Number] + " ";
       }

       if (Number >= 20 && Number <= 99)
       {
           string arr[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
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