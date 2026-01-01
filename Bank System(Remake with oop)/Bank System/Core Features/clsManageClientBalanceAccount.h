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
		return (clsDate::GetLocalDateAndTime() + _Delmi + TheAccountWhoWillSend.GetAccountNumber() + _Delmi + TheAccountWhoWillReceive.GetAccountNumber() + _Delmi + to_string(Amount) + _Delmi + to_string(TheAccountWhoWillSend.GetBalance()) + _Delmi   + to_string(TheAccountWhoWillReceive.GetBalance())+ _Delmi + TheUserWhoDidItTransaction.GetUserName() );
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

	public:

		class clsLogOfTransfer {

		private :
			string DateTime = "";
			string  AccountNumberOfWhoWillSend="";
			string  AccountNumberOfWhoWillReceive="";

			double Amount = 0.0;

			double BalanceOfWhoWillSend = 0.0;
			double BalanceOfWhoWillReceive = 0.0;

			string UserWhoDidTheOperation = "";



		private :
			clsLogOfTransfer(string DateTime, string AccountNumberOfWhoWillSend, string AccountNumberOfWhoWillReceive, double amount , double BalanceOfWhoWillSend, double BalanceOfWhoWillReceive , string UserWhoDidTheOperation ){
				this->DateTime = DateTime;
				this->AccountNumberOfWhoWillSend = AccountNumberOfWhoWillSend;
				this->AccountNumberOfWhoWillReceive = AccountNumberOfWhoWillReceive;
				this->Amount = amount;
				this->BalanceOfWhoWillSend = BalanceOfWhoWillSend;
				this->BalanceOfWhoWillReceive = BalanceOfWhoWillReceive;
				this->UserWhoDidTheOperation = UserWhoDidTheOperation;


			}


			 private:
      static clsLogOfTransfer  _RecordToStructLog(string Line) 
      {
       clsString::SetDelmi(_Delmi);
   	vector< string> Records = clsString::SplitString(Line); 
   	    
	return  clsLogOfTransfer(Records[0], Records[1], Records[2], stoi(Records[3]), stoi(Records[4]), stoi(Records[5]), Records[6]);

      }


		public:

			string  TimeAndDate() { return DateTime; }

			string TheAccountWhoWillSend() { return AccountNumberOfWhoWillSend; }
			string TheAccountWhoWillReceive() { return AccountNumberOfWhoWillReceive; }

			double AmountOfTransfer() { return Amount; }

			double TheBalanceWhoWillSendBalance() { return BalanceOfWhoWillSend; }
			double TheBalanceWhoWillReceiveBalance() { return BalanceOfWhoWillReceive; }

			string TheUserWhoDidItTransactionUserName() { return UserWhoDidTheOperation; }

			static vector< clsLogOfTransfer> VectorThatHaveAllTransactionsRecords()
			{
				vector< clsLogOfTransfer> AllLogs;
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






};
string clsManageClientBalance::_Delmi = "#//#";
string clsManageClientBalance::_LogFileName = "TransferLog.text";