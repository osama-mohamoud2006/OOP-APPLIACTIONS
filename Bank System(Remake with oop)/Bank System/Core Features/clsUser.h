#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsPerson.h"

class clsUser : public clsPerson {

private :
	string _Username;
	string _Password;
	int _Permissions; /// it is in bin but will represent it in dec number and using bitwise operator we will make operations on bin level 

	enum _enMode {enEmptyMode=1 , enUpdateMode=2 , enAddMode =3 };

	_enMode CurrentMode;

public:
	clsUser(string FirstName, string LastName, string Email, string Phone, // for clsPerson 
		string Username , string  Password , int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone) 
	{

	}




};