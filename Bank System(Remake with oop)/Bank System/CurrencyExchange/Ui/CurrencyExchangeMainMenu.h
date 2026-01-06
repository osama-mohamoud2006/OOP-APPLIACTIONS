#pragma once

class clsCurrencyMenu : protected clsScreen
{

private:
	enum enCurrencyOp{eNone=0,eListCurrenices=1 , eFindCurrency=2, eUpdateRate =3  , eCurrencyCalc =4 , BackToMainMenu=5};

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

	static void _ListCurrenciesScreen() {
		cout<<""
	}

	static enCurrencyOp _PerformOption(enCurrencyOp Option )
	{

		switch (Option)
		{

		case enCurrencyOp::eListCurrenices:
		{
			_BackToMenuAgain();
			break;
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