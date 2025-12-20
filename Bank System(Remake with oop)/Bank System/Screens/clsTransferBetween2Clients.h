#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsDepositScreen.h"
#include  "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsWithDrawScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsUtilPrintClientBalance.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsManageClientBalanceAccount.h"

class clsTransferBetween2UsersScreen : protected clsScreen {

private:
	static void _PrintWithdrawSuccessful() {
		cout << "\n\n";
		cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n";
		cout << setw(37) << left << "" << "             " << colorText(">> SUCCESS <<", "green") << "\n";
		cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n\n";
		cout << setw(37) << left << "" << "         Withdrawn Successfully!\n";
		cout << setw(37) << left << "" << "         Transaction completed.\n\n";
		cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n\n";
	}

	static void _PrintWithdrawFailed(double enteredAmount, double actualBalance) {
		cout << "\n\n\a";
		cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n";
		cout << setw(37) << left << "" << "              " << colorText(">> FAILED <<", "red") << "\n";
		cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n\n";
		cout << setw(37) << left << "" << "         Withdrawal Failed!\n";
		cout << setw(37) << left << "" << "         Insufficient funds.\n\n";
		cout << setw(37) << left << "" << "         Amount Requested : " << colorText("$" + to_string(enteredAmount), "red") << "\n";
		cout << setw(37) << left << "" << "         Available Balance: " << colorText("$" + to_string(actualBalance), "green") << "\n\n";
		cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n\n";
	}

public :
	static void TransFerBetween2Clients()
	{
		clsScreen::_PrintMenuOption(colorText("Transfer Between 2 Clients Screen", "pink"));

		string AccountNumber = "";
		clsBankClient ClientWhoWillSend = clsBankClient::EmptyObjForInitializing(); // client1

		// checking  if  the account of client 1 is existing
		AccountNumber = clsInputAndValidation::read_string("\nEnter Account Number: ");
		while (!(clsBankClient::ReturnCurrentClient_if_ItExists(AccountNumber, ClientWhoWillSend)))  // isn't existing 
		{
			screen_color(red);
			cout << "\n\n\aThe Account Number " << AccountNumber << " Isn't Existing !\a" << endl;
			AccountNumber = clsInputAndValidation::read_string("\nEnter Account Number: ");
		}

		// if it found
		screen_color(black);
		system("cls");
		clsUtilClientBalance::PrintClientBalanceRecord(ClientWhoWillSend); // print the client who will send screen 

		double PerAmountOfClient = ClientWhoWillSend.GetBalance();
		double amount = 0.0;
		short Trials = 0;

		// Make Sure entered the correct amount , Will Force you To Enter Amount You have Only and give you trials 
		while (true) { 
			Trials++;
			cout << "\n\n\t\t\t\t" << "Enter The Amount You Want To Send To Another Client:  ";
			amount = clsInputAndValidation::enter_postive_number( ""); 
			
			if ((PerAmountOfClient > amount)) break; // correct amount 
			else  	_PrintWithdrawFailed(amount, PerAmountOfClient);
			
			if (Trials > 4) {
				cout << "\a\n\n\n\t\t\t\t" << colorText("YOU ENTERTED WRONG WITHDRAW AMOUNT FOR ", "red") << Trials << colorText("THE OPERATION FAILED!\n", "red");
				_PrintWithdrawFailed(amount, PerAmountOfClient);
				return; // End the operation 
			}


		}



		// ClientWhoWillSend ---> withdraw from him
		clsBankClient::enSaveMode SaveStatus;

		SaveStatus= clsManageClientBalance::WithDraw(ClientWhoWillSend, amount);

		if (clsBankClient::enSaveMode::SuccessedToSave == SaveStatus) {
			system("cls");
			_PrintWithdrawSuccessful();
			clsUtilClientBalance::PrintClientBalanceRecord(ClientWhoWillSend, PerAmountOfClient);    //print balance details
		}

		else {
			system("cls");
			_PrintWithdrawFailed(amount, PerAmountOfClient);
			return;
		}



	};

};