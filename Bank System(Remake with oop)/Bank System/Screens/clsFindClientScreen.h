#pragma once
#include  "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsUtilPrintClientData.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
class clsFindClientScreen : protected clsScreen
{
	
public:
	static void FindClientByAccountNumber() {

		string AccountNumber = "";
		clsBankClient Client = clsBankClient::EmptyObjForInitializing();

		// Feature : make user attempt for 3 times if he didn't find the account ask him if he want to continue or not 
	
		short Trials =0;
		bool Exit = false; 
	               //  check if client is existing if it exits then return object ///
		do {
			Trials++;
			system("cls");
			cout << "\n\n\n\n";
			clsScreen::_PrintMenuOption(colorText("            Find Client Screen", "yellow"));

			if (Trials > 4) 
			{
			
				std::cout << colorText("\n\t\t\t\t\t\aYou Tried For " + to_string(Trials-1) + " Times To Find The Account !\n\t\t\t\t\tExit To Main Menu Or Try Again ? [y], [n] : ", "red");
				if (clsInputAndValidation::Confirm("")) {
					Exit = true;
					break;
				}
				else {
					Trials = 0;
					Exit = false;
					FindClientByAccountNumber();
				}

			}




			AccountNumber = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter Account Number : ");

		} while ( !(clsBankClient::ReturnCurrentClient_if_ItExists(AccountNumber, Client) ) && (Exit == false));


	  // if exists
		if(!Exit) clsUtilPrintClientData::PrintClientData(Client);


		while (true) 
		{

			Trials++;
			system("cls");
			cout << "\n\n\n\n";
			clsScreen::_PrintMenuOption(colorText("            Find Client Screen", "yellow"));


			if (Trials > 4)
			{
				std::cout << colorText("\n\t\t\t\t\t\aYou Tried For " + to_string(Trials - 1) + " Times To Find The Account !\n\t\t\t\t\tExit To Main Menu[y] Or Try Again[n] ? [y], [n] : ", "red");
				if (clsInputAndValidation::Confirm("")) {
					break; // exit the loop and will call return to the main menu 
				}
				else {
					Trials = 0;
					Exit = false;
					FindClientByAccountNumber();
				}

			}




	      }

	
	}

};

