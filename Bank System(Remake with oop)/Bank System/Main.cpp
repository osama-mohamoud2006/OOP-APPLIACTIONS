#include <iostream>
#include "AllClasses.h" 
 
using namespace std;

void UpdateClientInfo() {
	string AccountNumber="";
	AccountNumber = clsInputAndValidation::read_string("Enter Account Number: ");
	clsBankClient client = clsBankClient();
	
	// if the account isn't exisiting 
	while ( !(clsBankClient::ReturnCurrentClient_if_ItExists(AccountNumber, client)) ) {
		screen_color(red);
		cout << "\a\nAccount number: " << AccountNumber << " isn't exising!" << endl;
			cout << "Try agian !\n";
		AccountNumber = clsInputAndValidation::read_string("Enter Account Number: ");
	}
	// it will exit loop only if it found the desired account number 
	screen_color(black);
	cout << "\nCurrent Client Info: \n";
	client.Print();


}


int main() {

  //clsPerson p = clsPerson("jana", "mohmmed", "jaanaaa@gmail.com", "+20342442");
  //p.Print(); 

	//clsBankClient Client1 = clsBankClient::Find("A101");
	//Client1.Print();


	//if (clsBankClient::IsClientExist(Client1.GetAccountNumber() ,Client1.GetPin()  ))
	//{
	//	cout << "\nAccount is Exisiting!\n";
	//}

	//if (Client1.IsEmptyClientObj()) {
	//	cout << "Isn't exisiting \a\n";
	//}

	//cout << "___________________\n";
	//clsBankClient Client2 = clsBankClient::Find("245126");

	//Client2.Print();


	//if (!Client2.IsEmptyClientObj()) {
	//	cout << "Isn't exisiting \a\n";
	//}

	//cout << "___________________\n";
	//clsBankClient Client3 = clsBankClient::Find("A101", "3113");
	//Client3.Print();


	UpdateClientInfo();

	return 0; 
}