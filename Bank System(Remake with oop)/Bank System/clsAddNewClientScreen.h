#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h";
class clsAddNewClientScreen  : protected clsScreen
{

private:
    static void _PrintClientData(const clsBankClient & client)  {
        clsScreen::PrintBasicPersonData(client); // call the print method of super class 
        std::cout << "The Account Number is: " << client.GetAccountNumber() << endl;
       std::cout << "The Pin is: " << client.GetPin() << endl;
      std::cout << "The Balance is : " << client.GetBalance() << endl;
}

	static void  _EnterNewDataToUpdate(clsBankClient& Temp) {

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

		string AccountNumber = "";
		AccountNumber = clsInputAndValidation::read_string("Enter account number: ");

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\a\nThe client with account number :  " << AccountNumber << " is exist \n please enter valid account number!\n";
			AccountNumber = clsInputAndValidation::read_string("Enter account number: ");
		}

		// if account isn't existing 
		clsBankClient client = clsBankClient::InitializeToAddNewClient();

		cout << "\t\nAdd New Client \n";
		_EnterNewDataToUpdate(client);
		client.SetAccountNumber(AccountNumber);

		clsBankClient::enSaveMode SaveStatus;
		SaveStatus = client.Save();

		if (SaveStatus == clsBankClient::enSaveMode::FailedOrEmptyObj) cout << "\aFailed to save\a\n";
		else if (SaveStatus == clsBankClient::AccountNumberExists) cout << "Account number is already exists so failed to save!\n\a";
		else  _PrintClientData(client);

	}


};

