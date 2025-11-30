// cpp
#pragma once
#include <iostream>
#include "E:\projects\c++ course\10-OOP Concepts\Project 2\Project 2\clsString.h"
#include <string>
#include <iomanip>
#include<vector>
#include <stdio.h>
#include <cmath>
#include <ctime>

using namespace  std;
// Abstract class(contract)
class clsDateFunctions {
    virtual   bool isLeap()=0;
    virtual short numberOFDays()=0;
    virtual int NumberOfHours()=0;
    virtual  int NumberOfMin()=0;
    virtual int NumberOfSeconds()=0;
    virtual  short NumberOfDaysInMonth()=0;
    virtual  int HoursInMonth()=0;
    virtual  int MinInMonth()=0;
    virtual  int secondsInMonth()=0;
     virtual string FullDate(short y, short m, short d)=0;
    virtual short DayOrder()=0;
    virtual  string DayName( )=0;
     virtual string MonthName()=0;
     virtual void printMonthCalnder()=0;
     virtual void PrintYearCalnder()=0;
    virtual int TotalDaysSinceThisDate()=0;
    virtual short DayUntillDate()=0;
  virtual void GetDateFromDayOfYear(short NOdayUntillDate)=0;
    virtual void AddDaysToDate(short d)=0;
    virtual  void dateAfterAddingOneDay( )=0;


};

class clsDate : public clsDateFunctions  {
private:
      short y ;
     short m;
     short d;

public:

    clsDate() {
       *this =  GetCurrentLocalDate(); // make the current object have all data of this clsDate function
    } //take the local time
    clsDate(string FullDate ) {
        clsString::SetDelmi("/");
      vector<string > date = clsString::SplitString(FullDate);
        *this =clsDate( (short)stoi(date.at(0) ) , (short)stoi( date.at(1) ) , (short)stoi(date.at(2)));
    } //take the date as single string "d/m/y"
    clsDate(short d , short m , short y) {
        if (d>NumberOfDaysInMonth(y,m)) d=NumberOfDaysInMonth(y,m); // if user entered day bigger than actual days in month
          if (m>12) m=12;
        this->d=d;
        this->m=m;
        this->y=y;
    } //take d , m , y
    clsDate(short  NumberOfDays, short Year ) {
       *this =  GetDateFromDayOfYear(NumberOfDays,Year); // --> convert days to date

    } //number of days passed in the year and the year will return full date

    //set
    void SetD(short d) {
        this-> d= d;
    }
    void SetM(short m) {
        this->m = m;
    }
    void SetY(short y) {
        this-> y= y;
    }


    static string numberToText(int num)
    {
        if (num == 0)
            return "";
        if (num >= 1 && num <= 19)
        {
            string arr[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thriteen", "fourteen", "fivety", "sixteen", "seventeen", "eigtheen", "ninetheen"};

            return arr[num] + " ";
        }

        if (num >= 20 && num <= 99) //(20,30,40,50,60,70,80,90)
        {
            // 33 --> 30+3 --> 30->(20-90) , 3-->(1-19)
            string arr[] = {"", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};

            return arr[num / 10] + " " + numberToText(num % 10);
        }

        if (num >= 100 && num <= 1000)
        {
            // 125 --> 100+25
            string arr[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

            return arr[num / 100] + " hundered " + numberToText(num % 100);
        }

        if (num >= 1000 && num <= 10000)
        {
            // 2500 --> 2000+500
            string arr[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
            return arr[num/1000]+" thousand "+numberToText(num%1000);
        }
    }

   static  bool isLeap(short y)
    {
        // if it divided by 400 --> leap
        // if it divided by 4 And not divided by 100 --> leap
        return ((y % 400 == 0)|| (y%4==0 && y%100!=0) );
    }
    bool isLeap() {
        return isLeap(this->y);
    }

    static short numberOFDays(short y)
    {
        return (isLeap(y) == true) ? 366 : 365;
    } // number of days  in year
    short numberOFDays() {
        return numberOFDays(this->y);
    }

    static int NumberOfHours(short y)
    {
        return 24 * numberOFDays(y);
    }
    int NumberOfHours() {
        return NumberOfHours(this->y);
    }

   static  int NumberOfMin(int y)
    {
        return NumberOfHours(y) * 60;
    }
    int  NumberOfMin() {
        return NumberOfMin(this->y);
    }

    static  int NumberOfSeconds(int y)
    {
        return NumberOfMin(y) * 60;
    }
    int NumberOfSeconds() {
        return NumberOfSeconds(this->y);
    }

 static  short NumberOfDaysInMonth(short y, short m){

        if (m<1 || 12<m) return 0;
        // return (m==2)?((isLeap(y)==true)?  29 : 28) : (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) ? 31 : 30;

        short arr[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        return  (m==2)?((isLeap(y)==true)?  29 : 28):arr[m];
    }
    short NumberOfDaysInMonth() {
        return NumberOfDaysInMonth(this->y, this->m);
    }

    static  int HoursInMonth(short y, short m)
    {
        return 24 * NumberOfDaysInMonth(y, m);
    }
    int HoursInMonth() {
        return HoursInMonth(this->y , this->m);
    }

    static int MinInMonth(short y, short m)
    {
        return 60 * HoursInMonth(y, m);
    }
    int  MinInMonth() {
        return MinInMonth(this->y , this->m);
    }

    static  int secondsInMonth(short y, short m)
    {
        return MinInMonth(y, m) * 60;
    }
    int secondsInMonth() {
        return  secondsInMonth(this->y , this->m);
    }


    string FullDate(short y, short m, short d)
    {
        return (to_string(d) + "/" + to_string(m) + "/" + to_string(y));
    } // for functions
    string FullDate( )
    {
        return (to_string(this->d) + "/" + to_string(this->m) + "/" + to_string(this->y));
    } // for object
    static  string PrintFullDateForStatic(clsDate date) {
        return (to_string(date.d) + "/" + to_string(date.m) + "/" + to_string(date.y));
    }// for static

   static  short DayOrder(short year, short month, short day)
    {
        short a = ((14 - month) / 12);
        short y = year - a;
        short m = month + 12 * a - 2;

        return (day + y + ((y / 4)) - ((y / 100)) + ((y / 400)) + (((31 * m) / 12))) % 7;
    }
    short DayOrder() {
        return  DayOrder(this->y , this->m , this-> d);
    }

   static  string DayName(short dayOrder )
    {
        string Day[]={"sun","mon","tue","wed","thu","fri","sat"};
        return Day[dayOrder];
    }
    string DayName() {
        return  DayName(this->d);
    }

    static string MonthName(short m)
    {
        string month[] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "agu", "sep", "oct", "nov", "dec"};
        return month[m - 1];
    }
    string MonthName() override {
        return    MonthName(this->m);
    }

    static void printMonthCalnder(short m, short y)
    {
        int theLastDayInMonth = NumberOfDaysInMonth(y, m); // the last day
        int currentDay = DayOrder(y, m, 1);

        cout << "\n______________" << MonthName(m) << "______________" << endl;

        printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        for (int i = 0; i < currentDay; i++)
        {
            printf("     ");
        }

        for (int d = 1; d <= theLastDayInMonth; d++)
        {
            printf("%4d ", d);
            if ((d + currentDay) % 7 == 0)
                printf("\n");
        }
        printf("\n");

    }
    void printMonthCalnder() override  {
        printMonthCalnder(this->m, this->y);
    }

    static void PrintYearCalnder(short y)
    {
        for (short i = 1; i <= 12; i++)
        {
            printMonthCalnder(i,y); // print the month
            cout<<endl;
        }

    }
    void PrintYearCalnder() {
         PrintYearCalnder(this->y);
    }

    static int TotalDaysSinceThisDate(short y, short m, short d)
    {
        int totalDaysInMonths = 0;

        for (int i = 1; i <= m-1; i++)
        {
            totalDaysInMonths += NumberOfDaysInMonth(y, i); // count the total days untill the current month
        }

        // int the_rest_days_in_month = NumberOfDaysInMonth(y, m) - d;

        return totalDaysInMonths += d;
    } // count the total days untill the current date
    int TotalDaysSinceThisDate() {
        return TotalDaysSinceThisDate(this->y , this->m , this->d);
    }

    static short DayUntillDate(clsDate d)
    {
        short totalDays = 0;

        for (short i = 1; i <= d.m - 1; i++)
        {
            totalDays += NumberOfDaysInMonth(d.y, i);
        }
        return totalDays + d.d;
    }
    short DayUntillDate()
    {
     return DayUntillDate(*this);
    }

private : struct Stdate
    {
        short y;
        short m;
        short d;
    };
   //_______________________________________________________________________________//
public:

    static clsDate GetDateFromDayOfYear(short NunOfdaysUntillDate,short y) {

        // NOdayUntillDate is the number of days from 1/1 untill your day
        Stdate data;
        data.y = y; // the year

        short RemainingDays = NunOfdaysUntillDate; // will increment it to get the no.of days
        short m = 1;
        while (true)
        {
            short monthDays = NumberOfDaysInMonth(y, m); // the num of days in month

            if (RemainingDays > monthDays)
            {
                RemainingDays -= monthDays;
                m++;
            }
            else
            {
                data.m = m;
                data.d = RemainingDays;
                break;
            }
        }
        return clsDate(data.d,data.m,data.y);
    }
    void GetDateFromDayOfYear(short NumOFDaysUntillDate) {
      *this =  GetDateFromDayOfYear(NumOFDaysUntillDate,this->y);
    }//convert number of days to real date ( affect on current object)

   static clsDate AddDaysToDate(clsDate date, short d)
    {
        short RemainingDays = d + DayUntillDate(date); // total days

        date.m = 1;
        while (true)
        {
            short daysInMonth = NumberOfDaysInMonth(date.y, date.m);

            if (RemainingDays > daysInMonth)
            {
                RemainingDays -= daysInMonth;
                date.m++;

                if (date.m > 12)
                {
                    date.m = 1;
                    date.y++; // if new year
                }
            }
            else
            {

                date.d = RemainingDays;
                break;
            }
        }
        return date;
    }
    void AddDaysToDate(short d) override {
       *this = AddDaysToDate(*this ,d);
    }

// is date 1 less than date 2
    static bool isDate1LessThanDate2 (clsDate date , clsDate date2)
    {
        return (date.y < date2.y) ? true :
               (date.y == date2.y) ?
                 (date.m < date2.m) ? true :
                 (date.m == date2.m) ?
                   (date.d < date2.d) ? true : false
                 : false
               : false;
    }
    bool isDate1LessThanDate2(clsDate date2 ) {  // for object obj>d2
        return isDate1LessThanDate2(*this ,date2);
    }

    static bool isDate1equalsDate2(clsDate date, clsDate date2)
    {
        return ((date.y == date2.y) && (date.m == date2.m) && (date.d == date2.d));
    }
    bool isDate1equalsDate2(clsDate date2) { // for object
        return isDate1equalsDate2( *this ,  date2);
    }

    static bool isLastDayInMonth(clsDate date)
    {
        return (NumberOfDaysInMonth(date.y, date.m) == date.d);
    }
    bool isLastDayInMonth() {
        return isLastDayInMonth(*this);
    }

    static  bool isLastMonthInYear(clsDate date)
    {
        return (date.m == 12) ;
    }
    bool isLastMonthInYear() {
        return  isLastMonthInYear(*this);
    }

   static  clsDate dateAfterAddingOneDay(clsDate date)
    {

        if (isLastDayInMonth(date) == true)
        {
            date.d = 1; // rest day 1

            if (isLastMonthInYear(date) == true) // 1/1
            {
                date.m = 1;
                date.y = date.y + 1;
            }
            else date.m++;
        }
        else
        {
            date.d = date.d + 1;
        }
        return date;
    }
    void dateAfterAddingOneDay() {
       *this =  dateAfterAddingOneDay(*this);
    }

    static void swapDates(clsDate &date1, clsDate &date2)
    {
        clsDate temp;
        temp.d = date1.d;
        temp.m = date1.m;
        temp.y = date1.y;

        date1.d = date2.d;
        date1.m = date2.m;
        date1.y = date2.y;

        date2.d = temp.d;
        date2.m = temp.m;
        date2.y = temp.y;
    }

    static int DiffBetween2DatesInDays(clsDate date1, clsDate date2)
    {
        int FlagedAsD1IsnotLessD2 = 1;
        int days = 0;

        if (!isDate1LessThanDate2(date1, date2))
        {
            swapDates(date1, date2);
            FlagedAsD1IsnotLessD2 = -1;
        }
        while (isDate1LessThanDate2(date1, date2))
        {
            days++;
            date1 = dateAfterAddingOneDay(date1);
        }
        return days * FlagedAsD1IsnotLessD2;
    }
     int DiffBetween2DatesInDays(clsDate date2){
        return DiffBetween2DatesInDays(*this , date2 );
    }

    static clsDate GetCurrentLocalDate()
    {
        Stdate date;
        time_t epoch_time = time(0);
        tm *date_now = localtime(&epoch_time);
        // d/ m/ y --> 3/9/2025
        date.d = date_now->tm_mday;
        date.m = (date_now->tm_mon) + 1;
        date.y = (date_now->tm_year) + 1900;
        return clsDate(date.d,date.m,date.y);
    }


    static  int yourAgeInDays(clsDate birthday, clsDate d1)
    {
        int days = 0;
        while (isDate1LessThanDate2(birthday, d1))
        {
            days++; // add days from 1/8/2006 untill 3/9/2025
            birthday = dateAfterAddingOneDay(birthday);
        }
        return days;
    }
    int yourAgeInDays(clsDate BirthdayObj ) {
        return yourAgeInDays(BirthdayObj, *this );
    }

    // start from 20 to 32 .cpp
   // start from add x days ()
    static clsDate AddXdays(short days, clsDate date)
    {
        for (int i = 1; i <= days; i++)
        {
            date = dateAfterAddingOneDay(date);
        }
        return date;
    }
    void AddXdays(short days) {
        *this =  AddXdays(days,*this );
    }

    static  clsDate AddOneWeek(clsDate date)
    {
        for (int i = 1; i <= 7; i++)
        {
            date = dateAfterAddingOneDay(date);
        }
        return date;
    }
    void AddOneWeek() {
       *this =  AddOneWeek(*this);
    }

    static clsDate AddXweeks(short x, clsDate date)
    {
        for (int i = 1; i <= x; i++)
        {
            date = AddOneWeek(date);
        }
        return date;
    }
    void AddXweeks(short x) {
        *this = AddXweeks(x,*this);
    }


    static  clsDate AddOneMonth(clsDate date)
    {
        if (isLastMonthInYear(date))
        {
            date.y++;
            date.m = 1;
        }
        else
        {
            date.m++;
        }
        // if the days exceed the actual days in month
        // ex: 31/1 --> 31/2 (fatal mistake)
        // 31 > 28 ||29 , so will make the days the number of total days in month
        short ActualDaysInMonth = NumberOfDaysInMonth(date.y, date.m);
        if (date.d > ActualDaysInMonth)
        {
            date.d=ActualDaysInMonth ;
        }
        return date;
    }
    void AddOneMonth() {
        *this = AddOneMonth(*this);
    }

    static clsDate AddXMonths(short x, clsDate date)
    {
        for (int i = 1; i <= x; i++)
        {
            date = AddOneMonth(date);
        }
        return date;
    }
    void  AddXMonths(short x) {
        *this = AddXMonths(x,*this);
    }

   static clsDate AddOneYear(clsDate date)
    {
        date.y++;
        short numOfDaysInCurrentMonth =  NumberOfDaysInMonth(date.y,date.m);
        if (date.d >numOfDaysInCurrentMonth) date.d = numOfDaysInCurrentMonth;
        return date;
    }
    void  AddOneYear() {
        *this = AddOneYear(*this);
    }

    static  clsDate AddXYears(short x, clsDate &date)
    {
        for (int i = 1; i <= x; i++)
        {
            date = AddOneYear(date);

        }
        return date;
    }
    void AddXYears(short x) {
        *this = AddXYears(x,*this);
    }

    static  clsDate AddOneDecade(clsDate date)
    {
        date.y += 10;
        return date;
    }
    void AddOneDecade() {
        *this = AddOneDecade(*this);
    }

   static clsDate AdddXDecade(short x, clsDate date)
    {
        for (int i = 1; i <= x; i++)
        {
            date = AddOneDecade(date);
        }
        return date;
    }
    void AdddXDecade(short x) {
        *this = AdddXDecade(x,*this);
    }

   static  clsDate AddOneCentury(clsDate date)
    {
        date.y += 100;
        return date;
    }
    void AddOneCentury() {
        *this = AddOneCentury(*this);
    }

    static clsDate AddOneMillenuim(clsDate date)
    {
        date.y += 1000;
        return date;
    }
    void AddOneMillenuim() {
        *this = AddOneMillenuim(*this);
    }

    // 33 -> 46
    static  bool isFirstMonthInTheYear(clsDate date)
    {
      return (date.m == 1); // if m=1
    }
    bool isFirstMonthInTheYear() {
        return isFirstMonthInTheYear(*this);
    }

    static clsDate DecreaseOneDay(clsDate date)
    {

        if (isFirstMonthInTheYear(date)) // January
        {
            if (date.d == 1) // 1/1/2020 --> 31/12/2019
            {
                date.y--;                                     // 2019
                date.m = 12;                                  // 12
                date.d = NumberOfDaysInMonth(date.y, date.m); // 31
            }
            else // Other days in January (15/1 --> 14/1)
            {
                date.d--;
            }
        }
        else if (date.d == 1) // 1/4/2020 --> 31/3/2020
        {
            date.m--;                                     // 3
            date.d = NumberOfDaysInMonth(date.y, date.m); // 31
        }
        else // Normal case: decrease the day
        {
            date.d--;
        }
        return date;
    }
    void DecreaseOneDay() {
        *this = DecreaseOneDay(*this);
    }

    static clsDate DecreaseXDays(short x, clsDate &date)
    {
        for (short i = 1; i <= x; i++)
        {
            date = DecreaseOneDay(date);
        }
        return date;
    }
    void  DecreaseXDays(short x) {
        *this = DecreaseXDays(x,*this);
    }

    static clsDate DecreaseOneWeek(clsDate date)
    {
        for (int i = 1; i <= 7; i++)
        {
            date = DecreaseOneDay(date);
        }
        return date;
    }
    void DecreaseOneWeek() {
        *this = DecreaseOneWeek(*this);
    }

    static  clsDate DecreaseXWeeks(short x, clsDate date)
    {
        for (int i = 1; i <= x; i++)
        {
            date = DecreaseOneWeek(date);
        }
        return date;
    }
    void DecreaseXWeeks(short x) {
        *this = DecreaseXWeeks(x,*this);
    }

    static clsDate DecreaseOneMonth(clsDate date)
    {
        if (isFirstMonthInTheYear(date))
        {                // 1/1/2022 --> 1/12/2021
            date.y--;    // 2021
            date.m = 12; // 12
            return date;
        }
        else
        {
            date.m--;
        }
        short DaysInMonth = NumberOfDaysInMonth(date.y, date.m);
        if (date.d > DaysInMonth)
        {
            date.d = DaysInMonth;
        }
        return date;
    }
    void DecreaseOneMonth() {
        *this = DecreaseOneMonth(*this);
    }

    static clsDate DecreaseXMonth(short x, clsDate date) {
        for (short i = 1; i <= x; i++)
        {
            date = DecreaseOneMonth(date);
        }
        return date;
    }
    void DecreaseXMonth(short x) {
        *this = DecreaseXMonth(x,*this);
    }

    static clsDate DecreaseOneYear(clsDate date)
    {
        date.y--;
        short numOfDaysInCurrentMonth =  NumberOfDaysInMonth(date.y,date.m);
        if (date.d >numOfDaysInCurrentMonth) date.d = numOfDaysInCurrentMonth;
        return date;
    }
    void DecreaseOneYear() {
        *this = DecreaseOneYear(*this);
    }

    static clsDate DecreaseXYears(short x, clsDate date)
    {
        for (short i = 1; i <= x; i++)
        {
            date = DecreaseOneYear(date);
        }
       return date;

    }
    void DecreaseXYears(short x) {
        *this = DecreaseXYears(x,*this);

    }

   static  clsDate DecreaseOneDecade(clsDate date)
    {
        date.y -= 10;
        return date;
    }
    void DecreaseOneDecade() {
        *this = DecreaseOneDecade(*this);
    }

 static  clsDate DecreaseXdecades(clsDate date, short x = 10)
    {
        for (short i = 1; i <= x; i++)
        {
            date = DecreaseOneDecade(date);
        }
        return date;
    }
void DecreaseXdecades(short x = 10) {
        *this = DecreaseXdecades(*this , x);
    }

   static clsDate DecreaseOneCentury(clsDate date)
    {
        date.y -= 100;
        return date;
    }
    void DecreaseOneCentury() {
        *this = DecreaseOneCentury(*this);
    }

    static  clsDate DecreaseOneMillenum(clsDate date)
    {
        date.y -= 1000;
        //return clsDate(date.d,date.m,date.y);
        return date ;
    }
    void DecreaseOneMillenum() {
        *this = DecreaseOneMillenum(*this);
    }

    enum enDateCompare { Before = -1, Equal = 0, After = 1 };
    static enDateCompare CompareDates(clsDate date1 , clsDate date2) {
        if (isDate1LessThanDate2(date1,date2)) return enDateCompare::Before;
        else if (isDate1equalsDate2(date1,date2)) return enDateCompare::Equal;
        return enDateCompare::After;
    }
    enDateCompare CompareDates(clsDate date2) {
        return CompareDates(*this,date2);
    }

};

