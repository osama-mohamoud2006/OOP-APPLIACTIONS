#include <iostream>
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h";
#include "E:\projects\my library\AllStuff.h"
#include "AllClasses.h" 
#include <string>
#include <iomanip>
using namespace std;

///  ctrl + m+o

//46 = .
bool _CheckIfNumberIsnotFake(double amount ) 
{
	string AmountToCheck = to_string(amount);
	for (int i = 0; i < AmountToCheck.length(); i++) {

		if (AmountToCheck[i] == '.') continue; // skip the loop if the number have '.' (1.2,12.222)

		else {
	          if (!( isdigit(AmountToCheck[i]) ) ) return false;
		}

	}
	return true;
}


//balance 
void PrintClientBalanceRecord(clsBankClient Client) {

	cout << "| " << setw(15) << left << Client.GetAccountNumber();
	cout << "| " << setw(40) << left << Client.GetFullName();
	cout << "| " << setw(12) << left << Client.GetBalance();
	cout << endl;
}
void PrintBalancesClientList() {

	vector<clsBankClient> clients = clsBankClient::GetAllClientsInVector();
	string SubTitle = "\t\t   Client Balances List (" + to_string(clients.size()) + ") Client(s).";

	cout << "\n__________________________________________________________________________________________________\n\n";
	cout << SubTitle;
	cout << "\n__________________________________________________________________________________________________\n" << endl;

	cout << "| " << left << colorText("Account Number", "lightpurple") << setw(15 - 14) << "";
	cout << "| " << left << colorText("Client Name", "lightpurple") << setw(40 - 11) << "";
	cout << "| " << left << colorText("Balance", "lightpurple") << setw(12 - 7) << "";
	cout << "\n__________________________________________________________________________________________________\n" << endl;

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


int main() {

	//UpdateClientInfo();

	//AddNewClient();

	//DeleteClient();

	//PrintClientList();

	//PrintBalancesClientList();
	

	clsMainMenuScreen::_ShowMainMenuScreen();
		 return 0;

	/*cout<< _CheckIfNumberIsnotFake(1042)<<endl;*/

}
