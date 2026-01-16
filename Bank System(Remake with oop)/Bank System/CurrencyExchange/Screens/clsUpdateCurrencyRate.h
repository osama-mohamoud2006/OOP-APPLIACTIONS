#pragma once
#include  "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\CurrencyExchange\Screens\clsPrintUtilCurrenctDetails.h"
class clsUpdateCurrencyRateScreen : protected  clsScreen
{
	
	// 2 view the enterd currency code details if it exits
	// 3 enter the new currency 
	// 4 update the currency 

public:

	static void UpdateRateScreen()
	{
	

		string CurrencyCode = clsInputAndValidation::read_string("\t\t\t\t\tEnter Currency Code: ");
		vector <clsCurrencyExchange>  Rate ;
		short Trials = 5;

		while (clsCurrencyExchange::ReturnCurrentObj_IfExistByCode(Rate, CurrencyCode))
		{
			system("cls");
			Trials--;

			clsScreen::_PrintMenuOption(colorText("      Update Currency Rate Screen", "orange"));
			if (clsScreen::EndTheScreen(Trials)) return; // if the trials becomes 0 

			cout << "\n\t\t\t\t\tYou Entered Invalid Currency Code!\a" << endl;
			screen_color(red);
			CurrencyCode = clsInputAndValidation::read_string("\t\t\t\t\tEnter Currency Code: ");

		}

		system("color 0F");
		for(clsCurrencyExchange & c : Rate )clsUtilPrintCurrencyDetails::PrintCurrencyInfo(c); // print the rate of the currency (vector)

		// Enter New  Rate
		// confrim at first then cls then enter new ....... etc 
		cout << "\n\n";
		short NRate = clsInputAndValidation::enter_postive_number("\t\t\t\t\t\t\tEnter The New Currency Rate: ");


	}


};