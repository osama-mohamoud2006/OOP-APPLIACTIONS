#include <iostream>
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h"
#include "E:\projects\my library\AllStuff.h"
#include "AllClasses.h" 
#include <string>
#include <iomanip>
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Utility Library\clsUtillity.h"
using namespace std;
//  ctrl + m+o



int main() {
	srand((unsigned)time(NULL));
	//string pass = "1234";

	//clsUtil::EncryptText(pass);
	//clsUtil::DecryptText(pass);

	//cout <<pass<< endl;

while (true) 	if (!clsLoginScreen::ShowLoginScreen()) break;

}
