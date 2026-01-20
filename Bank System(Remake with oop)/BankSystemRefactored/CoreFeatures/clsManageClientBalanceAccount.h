#pragma once
#include "CoreFeatures/clsBankClient.h"

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
		std::vector<clsBankClient> clients = clsBankClient::GetAllClientsInVector(); // Fill Vector With All Clients 
		double total = 0.0;
		for (clsBankClient c : clients) { total += c.GetBalance(); }
		return total;
	}


private:
	static std::string _Delmi ;
	static std::string  _LogFileName;
	static std::string _LogRecord(clsBankClient &TheAccountWhoWillSend , clsBankClient &TheAccountWhoWillReceive, double Amount ,  clsUser &TheUserWhoDidItTransaction)
	{
		return (clsDate::GetLocalDateAndTime() + _Delmi + TheAccountWhoWillSend.GetAccountNumber() + _Delmi + TheAccountWhoWillReceive.GetAccountNumber() + _Delmi + std::to_string(Amount) + _Delmi + std::to_string(TheAccountWhoWillSend.GetBalance()) + _Delmi   + std::to_string(TheAccountWhoWillReceive.GetBalance())+ _Delmi + TheUserWhoDidItTransaction.GetUserName() );
	}
	
	static void _RegisterTransactionLogToFile(clsBankClient& TheAccountWhoWillSend, clsBankClient& TheAccountWhoWillReceive, double Amount, clsUser& TheUserWhoDidItTransaction) { // write log to file 

		std::fstream write;
		write.open(_LogFileName,std::ios::out | std::ios::app);
		if (write.is_open())
		{
			write <<  _LogRecord(TheAccountWhoWillSend, TheAccountWhoWillReceive, Amount, TheUserWhoDidItTransaction) << std::endl;
			write.close();
		}
		else write.close();
	}

	public:
		// class to get the file contents of history on vector 
		class clsGetHistoryOfTransfer final {

		private :
			std::string DateTime = "";
			std::string  AccountNumberOfWhoWillSend="";
			std::string  AccountNumberOfWhoWillReceive="";

			double Amount = 0.0;

			double BalanceOfWhoWillSend = 0.0;
			double BalanceOfWhoWillReceive = 0.0;

			std::string UserWhoDidTheOperation = "";



		private :
			clsGetHistoryOfTransfer(std::string DateTime, std::string AccountNumberOfWhoWillSend, std::string AccountNumberOfWhoWillReceive, double amount , double BalanceOfWhoWillSend, double BalanceOfWhoWillReceive , std::string UserWhoDidTheOperation ){
				this->DateTime = DateTime;
				this->AccountNumberOfWhoWillSend = AccountNumberOfWhoWillSend;
				this->AccountNumberOfWhoWillReceive = AccountNumberOfWhoWillReceive;
				this->Amount = amount;
				this->BalanceOfWhoWillSend = BalanceOfWhoWillSend;
				this->BalanceOfWhoWillReceive = BalanceOfWhoWillReceive;
				this->UserWhoDidTheOperation = UserWhoDidTheOperation;


			}


			 private: 
				 // convert record to obj 
            static clsGetHistoryOfTransfer  _RecordToClsLogTransferObj(std::string Line) 
      {
       clsString::SetDelmi(_Delmi);
   	std::vector< std::string> Records = clsString::SplitString(Line); 
   	    
	return  clsGetHistoryOfTransfer(Records[0], Records[1], Records[2], std::stoi(Records[3]), std::stoi(Records[4]), std::stoi(Records[5]), Records[6]);

      }


		public:

			std::string  TimeAndDate() const { return DateTime; }

			std::string TheAccountWhoWillSend() const  { return AccountNumberOfWhoWillSend; }
			std::string TheAccountWhoWillReceive() const { return AccountNumberOfWhoWillReceive; }

			double AmountOfTransfer() const  { return Amount; }

			double TheBalanceWhoWillSendBalance() const  { return BalanceOfWhoWillSend; }
			double TheBalanceWhoWillReceiveBalance() const  { return BalanceOfWhoWillReceive; }

			std::string TheUserWhoDidItTransactionUserName() const  { return UserWhoDidTheOperation; }

			static std::vector< clsGetHistoryOfTransfer> VectorThatHaveAllTransactionsRecords()
			{
				std::vector< clsGetHistoryOfTransfer> AllLogs;
				std::fstream read;
				read.open(_LogFileName, std::ios::in); //read mode
				if (read.is_open())
				{
					std::string Record = "";
					while (std::getline(read, Record))
					{
						AllLogs.push_back(_RecordToClsLogTransferObj(Record));
					}
					read.close();
				}
				else read.close();

				return AllLogs;
			}


		};




};
std::string clsManageClientBalance::_Delmi = "#//#";
std::string clsManageClientBalance::_LogFileName = "TransferLog.text";