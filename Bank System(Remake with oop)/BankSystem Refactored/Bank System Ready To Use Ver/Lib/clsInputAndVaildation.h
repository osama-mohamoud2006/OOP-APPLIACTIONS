#pragma once
#pragma warning(disable : 4996)
#include "Lib/clsDate.h"
#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include <fstream>
#include <cctype>

class clsInputAndValidation
{

   private:

   static std::string time()
   {
      std::time_t currentTime = std::time(0);
      std::tm *localTime = std::localtime(&currentTime);
      return std::asctime(localTime);
   }

   template <typename T> // to avoid un neccesssary overloading
   // write to file to use it to store the last input to file
   static void WriteTheLastResultToFile(T LastResult)
   {

      std::fstream write;
      write.open("ResultsHistory.text", std::ios::out | std::ios::app); // overwrite
      if (write.is_open())
      {
         // write the time and the last output to file
         write << "Date And time is: " << time() << std::endl;
         write << "The last input is: " << LastResult << std::endl;
         write.close();
      }
   }

   static void WriteTheLastResultToFile(bool LastResult)
   {
      std::fstream write;
      write.open("ResultsHistory.text", std::ios::out | std::ios::app);
      if (write.is_open())
      {
         // write the time and the last output to file
         write << "\nDate And time is: " << time()
               << "\nThe last OutputIs: "
               << PrintTrueOrFalse(LastResult);

         write.close();
      }
   }

   static std::string PrintTrueOrFalse(bool BoolFlag)
   {
      std::string arr[] = {"false", "true"};
      return arr[BoolFlag];
   }

   
   public:
   
   template <class N> // To Use it in class clsReadNum , to avoid unnessary repetion of code and make user decide the correct data type of the function instead of using double only

   class clsReadNum
   {
   public:
      // enter normal number without any validation
      static N enter_number(std::string message)
      {
         std::cout << message;
         N number;
         std::cin >> number;
         while (std::cin.fail())
         {
            std::cin.clear(); // to claer cin>> to reuse it
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << '\a';
            std::system("color 4f"); // red console screen
            std::cout << "\n\nplease enter correct number!: ";
            std::cin >> number;
         }

         std::system("color 0F"); // rest the screen to original color
         WriteTheLastResultToFile(number);
         return number;
      }

      static bool IsNumberBetween(N num, N start, N end)
      {
         bool res = (num >= start && num <= end);
         WriteTheLastResultToFile(res);
         return res;
      }

      // enter positive number
      static N enter_postive_number(std::string text)
      {
         bool vaild = false;
         N n = 0;
         do
         {
            std::cout << text;
            std::cin >> n;
            if (std::cin.fail())
            {
               std::cin.clear(); // to reuse cin>>
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               std::cout << "\a";
               std::system("color 4F"); // red if number isn't in range
            }

            else if (0 >= n)
            {
               std::cout << "\a";
               std::system("color 4F"); // red if number isn't in range
               std::cout << "\nplease enter postive number!\n ";
            }

            else
            {
               vaild = true;
            }

         } while (vaild == false);

         std::system("color 0F"); // rest screen color
         WriteTheLastResultToFile(n);
         return n;
      }

      // enter number in range
      static N enter_number_from_to(N from, N to, std::string text)
      {

         N number = 0;
         std::string mess = text + " (" + std::to_string((int)from) + " to " + std::to_string((int)to) + "):  ";
         number = enter_number(mess);
         while (!IsNumberBetween(number, from, to))
         {
            std::cout << "\a";
            std::system("color 4F"); // red if number isn't in range
            std::cout << "\nplease enter correct number which in range you assigned!\n";
            number = enter_number(text);
         }

         WriteTheLastResultToFile(number);
         return number;
      }

      // enter number in range (overloaded )
      static N enter_number_from_to(N from, N to)
      {
         N number = 0;
         number = enter_number("");
         while (!IsNumberBetween(number, from, to))
         {
            std::system("color 0F"); // rest screen color
            std::cout << "\nEnter correct number within range you assigned ! \n";
            std::cout << "\a";
            number = enter_number("");
         }

         WriteTheLastResultToFile(number);
         return number;
      }
   
   };

   static bool IsDateBetween(clsDate DtoCompare, clsDate d2, clsDate d3)
   {
      if (clsDate::CompareDates(d2, d3) == clsDate::After)
         clsDate::swapDates(d2, d3); // if d2>d3

      bool res = (clsDate::CompareDates(DtoCompare, d3) != clsDate::After && clsDate::CompareDates(DtoCompare, d2) != clsDate::Before);

      WriteTheLastResultToFile(res);

      return res;
   }

   // read string
   static std::string read_string(std::string message)
   {
      std::cout << message;
      std::string str;
      std::cin >> str;
      WriteTheLastResultToFile(str);
      return str;
   }

   // read char
   static char EnterChar()
   {
      char c;
      std::cin >> c;
      WriteTheLastResultToFile(c);
      return std::toupper(c);
   }

   // read full line
   static std::string read_full_line(const std::string &message)
   {
      std::cout << message;
      if (std::cin.peek() == '\n')
      {
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }

      std::string line = "";
      std::getline(std::cin, line);
      WriteTheLastResultToFile(line);
      return line;
   }

   static bool IsVaildDate(clsDate d)
   {
      bool res = !((d.GetD() <= 0) || (d.GetD() > d.NumberOfDaysInMonth(d.GetY(), d.GetM())) ||
                   (d.GetM() > 12) || (d.GetM() <= 0));
      WriteTheLastResultToFile(res);
      return res;
   }

   // return true if 'Y' or 'y'
   static bool Confirm(std::string message)
   {
      char choice = ' ';

      do
      {
         std::cout << message;
         choice = clsInputAndValidation::EnterChar(); // make the char toupper also

      } while (choice != 'N' && choice != 'Y');

      return (choice == 'Y');
   }

};