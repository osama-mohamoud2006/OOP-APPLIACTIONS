#pragma once

class clsLoginHistory
{
private:
	string _Delmi = "#//#";
	static string _LoginLogFileName ;
	static string DateAndTime;
	string username;
	string pass;
	int permission;

public:
	string GetUsername() { return username; }
	string GetPassword() { return pass;  }
	string GetPermission() { return to_string(permission); }

	clsLoginHistory(string DateAndTime, string username, string pass, int per) {
		this->DateAndTime = DateAndTime;
		this->username = username;
		this->pass = pass;
		this->permission = per;
	}

private:

	static clsLoginHistory _ConvertLineToObject(string line)
	{
		clsString::SetDelmi(_Delmi);
		vector<string> RecordsOfLogs = clsString::SplitString(line);
		return clsLoginHistory(RecordsOfLogs[0], RecordsOfLogs[1], RecordsOfLogs[2], stoi(RecordsOfLogs[3]) );
	}

	static vector <clsLoginHistory> _LoadLogFileOnVector() {
		vector<clsLoginHistory> Record;
		fstream read;
		read.open(_LoginLogFileName, ios::in);
		if (read.is_open())
		{
			string record = "";
			while (getline(read, record))
			{
				Record.push_back(_ConvertLineToObject(record));
			}
			read.close();
		}

	}


public:
	static vector < clsLoginHistory>  FileOnVector() {
		return _LoadLogFileOnVector();
	}

};

string clsLoginHistory::_LoginLogFileName = "LoginHistory.text";