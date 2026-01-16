#pragma once
#include  "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\CurrencyExchange\Screens\clsPrintUtilCurrenctDetails.h"

class clsFindCurrencyScreen : protected clsScreen
{

private:
	enum _enFindChoice { eFindByCountry = 1, eFindByCode = 2 };

	static void _PrintChoice() {

		std::cout << setw(37) << left << "" << "===========================================\n";
		std::cout << setw(37) << left << "" << "\t[1] Find By Country Name.\n";
		std::cout << setw(37) << left << "" << "\t[2] Find By Code Of Currency.\n";
		std::cout << setw(37) << left << "" << "\t[3] Cancel.\n";
		std::cout << setw(37) << left << "" << "===========================================\n";
	}


static	void _FindCurrencyByCode()
	{
		clsScreen::_PrintMenuOption(colorText("           Find Currency By Code","yellow"));

		short trials = 5;

		vector <clsCurrencyExchange> Currency ;

		string CurrencyCode = "";
		CurrencyCode = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter The Currency Code: ");

		while (!clsCurrencyExchange::ReturnCurrentObj_IfExistByCode(Currency, CurrencyCode) ) // if it isn't existing 
		{
			trials--;
			if (clsScreen::EndTheScreen(trials)) return;
			screen_color(red);
			cout << "\n\t\t\t\tThe Currency Code You Entered Isn't Existing!\a";
			CurrencyCode = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter The Currency Code: ");
		}

		system("color 0F");
		system("cls");

		for (clsCurrencyExchange& E : Currency) 	clsUtilPrintCurrencyDetails::PrintCurrencyInfo(E);
	}
	static void _FindCurrencyByCountry() {

		clsScreen::_PrintMenuOption(colorText("         Find Currency By Country","pink"));

		short trials = 5;

		clsCurrencyExchange Currency = clsCurrencyExchange::ReturnEmptyObjForInitializing();

		string CountryName = "";
		CountryName = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter The Country Name: ");

		while (!clsCurrencyExchange::ReturnCurrentObj_IfExistByCountry(Currency, CountryName)) // if it isn't existing 
		{
			trials--;
			if (clsScreen::EndTheScreen(trials)) return; 
			screen_color(red);
			cout << "\n\t\t\t\tThe Country Name You Entered Isn't Existing!\a";
			CountryName = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter The  Country Name: ");
		}

		system("cls");
		system("color 0F");

		clsUtilPrintCurrencyDetails::PrintCurrencyInfo(Currency);
	}

	static void _PerformFindAccordingToChoice(_enFindChoice Choice)
	{

		system("cls");
		switch (Choice)
		{
		case _enFindChoice::eFindByCode:
		{
			_FindCurrencyByCode();
			break;
		}

		case _enFindChoice::eFindByCountry:
		{
			_FindCurrencyByCountry();
			break;
		}

	

		}

	}


public:
	static void FindCurrency()
	{

		short Option = 0;
		short Trials = 5;
		while (true)
		{
			system("cls");
			Trials--;
			clsScreen::_PrintMenuOption(colorText("           Find Currency","cyan"));

			if (clsScreen::EndTheScreen(Trials)) return; 
			_PrintChoice(); // show the menu to choose what you  want to find 
			Option = clsInputAndValidation::enter_number_from_to(1, 3, "\t\t\t\t\tEnter Option");

			if (Option == 1 || Option == 2 || Option ==3 ) break;
			else Trials++;
		}

		if (Option == 3) return;  // cancel  option 
		_PerformFindAccordingToChoice(_enFindChoice(Option)); // perform the find According to the user choice 

	}



};

