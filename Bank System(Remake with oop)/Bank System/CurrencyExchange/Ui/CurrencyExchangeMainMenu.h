#pragma once

class clsCurrencyMenu
{

private:
	enum enCurrencyOp{eListCurrenices=1 , eFindCurrency=2, eUpdateRate =3  , eCurrencyCalc =4 , BackToMainMenu=5};

	static void _EMainMenu() {

		std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
	
		std::cout << setw(37) << left << "" << "===========================================\n";

	}
	static  void  _BackToMainMenuAgain() {
		std::cout << colorText("\n\n\n\t\t\t\t To Back To Currency Menu ", "red");
		system("pause");
	}




};