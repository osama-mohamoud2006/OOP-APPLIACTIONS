#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsPerson.h"
#include<iostream>
#include<string>

class clsMainMenuScreen : protected clsScreen
{

	private:

    enum _enMainMenuOptions {
        eListClientsScreen = 1, eAddNewClientScreen = 2, eDeleteClientScreen = 3,
        eUpdateClientScreen = 4, eFindClientScreen = 5, eShowTransactionsMenueScreen = 6,
        eAdminScreen = 7, eLogoutScreen = 8 , eExitScreen=9
    };


	static void _EMainMenu() {
	
		std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
		std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		std::cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		std::cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		std::cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		std::cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		std::cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		std::cout << setw(37) << left << "" << "\t[7] Admin Menu.\n";
		std::cout << setw(37) << left << "" << "\t[8] Logout.\n";
		std::cout << setw(37) << left << "" << "\t[8] Exit.\n";
		std::cout << setw(37) << left << "" << "===========================================\n";

	}

	static  void  _BackToMainMenuAgain() {
		system("pause");
		std::cout << colorText("\n\tPress Any Key To Back To Main Menu.................\n","orange");
	}





	static _enMainMenuOptions _PerformMainMenuOption(_enMainMenuOptions OptionByuser)
	{
		switch (OptionByuser) {

		case _enMainMenuOptions::eListClientsScreen: //1 
			// call list  client screen 
			_BackToMainMenuAgain();
			break;

		case _enMainMenuOptions::eAddNewClientScreen: //2 
			// call add new client screen 
			_BackToMainMenuAgain();
			break;

		case _enMainMenuOptions::eDeleteClientScreen: //3
			// call delete  client screen 
			_BackToMainMenuAgain();
			break;

		case _enMainMenuOptions::eUpdateClientScreen: //4
			// call update  client screen 
			_BackToMainMenuAgain();
			break;

		case _enMainMenuOptions::eFindClientScreen: //5
			// call find  client screen 
			_BackToMainMenuAgain();
			break;

		case _enMainMenuOptions::eShowTransactionsMenueScreen: //6
			// call transactions   screen 
			_BackToMainMenuAgain();
			break;

		case _enMainMenuOptions::eAdminScreen: //7
			// call manage   screen 
			_BackToMainMenuAgain();
			break;

		case _enMainMenuOptions::eLogoutScreen: //8
			// call login again

			break;

		case _enMainMenuOptions::eExitScreen: //9
			// exit the program
			break;

	  }


	}


public: 
	static void _ShowMainMenuScreen() {

	
			clsScreen:: _PrintMenuOption("Main Menu");
			_EMainMenu();
			std::cout << setw(37) << left << "" << clsInputAndValidation::enter_number_from_to(1, 9,"Enter Option From ");
		

	}

};