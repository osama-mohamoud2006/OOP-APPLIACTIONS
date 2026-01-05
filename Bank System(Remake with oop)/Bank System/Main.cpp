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
	cout << c.GetCurrencyName() << endl;
	cout << c.GetCurrencyCode() << endl;
	cout << c.GetCountryName() << endl;
	cout << c.GetCurrentRate() << endl; 
}

void _FindCurrencyByCode() 
{
	//clsScreen::_PrintMenuOption();

	short trials = 5; 
	//if (clsScreen::EndTheScreen(Trials)) return; 

	clsCurrencyExchange Currency = clsCurrencyExchange::ReturnEmptyObjForInitializing();
	string CurrencyCode = "";
	CurrencyCode = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter The Currency Code: ");

	while (!clsCurrencyExchange::ReturnCurrentObj_IfExistByCode(Currency, CurrencyCode)) // if it isn't existing 
	{
		trials--;
		cout << "\n\t\t\t\tThe Currency Code You Entered Isn't Existing!\a";
		CurrencyCode = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter The Currency Code: ");
	}

	PrintCurrencyInfo(Currency); 

}

void _PerformFindAccordingToChoice(_enFindChoice Choice )
{

	switch (Choice) 
	{
		system("cls");
	case _enFindChoice::eFindByCode: 
	{
		break; 
	}

	case _enFindChoice::eFindByCountry:
	{

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
		Option = clsInputAndValidation::enter_number_from_to(1, 2, "\t\t\t\t\tEnter Option[1],[2]: ");

		if (Option == 1 || Option == 2) break;
		else Trials++;
	}
	
	_PerformFindAccordingToChoice(_enFindChoice(Option)); // perform the find According to the user choice 

	//string CountryName = clsInputAndValidation::read_string("\n\t\t\t\t\tEnterTheCountryName: ");
}


int main() {

	//clsCurrencyExchange c = clsCurrencyExchange::ReturnEmptyObjForInitializing();

	//c = clsCurrencyExchange::FindByCode("usd");
	//cout << "the country is : " << c.GetCountryName() << endl; 

	//while (true) 	if (!clsLoginScreen::ShowLoginScreen()) break; 
}
