#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\CurrencyExchange\Core\clsCurrencyExchange.h"

class clsListCurrencies : protected clsScreen
{

private:
	static void _Header()
	{
		
			cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________________________________\n" << endl;
			cout << setw(8) << left << "" << "| " << left << colorText("Country", "lightpurple") << setw(30 - 7) << "";
			cout << "| " << left << colorText("Code", "lightpurple") << setw(8 - 4) << "";
			cout << "| " << left << colorText("Name", "lightpurple") << setw(45 - 4) << "";
			cout << "| " << left << colorText("Rate/(1$)", "lightpurple") << setw(10 - 9) << "";
			cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________________________________\n" << endl;

	}

	static void _PrintRecord(clsCurrencyExchange C)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << C.GetCountryName();
		cout << "| " << setw(8) << left << C.GetCurrencyCode();
		cout << "| " << setw(45) << left << C.GetCurrencyName();
		cout << "| " << setw(10) << left << fixed << setprecision(6) << C.GetCurrentRate();
		cout << endl;  
	}

public :
	static void ShowListCurrencies()
	{
		vector<clsCurrencyExchange> Currencies = clsCurrencyExchange::LoadFileContentOnVector();

		clsScreen::_PrintMenuOption(colorText("           Currencies List","lightpurple") );
		_Header();

		if (Currencies.empty()) cout << colorText("\n\t\t\t\t\tNO CURRENCIES IN THE SYSTEM !", "red");

		else
		{
			for (clsCurrencyExchange& c : Currencies) _PrintRecord(c); cout << endl; 
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

	}

};