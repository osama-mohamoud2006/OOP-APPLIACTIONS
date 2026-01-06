#include <iostream>
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h"
#include "E:\projects\my library\AllStuff.h"
#include "AllClasses.h" 
#include <string>
#include <iomanip>
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Utility Library\clsUtillity.h"
using namespace std;
//  ctrl + m+o

// Good Bye done at : 2/1/2026 --> i thought it has done
// lol i started this project last year 

enum _enFindChoice{eFindByCountry=1 , eFindByCode=2 };

void _PrintChoice() {

	std::cout << setw(37) << left << "" << "===========================================\n";
	std::cout << setw(37) << left << "" << "\t[1] Find By Country Name.\n";
	std::cout << setw(37) << left << "" << "\t[2] Find By Code Of Currency.\n";
	std::cout << setw(37) << left << "" << "===========================================\n";
}


void PrintCurrencyInfo(clsCurrencyExchange& c)
{
	system("cls");
	// Get terminal width and calculate padding
	int terminalWidth = 120;
	int contentWidth = 48;
	int leftPadding = (terminalWidth - contentWidth) / 2;

	cout << "\n\n";
	cout << setw(leftPadding) << "" << colorText("================================================", "cyan") << "\n";
	cout << setw(leftPadding) << "" << "           " << colorText(">> CURRENCY CARD <<", "yellow") << "\n";
	cout << setw(leftPadding) << "" << colorText("================================================", "cyan") << "\n\n";

	cout << setw(leftPadding) << "" << colorText("  CURRENCY INFORMATION", "lightpurple") << "\n";
	cout << setw(leftPadding) << "" << "  ----------------------------------------------\n";
	cout << setw(leftPadding) << "" << "    Currency Name : " << c.GetCurrencyName() << "\n";
	cout << setw(leftPadding) << "" << "    Currency Code : " << colorText(c.GetCurrencyCode(), "cyan") << "\n";
	cout << setw(leftPadding) << "" << "    Country       : " << c.GetCountryName() << "\n\n";

	cout << setw(leftPadding) << "" << colorText("  EXCHANGE RATE", "yellow") << "\n";
	cout << setw(leftPadding) << "" << "  ----------------------------------------------\n";
	cout << setw(leftPadding) << "" << "    Current Rate  : " << colorText("1 USD = " + to_string(c.GetCurrentRate()) + " " + c.GetCurrencyCode(), "green") << "\n\n";

	cout << setw(leftPadding) << "" << colorText("================================================", "cyan") << "\n\n";
}


void _FindCurrencyByCode() 
{
	//clsScreen::_PrintMenuOption();

	short trials = 5; 
	
	clsCurrencyExchange Currency = clsCurrencyExchange::ReturnEmptyObjForInitializing();

	string CurrencyCode = "";
	CurrencyCode = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter The Currency Code: ");

	while (!clsCurrencyExchange::ReturnCurrentObj_IfExistByCode(Currency, CurrencyCode)) // if it isn't existing 
	{
		trials--;
		//if (clsScreen::EndTheScreen(Trials)) return; 
		screen_color(red);
		cout << "\n\t\t\t\tThe Currency Code You Entered Isn't Existing!\a";
		CurrencyCode = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter The Currency Code: ");
	}

	system("color 0F");
	PrintCurrencyInfo(Currency); 

}


void _FindCurrencyByCountry() {
	//clsScreen::_PrintMenuOption();

	short trials = 5;

	clsCurrencyExchange Currency = clsCurrencyExchange::ReturnEmptyObjForInitializing();

	string CountryName= "";
	CountryName = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter The Country Name: ");

	while (!clsCurrencyExchange::ReturnCurrentObj_IfExistByCountry(Currency, CountryName)) // if it isn't existing 
	{
		trials--;
		//if (clsScreen::EndTheScreen(Trials)) return; 
		screen_color(red);
		cout << "\n\t\t\t\tThe Country Name You Entered Isn't Existing!\a";
		CountryName = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter The  Country Name: ");
	}
	system("color 0F");

	PrintCurrencyInfo(Currency);
}

void _PerformFindAccordingToChoice(_enFindChoice Choice )
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


void FindCurrency() 
{
	
	short Option = 0; 
	short Trials = 5; 
	while (true)
	{
		system("cls");
		Trials--;
		//if (clsScreen::EndTheScreen(Trials)) return; 
		// clsScreen::

		_PrintChoice(); // show the menu to choose what you  want to find 
		Option = clsInputAndValidation::enter_number_from_to(1, 2, "\t\t\t\t\tEnter Option");

		if (Option == 1 || Option == 2) break;
		else Trials++;
	}
	
	_PerformFindAccordingToChoice(_enFindChoice(Option)); // perform the find According to the user choice 

}



int main() {
	//clsCurrencyMenu::ShowCurrencyMenu();
	//FindCurrency(); 
	//clsCurrencyExchange c = clsCurrencyExchange::ReturnEmptyObjForInitializing();

	//c = clsCurrencyExchange::FindByCode("usd");
	//cout << "the country is : " << c.GetCountryName() << endl; 

	while (true) 	if (!clsLoginScreen::ShowLoginScreen()) break; 
}
