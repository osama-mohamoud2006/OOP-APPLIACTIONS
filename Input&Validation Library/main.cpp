#include <iostream>
#include "clsInputAndVaildation.h"
using namespace std;
static  string ReturnTrueOrFalse(bool BoolFlag) {
    string arr[]={"false","true"};
    return arr[BoolFlag];
}
int main() {
// // cout<< ReturnTrueOrFalse(0)<<endl;
//     int x = clsInputAndValidation::enter_number("Enter X: ");
//     int y=  clsInputAndValidation::enter_number("Enter Y: ");
//     int z = clsInputAndValidation::enter_number("Enter Z: ");
     //
     // cout<<"the x is: "<<x<<endl ;

  // cout<<  clsInputAndValidation::IsNumberBetween(4,1,10)<<endl;;
cout<<"enter num: ";
 double x = clsInputAndValidation::clsReadNum<int>::enter_number_from_to(1,10);

 string str = clsInputAndValidation::read_string("enter any thing: "); 
  //   cout<<  clsInputAndValidation::IsDateBetween(clsDate(31,12,2025), clsDate(1,1,2022), clsDate(31,12,2025) )<<endl;  // ✅ true
  // cout<< clsInputAndValidation::IsDateBetween(clsDate(15,6,2024), clsDate(31,12,2024),clsDate( 1,1,2024) )  <<endl ;  // ✅ true
  //
  //  cout<< clsInputAndValidation::IsDateBetween(clsDate("1/1/2025"),clsDate( "1/1/2024"), clsDate("31/12/2024") )<<endl;;   // ❌ false
}