#pragma once

class clsTransferLogScreen : protected clsScreen
{


private :

    static void _PrintHeader() {
        int leftPadding = 20;

        std::cout << setw(leftPadding) << ""
            << left
            << "| " << setw(25) << colorText("Time - Date", "lightpurple")
            << "| " << setw(20) << colorText("Sender", "lightpurple")
            << "| " << setw(20) << colorText("Receiver", "lightpurple")
            << "| " << setw(15) << colorText("Amount", "lightpurple")
            << "| " << setw(22) << colorText("Sender Balance", "lightpurple")
            << "| " << setw(22) << colorText("Receiver Balance", "lightpurple")
            << "| " << setw(15) << colorText("User", "lightpurple")
            << "|\n";

        std::cout << setw(leftPadding) << "" << string(150, '_') << "\n" << endl;
    }

    static void _PrintRecord(clsManageClientBalance::clsLogOfTransfer& Record) {
		cout << Record.TimeAndDate() << endl;
        int leftPadding = 20;
        std::cout << setw(leftPadding) << ""
            << left
            << "| " << setw(25) << Record.TimeAndDate()
            << "| " << setw(20) << Record.TheAccountWhoWillSendFullName()
            << "| " << setw(20) << Record.TheAccountWhoWillReceiveFullName()
            << "| " << setw(15) << fixed << setprecision(2) << Record.AmountOfTransfer()
            << "| " << setw(22) << fixed << setprecision(2) << Record.TheBalanceWhoWillSendBalance()
            << "| " << setw(22) << fixed << setprecision(2) << Record.TheBalanceWhoWillReceiveBalance()
            << "| " << setw(15) << Record.TheUserWhoDidItTransactionUserName()
			<< "|\n";

    }

public:
	static void ShowLogTransferScreen()
	{
		clsScreen::_PrintMenuOption(colorText("      Log Of Transfer Screen", "orange"));

		vector<clsManageClientBalance::clsLogOfTransfer> Records = clsManageClientBalance::clsLogOfTransfer::VectorThatHaveAllTransactionsRecords();

		_PrintHeader();                                 //header 

		if(Records.empty() )    std::cout << colorText("\a\n\t\t\t\tNo Users Available In the System!", "red") << endl;

		else
		{
			for (clsManageClientBalance::clsLogOfTransfer& R : Records) _PrintRecord(R);
			
			std::cout << "\n_____________________________________________________________________________________________________________________\n" << endl;
		}
	
	}



};