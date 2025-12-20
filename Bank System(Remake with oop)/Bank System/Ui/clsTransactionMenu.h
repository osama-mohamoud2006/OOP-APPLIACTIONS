#pragma once 

class clsTransactionMenu {

private:

	enum _enTransactionMenuElements{
		eNone=0,eDeposit=1,eWithDraw=2,eTotalBalances=3,eBackToMainMenu=4};

	static void _ETransactionsMenu() {

		std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << colorText("\t\t\Transactions Menu\n","orange");
		std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		std::cout << setw(37) << left << "" << "\t[2] WithDraw.\n";
		std::cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		std::cout << setw(37) << left << "" << "\t[4] Main Menu.\n";
		
		std::cout << setw(37) << left << "" << "===========================================\n";

	}

	static  void  _BackToTransactionsMenuAgain() {
		std::cout << colorText("\n\n\n\t\t\t\t To Back To Transactions Menu ", "red");
		system("pause");
	}



	static _enTransactionMenuElements PerformOptionInTransactionMenu(_enTransactionMenuElements option) 
	{

	}


public :
	static void ShowTransactionMenu() {

		_enTransactionMenuElements Option = eNone; // just for initializing 

		while (Option != _enTransactionMenuElements::eBackToMainMenu) // if the option isn't main menu just call them again 
		{
			system("cls");
			_ETransactionsMenu(); // show elements of menu 
			std::cout << setw(37) << left << "" << "Enter Option";
			//OptionByUser = _PerformMainMenuOption((_enMainMenuOptions)clsInputAndValidation::enter_number_from_to(1, 9, ""));
		}

	}


};