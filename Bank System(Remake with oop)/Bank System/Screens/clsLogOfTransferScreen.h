#pragma once

class clsTransferLogScreen : protected clsScreen
{


private :
	static void _PrintHeader() {
		int leftPadding = 20; // Adjust for centering

		std::cout << setw(leftPadding) << "" << "| " << left << colorText("Time - Date", "lightpurple") << setw(25 - 11) << "";
		std::cout << "| " << left << colorText("Who Send", "lightpurple") << setw(15 - 8) << "";
		std::cout << "| " << left << colorText("Who Received", "lightpurple") << setw(15 - 8) << "";
		std::cout << "| " << left << colorText("Amount", "lightpurple") << setw(15 - 11) << "";
		std::cout << "| " << left << colorText("The Balance Of Who Send After Transferring", "lightpurple") << setw(15 - 8) << "";
		std::cout << "| " << left << colorText("The Balance Of Who Recevied After Transferring", "lightpurple") << setw(15 - 8) << "";
		std::cout << "| " << left << colorText("The User Who Did The Opeartion", "lightpurple") << setw(15 - 8) << "";
		std::cout << "\n" << setw(leftPadding) << "" << "_________________________________________________________________________________\n" << endl;
	}

	static void _PrintRecord(clsManageClientBalance::stLogTransfer & Record)
	{
		cout << Record.TimeAndDate << setw(25 - 11) << "|";
		cout << Record.TheAccountWhoWillSend.GetFullName() << setw(15 - 8) << "|";
		cout<< Record.TheAccountWhoWillReceive.GetFullName() << setw(15 - 8) << "|";
		cout << Record.Amount << setw(15 - 11) << "|";
		cout<< Record.TheAccountWhoWillSend.GetBalance() << setw(15 - 11) << "|";
		cout<< Record.TheAccountWhoWillReceive.GetBalance()<<setw(15 - 11) << "|";
		cout<<Record.TheUserWhoDidItTransaction.GetUserName() << setw(15 - 11) << "|";


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
			for (clsManageClientBalance::stLogTransfer& R : Records)
			{
				_PrintRecord(R);
				cout << endl;
			}

			std::cout << "\n_____________________________________________________________________________________________________________________\n" << endl;
		}
	
	}



};