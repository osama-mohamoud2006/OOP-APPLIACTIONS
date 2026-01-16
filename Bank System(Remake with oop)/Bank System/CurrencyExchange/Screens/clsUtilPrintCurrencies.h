#pragma once

class clsPrintCurrencies
{

public :static void ViewTheCountriesDetails(vector <clsCurrencyExchange>  Rate)
{
	for (clsCurrencyExchange& c : Rate)clsUtilPrintCurrencyDetails::PrintCurrencyInfo(c);
}

};