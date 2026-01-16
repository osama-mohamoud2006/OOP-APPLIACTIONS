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
		this->_CountryName = CountryName;

		this->_CurrencyCode = CurrencyCode;
		this->_CurrencyName = CurrencyName;
		this->_Rate = Rate;
	}

	// Get Only -- read only properties
	string GetCountryName()const { return this->_CountryName; }
	string GetCurrencyCode()const { return this->_CurrencyCode; }
	string GetCurrencyName()const { return this->_CurrencyName; }
	double GetCurrentRate()const { return this->_Rate; }

	// Set 
	void SetCurrencyRate(double& Rate) { this->_Rate = Rate; }
	
private:
static	clsCurrencyExchange _EmptyObj() {
		return clsCurrencyExchange(eEmptyMode, "", "", "", 0.0);
	}

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

	static void UpdateFile(vector< clsCurrencyExchange>& VectorUpdated)
	{
		fstream write;
		write.open(_FileName, ios::out); // overwrite
		
		if( write.is_open() )
		{
			for (clsCurrencyExchange& C : VectorUpdated) { write << _ConvertObjectToLine(C) << endl;  }
		}

			write.close();
	}

public:
	static clsCurrencyExchange ReturnEmptyObjForInitializing() { return _EmptyObj(); }

	///  FindByCountry
	// FindByCode
public:
	static clsCurrencyExchange FindByCountry(string CountryName) 
	{
		CountryName = clsString::UpperAll(CountryName); // to make the search not depend if the word is upper or not 
		fstream read;
		read.open(_FileName, ios::in);
		if (read.is_open())
		{
			string record = "";
			while (getline(read, record))
			{
				clsCurrencyExchange TheCountry = _ConvertLineToObject(record); // convert each line to object 
				if ( clsString::UpperAll(TheCountry.GetCountryName() )== CountryName ) { read.close();  return TheCountry; }
			}

			
		}

		read.close();
		return _EmptyObj(); // --> return empty obj if the country isn't existing 
	}

	static clsCurrencyExchange SearchByCode(string Code) // if i want to check if the  currency is existing or not only
	{
		Code = clsString::UpperAll(Code); // to make the search not depend if the word is upper or not 
		fstream read;
		read.open(_FileName, ios::in);
		if (read.is_open())
		{
			string record = "";
			while (getline(read, record))
			{
				clsCurrencyExchange TheCountry = _ConvertLineToObject(record); // convert each line to object 
				if (clsString::UpperAll(TheCountry.GetCurrencyCode()) == Code) { read.close();  return TheCountry; }
			}


		}

		read.close();
		return _EmptyObj(); // --> return empty obj if the country isn't existing 
	}


	static vector<clsCurrencyExchange> FindByCode(string Code)
	{
		vector<clsCurrencyExchange>  C; 
		Code = clsString::UpperAll(Code); // to make the search not depend if the word is upper or not 
		fstream read;
		read.open(_FileName, ios::in);
		if (read.is_open())
		{
			string record = "";
			while (getline(read, record))
			{
				clsCurrencyExchange TheCountry = _ConvertLineToObject(record); // convert each line to object 
				if (clsString::UpperAll(TheCountry.GetCurrencyCode()) == Code) { C.push_back(TheCountry);}
			}


		}

		read.close();
		return C;
	}

	static bool IsCurrencyCodeExist(string CurrencyCode ) {
		vector<clsCurrencyExchange>  c=  FindByCode(CurrencyCode);
		return (!c.empty());  // if the vector isn't empty 
	}

	static bool IsCountryExist(string CountryName)
	{
		clsCurrencyExchange c = FindByCountry(CountryName);
		return (!c._IsEmpty());
	}

	static bool ReturnCurrentObj_IfExistByCode(vector <clsCurrencyExchange> & Currency , string CurrencyCode) { /// return vector 
		Currency = FindByCode(CurrencyCode);
		return  ( !Currency.empty() );
	}

	static bool ReturnCurrentObj_IfExistByCode(string CurrencyCode,clsCurrencyExchange& Currency) {
		// i will use it to check if the currency is existing or not no need to get the countries who use this currency 
		Currency = SearchByCode(CurrencyCode);
		return (!Currency._IsEmpty());
	}


	static bool ReturnCurrentObj_IfExistByCountry(clsCurrencyExchange& Currency, string CountryName) { 
		Currency = FindByCountry(CountryName);
		return  (!Currency._IsEmpty());
	}

	/// Update The Rate 
	private:
	 void _UpdateRateOnFile()
	{
		vector <clsCurrencyExchange> Records = _LoadFileOnVector();

		for (clsCurrencyExchange& c : Records)  if (c.GetCountryName() == this->GetCountryName() ) { c = *this; break; }
		
		UpdateFile(Records); 
	}
	 
	 public:
		 void UpdateRate(const double &NewRate)
		 {
			 this->_Rate = NewRate;
			 _UpdateRateOnFile();
		 }

		 // get the file contents on file
		static vector< clsCurrencyExchange> LoadFileContentOnVector()
		 {
			 return _LoadFileOnVector();
		 }


		 double AnyCurrencyToUSD(const double & Amount)
		{
			/*Converting Euros(Any Currency) to USD(Multiply) :
				You have €100.The EUR / USD rate is 1.20.
				€100 * 1.20 = $120. */
			 return (this->GetCurrentRate() * Amount);
		}

};
string clsCurrencyExchange::_Delmi = "#//#";
string clsCurrencyExchange::_FileName = "Currencies.text";