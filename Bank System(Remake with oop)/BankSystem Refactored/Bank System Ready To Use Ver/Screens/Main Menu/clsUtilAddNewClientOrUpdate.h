#pragma once

class clsUtilAddOrUpdateClient {


public:

	static void EnterDataOfClient(clsBankClient& Temp) 
	{
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

		double balance = clsInputAndValidation::clsReadNum<double>::enter_postive_number("\nEnter Balance: ");
		Temp.SetBalance(balance);
	}


};