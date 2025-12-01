#include <iostream>
#include "clsInputAndVaildation.h"
using namespace std;
static  string ReturnTrueOrFalse(bool BoolFlag) {
    string arr[]={"false","true"};
    return arr[BoolFlag];
}
int main() {
// cout<< ReturnTrueOrFalse(0)<<endl;
    // int x = clsInputAndValidation::enter_number("");
    // cout<<"the x is: "<<x;

  // cout<<  clsInputAndValidation::IsNumberBetween(4,1,10)<<endl;;

    // حالة عادية
    cout<<  clsInputAndValidation::IsDateBetween(clsDate(15,6,2024), clsDate(1,1,2024), clsDate(31,12,2024) )<<endl;  // ✅ true

    // حالة معكوسة (هيبدلهم أوتوماتيك)
  cout<< clsInputAndValidation::IsDateBetween(clsDate(15,6,2024), clsDate(31,12,2024),clsDate( 1,1,2024) )  <<endl ;  // ✅ true

    // خارج النطاق
   cout<< clsInputAndValidation::IsDateBetween(clsDate("1/1/2025"),clsDate( "1/1/2024"), clsDate("31/12/2024") )<<endl;;   // ❌ false
}