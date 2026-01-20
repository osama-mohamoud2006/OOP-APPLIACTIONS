#pragma once 
#include "CoreFeatures/clsPerson"
#include "Lib/clsDate.h"


class clsUser  :public clsPerson {

private :
	static std::string _FileName;
	static std::string _Delmi; 
	std::string _Username; // PK 
	std::string _Password;
	int _Permissions; /// it is in bin but will represent it in dec number and using bitwise operator we will make operations on bin level 

	enum _enMode {enEmptyMode=1 , enUpdateMode=2 , enAddMode =3 };

	_enMode _CurrentMode;
	

    static void ThrowExceptionCouldnotOpenFile()
	{
		throw std::invalid_argument("failed to open/read file\a");
	}

public:

	enum enUserPermission {eALL=-1,eListClients=1, eAddClient=2,eDeleteClient=4,eUpdateClient=8 , eFindClient=16 , eTransactions=32,eManageUsers=64 , eViewLoginLog=128 , eCurrencyExchange=256};

	// Parametrized Constructor 
	clsUser( _enMode Mode, std::string Username, std::string  Password, int Permissions
		,std::string FirstName, std::string LastName, std::string Email, std::string Phone ) :
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

	void SetUsername(const std::string &username)
	{
		this->_Username = username;
	}

	void SetPassword(const std::string &password) 
	{
		this->_Password = password;
	}

	// Get 
	std::string GetUserName() 
	{
		return this->_Username;
	}

	std::string GetPassword()
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
	
	static  std::string _ConvertObjectToLine( const clsUser & User) 
	{// Encrypt Password Using Xor  ---> password[i] ^ 'd'
		return (User._Username + _Delmi  + clsUtil::EncryptOrDecryptUsingXor(User._Password )+ _Delmi + std::to_string(User._Permissions) + _Delmi + User.GetFirstName() + _Delmi + User.GetLastName() + _Delmi + User.GetEmail() + _Delmi + User.GetPhone());
	}

	static  clsUser _ConvertLineToObject(const std::string & UserRecordLine) 
	{  // Decrypt Password  
		clsString::SetDelmi(_Delmi);
		std::vector <std::string> RecordIntoVector =clsString::SplitString(UserRecordLine);

		return  clsUser(_enMode::enUpdateMode, RecordIntoVector.at(0), clsUtil::EncryptOrDecryptUsingXor(RecordIntoVector.at(1)), std::stoi(RecordIntoVector.at(2)), RecordIntoVector.at(3), RecordIntoVector.at(4), RecordIntoVector.at(5), RecordIntoVector.at(6) ) ; 
	}

	 static std::vector<clsUser> _LoadFileOnVector() {

		 std::vector<clsUser> Records;
		 std::fstream Read;
		 Read.open(_FileName, std::ios::in);
		 if (Read.is_open())
		 {
			 std::string Record = "";
			 while (std::getline(Read, Record))
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

	 static void _UpdateFile(std::vector<clsUser> & Users ) {
		 std::fstream write;
		 write.open(_FileName, std::ios::out);
		 if (write.is_open()) {
			 for (clsUser u : Users) {
				 if(!u._GetTrueIfMarkedForDelete() ) write << _ConvertObjectToLine(u) << std::endl;
			 }
		 }
		 else { ThrowExceptionCouldnotOpenFile(); }
	 }

	 public:

		 static clsUser ReturnEmptyObjForInitializingUser()
		 {
			 return _EmptyObj();
		 }


		 ////                                                                                             Find                                                                                                               ////

		 static clsUser FindUser(const std::string &  UserNameOFUserToFind) 
		 {
			 // 1: load file on vector , 2 make for loop vector , 3 check if the account number of obj is exist in vector if okay return true , else return false 
		
			 std::fstream Read;
			 Read.open(_FileName, std::ios::in);
			 if (Read.is_open()) 
			 {
				 std::string Record = "";
				 while (std::getline(Read, Record))
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
			  
		 static clsUser FindUser(const std::string& UserNameOFUserToFind , const std::string &Password )
		 {
			 // 1: load file on vector , 2 make for loop vector , 3 check if the account number of obj is exist in vector if okay return true , else return false 

			 std::fstream Read;
			 Read.open(_FileName, std::ios::in);
			 if (Read.is_open())
			 {
				 std::string Record = "";
				 while (std::getline(Read, Record))
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

		 static bool IsUserExist(const std::string& UserNameOFUserToFind) 
		 {
			 clsUser User = FindUser(UserNameOFUserToFind); // empty (empty )
			 return  (!(User.IsEmpty())) ? true : false;
		 }

		 static bool IsUserExist(const std::string& UserNameOFUserToFind  , const std::string& Password)
		 {
			 clsUser User = FindUser(UserNameOFUserToFind, Password);
			 return  (!(User.IsEmpty())) ? true : false;
		 }

		 static bool  FindUserAndReturnObj_If_exist(const std::string &UserNameOFUserToFind , clsUser &User)
		 {
			  User= FindUser(UserNameOFUserToFind);
			  return  (!( User.IsEmpty() )  ) ? true : false; 
		 }
		 static bool  FindUserAndReturnObj_If_exist(const std::string &UserNameOFUserToFind, const std::string& Password,clsUser& User)
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
			  enum enSave {enSavedSuccessfully=1 , enFailedOrEmptyToSave =2 , enUsernameExists =3 };
			 //Save To file and return enum to know the status 
			 enSave Save() 
			 {
				 switch ( _CurrentMode )
				 {

				 case _enMode::enUpdateMode: 
				 {
					 // check Before Saving if empty then the save failed 
					 if (!_CheckBeforeSaveForAddUser()) { // if it isn't empty 
						 _Update();
						 return enSavedSuccessfully;
					 }
					 else return  enFailedOrEmptyToSave; 
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
			 void _AddLineToFile(std::string Line)
			 {
				 std::fstream Write; // write mode to write on file
				 Write.open(_FileName, std::ios::out | std::ios::app);
				 if (Write.is_open())
				 {
					 Write << Line << std::endl;
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


			    ////                                                                                       Update                                                                                                                                   /////////
			 private:
			 void _Update() 
			 {
				 std::vector<clsUser> Load = _LoadFileOnVector();
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
						 std::vector<clsUser> Data = _LoadFileOnVector();
						 for (clsUser& User : Data) { if (User.GetUserName() == this->_Username) User._SetAsMarkedForDeletion(); };
						 *this = _EmptyObj();
						 _UpdateFile(Data);
					 }


					 ///                                                                                    For listing Or What Ever                                            ///////////
					 public:
					static	 std::vector<clsUser> LoadTheWholeFileOnVector() {
							 return _LoadFileOnVector();
						 }


					/////////////////////                                                                      Check Permission                                                   //////////////

					static bool CheckPermission(enUserPermission &CurrentPermissionToCheck, clsUser& UserToCheck) 
					{
						if (enUserPermission::eALL == UserToCheck.GetPermissions()) return true;
						else if ( ( UserToCheck.GetPermissions() & CurrentPermissionToCheck ) == CurrentPermissionToCheck) return true;
						else return false; 
					}

					static bool CheckPermission(enUserPermission CurrentPermissionToCheck, int PermOfUserToCheck)
					{
						if (enUserPermission::eALL == PermOfUserToCheck ) return true;
						else if ((PermOfUserToCheck & CurrentPermissionToCheck) == CurrentPermissionToCheck) return true;
						else return false;
					}




					////                                                                                                                Login Of User                                                                             //////////

					private:
						static std::string _LoginLogFileName;

						std::string  _RecordOfLoginDetails() 
						{// encrypt password with --->  password[i] ^ 'd'
							return ( clsDate::GetLocalDateAndTime() + _Delmi + this->_Username + _Delmi + clsUtil::EncryptOrDecryptUsingXor(this->_Password )+ _Delmi + std::to_string(this->_Permissions) );
						}

						public:

							void SaveLoginDetails() /// write login session details to file 
							{
								std::fstream write;
								write.open(_LoginLogFileName,std::ios::out | std::ios::app);
								if (write.is_open())
								{
									write <<  _RecordOfLoginDetails() << std::endl;
									write.close();
								}
								else { write.close();  ThrowExceptionCouldnotOpenFile(); }
							}


							class clsLoginHistory final
							{
							private:
								std::string DateAndTime;
								std::string username;
								std::string pass;
								int permission;

							public: 
								//Get --> to call 
								std::string GetTimeDate() { return DateAndTime; }
								std::string GetUsername() { return username; }
								std::string GetPassword() { return pass; }
								std::string GetPermission() { return std::to_string(permission); }

							private:

								clsLoginHistory(std::string DateAndTime, std::string username, std::string pass, int per) {
									this->DateAndTime = DateAndTime;
									this->username = username;
									this->pass = pass;
									this->permission = per;
								}

								static clsLoginHistory _ConvertLineToObject(std::string line)
								{ // Decrypt Password 
									clsString::SetDelmi(_Delmi);
									std::vector<std::string> RecordsOfLogs = clsString::SplitString(line);
									return clsLoginHistory(RecordsOfLogs[0], RecordsOfLogs[1], clsUtil::EncryptOrDecryptUsingXor(RecordsOfLogs[2]) , std::stoi(RecordsOfLogs[3]));
								}

								static std::vector <clsLoginHistory> _LoadLogFileOnVector() 
								{
									std::vector<clsLoginHistory> Record;
									std::fstream read;
									read.open(_LoginLogFileName, std::ios::in);
									if (read.is_open())
									{
										std::string record = "";
										while (std::getline(read, record))
										{
											Record.push_back(_ConvertLineToObject(record));
										}
										read.close();
									}
									else ThrowExceptionCouldnotOpenFile();

									return Record;
								}


							public:
								static std::vector < clsLoginHistory>  FileOnVector() {
									return _LoadLogFileOnVector();
								}

							};


};

std::string clsUser::_Delmi = "#//#";
std::string clsUser::_FileName = "UsersDb.text"; 
std::string clsUser::_LoginLogFileName = "LoginHistory.text";