#pragma once
#include "../Screens/clsScreen.h"
#include "../Screens/clsUtilPrintClientData.h"
#include "../Core Features/clsBankClient.h"
class clsFindClientScreen : protected clsScreen
{
	
public:
	static void FindClientByAccountNumber() {
		if (!clsScreen::HavePermission(clsUser::enUserPermission::eFindClient)) { return; } // if he hasn't per 
		string AccountNumber = "";
		clsBankClient Client = clsBankClient::EmptyObjForInitializing();

		// Feature : make user attempt for 3 times if he didn't find the account ask him if he want to continue or not 
	
		short Trials =0;

		while (true) 
		{

			Trials++;
			system("cls");
			cout << "\n\n\n\n";
			clsScreen::_PrintMenuOption(colorText("            Find Client Screen", "yellow"));


			if (Trials > 4)
			{
				std::cout << colorText("\n\t\t\t\t\t\aYou Tried For " + to_string(Trials - 1) + " Times To Find The Account !\n\t\t\t\t\tExit To Main Menu[y] Or Try Again[n] ? : ", "red");
				if (clsInputAndValidation::Confirm("")) { // if user entered 'Y' then it will returns true 'confirm()'
					break ; // Back to main menu 
				}
				else {
					Trials = 0;
					continue; // skip this loop and start again 
				}

			}


			AccountNumber = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter Account Number : ");

			if ( clsBankClient::ReturnCurrentClient_if_ItExists(AccountNumber, Client) ) { // print client data then break
				clsUtilPrintClientData::PrintClientData(Client);
				break; 
			}



	      }

	
	}

};


