#pragma once
#include "Core Features/clsUser.h"
#include "Screens/Screens Of Manging Users/clsUtilPrintUserDetails.h"
#include "Screens/Screens Of Manging Users/clsUtilPrintStatus.h"

class clsFindUsersScreen :  protected clsScreen 
{

private:
	static void _PrintSuccess() {
		clsUtilPrintUserStatus::_PrintSuccess("         USER FOUNDED SUCCESSFULLY!\n");
	}

public:

	static void FindUser()
	{
	string user_name = "";
	clsUser User = clsUser::ReturnEmptyObjForInitializingUser();
	short Trials = 0;

	while (true){

		Trials++;
		system("cls");
		cout << "\n\n\n\n";
		clsScreen::_PrintMenuOption(colorText("            Find User Screen", "yellow"));

		if (Trials > 4)
		{
			std::cout << colorText("\n\t\t\t\t\t\aYou Tried For " + to_string(Trials - 1) + " Times To Find The User !\n\t\t\t\t\tExit To Manage Users Menu[y] Or Try Again[n] ? : ", "red");
			if (clsInputAndValidation::Confirm("")) { // if user entered 'Y' then it will returns true 'confirm()'
				break; // Back to Manage users  menu 
			}

			else {
				Trials = 0;
				continue; // skip this loop and start again 
			}

		}

		user_name = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter Username: ");
		if (   clsUser::FindUserAndReturnObj_If_exist(user_name,User) ) { // print user  data then break
			system("cls");
			_PrintSuccess();
			clsUtilPrintUserDetails::PrintUserInfo(User);
			break;
		}

	}

	}


};