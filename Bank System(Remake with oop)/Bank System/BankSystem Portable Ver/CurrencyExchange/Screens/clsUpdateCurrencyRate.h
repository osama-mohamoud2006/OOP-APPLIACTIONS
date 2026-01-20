#pragma once
#include "CurrencyExchange/Screens/clsUtilPrintCurrencies.h"
#include  "CurrencyExchange/Screens/clsPrintUtilCurrenctDetails.h"
class clsUpdateCurrencyRateScreen : protected  clsScreen
{

public:

	static void UpdateRateScreen()
	{
	
		clsScreen::_PrintMenuOption(colorText("      Update Currency Rate Screen", "green"));

		string CurrencyCode = clsInputAndValidation::read_string("\t\t\t\t\tEnter Currency Code: ");
		if (clsString::UpperAll(CurrencyCode) == "USD")
		{
			system("cls");
			cout << colorText("\n\t\t\tThe USD Is The Main Reference For All Currencies , So You Cannot Change It !\a","red") << endl;
			return;
		}

		vector <clsCurrencyExchange>  Rate;
		short Trials = 5;

		while (!clsCurrencyExchange::ReturnCurrentObj_IfExistByCode(Rate, CurrencyCode))
		{
			Trials--;
			if (clsScreen::EndTheScreen(Trials)) return; // if the trials becomes 0 

			screen_color(red);
			cout << "\n\t\t\t\t\tYou Entered Invalid Currency Code!\a" << endl;
			CurrencyCode = clsInputAndValidation::read_string("\t\t\t\t\tEnter Currency Code: ");
		}

		system("color 0F");

		clsPrintCurrencies::ViewTheCountriesDetails(Rate);// print the rate of the currency (vector)

		// Enter New  Rate
		if (clsInputAndValidation::Confirm(colorText("\n\t\t\tAre You Sure About Updating The Currency Rate For This/These Country(ies) [y],[n]:  ", "red")))
		{
			system("cls");
			clsScreen::_PrintMenuOption(colorText("      Updating Currency Rate......", "cyan"));

			double NRate = clsInputAndValidation::clsReadNum<double> ::enter_postive_number("\t\t\t\t\tEnter The New Currency Rate: ");

			for (clsCurrencyExchange& Currency : Rate) { Currency.UpdateRate(NRate); }// will update the currency rate for each object 

			system("cls");
			cout << colorText("\n\t\t\tAll Country(ies) With The Currency Code " + CurrencyCode + " Their Rate Updated Successfully!\n","green");

			clsPrintCurrencies::ViewTheCountriesDetails(Rate);// print the rate of the currency (vector)
		}

		else cout << colorText("\n\n\t\t\t\t\tOKAY NO CHANGE !\n","pink");



	}


};