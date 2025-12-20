#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h" // core 
#include   "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsManageClientBalanceAccount.h" // core -- > WithDraw 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsUtilPrintClientBalance.h"

class clsWithDrawScreen : protected clsScreen
{
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

public:

    static void ShowWithDrawFromClientScreen() 
    {

		clsScreen::_PrintMenuOption(colorText("            WithDraw Screen", "yellow"));
		string AccountNumber = "";
		AccountNumber = clsInputAndValidation::read_string("\nEnter Account Number: ");
		clsBankClient Client = clsBankClient::EmptyObjForInitializing();

		while (!(clsBankClient::ReturnCurrentClient_if_ItExists(AccountNumber, Client))) // if the client isn't existing ask for entering the account number again 
		{
			screen_color(red);
			cout << "\n\n\aThe Account Number " << AccountNumber << " Isn't Existing !\a" << endl;
			AccountNumber = clsInputAndValidation::read_string("\nEnter Account Number: ");
		}

		system("cls");
		// if account is existing
		screen_color(black);
		clsUtilClientBalance::PrintClientBalanceRecord(Client);    //print balance details

		double amount = clsInputAndValidation::enter_postive_number("\n\n\t\t\t\tEnter The Amount You Want To WithDraw: ");
		double PerBalance = Client.GetBalance();

		if (clsInputAndValidation::Confirm(colorText("\n\n\t\t\t\tYou Are About WithDrawing " + to_string(amount) + " Are You Sure [y],[n]: ", "cyan")))
		{
			clsBankClient::enSaveMode SaveStatus;
			SaveStatus = clsManageClientBalance::WithDraw(Client, amount); // withdraw and Return Save Status

			if (clsBankClient::enSaveMode::SuccessedToSave == SaveStatus) {
				system("cls");
				_PrintWithdrawSuccessful();
				clsUtilClientBalance::PrintClientBalanceRecord(Client, PerBalance);    //print balance details
			}
			else {
				system("cls");
	      _PrintWithdrawFailed(amount, PerBalance);
			}
			
		}

		else {
			cout << "\n\n\t\t\t\t Okay No Change ;)" << endl;
		}
   }



};

