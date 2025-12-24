#include <iostream>
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h"
#include "E:\projects\my library\AllStuff.h"
#include "AllClasses.h" 
#include <string>
#include <iomanip>
using namespace std;

///  ctrl + m+o

int main() {


///clsMainMenuScreen::_ShowMainMenuScreen();

	clsUser User1 = clsUser::ReturnEmptyObjForInitializingUser();
	string line = "username #//# password  #//#  permissions  #//# first name #//# last name  #//# email #//# phone ";
	User1._AddLineToFile(line); 

		 return 0;

}
