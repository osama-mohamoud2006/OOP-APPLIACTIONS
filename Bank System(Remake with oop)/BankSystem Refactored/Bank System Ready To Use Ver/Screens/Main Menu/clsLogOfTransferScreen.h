#pragma once

class clsTransferLogScreen : protected clsScreen
{


private:

	static void _PrintHeader() {
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(8) << "User";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

	static void PrintTransferLogRecordLine(clsManageClientBalance::clsGetHistoryOfTransfer TransferLogRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.TimeAndDate();
		cout << "| " << setw(8) << left << TransferLogRecord.TheAccountWhoWillReceive();
		cout << "| " << setw(8) << left << TransferLogRecord.TheAccountWhoWillSend();
		cout << "| " << setw(8) << left << TransferLogRecord.AmountOfTransfer();
		cout << "| " << setw(10) << left << TransferLogRecord.TheBalanceWhoWillSendBalance();
		cout << "| " << setw(10) << left << TransferLogRecord.TheAccountWhoWillReceive();
		cout << "| " << setw(8) << left << TransferLogRecord.TheUserWhoDidItTransactionUserName();

		cout << endl;
	}

public:
	static void ShowLogTransferScreen()
	{
		clsScreen::_PrintMenuOption(colorText("        Log Of Transfer Screen", "orange"));

		vector<clsManageClientBalance::clsGetHistoryOfTransfer> Records = clsManageClientBalance::clsGetHistoryOfTransfer::VectorThatHaveAllTransactionsRecords();

		         _PrintHeader();                            //header 

		if(Records.empty() )    std::cout << colorText("\a\n\t\t\t\tNo Users Available In the System!", "red") << endl;

		else
		{
			for (clsManageClientBalance::clsGetHistoryOfTransfer& R : Records) PrintTransferLogRecordLine(R);
			
			std::cout << "\n_____________________________________________________________________________________________________________________\n" << endl;
		}
	
	}


};