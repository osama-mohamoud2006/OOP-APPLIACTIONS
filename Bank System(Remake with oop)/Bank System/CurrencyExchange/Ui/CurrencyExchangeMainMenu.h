#pragma once

class clsCurrencyMenu : protected clsScreen
{

private:
	enum enCurrencyOp { eNone = 0, eListCurrenices = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalc = 4, BackToMainMenu = 5 };

	static void _EMainMenu() {

		std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << "\t[1] Show Currencies List.\n";
		std::cout << setw(37) << left << "" << "\t[2] Find Currencies.\n";
		std::cout << setw(37) << left << "" << "\t[3] Update Rate Currency.\n";
		std::cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		std::cout << setw(37) << left << "" << "\t[5] Back To Main Menu.\n";
		std::cout << setw(37) << left << "" << "===========================================\n";
	}
	static  void  _BackToMenuAgain() {
		std::cout << colorText("\n\n\n\t\t\t\t To Back To Currency Menu ", "red");
		system("pause");
	}

	//1 ()
	static void _ListCurrenciesScreen() {
		cout << "\n\n\n\n\n\t\t\t\t\tWill BE LIST CURRENCIES SOOON!!!!\n";
	}

	//2 ()
	static void  _FindCurrency()
	{
		cout << "\n\n\n\n\n\t\t\t\t\tWill BE FIND CURRENCY SOOON!!!!\n";
	}

	static void 

	static enCurrencyOp _PerformOption(enCurrencyOp Option )
	{
         system("cls");
		switch (Option)
		{
			
		case enCurrencyOp::eListCurrenices:
		{
			_ListCurrenciesScreen();
			_BackToMenuAgain();
			break;
		}

		case enCurrencyOp::eFindCurrency:
		{
			_FindCurrency();
			_BackToMenuAgain();
			break;
		}

		case enCurrencyOp::eUpdateRate:
		{

			_BackToMenuAgain();
			break;
		}

		case enCurrencyOp::eCurrencyCalc:
		{

			_BackToMenuAgain();
			break;
		}

		case enCurrencyOp::BackToMainMenu:
		{
			return enCurrencyOp::BackToMainMenu; 
		}


		}

		return Option;
	}


public:
	static void ShowCurrencyMenu() 
	{
		enCurrencyOp Option = enCurrencyOp::eNone;
		while (Option != enCurrencyOp::BackToMainMenu)
		{
			system("cls");
			clsScreen::_PrintMenuOption(colorText("       Currency Exchange Menu", "orange"), GCurrentUser);
			_EMainMenu();
			Option =  _PerformOption((enCurrencyOp)clsInputAndValidation::enter_number_from_to(1, 5, "\n\t\t\t\t\tEnter Option"));//Perform According To Option                                 
		}

	}


};