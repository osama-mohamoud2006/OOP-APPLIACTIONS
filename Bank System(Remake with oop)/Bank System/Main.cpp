#include <iostream>
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h";
#include "AllClasses.h" 
 
using namespace std;

clsBankClient EnterNewDataToUpdate() {
	clsBankClient Temp;
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

	 return Temp;
}

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

	cout << "\nUpdate Info\n";
	client=EnterNewDataToUpdate(); // take the new data and set them to the object
	client.Update();


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