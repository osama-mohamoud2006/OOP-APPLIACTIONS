#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsUser.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\Global.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsMainMenuUi.h"

class clsLoginScreen : protected clsScreen
{

public:
	static void LoginScreen() 
	{
		string Username = "";
		string Password = "";
	   bool LoginFailed = false;

		clsScreen::_PrintMenuOption(colorText("               Login", "green"));
		do {
			
			cout << "\n";
			  Username=clsInputAndValidation::read_string("\n\t\t\t\t\tEnter Username: ");
			  Password = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter Password: ");


			  // take the username and find it if exist will return true and you will have the object that have that username
			  if (!clsUser::FindUserAndReturnObj_If_exist(Username, Password, GCurrentUser)) // failed 
			  {
				  LoginFailed = true;
				  cout << colorText("\n\n\t\t\t\t\t\aUSERNAME OR PASSWORD ISN'T CORRECT !\n\n", "red");

			  } else { LoginFailed = false;}
			  
		} while (LoginFailed);

		// If logged in done then Show main menu
		clsMainMenuScreen::ShowMainMenuScreen(); 

	}

};