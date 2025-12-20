#pragma once

#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsUtilPrintClientData.h"

#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h";


class clsAddNewClientScreen  : protected clsScreen
{

private:
	static void  _EnterNewDataToUpdate(clsBankClient& Temp) {
		std::cout << "\n\n";
		_PrintMenuOption(colorText("        Adding New Client" ,"green"));
		string DataToFill = "";

		DataToFill = clsInputAndValidation::read_string("\nEnter New First Name: ");
		Temp.SetFirstName(DataToFill);

		DataToFill = clsInputAndValidation::read_string("\nEnter New Last Name: ");
		Temp.SetLastName(DataToFill);

		DataToFill = clsInputAndValidation::read_string("\nEnter New Pin number: ");
		Temp.SetPin(DataToFill);

		DataToFill = clsInputAndValidation::read_string("\nEnter Email: ");
		Temp.SetEmail(DataToFill);

		DataToFill = clsInputAndValidation::read_string("\nEnter New Phone number: ");
		Temp.SetPhone(DataToFill);

		double balance = clsInputAndValidation::enter_postive_number("\nEnter Balance: ");
		Temp.SetBalance(balance);


	}

public:
	static void AddNewClient() {

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

	
		_EnterNewDataToUpdate(client); // fill the new data 
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

