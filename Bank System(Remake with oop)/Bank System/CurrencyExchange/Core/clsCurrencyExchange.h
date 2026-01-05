#pragma once

class clsCurrencyExchange
{
	//United States of America#//#USD#//#US Dollar#//#1.000000
private:
	string _CountryName;
	string _CountryCode;
	string _CurrencyName;
	double _Rate;

	enum _enMode { eEmptyMode = 1 , eUpdateMode=2 };   /// The Mode Of The File 
	_enMode _CurrentMode; 

public:
	clsCurrencyExchange(string CountryName, string CountryCode, string CurrencyName, double Rate)
	{
	}



};