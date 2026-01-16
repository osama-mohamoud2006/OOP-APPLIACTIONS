#pragma once
#include  "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\CurrencyExchange\Screens\clsPrintUtilCurrenctDetails.h"
class clsUpdateCurrencyRateScreen : protected  clsScreen
{
	
	// 2 view the enterd currency code details if it exits
	// 3 enter the new currency 
	// 4 update the currency 

private:
	static void ViewTheCountriesDetails(vector <clsCurrencyExchange>  Rate)
	{
		for (clsCurrencyExchange& c : Rate)clsUtilPrintCurrencyDetails::PrintCurrencyInfo(c); 
	}

public:

	static void UpdateRateScreen()
	{
	
		clsScreen::_PrintMenuOption(colorText("      Update Currency Rate Screen", "orange"));

		string CurrencyCode = clsInputAndValidation::read_string("\t\t\t\t\tEnter Currency Code: ");
		vector <clsCurrencyExchange>  Rate ;
		short Trials = 5;

		while (clsCurrencyExchange::ReturnCurrentObj_IfExistByCode(Rate, CurrencyCode))
		{
			Trials--;
			if (clsScreen::EndTheScreen(Trials)) return; // if the trials becomes 0 

			screen_color(red);
			cout << "\n\t\t\t\t\tYou Entered Invalid Currency Code!\a" << endl;
			CurrencyCode = clsInputAndValidation::read_string("\t\t\t\t\tEnter Currency Code: ");
		}

		system("color 0F");

		ViewTheCountriesDetails(Rate);// print the rate of the currency (vector)

		// Enter New  Rate
		if (clsInputAndValidation::Confirm(colorText("\n\t\t\t\t\t\t\tAre You Sure About Updating The Currency Rate For This/These Country(ies) ", "red")))
		{
			system("cls");
			clsScreen::_PrintMenuOption(colorText("      Updating Currency Rate......", "cyan"));

			double NRate = clsInputAndValidation::enter_postive_number("\t\t\t\t\t\t\tEnter The New Currency Rate: ");

			for (clsCurrencyExchange& c : Rate)  c.UpdateRate(NRate); // will update the currency rate for each object 

			cout << colorText("\n\t\t\t\tAll Country(ies) With The Currency Code " + CurrencyCode + " Their Rate Updated Successfully!\n","green");

			ViewTheCountriesDetails(Rate);// print the rate of the currency (vector)
		}

		else cout << colorText("\n\n\t\t\t\t\tOKAY NO CHANGE !\n","pink");



	}


};