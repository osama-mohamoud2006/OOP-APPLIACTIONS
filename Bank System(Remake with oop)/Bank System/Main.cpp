#include <iostream>
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h"
#include "E:\projects\my library\AllStuff.h"
#include "AllClasses.h" 
#include <string>
#include <iomanip>
using namespace std;
//  ctrl + m+o
static  string time() {
	std::time_t currentTime = std::time(0);
	std::tm* localTime = std::localtime(&currentTime);
	return std::asctime(localTime);
}

int main() {

	string Time = clsDate::GetLocalDateAndTime();
	cout << Time << endl;

	//while (true) 	if (!clsLoginScreen::ShowLoginScreen()) break;

}
