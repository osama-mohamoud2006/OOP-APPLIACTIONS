#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsDepositScreen.h"
#include  "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsWithDrawScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsUtilPrintClientBalance.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsManageClientBalanceAccount.h"

class clsTransferBetween2UsersScreen : protected clsScreen {

private:

	static void _PrintSuccess(const clsBankClient& fromClient, const clsBankClient& toClient, double amount) {
		cout << "\n\n";
		cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n";
		cout << setw(37) << left << "" << "             " << colorText(">> SUCCESS <<", "green") << "\n";
		cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n\n";
		cout << setw(37) << left << "" << "         Transfer Completed Successfully!\n\n";
		cout << setw(37) << left << "" << "         From: " << colorText(fromClient.GetFirstName() + " " + fromClient.GetLastName(), "cyan") << "\n";
		cout << setw(37) << left << "" << "         To  : " << colorText(toClient.GetFirstName() + " " + toClient.GetLastName(), "green") << "\n\n";
		cout << setw(37) << left << "" << "         Amount Transferred: " << colorText("$" + to_string(amount), "yellow") << "\n";
		cout << setw(37) << left << "" << "         New Balance      : " << colorText("$" + to_string(fromClient.GetBalance()), "green") << "\n\n";
		cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n\n";
	}

	static void _PrintTransferFailed(const clsBankClient& fromClient, const clsBankClient& toClient, double amount, double availableBalance) {
	
		system("cls");
		cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n";
		cout << setw(37) << left << "" << "              " << colorText(">> FAILED <<", "red") << "\n";
		cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n\n";
		cout << setw(37) << left << "" << "         Transfer Failed!\n";
		cout << setw(37) << left << "" << "         Insufficient funds.\n\n";
		cout << setw(37) << left << "" << "         From: " << colorText(fromClient.GetFirstName() + " " + fromClient.GetLastName(), "cyan") << "\n";
		cout << setw(37) << left << "" << "         To  : " << colorText(toClient.GetFirstName() + " " + toClient.GetLastName(), "yellow") << "\n\n";
		cout << setw(37) << left << "" << "         Amount Requested : " << colorText("$" + to_string(amount), "red") << "\n";
		cout << setw(37) << left << "" << "         Available Balance: " << colorText("$" + to_string(availableBalance), "green") << "\n\n";
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


	static clsBankClient  _CheckAccountBeforeContinue()
	{

		string AccountNumber = "";
		clsBankClient Client = clsBankClient::EmptyObjForInitializing(); // client1

		// checking  if  the account of client is existing
		AccountNumber = clsInputAndValidation::read_string("\nEnter Account Number: ");
		while (!(clsBankClient::ReturnCurrentClient_if_ItExists(AccountNumber, Client)))  // isn't existing 
		{
			screen_color(red);
			cout << "\n\n\aThe Account Number " << AccountNumber << " Isn't Existing !\a" << endl;
			AccountNumber = clsInputAndValidation::read_string("\nEnter Account Number: ");
		}

		return Client;
	}


public :
	static void TransFerBetween2Clients()
	{
		clsScreen::_PrintMenuOption(colorText("  Transfer Between 2 Clients Screen", "pink"));


		clsBankClient ClientWhoWillSend = _CheckAccountBeforeContinue(); // client1

		// if it found
		screen_color(black);
		system("cls");
		clsUtilClientBalance::PrintClientBalanceRecord(ClientWhoWillSend); // print the client who will send screen 

		double PerAmountOfClient = ClientWhoWillSend.GetBalance();
		double amount = 0.0; // From ClientWhoWillSend --  balance  - the sum of money 
		short Trials = 0;

		// Make Sure entered the correct amount , Will Force you To Enter Amount You have Only and give you trials 
		while (true) { 
			Trials++;
			cout << "\n\n\t\t\t\t" << "Enter The Amount You Want To Send To Another Client:  ";
			amount = clsInputAndValidation::enter_postive_number( ""); 
			
			if ((PerAmountOfClient >= amount)) break; // correct amount 

			else { system("cls");    _PrintWithdrawFailed(amount, PerAmountOfClient); }
			
			if (Trials > 4) {
				system("cls");
				cout << "\a\n\n\n\t\t\t\t" << colorText("YOU ENTERTED WRONG WITHDRAW AMOUNT FOR ", "red") << colorText( to_string(Trials),"red") << colorText(" Times THE OPERATION FAILED!\n", "red");
				_PrintWithdrawFailed(amount, PerAmountOfClient);
				return; // End the operation 
			}


		}


         clsBankClient::enSaveMode SaveStatus = clsBankClient::enSaveMode::FailedOrEmptyObj; // initialize 
		 clsBankClient ClientWhoWillReceive = clsBankClient::EmptyObjForInitializing();
		 bool Confirmed = false; 

		// ClientWhoWillSend ---> withdraw from him
		if (  (Confirmed= clsInputAndValidation::Confirm(colorText("\n\t\t\t\tAre You Sure [y],[n]: ","red"))  )   )
		{
			
			system("cls");
			clsBankClient::enSaveMode  WasDepositDone = clsBankClient::enSaveMode::FailedOrEmptyObj; // check if the withdraw from who will send done or not 

			clsScreen::_PrintMenuOption(colorText("     The Client Who Will Receive", "cyan"));
			ClientWhoWillReceive = _CheckAccountBeforeContinue(); // check if the second account is existing  -- > if found it who will receive will have the  object

			// check before continuing 
			if (ClientWhoWillReceive.GetAccountNumber() == ClientWhoWillSend.GetAccountNumber()) {
				system("color 0F");
				system("cls");
				cout << colorText(" \n\n\t\t\t\t\aYOU CANN'T TRANSFER TO YOURSELF!!!!", "red") << "\n";
				// undo --> return;
				return;
			}

			// check if the withdraw done
			if (clsManageClientBalance::WithDraw(ClientWhoWillSend, amount) == clsBankClient::enSaveMode::SuccessedToSave )
			{

			           // then  start depositing 
				if (clsManageClientBalance::Deposit(ClientWhoWillReceive, amount) == clsBankClient::enSaveMode::FailedOrEmptyObj)
				{// undo deposit if failed to save the change on file 
					clsManageClientBalance::WithDraw(ClientWhoWillReceive, amount); 	cout << colorText("\n\n\a\t\t\t\t\DEPOSIT FAILED !\n","red");
					return; 
				}

			}
			else {   // if not 
				cout << "\n\n\a\t\t\t\t\tWITHDRAW FAILED !\n";
				clsManageClientBalance::Deposit(ClientWhoWillSend, amount);  // return the amount that he withdrawal
				return; 
			}

		}

		if (!Confirmed) cout << colorText("\n\n\t\t\t\t\tNO CHANGE!\n","pink"); // if not confirmed by y 
		else {

			if (clsBankClient::enSaveMode::SuccessedToSave == SaveStatus)
			{
				system("cls");
				screen_color(black);
				_PrintSuccess(ClientWhoWillSend, ClientWhoWillReceive, amount);
			}

			else
			{
				_PrintTransferFailed(ClientWhoWillSend, ClientWhoWillReceive, amount, ClientWhoWillSend.GetBalance());
			}

		}


	};

};