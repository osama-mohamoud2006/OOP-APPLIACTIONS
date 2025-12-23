#pragma once 
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsScreen.h"


class clsMangeUsersMenu  : protected clsScreen 
{

private:

	enum _enManagUsers{
		none =0,eListUsers =1 , eAddNewUser=2 , eDeleteUser= 3 , eUpdateUser =4 , eFindUser =5, eMainMenu=6};


	static void _EManageUsersMenu() {

	//	std::cout << setw(37) << left << "" << "===========================================\n";
		
		//std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << "\t[1] Show Users List.\n";
		std::cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		std::cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		std::cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
		std::cout << setw(37) << left << "" << "\t[5] Find User.\n";
		std::cout << setw(37) << left << "" << "\t[6] Back To Main Menu.\n";
		std::cout << setw(37) << left << "" << "===========================================\n";

	}
	static  void  _BackToManageUsersMenuAgain() {
		std::cout << colorText("\n\n\n\t\t\t\t To Back To Manage Users  Menu ", "red");
		system("pause");
	}
	

	static _enManagUsers _PerformMenuOption(_enManagUsers Option ) {
		system("cls");

		switch (Option) 
		{

		case _enManagUsers::eListUsers: 
		{

			_BackToManageUsersMenuAgain();
			break;
		}

		case _enManagUsers::eAddNewUser: 
		{

			_BackToManageUsersMenuAgain();
			break;
		};

		case _enManagUsers::eDeleteUser: 
		{

			_BackToManageUsersMenuAgain();
			break;
		}
		
		case _enManagUsers::eUpdateUser:
		{

			_BackToManageUsersMenuAgain();
			break;
		}

		case _enManagUsers::eFindUser:
		{

			_BackToManageUsersMenuAgain();
			break;
		}

		case _enManagUsers::eMainMenu: 
		{
			return _enManagUsers::eMainMenu;
		}


		}

		return Option;

	}

public:
	static void ShowManageUsersMenu() 
	{
		_enManagUsers option = _enManagUsers::none;  // initialize option 
		while (option!= _enManagUsers::eMainMenu) 
		{
			system("cls");
			clsScreen::_PrintMenuOption(colorText("\t\t\tManage UsersMenu\n", "green"));
			_EManageUsersMenu(); // Show the menu options 
			
		}

	}

};