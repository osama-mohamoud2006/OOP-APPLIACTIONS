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

public:
	// Parametrized Constructor 
	clsUser(string FirstName, string LastName, string Email, string Phone, // for clsPerson 
		_enMode Mode,string Username , string  Password , int Permissions) :
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

private:
	// record sample : username#//#first name#//# last name#//# password #//# permissions 
	
	string _ConvertObjectToLine( const clsUser & User) 
	{
		return ()
	}



};

string clsUser::_Delmi = "#//#";
string clsUser::_FileName = "UsersDb.text"; 