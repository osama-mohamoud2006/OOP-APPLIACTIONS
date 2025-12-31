#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"

class clsManageClientBalance {
private :
	
	// if the amount < 0 then return true 
	static bool  _IsNegative(double amount) {
		return ( amount < 0  ) ? true : false; 
	}

	// if the client balance < amount you want to withdraw then return true 
	static bool _IsCurrentBalanceLessThanAmount(double amount, clsBankClient &Temp) {
		return (Temp.GetBalance() < amount) ? true : false;
	}

public: 
	static  clsBankClient::enSaveMode  Deposit(clsBankClient & Client,double amount) {
		double OldBalance = Client.GetBalance();

		if (_IsNegative(amount)) return clsBankClient::enSaveMode::FailedOrEmptyObj;

		double NBalance  = Client.GetBalance()+amount; // Get the current account balance and it new amount to it

		Client.SetBalance(NBalance);

		if (Client.Save() == clsBankClient::enSaveMode::FailedOrEmptyObj) {
			Client.SetBalance(OldBalance);
			return clsBankClient::enSaveMode::FailedOrEmptyObj;
		}

		else return clsBankClient::enSaveMode::SuccessedToSave;

	}

	static  clsBankClient::enSaveMode  WithDraw(clsBankClient& Client, double amount) {
		double OldBalance = Client.GetBalance();

		if (_IsNegative(amount) || _IsCurrentBalanceLessThanAmount(amount, Client)) return clsBankClient::enSaveMode::FailedOrEmptyObj;
		double NBalance = Client.GetBalance() - amount; // Get the current account balance and it new amount to it
		Client.SetBalance(NBalance);
		if (Client.Save() == clsBankClient::enSaveMode::FailedOrEmptyObj) { 
			Client.SetBalance(OldBalance);  
			return clsBankClient::enSaveMode::FailedOrEmptyObj;
		}

		else return clsBankClient::enSaveMode::SuccessedToSave;

	}

	// Transfer

	 enum enTransferStatus {eSuccesedToTransfer =1 , eRecieverEqualsSender=2 , eFailed=3 };

	static enTransferStatus TransferBetween2Clients(clsBankClient& WhoWIlSend, clsBankClient& WhoWillReceive , double amount )
	{

		if (WhoWIlSend.GetAccountNumber() == WhoWillReceive.GetAccountNumber()) { return enTransferStatus::eRecieverEqualsSender; }

		clsBankClient::enSaveMode ResultsOfWithdraw = WithDraw(WhoWIlSend, amount);
		switch (ResultsOfWithdraw) 
		{
		case 	clsBankClient::enSaveMode::FailedOrEmptyObj: return enTransferStatus::eFailed; // withdraw  & deposit will handle itself if the balance didn't save
		case  clsBankClient::enSaveMode::SuccessedToSave:
		{ 
			clsBankClient::enSaveMode  ResultsOfDeposit = Deposit(WhoWillReceive,amount);
			return (ResultsOfDeposit == clsBankClient::enSaveMode::SuccessedToSave) ? enTransferStatus::eSuccesedToTransfer : enTransferStatus::eFailed;
		}

			}


	}


	// Total Balances

	static double GetTotalBalances() {
		vector<clsBankClient> clients = clsBankClient::GetAllClientsInVector(); // Fill Vector With All Clients 
		double total = 0.0;
		for (clsBankClient c : clients) { total += c.GetBalance(); }
		return total;
	}


};