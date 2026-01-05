#pragma once

class clsCurrencyExchange
{

private:
	string _CountryName;
	string _CurrencyCode;
	string _CurrencyName;
	double _Rate;

	static string _FileName;
	static string  _Delmi;

	enum _enMode { eEmptyMode = 1 , eUpdateMode=2 };   /// The Mode Of The File 
	_enMode _CurrentMode; 

public:
	// constructor 
	clsCurrencyExchange(_enMode CurrentMode,string CountryName, string CurrencyCode, string CurrencyName, double Rate)
	{
		this->_CurrentMode = CurrentMode;
		this->_CurrencyName = CountryName;

		this->_CurrencyCode = CurrencyCode;
		this->_CurrencyName = CurrencyName;
		this->_Rate = Rate;
	}

	// Get Only -- read only properties
	string GetCountryName()const { return this->_CountryName; }
	string GetCurrencyCode()const { return this->_CurrencyCode; }
	string GetCurrencyName()const { return this->_CurrencyName; }
	double GetCurrentRate()const { return this->_Rate; }


private:
	
	bool _IsEmpty() { return (_CurrentMode == eEmptyMode); }

//United States of America#//#USD#//#US Dollar#//#1.000000   --> line
	static clsCurrencyExchange _ConvertLineToObject(string Line) {
		
		clsString::SetDelmi(_Delmi);
		vector<string> Record = clsString::SplitString(Line); // Cut the line 

		return clsCurrencyExchange(eUpdateMode,Record[0], Record[1], Record[2],stod (Record[3]) ) ;
	}

	static string _ConvertObjectToLine(clsCurrencyExchange &Obj) {
		return ( Obj.GetCountryName() + _Delmi + Obj.GetCurrencyCode() + _Delmi + Obj.GetCurrencyName() + _Delmi + to_string(Obj.GetCurrentRate() )  );
	}

	static vector< clsCurrencyExchange> _LoadFileOnVector()
	{
		vector <clsCurrencyExchange> Vcu; 
		fstream read;
		read.open(_FileName, ios::in);
		if (read.is_open())
		{
			string record = "";
			while (getline(read, record))
			{
				Vcu.push_back(_ConvertLineToObject(record)); // convert the line to obj then push it to vector 
			}
			read.close();
		}
	
		return Vcu;
	}


	///  FindByCountry
	// FindByCode
public:
	static clsCurrencyExchange FindByCountry(string CountryName) 
	{
		vector< clsCurrencyExchange> Records = _LoadFileOnVector();
		fstream read;
		read.open(_FileName, ios::in);
		if (read.is_open())
		{
			for (clsCurrencyExchange& C : Records) if (C.GetCountryName() == CountryName) return C;

		}

	}


};
string clsCurrencyExchange::_Delmi = "#//#";
string clsCurrencyExchange::_FileName = "Currencies.text";