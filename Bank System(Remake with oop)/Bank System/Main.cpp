#include <iostream>
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h";
#include "AllClasses.h" 
#include<string>
 
using namespace std;

char EnterChar() {
	char c;
	cin >> c;
	return toupper(c);
}

void  EnterNewDataToUpdate(clsBankClient &Temp) {

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

	 double balance  = clsInputAndValidation::enter_postive_number("\nEnter Balance: ");
	 Temp.SetBalance(balance);

	 
}

void UpdateClientInfo() {

	string AccountNumber="";
	AccountNumber = clsInputAndValidation::read_string("Enter Account Number: ");
	clsBankClient client = clsBankClient::EmptyObjForInitializing();
	
	// if the account isn't exisiting 
	while ( !(clsBankClient::ReturnCurrentClient_if_ItExists(AccountNumber, client)) ) {
		screen_color(red);
		cout << "\a\nAccount number: " << AccountNumber << " isn't exising!" << endl;
			cout << "Try agian !\n";
		AccountNumber = clsInputAndValidation::read_string("Enter Account Number: ");
	}

	// it will exit loop only if it found the desired account number 
	screen_color(black);
	cout << "\nCurrent Client Info: ";
	client.Print();

	cout << "\nUpdate Info\n";
   EnterNewDataToUpdate(client); // take the new data and set them to the object

   clsBankClient::enSaveMode FinalSave;
   FinalSave = client.Save();
  
   if (FinalSave == clsBankClient::enSaveMode::SuccessedToSave) {
	   screen_color(green);
	   cout << "saved successfully!" << endl;
   }
   else {
	   screen_color(red);
	   cout << "failed  to save!" << endl;
   }


}

void AddNewClient() {

	string AccountNumber = "";
	AccountNumber = clsInputAndValidation::read_string("Enter account number: ");
	while (clsBankClient::IsClientExist(AccountNumber)) 
	{
		cout << "\a\nThe client with account number : " << AccountNumber << " is exist \n please enter vaild account number!\n";
		AccountNumber = clsInputAndValidation::read_string("Enter account number: ");
	}

	// if account isn't existing 
	clsBankClient client = clsBankClient::InitializeToAddNewClient();
	
	cout << "\nAdd New Client \n";
	EnterNewDataToUpdate(client);
	client.SetAccountNumber(AccountNumber);

	clsBankClient::enSaveMode SaveStatus;
	SaveStatus = client.Save();

	if (SaveStatus == clsBankClient::enSaveMode::FailedOrEmptyObj) cout << "Failed to save\a\n";
	else if (SaveStatus == clsBankClient::AccountNumberExists) cout << "Account number is already exists so failed to save!\n\a";
	else cout << "saved to file !\n";

}

void DeleteClient() 
{
	string AccountNumber = "";
	AccountNumber = clsInputAndValidation::read_string("Enter account number");
	while (! (clsBankClient::IsClientExist(AccountNumber))) { // if account isn't exist then you should enter exist account number 
		cout << "\nAccount number " << AccountNumber << " isn't exist please enter correct account number !";
		AccountNumber = clsInputAndValidation::read_string("Enter account number");
	}

	cout << "\nAre you sure?[y],[n]\n";
	char choice = EnterChar();
	
	if (choice == 'Y') {
		 // call delete here 

	}


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
	//	cout << "Isn't exisitting \a\n";
	//}

	//cout << "___________________\n";
	//clsBankClient Client3 = clsBankClient::Find("A101", "3113");
	//Client3.Print();


	//UpdateClientInfo();

	AddNewClient();

	return 0; 
}