#pragma once
#pragma warning(disable : 4996)
#include <ctime>
#include <limits>

class clsLogHistory
{
	 // Sample Log Record : time - date#//#username#//#password#//#permissions
private:
	static string  _FileName;
	static string _Delmi;
	static time_t  timeNow;
	//clsDate CDate;
	//clsDate CTime;

  static	string _GetTime() {
	  tm* Time = localtime(&timeNow);
	  return (to_string(Time->tm_hour)+":"+to_string(Time->tm_min) + ":" + to_string(Time->tm_sec ) );
	}

public :

	static void WriteLoginHistoryToFile(string Username , string pass , int Permission =0 ) 
	{
		fstream write;
		write.open(_FileName, ios::out | ios::app);
		if (write.is_open()) 
		{
			write << clsDate::PrintFullDateForStatic(clsDate::GetCurrentLocalDate()) << " - ";
			write << _GetTime ()<< _Delmi;
			write << Username << _Delmi;
			write << pass << _Delmi;
			write << Permission << endl;

		}

	}

	static void WriteLoginHistoryToFile(clsUser & User)
	{
		fstream write;
		write.open(_FileName, ios::out | ios::app);
		if (write.is_open())
		{
			write << clsDate::PrintFullDateForStatic(clsDate::GetCurrentLocalDate()) << " - ";
			write << _GetTime() << _Delmi;
			write << User.GetUserName() << _Delmi;
			write << User.GetPassword() << _Delmi;
			write << User.GetPermissions() << endl;

		}

	}

};
string clsLogHistory::_FileName = "TheLoginHistory.text";
string clsLogHistory::_Delmi = "#//#";
time_t  clsLogHistory::timeNow = time(0); 