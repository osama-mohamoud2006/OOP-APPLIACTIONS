#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsPerson.h"

class clsUser : public clsPerson {

private :
	static string _FileName;
	static string _Delmi; 
	string _Username;
	string _Password;
	int _Permissions; /// it is in bin but will represent it in dec number and using bitwise operator we will make operations on bin level 

	enum _enMode {enEmptyMode=1 , enUpdateMode=2 , enAddMode =3 };

	_enMode _CurrentMode;
	

	static void ThrowExceptionCouldnotOpenFile() {
		throw::invalid_argument("failed to open/read file\a");
	}

public:
	// Parametrized Constructor 

	
	clsUser( _enMode Mode, string Username, string  Password, int Permissions
		,string FirstName, string LastName, string Email, string Phone ) :
	clsPerson(FirstName, LastName, Email, Phone) 
	{	
		this->_CurrentMode = Mode;
		this->_Username = Username;
		this->_Password = Password;
		this->_Permissions = Permissions;
	}

	// Set 
	void SetPermissions( int Permissions) 
	{
		this->_Permissions = Permissions;
	}

	void SetUsername(const string &username)
	{
		this->_Username = username;
	}

	void SetPassword(const string &password) 
	{
		this->_Password = password;
	}

	// Get 
	string GetUserName() 
	{
		return this->_Username;
	}

	string GetPassword()
	{
		return this->_Password;
	}

	int GetPermissions() 
	{
		return this->_Permissions; 
	}

	
	// Important Methods to use

	bool IsEmpty() 
	{
		return (_CurrentMode == _enMode::enEmptyMode); 
	}

public :

	static clsUser ReturnEmptyObjForInitializingUser() 
	{
		return clsUser(_enMode::enEmptyMode, "", "", 0, "", "", "", "");
	}


private :

public :
	// record sample : username #//# password  #//#  permissions  #//# first name #//# last name  #//# email #//# phone 
	
	 string _ConvertObjectToLine( const clsUser & User) 
	{
		return (User._Username + _Delmi  + User._Password +_Delmi + to_string(User._Permissions) + _Delmi + User.GetFirstName() + _Delmi + User.GetLastName() + _Delmi + User.GetEmail() + _Delmi + User.GetPhone());
	}

	 clsUser _ConvertLineToObject(const string & UserRecordLine) 
	{
		clsString::SetDelmi(_Delmi);
		vector <string> RecordIntoVector =clsString::SplitString(UserRecordLine);

		return  clsUser(_enMode::enUpdateMode, RecordIntoVector.at(0), RecordIntoVector.at(1), stoi(RecordIntoVector.at(2)), RecordIntoVector.at(3), RecordIntoVector.at(4), RecordIntoVector.at(4), RecordIntoVector.at(5) ) ; 
	}

	 void _AddLineToFile(string Line) 
	 {
		 fstream Write; // write mode to write on file
		 Write.open(_FileName, ios::out | ios::app);
		 if (Write.is_open() ) 
		 {
			 Write << Line << endl; 
			 Write.close();
		}
		 else 
		 {
			 ThrowExceptionCouldnotOpenFile();
		 }

	 }




};

string clsUser::_Delmi = "#//#";
string clsUser::_FileName = "UsersDb.text"; 