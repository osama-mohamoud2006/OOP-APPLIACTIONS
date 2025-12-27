#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsPerson.h"

class clsUser : public clsPerson {

private :
	static string _FileName;
	static string _Delmi; 
	string _Username; // PK 
	string _Password;
	int _Permissions; /// it is in bin but will represent it in dec number and using bitwise operator we will make operations on bin level 

	enum _enMode {enEmptyMode=1 , enUpdateMode=2 , enAddMode =3 };

	_enMode _CurrentMode;
	

    static void ThrowExceptionCouldnotOpenFile()
	{
		throw::invalid_argument("failed to open/read file\a");
	}

public:

	enum enUserPermission {eListClients=1, eAddClient=2,eDeleteClient=4,eUpdateClient=8 , eFindClient=16 , eTransactions=32,eManageUsers=64 };

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


private :
	// record sample : username #//# password  #//#  permissions  #//# first name #//# last name  #//# email #//# phone 
	
	static  string _ConvertObjectToLine( const clsUser & User) 
	{
		return (User._Username + _Delmi  + User._Password +_Delmi + to_string(User._Permissions) + _Delmi + User.GetFirstName() + _Delmi + User.GetLastName() + _Delmi + User.GetEmail() + _Delmi + User.GetPhone());
	}

	static  clsUser _ConvertLineToObject(const string & UserRecordLine) 
	{
		clsString::SetDelmi(_Delmi);
		vector <string> RecordIntoVector =clsString::SplitString(UserRecordLine);

		return  clsUser(_enMode::enUpdateMode, RecordIntoVector.at(0), RecordIntoVector.at(1), stoi(RecordIntoVector.at(2)), RecordIntoVector.at(3), RecordIntoVector.at(4), RecordIntoVector.at(5), RecordIntoVector.at(6) ) ; 
	}

	 static vector<clsUser> _LoadFileOnVector() {

		 vector<clsUser> Records;
		 fstream Read;
		 Read.open(_FileName, ios::in);
		 if (Read.is_open())
		 {
			 string Record = "";
			 while (getline(Read, Record))
			 {
				 Records.push_back(_ConvertLineToObject(Record) ); // read file line by line then push it to file 
			 }
			 Read.close();
		 }
		 else { ThrowExceptionCouldnotOpenFile(); }
		return Records;
	 }

	 static clsUser _EmptyObj() {
		 return clsUser(_enMode::enEmptyMode, "", "", 0, "", "", "", "");
	 }

	 static void _UpdateFile(vector<clsUser> & Users ) {
		 fstream write;
		 write.open(_FileName, ios::out);
		 if (write.is_open()) {
			 for (clsUser u : Users) {
				 if(!u._GetTrueIfMarkedForDelete() ) write << _ConvertObjectToLine(u) << endl;
			 }
		 }
		 else { ThrowExceptionCouldnotOpenFile(); }
	 }

	 public:

		 static clsUser ReturnEmptyObjForInitializingUser()
		 {
			 return _EmptyObj();
		 }
		 static clsUser InitializeForUpdatingUser(){
			 return clsUser(_enMode::enUpdateMode, "", "", 0, "", "", "", "");
		 }
		 ////                                                                                             Find                                                                                                               ////

		 static clsUser FindUser(const string &  UserNameOFUserToFind) 
		 {
			 // 1: load file on vector , 2 make for loop vector , 3 check if the account number of obj is exist in vector if okay return true , else return false 
		
			 fstream Read;
			 Read.open(_FileName, ios::in);
			 if (Read.is_open()) 
			 {
				 string Record = "";
				 while (getline(Read, Record))
				 {
					 clsUser Temp = _ConvertLineToObject(Record);
					 if (Temp._Username == UserNameOFUserToFind) {
						 Read.close();
						 return Temp;
					 }
				 



				 }
				
				          Read.close();
						 return _EmptyObj();
				 }

			else   ThrowExceptionCouldnotOpenFile(); 
			 }
			  
		 static clsUser FindUser(const string& UserNameOFUserToFind , const string &Password )
		 {
			 // 1: load file on vector , 2 make for loop vector , 3 check if the account number of obj is exist in vector if okay return true , else return false 

			 fstream Read;
			 Read.open(_FileName, ios::in);
			 if (Read.is_open())
			 {
				 string Record = "";
				 while (getline(Read, Record))
				 {
					 clsUser Temp = _ConvertLineToObject(Record);
					 if (Temp._Username == UserNameOFUserToFind  && Temp._Password == Password ) {
						 Read.close();
						 return Temp;
					 }
				 }

				 Read.close();
				 return _EmptyObj();
			 }

			 else   ThrowExceptionCouldnotOpenFile();
		 }

		 static bool IsUserExist(const string& UserNameOFUserToFind) 
		 {
			 clsUser User = FindUser(UserNameOFUserToFind); // empty (empty )
			 return  (!(User.IsEmpty())) ? true : false;
		 }

		 static bool IsUserExist(const string& UserNameOFUserToFind  , const string& Password)
		 {
			 clsUser User = FindUser(UserNameOFUserToFind, Password);
			 return  (!(User.IsEmpty())) ? true : false;
		 }

		 static bool  FindUserAndReturnObj_If_exist(const string &UserNameOFUserToFind , clsUser &User)
		 {
			  User= FindUser(UserNameOFUserToFind);
			  return  (!( User.IsEmpty() )  ) ? true : false; 
		 }
		 static bool  FindUserAndReturnObj_If_exist(const string &UserNameOFUserToFind, const string& Password,clsUser& User)
		 {
			 User = FindUser(UserNameOFUserToFind,Password);
			 return  (!(User.IsEmpty())) ? true : false;
		 }

		 private:
			 bool _CheckBeforeSaveForAddUser() { // if the data members are empty then return false 
				return  (this->_Username == "" || this->_Password == "" || this->GetPhone() == "" || this->GetFullName() == "" ) ? true : false; 
			 }


		 //Save For [ add  , update ]

		 public:
			static  enum enSave {enSavedSuccessfully=1 , enFailedOrEmptyToSave =2 , enUsernameExists =3 };
			 //Save To file and return enum to know the status 
			 enSave Save() 
			 {
				 switch ( _CurrentMode )
				 {

				 case _enMode::enUpdateMode: 
				 {
					 Update();
					 return (_CheckBeforeSaveForAddUser()) ? enSavedSuccessfully : enFailedOrEmptyToSave; // check Before Saving 
				 }

				 case _enMode::enEmptyMode:
				 {
					 return enFailedOrEmptyToSave;
				 }

				 case _enMode::enAddMode:
				 {

					 if (this->IsEmpty()) return enFailedOrEmptyToSave; // failed to add
					 else {
						 if( !IsUserExist(this->_Username) ) // check if it isn't exist then save 
						 {
							 if(_CheckBeforeSaveForAddUser() ) {
								 _CurrentMode = enEmptyMode; //rest it
								 return enFailedOrEmptyToSave; // failed to add
							 }
							 _AddNewUser();
							 _CurrentMode = enUpdateMode; //rest it
							 return enSavedSuccessfully;

						 }
						 else return  enUsernameExists; 
					 }
				 }

				 }

			 }
			


			 //////                                                                                            Add User                                                                   ////

			static clsUser InitializeToAddNewUser() {
				 return clsUser(enAddMode, "", "", 0, "", "", "", "");
			 }

		 private :
			 void _AddLineToFile(string Line)
			 {
				 fstream Write; // write mode to write on file
				 Write.open(_FileName, ios::out | ios::app);
				 if (Write.is_open())
				 {
					 Write << Line << endl;
					 Write.close();
				 }
				 else
				 {
					 ThrowExceptionCouldnotOpenFile();
				 }

			 }

			 void _AddNewUser() 
			 {
				 _AddLineToFile(_ConvertObjectToLine(*this));
			 }


			    ////                                                                                Update                                                                                                                                   /////////
			 private:
			 void Update() 
			 {
				 vector<clsUser> Load = _LoadFileOnVector();
				 for (clsUser& User : Load) {
					 if (User._Username == this->_Username) 
					 {
						 User = *this; // set the updated obj to the vector obj
						 break; 
					 }
				 }

				 _UpdateFile(Load);
			 }


			 //                                                                                                Delete                                                                                                                   ///

			 private:
				 bool _MarkForDelete = false;

				 void _SetAsMarkedForDeletion() {
					 _MarkForDelete = true;
				 }
				 bool _GetTrueIfMarkedForDelete() {
					 return (_MarkForDelete == true);
				 }

				 public:
					 void Delete() 
					 {
						 vector<clsUser> Data = _LoadFileOnVector();
						 for (clsUser& User : Data) { if (User.GetUserName() == this->_Username) User._SetAsMarkedForDeletion(); };
						 *this = _EmptyObj();
						 _UpdateFile(Data);
					 }


					 ///                                                     For listing Or What Ever                                            ///////////
					 public:
					static	 vector<clsUser> LoadTheWholeFileOnVector() {
							 return _LoadFileOnVector();
						 }
};

string clsUser::_Delmi = "#//#";
string clsUser::_FileName = "UsersDb.text"; 