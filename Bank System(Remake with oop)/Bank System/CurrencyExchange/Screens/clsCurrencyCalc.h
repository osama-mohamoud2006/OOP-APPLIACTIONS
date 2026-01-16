#pragma once 

class clsCurrencyCalc : protected clsScreen
{
	// 1 ask for the first  currency & second currency
	// 2 check if the second obj is usd or not
	// 3 if it is use then formula will be = currency1 rate /rate of  usd , else usd * currency rate 2
	
	/*
	Converting Euros (Any Currency) to USD (Multiply):
  You have €100. The EUR/USD rate is 1.20.
   €100 * 1.20 = $120.

    Converting USD to Euros (Divide):
    You have $100. The USD/EUR rate is 0.80 (meaning 1 USD buys 0.80 Euros).
   $100 / 0.80 = €125.
	*/
private :
	static vector <clsCurrencyExchange> CurrencyToOrFrom(const string &Message)
	{
		string CurrencyCode = clsInputAndValidation::read_string("\t\t\tEnter Currency Code "+ Message+" : ");
		short Trials = 5;
		clsCurrencyExchange C = clsCurrencyExchange::ReturnEmptyObjForInitializing();

		while (!clsCurrencyExchange::ReturnCurrentObj_IfExistByCode( CurrencyCode, C) ) // will cjheck if the currency is existing or not 
		{
			Trials--;
			if (clsScreen::EndTheScreen(Trials)) return; // if the trials becomes 0 

			screen_color(red);
			cout << "\n\t\t\t\t\tYou Entered Invalid Currency Code!\a" << endl;
			CurrencyCode = clsInputAndValidation::read_string("\t\t\t\t\tEnter Currency Code: ");
		}

	}

public :
	static void CalcCurrencyScreen() // will convert and display the change no need for changing any files !
	{
		clsScreen::_PrintMenuOption(colorText("\t\t\t\t\t\tCurrency Calculator Screen","blue"));

		vector<clsCurrencyExchange> TheCurrencyFrom = CurrencyToOrFrom("Of The Currency You Want To Convert From"); // From
		vector<clsCurrencyExchange> TheCurrencyTo= CurrencyToOrFrom("Of The Currency You Want To Convert To"); // To

		//if(TheCurrencyTo.at(0).GetCurrencyCode() == "USD")  AnyCurrencyToUSD()
		
	}

};