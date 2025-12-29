#pragma once 
//core
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsPerson.h"
//Screens Of Main Menu 
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsShowListScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsAddNewClientScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsShowDeleteScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsShowUpdateClientScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsFindClientScreen.h"

// Transaction Menu
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsTransactionMenuUi.h"

// Mange Users
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsManageUsersMenuUi.h"

// Current User Obj
 #include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\Global.h"

class clsMainMenuScreen : protected clsScreen
{

	private:

    enum _enMainMenuOptions {
        none=0,eListClientsScreen = 1, eAddNewClientScreen = 2, eDeleteClientScreen = 3,
        eUpdateClientScreen = 4, eFindClientScreen = 5, eShowTransactionsMenueScreen = 6,
        eUserscreen = 7, eLogoutScreen = 8 , eDisplayCurrentUserInfo=9,eExitScreen=10
    };


	static void _EMainMenu() {
	
		//std::cout << setw(37) << left << "" << "===========================================\n";
		//std::cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
		std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		std::cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		std::cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		std::cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		std::cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		std::cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		std::cout << setw(37) << left << "" << "\t[7] Admin Menu.\n";
		std::cout << setw(37) << left << "" << "\t[8] Logout.\n";
		std::cout << setw(37) << left << "" << "\t[8] Display Current User Info.\n";
		std::cout << setw(37) << left << "" << "\t[10] Exit.\n";
		std::cout << setw(37) << left << "" << "===========================================\n";

	}
	static  void  _BackToMainMenuAgain() {
		std::cout << colorText("\n\n\n\t\t\t\t To Back To Main Menu ","red");
		system("pause");
	}
	static void _ShowExitScreen() {
		std::cout << "\n\n\n\n\n Exiting The System................\n ";
		std::cout<<colorText("Good Bye :)","cyan")<<"\n\n\n";
		exit(0); /// End the system 
	}

	//1  (done)
	static void _ShowListClient() {
	/*	std::cout << "Will be Show List Client Soon...............\n";*/
		clsShowListScreen::PrintClientList();
	}

	//2  (done) 
	static  void _ShowAddNewClientScreen() {
		//std::cout << "Will be Add New Client Soon...............\n";
		clsAddNewClientScreen::AddNewClient();
	}

    //3 (done)
    static void _ShowDeleteClientScreen(){
        //std::cout << "Will be Delete Client Soon...............\n";
		clsShowDeleteClientScreen::DeleteClient();
    }

    //4 (done)
    static void _ShowUpdateClientScreen(){
        //std::cout<<"Will Be Client Update Screen\n";
		clsShowUpdateClientScreen::UpdateClientInfo();
    }
    
    //5 (done)
    static void _ShowFindClientScreen(){
      //  std::cout<<"Will Be Client Find Screen\n";
		clsFindClientScreen::FindClientByAccountNumber();

    }

    //6 (done)
    static void _ShowTransactionsScreen(){
        //std::cout<<"Will Be Transactions Screen\n";
		//  clsScreen::_PrintMenuOption(colorText("               Transactions Screen", "magenta"));
		clsTransactionMenu::ShowTransactionMenu();
    }

    //7  (done)
    static void _ShowManageUsersMenuScreen(){
     /*   std::cout<<"Will Be Admin Screen\n";*/
		clsMangeUsersMenu::ShowManageUsersMenu();
    }

    //8 (done)
    static void _ShowLogoutScreen(){
     //  std::cout<<"Will Be Logout Screen\n";
		  GCurrentUser = clsUser::ReturnEmptyObjForInitializingUser();  // --> empty the current user 
		 // clsLoginScreen::LoginScreen();// ---> circular refrence 
    }

	static void _ShowCurrentUserInfo() {

	}

	static _enMainMenuOptions  _PerformMainMenuOption(_enMainMenuOptions OptionByuser)
	{
		system("cls");
		switch (OptionByuser) {

		case _enMainMenuOptions::eListClientsScreen: {//1 
			_ShowListClient();// call list  client screen 
			_BackToMainMenuAgain();
			break;
		}

		case _enMainMenuOptions::eAddNewClientScreen: { //2 
			_ShowAddNewClientScreen();// call add new client screen 
			_BackToMainMenuAgain();
			break;
		}

		case _enMainMenuOptions::eDeleteClientScreen: {//3
			_ShowDeleteClientScreen();// call delete  client screen 
			_BackToMainMenuAgain();
			break;
		}

		case _enMainMenuOptions::eUpdateClientScreen: {//4
			_ShowUpdateClientScreen();// call update  client screen 
			_BackToMainMenuAgain();
			break;
		}

		case _enMainMenuOptions::eFindClientScreen: { //5
			_ShowFindClientScreen();// call find  client screen 
			_BackToMainMenuAgain();
			break;
		}

		case _enMainMenuOptions::eShowTransactionsMenueScreen: {//6
			_ShowTransactionsScreen();	// call transactions   screen 
			break;
		}

		case _enMainMenuOptions::eUserscreen: { //7
			//clsScreen::_PrintMenuOption(colorText("               Admin Screen", "orange"));
			_ShowManageUsersMenuScreen();		// call manage   screen 
			break;
		}

		case _enMainMenuOptions::eLogoutScreen: {//8
			//clsScreen::_PrintMenuOption(colorText("               Logout Screen", "pink"));
			_ShowLogoutScreen();	// call login again
			break;
		}

		case _enMainMenuOptions::eDisplayCurrentUserInfo: {
			_ShowCurrentUserInfo();
			_BackToMainMenuAgain();
			break;
		}

		case _enMainMenuOptions::eExitScreen: {//10
			_ShowExitScreen();// exit the program
			break;
		}

	  }


		return OptionByuser;
	}


public: 
	static void  ShowMainMenuScreen() {
		_enMainMenuOptions OptionByUser= _enMainMenuOptions::none;

		while (OptionByUser != _enMainMenuOptions::eExitScreen && OptionByUser != _enMainMenuOptions::eLogoutScreen ) {
			system("cls");
			clsScreen::_PrintMenuOption(colorText("               Main Menu","yellow"),GCurrentUser); // PrintBasicPersonData the name of menu 
			_EMainMenu(); // print main menu elements 
			std::cout << setw(37) << left << "" << "Enter Option";
			OptionByUser =_PerformMainMenuOption((_enMainMenuOptions)clsInputAndValidation::enter_number_from_to(1, 10, ""));
		}

	}

};