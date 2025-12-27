#pragma once 
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\Screens Of Manging Users\clsListUsersScreen.h""
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\Screens Of Manging Users\clsAddUsers.h"

class clsMangeUsersMenu  : protected clsScreen 
{

private:

	enum _enManagUsers{
		none =0,eListUsers =1 , eAddNewUser=2 , eDeleteUser= 3 , eUpdateUser =4 , eFindUser =5, eMainMenu=6};


	static void _EManageUsersMenu() {
		
	//	std::cout << setw(37) << left << "" << "===========================================\n";
		
		//std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(39) << left << " " << "\t[1] Show Users List.\n";
		std::cout << setw(39) << left << " " << "\t[2] Add New User.\n";
		std::cout << setw(39) << left << " " << "\t[3] Delete User.\n";
		std::cout << setw(39) << left << " " << "\t[4] Update User Info.\n";
		std::cout << setw(39) << left << " " << "\t[5] Find User.\n";
		std::cout << setw(39) << left << " " << "\t[6] Back To Main Menu.\n";
		std::cout << setw(37) << left << " " << "===========================================\n";

	}
	static  void  _BackToManageUsersMenuAgain() {
		std::cout << colorText("\n\n\n\t\t\t\t To Back To Manage Users  Menu ", "red");
		system("pause");
	}
	
	//1 (done )
	static  void _ShowListUsersScreen() {
		/*cout << "\n\t\t\t" << "Will Be List Users Screen\n";*/
		clsListUsersScreen::ListUsersScreen();
	}

	//2 (done) 
	static void _AddNewUsersScreen()
	{
		//cout << "\n\t\t\t" << "Will Be Add New Users Screen\n";
		clsAddUsers::AddNewUser();
	}

	//3 ()
	static void _DeleteUsersScreen()
	{
		cout << "\n\t\t\t" << "Will Be  Delete Users Screen\n";
	}


	//4 ()
	static void _UpdateUsersScreen()
	{
		cout << "\n\t\t\t" << "Will Be  Update Users Screen\n";
	}

	//5()
	static void _FindUsersScreen() 
	{
		cout << "\n\t\t\t" << "Will Be  Find Users Screen\n";
	}



	static _enManagUsers _PerformMenuOption(_enManagUsers Option ) {
		system("cls");

		switch (Option) 
		{

		case _enManagUsers::eListUsers: 
		{
			_ShowListUsersScreen();
			_BackToManageUsersMenuAgain();
			break;
		}

		case _enManagUsers::eAddNewUser: 
		{
			_AddNewUsersScreen();
			_BackToManageUsersMenuAgain();
			break;
		};

		case _enManagUsers::eDeleteUser: 
		{
			_DeleteUsersScreen();
			_BackToManageUsersMenuAgain();
			break;
		}
		
		case _enManagUsers::eUpdateUser:
		{
			_UpdateUsersScreen();
			_BackToManageUsersMenuAgain();
			break;
		}

		case _enManagUsers::eFindUser:
		{
			_FindUsersScreen();
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
			cout << "\n\n";
			clsScreen::_PrintMenuOption(colorText("\t  Manage Users Menu", "green"));
			_EManageUsersMenu(); // Show the menu options 
			cout << "\n";
			std::cout << setw(39) << left << "" << "Enter Option";
			option = _PerformMenuOption((_enManagUsers)clsInputAndValidation::enter_number_from_to(1,6,""));
		}

	}

};