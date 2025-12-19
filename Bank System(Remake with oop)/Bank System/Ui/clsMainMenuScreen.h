#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsPerson.h"
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsShowListScreen.h"
#include<iostream>
#include<string>

class clsMainMenuScreen : protected clsScreen
{

	private:

    enum _enMainMenuOptions {
        none=0,eListClientsScreen = 1, eAddNewClientScreen = 2, eDeleteClientScreen = 3,
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
		std::cout << setw(37) << left << "" << "\t[9] Exit.\n";
		std::cout << setw(37) << left << "" << "===========================================\n";

	}
	static  void  _BackToMainMenuAgain() {
		std::cout << colorText("\n\n\n\t\t\t\t To Back To Main Menu ","red");
		system("pause");
	}
	static void _ShowExitScreen() {
		std::cout << "\n\n\n\n\n Exiting The System................\n ";
		std::cout<<colorText("Good Bye :)","cyan")<<"\n\n\n";
	}

	//1 
	static void _ShowListClient() {
	/*	std::cout << "Will be Show List Client Soon...............\n";*/
		clsShowListScreen::PrintClientList();
	}
	//2
	static  void _ShowAddNewClientScreen() {
		std::cout << "Will be Add New Client Soon...............\n";
	}

    //3
    static void _ShowDeleteClientScreen(){
        std::cout << "Will be Delete Client Soon...............\n";
    }

    //4 
    static void _ShowUpdateClientScreen(){
        std::cout<<"Will Be Client Update Screen\n";
    }
    
    //5 
    static void _ShowFindClientScreen(){
        std::cout<<"Will Be Client Find Screen\n";
    }

    //6 
    static void _ShowTransactionsScreen(){
        std::cout<<"Will Be Transactions Screen\n";
    }

    //7 
    static void _ShowAdminScreen(){
        std::cout<<"Will Be Admin Screen\n";
    }

    //8 
    static void _ShowLogoutScreen(){
        std::cout<<"Will Be Logout Screen\n";
    }


	static _enMainMenuOptions  _PerformMainMenuOption(_enMainMenuOptions OptionByuser)
	{
		system("cls");
		switch (OptionByuser) {

		case _enMainMenuOptions::eListClientsScreen: //1 

			clsScreen::_PrintMenuOption(colorText("           List Clients Screen","purple"));
			_ShowListClient();// call list  client screen 
			_BackToMainMenuAgain();
			break;

		case _enMainMenuOptions::eAddNewClientScreen: //2 
			clsScreen::_PrintMenuOption(colorText("               Add New Client Screen","cyan"));
			_ShowAddNewClientScreen();// call add new client screen 
			_BackToMainMenuAgain();
			break;

		case _enMainMenuOptions::eDeleteClientScreen: //3
			clsScreen::_PrintMenuOption(colorText("               Delete Client Screen","red"));
			_ShowDeleteClientScreen();// call delete  client screen 
			_BackToMainMenuAgain();
			break;

		case _enMainMenuOptions::eUpdateClientScreen: //4
			clsScreen::_PrintMenuOption(colorText("               Update Client Screen","blue"));
			_ShowUpdateClientScreen();// call update  client screen 
			_BackToMainMenuAgain();
			break;


		case _enMainMenuOptions::eFindClientScreen: //5
            clsScreen::_PrintMenuOption(colorText("               Find Client Screen","yellow") );
            _ShowFindClientScreen();// call find  client screen 
			_BackToMainMenuAgain();
			break;

		case _enMainMenuOptions::eShowTransactionsMenueScreen: //6
            clsScreen::_PrintMenuOption(colorText("               Transactions Screen","magenta"));
            _ShowTransactionsScreen();	// call transactions   screen 
			_BackToMainMenuAgain();
			break;

		case _enMainMenuOptions::eAdminScreen: //7
            clsScreen::_PrintMenuOption(colorText("               Admin Screen","orange"));
            _ShowAdminScreen();		// call manage   screen 
			_BackToMainMenuAgain();
			break;

		case _enMainMenuOptions::eLogoutScreen: //8
            clsScreen::_PrintMenuOption(colorText("               Logout Screen","pink"));
            _ShowLogoutScreen();	// call login again
			break;

		case _enMainMenuOptions::eExitScreen: //9
			_ShowExitScreen();// exit the program
			break;

	  }


		return OptionByuser;
	}


public: 
	static void _ShowMainMenuScreen() {
		_enMainMenuOptions OptionByUser= _enMainMenuOptions::none;

		while (OptionByUser != _enMainMenuOptions::eExitScreen) {
			system("cls");
			clsScreen::_PrintMenuOption(colorText("               Main Menu","lightpurple")); // Print the name of menu 
			_EMainMenu(); // print main menu elements 
			std::cout << setw(37) << left << "" << "Enter Option";
			OptionByUser =_PerformMainMenuOption((_enMainMenuOptions)clsInputAndValidation::enter_number_from_to(1, 9, ""));
		}

	}

};