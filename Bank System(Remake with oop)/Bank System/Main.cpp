#include <iostream>
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h"
#include "E:\projects\my library\AllStuff.h"
#include "AllClasses.h" 
#include <string>
#include <iomanip>
using namespace std;

///  ctrl + m+o

void PrintUserInfo( clsUser & user ) 
{
	cout << "the user name is : " << user.GetUserName() << endl; 
	cout << "the Full name is :  " << user.GetFullName() << endl;
	cout << "the Email is : " << user.GetEmail() << endl;
	cout << "the Phone is : " << user.GetPhone() << endl;
	cout << "the Permissions is : " << user.GetPermissions() << endl;
	cout << "----------------------------------------" << endl;
	cout << "the Password is : " << user.GetPassword() << endl;

}

void FindUser() 
{
	string UserName = "";
	clsUser user = clsUser::ReturnEmptyObjForInitializingUser();
	UserName = clsInputAndValidation::read_string("\n\t\t\t\tEnter Username : ");

	while (!( clsUser::FindUserAndReturnObj_If_exist(UserName,user) )  )  // if it isn't existing 
	{
		cout << "\n\t\t\t\t\aThe Username " << UserName << " isn't existing !\n";
		UserName = clsInputAndValidation::read_string("\n\t\t\t\tEnter Another Username : ");
	}

	cout<< "the User is found successfully \n";
	PrintUserInfo(user);

}




int main() {


///clsMainMenuScreen::_ShowMainMenuScreen();

	FindUser();

}
