#pragma once

#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsUtilPrintClientData.h"

#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsUtilAddNewClientOrUpdate.h"


class clsAddNewClientScreen  : protected clsScreen
{

private:
	static void  _EnterNewDataOfNewClient(clsBankClient& Temp) {
		std::cout << "\n\n";
		_PrintMenuOption(colorText("        Adding New Client" ,"green"));
		clsUtilAddOrUpdateClient::EnterDataOfClient(Temp);
	}

public:
	static void AddNewClient() {

		if (!clsScreen::HavePermission(clsUser::enUserPermission::eAddClient)) { return; } // if he hasn't per 

		do {

	      system("cls");
		clsScreen::_PrintMenuOption(colorText("        Add New Client Screen", "cyan"));
		string AccountNumber = "";
		AccountNumber = clsInputAndValidation::read_string("Enter account number: ");

		while (clsBankClient::IsClientExist(AccountNumber)) // if account number is existing then ask user to enter another acc num
		{
			screen_color(red);
			cout << "\t\t\t\a\nThe client with account number: " << AccountNumber << " is existing \nplease enter valid account number!\n";
			AccountNumber = clsInputAndValidation::read_string("\nEnter account number: ");
		}

		// if account isn't existing 
		system("cls");
		screen_color(black);
		clsBankClient client = clsBankClient::InitializeToAddNewClient();

	
		_EnterNewDataOfNewClient(client); // fill the new data 
		client.SetAccountNumber(AccountNumber);

		clsBankClient::enSaveMode SaveStatus; // check the save status 
		SaveStatus = client.Save();

		if (SaveStatus == clsBankClient::enSaveMode::FailedOrEmptyObj) {
			cout << "\aFailed to save\a\n";
			return ;
		}
		else if (SaveStatus == clsBankClient::AccountNumberExists) {
			cout << "Account number is already exists so failed to save!\n\a";
			return;
		}

		else clsUtilPrintClientData::PrintClientData(client,"CLIENT ADDED SUCCESSFULLY ");  

		} while (clsInputAndValidation::Confirm("\t\t\t\t   Do you Want To Add Another Client? [y],[n] ") );	// Do You Want To Add More Clients?
	

	}


};

