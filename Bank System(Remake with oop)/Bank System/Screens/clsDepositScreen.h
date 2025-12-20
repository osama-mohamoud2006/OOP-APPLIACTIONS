#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
#include   "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsManageClientBalanceAccount.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsScreen.h"

class clsDepositScreen : protected clsScreen {
	
public:
	static void DepositBalanceFromClient() 
	{
		clsScreen::_PrintMenuOption(colorText("Deposit Screen", "cyan"));
		string AccountNumber = "";
		AccountNumber = clsInputAndValidation::read_string("\nEnter Account Number: ");
		clsBankClient Client  =clsBankClient::EmptyObjForInitializing();

		while (  !(clsBankClient::ReturnCurrentClient_if_ItExists(AccountNumber, Client) ) ) // if the client isn't existing ask for entering the account number again 
		{
			cout << "\n\nThe Account Number " << AccountNumber << " Isn't Existing !\a" << endl;
			AccountNumber = clsInputAndValidation::read_string("\nEnter Account Number: ");
		}


	}

};


