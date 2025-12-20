#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"

class clsManageClientBalance {
private :


	// if the amount < 0 then return true 
	static bool  _IsNegative(double amount) {
		return ( amount < 0  ) ? true : false; 
	}

	// if the client balance < amount you want to withdraw then return false 
	static bool _CheckBeforeWithDraw(double amount, clsBankClient &Temp) {
		return (Temp.GetBalance() < amount) ? false : true;
	}

public: 
	static  clsBankClient::enSaveMode  Deposit(clsBankClient & Client,double amount) {
		if (_IsNegative(amount) ) return;
		double NBalance  = Client.GetBalance()+amount; // Get the current account balance and it new amount to it
		Client.SetBalance(NBalance); 
		return Client.Save();
		
	}

	static  clsBankClient::enSaveMode  WithDraw(clsBankClient& Client, double amount) {
		if (_IsNegative(amount)) return;
		double NBalance = Client.GetBalance() + amount; // Get the current account balance and it new amount to it
		Client.SetBalance(NBalance);
		return Client.Save();

	}

};