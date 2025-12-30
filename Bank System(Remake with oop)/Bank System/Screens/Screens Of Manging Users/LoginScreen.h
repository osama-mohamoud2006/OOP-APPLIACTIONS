#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsUser.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\Global.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsMainMenuUi.h"

class clsLoginScreen : protected clsScreen
{
private :

	static void _WaringTheLock(short &NumOfTrials) {
		cout << "\n\n\a";
		cout << setw(37) << left << "" << colorText("================================================", "red") << "\n";
		cout << setw(37) << left << "" << "              " << colorText(">> FAILED TO LOGIN <<", "red") << "\n";
		cout << setw(37) << left << "" << colorText("================================================", "red") << "\n\n";
		cout << setw(37) << left << "" << "You Still Have "<<to_string(NumOfTrials)<<" Trial(s) Before Locking The System" << ".\n";
		cout << "\n";
		cout << setw(37) << left << "" << colorText("================================================", "red") << "\n\n";
	}

	static  void _ExitTheSystemWaring() {
		cout << "\n\n\a";
		cout << setw(37) << left << "" << colorText("================================================", "red") << "\n";
		cout << setw(37) << left << "" << "              " << colorText(">> LOCKED <<", "red") << "\n";
		cout << setw(37) << left << "" << colorText("================================================", "red") << "\n\n";
		cout << setw(37) << left << "" << colorText("         SECURITY ALERT!", "yellow") << "\n\n";
		cout << setw(37) << left << "" << "         Too many failed login attempts.\n";
		cout << setw(37) << left << "" << "         The system has been locked for security.\n\n";
		cout << setw(37) << left << "" << colorText("================================================", "red") << "\n\n";
	}

	static bool _Login() 
	{

		string Username = "";
		string Password = "";
	   bool LoginFailed = false;
	   short Trials = 3; 
	  
		do {
			
			  Username=clsInputAndValidation::read_string("\n\t\t\t\t\tEnter Username: ");
			  Password = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter Password: ");

			  // take the username and find it if exist will return true and you will have the object that have that username
			  if (!clsUser::FindUserAndReturnObj_If_exist(Username, Password, GCurrentUser)) // failed 
			  {
				
				  Trials--;
				  system("cls");
				  _WaringTheLock(Trials);
				  
				  if(Trials==0)
				  {
					  system("cls");
					  _ExitTheSystemWaring();
					  return false; 
				  }

				  LoginFailed = true;

			  }
			  else 
			  { 
				  LoginFailed = false;
				  GCurrentUser.SaveLoginLog(); // Save the successful login details on file 
				  clsMainMenuScreen::ShowMainMenuScreen();
				  return true; 
			  }
			  
		} while (LoginFailed);


	}

public:
	static bool ShowLoginScreen() {
		clsScreen::_PrintMenuOption(colorText("               Login", "green"));
		return (_Login()) ? true : false; 
	}


};