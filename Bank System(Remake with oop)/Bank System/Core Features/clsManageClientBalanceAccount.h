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

	static enTransferStatus TransferBetween2Clients(clsBankClient& WhoWIlSend, clsBankClient& WhoWillReceive , double amount  , clsUser GCURRENTUSER = GCurrentUser)
	{

		if (WhoWIlSend.GetAccountNumber() == WhoWillReceive.GetAccountNumber()) { return enTransferStatus::eRecieverEqualsSender; }

		clsBankClient::enSaveMode ResultsOfWithdraw = WithDraw(WhoWIlSend, amount);
		switch (ResultsOfWithdraw) 
		{
		case 	clsBankClient::enSaveMode::FailedOrEmptyObj: return enTransferStatus::eFailed; // withdraw  & deposit will handle itself if the balance didn't save
		case  clsBankClient::enSaveMode::SuccessedToSave:
		{ 
			clsBankClient::enSaveMode  ResultsOfDeposit = Deposit(WhoWillReceive,amount);
			if(clsBankClient::enSaveMode::FailedOrEmptyObj == ResultsOfDeposit)  Deposit(WhoWIlSend, amount); // return money to the sender if it failed to deposit 

			if (ResultsOfDeposit == clsBankClient::enSaveMode::SuccessedToSave)
			{
				_RegisterTransactionLogToFile(WhoWIlSend, WhoWillReceive, amount, GCURRENTUSER); // write transfer details on file 
				return enTransferStatus::eSuccesedToTransfer;
			}
			else return enTransferStatus::eFailed;


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


private:
	static string _Delmi ;
	static string  _LogFileName;
	static string _LogRecord(clsBankClient &TheAccountWhoWillSend , clsBankClient &TheAccountWhoWillReceive, double Amount ,  clsUser &TheUserWhoDidItTransaction)
	{
		return (clsDate::GetLocalDateAndTime() + _Delmi + TheAccountWhoWillSend.GetFullName() + _Delmi + TheAccountWhoWillReceive.GetFullName() + _Delmi + to_string(Amount) + _Delmi + to_string(TheAccountWhoWillSend.GetBalance()) + _Delmi   + to_string(TheAccountWhoWillReceive.GetBalance())+ _Delmi + TheUserWhoDidItTransaction.GetUserName() );
	}
	
	static void _RegisterTransactionLogToFile(clsBankClient& TheAccountWhoWillSend, clsBankClient& TheAccountWhoWillReceive, double Amount, clsUser& TheUserWhoDidItTransaction) {

		fstream write;
		write.open(_LogFileName,ios::out | ios::app);
		if (write.is_open())
		{
			write <<  _LogRecord(TheAccountWhoWillSend, TheAccountWhoWillReceive, Amount, TheUserWhoDidItTransaction) << endl;
			write.close();
		}
		else write.close();
	}


	 struct stLogTransfer
	{ // all objects here doesn't have def constructor so you should send parameters to the constructor to create obj from them 
		string TimeAndDate;  // ----> as a obj 
		clsBankClient TheAccountWhoWillSend = clsBankClient::EmptyObjForInitializing();
		clsBankClient TheAccountWhoWillReceive= clsBankClient::EmptyObjForInitializing();
		double Amount=0.0;
		clsUser TheUserWhoDidItTransaction= clsUser::ReturnEmptyObjForInitializingUser();

	};

	static stLogTransfer _RecordToStructLog(string Line) {
		clsManageClientBalance::stLogTransfer temp;
        clsString::SetDelmi(_Delmi);
		vector< string> Records = clsString::SplitString(Line); 
		 
		temp.TimeAndDate = Records[0];
		temp.TheAccountWhoWillSend.GetFullName() = Records[1];
		temp.TheAccountWhoWillReceive.GetFullName() = Records[2];
		temp.Amount = stoi(Records[3]);
		temp.TheUserWhoDidItTransaction.GetUserName() = Records[4];
		return temp; 

	}

	public :
		static vector< stLogTransfer> VectorThatHaveAllTransactionsRecords()
		{
			vector< stLogTransfer> AllLogs; 
			fstream read;
			read.open(_LogFileName, ios::in); //read mode
			if (read.is_open())
			{
				string Record = "";
				while (getline(read, Record))
				{
					AllLogs.push_back(_RecordToStructLog(Record));
				}
				read.close();
			}
			else read.close();

			return AllLogs;
		}


};
string clsManageClientBalance::_Delmi = "#//#";
string clsManageClientBalance::_LogFileName = "TransferLog.text";