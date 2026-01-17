#pragma once 
#include  "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\CurrencyExchange\Screens\clsPrintUtilCurrenctDetails.h"

class clsCurrencyCalc : protected clsScreen
{

private :
	static  clsCurrencyExchange _CurrencyToOrFrom(const string &Message)
	{
		string CurrencyCode = clsInputAndValidation::read_string("\n\t\t\tEnter Currency Code "+ Message+" : ");
		//short Trials = 5;
		clsCurrencyExchange C = clsCurrencyExchange::ReturnEmptyObjForInitializing();

		while (!clsCurrencyExchange::ReturnCurrentObj_IfExistByCode( CurrencyCode, C) ) // will check if the currency is existing or not 
		{
			//Trials--;
			//if (clsScreen::EndTheScreen(Trials)) return; // if the trials becomes 0 
			cout << colorText("\n\n\t\t\t\t\tYou Entered Invalid Currency Code!\a" ,"red") << endl;
			CurrencyCode = clsInputAndValidation::read_string("\t\t\t\t\tEnter Currency Code: ");
		}


		return C;
	}

	static void _PrintFromAnyCurrencyToUSD_Details(clsCurrencyExchange &  c ,double Amount , double  AnyCurrencyToUSDRes )
	{

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
		//cout << setw(leftPadding) << "" << "    Country       : " << c.GetCountryName() << "\n\n";

		cout << setw(leftPadding) << "" << "    Current Rate  : " << colorText("1 USD = " + to_string(c.GetCurrentRate()) + " " + c.GetCurrencyCode(), "green") << "\n\n";

		// Fixed conversion result line with proper padding and formatting
		cout << setw(leftPadding) << "" << "    Conversion    : "
			<< to_string(Amount) << " " << c.GetCurrencyCode()
			<< " = " << to_string(AnyCurrencyToUSDRes) << " USD\n\n";

		cout << setw(leftPadding) << "" << colorText("================================================", "cyan") << "\n\n";
	}

	static void _PrintFromUSDToAnyCurrencyDetails(double Amount, double TheConvertedAmount,clsCurrencyExchange&FromCurrencyDetails, clsCurrencyExchange& ToCurrencyDetails)
	{
		int terminalWidth = 120;
		int contentWidth = 48;
		int leftPadding = (terminalWidth - contentWidth) / 2;

		cout << "\n\n";
		cout << setw(leftPadding) << "" << colorText("================================================", "cyan") << "\n";
		cout << setw(leftPadding) << "" << "           " << colorText(">> CONVERSION RESULT <<", "yellow") << "\n";
		cout << setw(leftPadding) << "" << colorText("================================================", "cyan") << "\n\n";

		cout << setw(leftPadding) << "" << colorText("  CURRENCY INFORMATION", "lightpurple") << "\n";
		cout << setw(leftPadding) << "" << "  ----------------------------------------------\n";
		cout << setw(leftPadding) << "" << "    Country Name   : " << ToCurrencyDetails.GetCountryName() << "\n";
		cout << setw(leftPadding) << "" << "    Currency Name  : " << ToCurrencyDetails.GetCurrencyName() << "\n";
		cout << setw(leftPadding) << "" << "    Currency Code  : " << colorText(ToCurrencyDetails.GetCurrencyCode(), "cyan") << "\n\n";

		cout << setw(leftPadding) << "" << "    Conversion     : "
			<< colorText(to_string(Amount) + " " + FromCurrencyDetails.GetCurrencyCode()
				+ " = " + to_string(TheConvertedAmount) + " " + ToCurrencyDetails.GetCurrencyCode(), "green") << "\n\n";

		cout << setw(leftPadding) << "" << colorText("================================================", "cyan") << "\n\n";
	}

	static void _CalcCurrencyScreen() // will convert and display the change no need for changing any files !
	{
		clsScreen::_PrintMenuOption(colorText("       Currency Calculator Screen","pink"));

		
		clsCurrencyExchange TheCurrencyFrom = _CurrencyToOrFrom("Of The Currency You Want To Convert From"); // From
		clsCurrencyExchange TheCurrencyTo= _CurrencyToOrFrom("Of The Currency You Want To Convert To"); // To

		while (TheCurrencyFrom.GetCurrencyCode() == TheCurrencyTo.GetCurrencyCode())
		{
			cout << colorText("\n\n\t\t\t\t\t\aTO AND FROM CANNOT BE THE SAME !!\n\n","red");
			return; 
		}

		double Amount = clsInputAndValidation::enter_postive_number(colorText("\n\n\t\t\tEnter The Amount You Want To Convert To "+ TheCurrencyTo.GetCurrencyCode()+" : ","green"));
		double ConversationToUSD = TheCurrencyFrom.AnyCurrencyToUSD(Amount);

		if (TheCurrencyTo.GetCurrencyCode() == "USD") { system("cls");  _PrintFromAnyCurrencyToUSD_Details(TheCurrencyFrom, Amount, ConversationToUSD); }
		else
		{
			system("cls");
			//_PrintFromAnyCurrencyToUSD_Details(TheCurrencyFrom, Amount, ConversationToUSD);
			_PrintFromUSDToAnyCurrencyDetails(Amount, TheCurrencyTo.FromUSDToAnyCurrency(ConversationToUSD), TheCurrencyFrom, TheCurrencyTo);
	
		}
		
	}

	public:

		static void StartCalcCurrencyScreen()
		{
			do
			{
				system("cls");
				_CalcCurrencyScreen();

			} while (clsInputAndValidation::Confirm(colorText("\n\t\t\t\t\tDo You Want To Make Another Calc [y],[n]: ","red")));
		}

};