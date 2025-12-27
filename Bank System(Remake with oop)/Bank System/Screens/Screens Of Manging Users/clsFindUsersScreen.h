#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsUser.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\Screens Of Manging Users\clsUtilPrintUserDetails.h"

class clsFindUsersScreen :  protected clsScreen 
{


	static void FindUser(){
	string user_name = "";
	clsUser User = clsUser::ReturnEmptyObjForInitializingUser();

	// Feature : make user attempt for 3 times if he didn't find the account ask him if he want to continue or not 

	short Trials = 0;

	while (true)
	{

		Trials++;
		system("cls");
		cout << "\n\n\n\n";
		clsScreen::_PrintMenuOption(colorText("            Find User Screen", "yellow"));


		if (Trials > 4)
		{
			std::cout << colorText("\n\t\t\t\t\t\aYou Tried For " + to_string(Trials - 1) + " Times To Find The User !\n\t\t\t\t\tExit To Mange Users Menu[y] Or Try Again[n] ? : ", "red");
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
			clsUtilPrintUserDetails::PrintUserInfo(User);
			break;
		}

	}

	}


};