#pragma once 

class clsUtilBoolFindClient {


public:
	static bool FindClientAndReturnTrue_If_Exists(string Message ,string AccountNumber , clsBankClient &client) 
	{
        short Trials = 0; 
        while ((clsBankClient::ReturnCurrentClient_if_ItExists(AccountNumber, client))) // if exists 
        { 
            screen_color(red);
            cout << "\n\aAccount number: " << AccountNumber << Message;
            AccountNumber = clsInputAndValidation::read_string("\nEnter account number: ");
        }

	}


};
