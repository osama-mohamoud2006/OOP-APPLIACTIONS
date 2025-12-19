#include <iostream>
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h";
#include "E:\projects\my library\AllStuff.h"
#include "AllClasses.h" 
#include <string>
#include <iomanip>
using namespace std;

///  ctrl + m+o




//void UpdateClientInfo() {
//
//	string AccountNumber="";
//	AccountNumber = clsInputAndValidation::read_string("Enter Account Number: ");
//	clsBankClient client = clsBankClient::EmptyObjForInitializing();
//	
//	// if the account isn't exisiting 
//	while ( !(clsBankClient::ReturnCurrentClient_if_ItExists(AccountNumber, client)) ) {
//		screen_color(red);
//		cout << "\a\nAccount number: " << AccountNumber << " isn't exising!" << endl;
//			cout << "Try agian !\n";
//		AccountNumber = clsInputAndValidation::read_string("Enter Account Number: ");
//	}
//
//	// it will exit loop only if it found the desired account number 
//	screen_color(black);
//	cout << "\nCurrent Client Info: ";
//	_PrintBasicPersonData();
//
//	cout << "\nUpdate Info\n";
//   _EnterNewDataToUpdate(client); // take the new data and set them to the object
//
//   clsBankClient::enSaveMode FinalSave;
//   FinalSave = client.Save();
//  
//   if (FinalSave == clsBankClient::enSaveMode::SuccessedToSave) {
//	   screen_color(green);
//	   cout << "saved successfully!" << endl;
//   }
//   else {
//	   screen_color(red);
//	   cout << "failed  to save!" << endl;
//   }
//
//
//}






//void DeleteClient() 
//{
//	string AccountNumber = "";
//	AccountNumber = clsInputAndValidation::read_string("Enter account number: ");
//	clsBankClient client = clsBankClient::EmptyObjForInitializing();
//	while (! (clsBankClient::ReturnCurrentClient_if_ItExists(AccountNumber,client))) { // if account isn't exist then you should enter exist account number 
//		cout << "\n\aAccount number:  " << AccountNumber << " isn't exist please enter correct account number !\n";
//		AccountNumber = clsInputAndValidation::read_string("Enter account number: ");
//	}
//
//	cout << "\nAre you sure?[y],[n]\n";
//	char choice =clsInputAndValidation:: EnterChar();
//	
//	if (choice == 'Y' && client.DeleteClient()) {
//		 // call delete here 
//		cout << "deleted successfully!\n";
//		client.PrintBasicPersonData();
//	}
//	else {
//		cout << "No change!\n";
//		client.PrintBasicPersonData();
//	}
//
//
//}

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
}
