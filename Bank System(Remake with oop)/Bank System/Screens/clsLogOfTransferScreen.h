#pragma once

class clsTransferLogScreen : protected clsScreen
{


private :

        static void _PrintHeader() {
            int leftPadding = 20;

            // Print header with proper widths
            std::cout << setw(leftPadding) << "" << "| " << left << colorText("Time - Date", "lightpurple") << setw(14) << "";
            std::cout << "| " << left << colorText("Who Send", "lightpurple") << setw(12) << "";
            std::cout << "| " << left << colorText("Who Received", "lightpurple") << setw(8) << "";
            std::cout << "| " << left << colorText("Amount", "lightpurple") << setw(9) << "";
            std::cout << "| " << left << colorText("Sender Balance", "lightpurple") << setw(6) << "";
            std::cout << "| " << left << colorText("Receiver Balance", "lightpurple") << setw(4) << "";
            std::cout << "| " << left << colorText("Done By", "lightpurple") << setw(8) << "";
            std::cout << "|\n";

            std::cout << setw(leftPadding) << "" << string(140, '_') << "\n" << endl;
        }

        static void _PrintRecord(clsManageClientBalance::stLogTransfer & Record) {
            int leftPadding = 20;

            std::cout << setw(leftPadding) << "" << "| " << left << setw(23) << Record.TimeAndDate;
            std::cout << "| " << left << setw(20) << Record.TheAccountWhoWillSend.GetFullName();
            std::cout << "| " << left << setw(20) << Record.TheAccountWhoWillReceive.GetFullName();
            std::cout << "| " << left << setw(15) << Record.Amount;
            std::cout << "| " << left << setw(20) << Record.TheAccountWhoWillSend.GetBalance();
            std::cout << "| " << left << setw(20) << Record.TheAccountWhoWillReceive.GetBalance();
            std::cout << "| " << left << setw(15) << Record.TheUserWhoDidItTransaction.GetUserName();
            std::cout << "|\n";
        }


public:
	static void ShowLogTransferScreen()
	{
		clsScreen::_PrintMenuOption(colorText("      Log Of Transfer Screen", "orange"));

		vector<clsManageClientBalance::stLogTransfer> Records = clsManageClientBalance::VectorThatHaveAllTransactionsRecords();

		_PrintHeader();                                 //header 

		if(Records.empty() )    std::cout << colorText("\a\n\t\t\t\tNo Users Available In the System!", "red") << endl;

		else
		{
			for (clsManageClientBalance::stLogTransfer& R : Records) _PrintRecord(R);
			
			std::cout << "\n_____________________________________________________________________________________________________________________\n" << endl;
		}
	
	}



};