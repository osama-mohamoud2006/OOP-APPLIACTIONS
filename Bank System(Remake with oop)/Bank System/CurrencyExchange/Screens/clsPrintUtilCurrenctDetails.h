#pragma once

class clsUtilPrintCurrencyDetails  
{

public :
	static void PrintCurrencyInfo(clsCurrencyExchange& c)
	{
		system("cls");
		// Get terminal width and calculate padding
		int terminalWidth = 120;
		int contentWidth = 48;
		int leftPadding = (terminalWidth - contentWidth) / 2;

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

};