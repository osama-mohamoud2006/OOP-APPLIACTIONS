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

	               //  check if client is existing if it exits then return object ///
		do {
			system("cls");
			cout << "\n\n\n\n";
			clsScreen::_PrintMenuOption(colorText("            Find Client Screen", "yellow"));
			AccountNumber = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter Account Number : ");

		} while (!(clsBankClient::ReturnCurrentClient_if_ItExists(AccountNumber, Client) ));

		// if exists
		clsUtilPrintClientData::PrintClientData(Client);

	}

};

