#pragma once

#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsManageClientBalanceAccount.h"

class clsTotalBalanceScreen : protected clsScreen
{

private:
	void PrintClientBalanceRecord(clsBankClient Client) {

		cout << "| " << setw(15) << left << Client.GetAccountNumber();
		cout << "| " << setw(40) << left << Client.GetFullName();
		cout << "| " << setw(12) << left << Client.GetBalance();
		cout << endl;
	}

public:

	void PrintBalancesClientList() {

		vector<clsBankClient> clients = clsBankClient::GetAllClientsInVector();
		string SubTitle = "\t\t   Client Balances List (" + to_string(clients.size()) + ") Client(s).";

            clsScreen::_PrintMenuOption("Total Balances Screen ")

		if (clients.empty()) {
			cout << colorText("\n\t\t\t\tNo Clients Available In the System!", "red") << endl;
		}
		else {

			for (const clsBankClient& c : clients) {
				PrintClientBalanceRecord(c);
			}
			cout << "\n__________________________________________________________________________________________________\n" << endl;
		}
		double total = clsBankClient::GetTotalBalances();
		cout << "\n\t\t\t\t   Total Balances = " << total << endl;
		cout << "\t\t\t\t   ( " << clsInputAndValidation::NumberToText((int)total) << ")" << endl;
	}
};