#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsDepositScreen.h"
#include  "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsWithDrawScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsFindAccountBalanceScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsTransferBetween2Clients.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsTotalBalancesScreen.h"
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h";
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsUser.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsLogOfTransferScreen.h"


class clsTransactionMenu : clsScreen {

private:

	enum _enTransactionMenuElements
	{	eNone=0,eDeposit=1,eWithDraw=2,eTotalBalances=3,eFindClientBalance=4,eTransferBetween2Clients=5,  eTransferLog=6 ,eBackToMainMenu=7  };

	static void _ETransactionsMenu() {
	
		//std::cout << setw(37) << left << "" << "===========================================\n";
		//std::cout << setw(37) << left << "" << colorText("\t\t\Transactions Menu\n","orange");
		//std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		std::cout << setw(37) << left << "" << "\t[2] WithDraw.\n";
		std::cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		std::cout << setw(37) << left << "" << "\t[4] Find Account Balances.\n";
		std::cout << setw(37) << left << "" << "\t[5] Transfer Between 2 Clients.\n";
		std::cout << setw(37) << left << "" << "\t[5] Transfer Between 2 Clients Log.\n";
		std::cout << setw(37) << left << "" << "\t[7] Main Menu.\n";
		
		std::cout << setw(37) << left << "" << "===========================================\n";

	}
	static  void  _BackToTransactionsMenuAgain() {
		std::cout << colorText("\n\n\n\t\t\t\t To Back To Transactions Menu ", "red");
		system("pause");
	}


	 /// Features in the screen
	
	//1 (done)
	static void _ShowDepositScreen(){
	/*	cout << "\nWill Be Deposit Screen Soon!\n";*/
		clsDepositScreen::ShowDepositBalanceFromClientScreen();
	}

	//2 (done)
	static void _ShowWithDrawScreen() {
		//cout << "\nWill Be WithDraw Screen Soon!\n";
		clsWithDrawScreen::ShowWithDrawFromClientScreen();

	}

	//3 (done)
	static  void _ShowTotalBalancesScreen() {
	/*	cout << "\nWill Be Show Total Balances Screen Soon!\n";*/
		clsTotalBalanceScreen::PrintBalancesClientList();
	}


	//4  (done)
	static void _ShowFIndClientBalanceScreen() {
		clsFindAccountBalanceScreen::FindClientByAccountNumberToGetHisBalance();
	}

	//5 (done)
	static void _ShowTransferBetween2ClientsScreen() {
		clsTransferBetween2UsersScreen::TransFerBetween2Clients();
	}

	//6 ()
	static void _ShowTransferLogScreen() {
		clsTransferLogScreen::ShowLogTransferScreen();
	}

	static _enTransactionMenuElements _PerformOptionInTransactionMenu(_enTransactionMenuElements option) 
	{
		system("cls"); // just clear screen on every option call 
		switch (option)
		{

		case _enTransactionMenuElements::eDeposit: { //1
			_ShowDepositScreen();
			_BackToTransactionsMenuAgain();
			break;
		};

		case _enTransactionMenuElements::eWithDraw: { //2
			_ShowWithDrawScreen();
			_BackToTransactionsMenuAgain();
			break;
		};

		case _enTransactionMenuElements::eTotalBalances: { //3 
			_ShowTotalBalancesScreen();
			_BackToTransactionsMenuAgain();
			break;
		};

		case 	_enTransactionMenuElements::eFindClientBalance: { //4 
			_ShowFIndClientBalanceScreen();
			_BackToTransactionsMenuAgain();
			break;
		}

		case _enTransactionMenuElements::eTransferBetween2Clients: { //5 
			_ShowTransferBetween2ClientsScreen();
			_BackToTransactionsMenuAgain();
			break;
		}

		case _enTransactionMenuElements::eTransferLog:
		{
			_ShowTransferLogScreen();
			_BackToTransactionsMenuAgain();
			break;
		}

		case _enTransactionMenuElements::eBackToMainMenu: { //7
			return _enTransactionMenuElements::eBackToMainMenu;
		}


		};

		return option;
	}

public :
	static void ShowTransactionMenu() {

		if (!clsScreen::HavePermission(clsUser::enUserPermission::eTransactions) ) { // if he hasn't per 
			cout << "\n\t\t\t\t\t";  system("pause"); // to fix clear screen   if per isn't allowed 
			return; 
		} 

		_enTransactionMenuElements Option = eNone; // just for initializing 

		while (Option != _enTransactionMenuElements::eBackToMainMenu) // if the option isn't main menu just call them again 
		{
			system("cls");
			cout << "\n\n";
			clsScreen::_PrintMenuOption(colorText("\t  Transactions Menu", "orange"),GCurrentUser);
			_ETransactionsMenu(); // show elements of menu 
			std::cout << setw(37) << left << "" << "Enter Option";
			Option = _PerformOptionInTransactionMenu((_enTransactionMenuElements)clsInputAndValidation::enter_number_from_to(1, 7, ""));
		}

	}


};