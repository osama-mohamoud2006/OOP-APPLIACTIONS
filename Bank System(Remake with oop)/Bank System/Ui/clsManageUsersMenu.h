#pragma once 
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsScreen.h"


class clsMangeUsersMenu  : protected clsScreen 
{

private:

	enum _enManagUsers{
		none =0,eListUsers =1 , eAddNewUser=2 , eDeleteUser= 3 , eUpdateUser =4 , eFindUser =5, eMainMenu=6};


	static void _EUsersMenu() {

		std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << "\t\t\tManage UsersMenu\n";
		std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		std::cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		std::cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		std::cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		std::cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		std::cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		std::cout << setw(37) << left << "" << "\t[7] Admin Menu.\n";
		std::cout << setw(37) << left << "" << "\t[8] Logout.\n";
		std::cout << setw(37) << left << "" << "\t[9] Exit.\n";
		std::cout << setw(37) << left << "" << "===========================================\n";

	}

	static  void  _BackToManageUsersMenuAgain() {
		std::cout << colorText("\n\n\n\t\t\t\t To Back To Manage Users  Menu ", "red");
		system("pause");
	}
	

public:
	static void ShowManageUsersMenu() 
	{
		_enManagUsers option = _enManagUsers::none;  // initialize option 
		while (option!= _enManagUsers::eMainMenu) 
		{
			system("cls");

		}

	}

};