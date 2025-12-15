#pragma once
#include "E:\projects\c++ course\10-OOP Concepts\Project 2\Project 2\clsString.h"
#include "clsPerson.h"
#include<fstream>
#include<vector>
#include<iostream>
using namespace std ;

class clsBankClient : public clsPerson{
    // clsBankClient is sub class of clsPerson
	private:
  enum _enMode {enUpdateClient=1,enEmptyClientObject=2};
          _enMode _Mode=_enMode::enEmptyClientObject;

		  string _AccountNumber;
          string _Pin;
           double _Balance=0.0;
          string FileName = "Clients.txt";
          string 

           public:
               // parametrized constructor 
               clsBankClient(_enMode mode,
                   string FirstName , string LastName , string Email , string Phone, // for clsPerson()
                   string AccountNumber ,string Pin , double Balance ) 
                   : clsPerson(FirstName, LastName, Email, Phone) 
              {  
               this->_AccountNumber = AccountNumber;
                 this->_Pin = Pin;
               this->_Balance = Balance;

               }

               //set 
               void SetFileName(string FileName) { this->FileName = FileName;  }
               void SetAccountNumber(string AccountNumber) {
               this->_AccountNumber = AccountNumber;
               }
               void SetPin(string Pin) { this->_Pin = Pin; }
               void SetBalance(double Balance) { this->_Balance = Balance; }

               //get
               string  GetAccountNumber() {
                 return this->_AccountNumber;
               }
               string  GetPin() {  return this->_Pin ; }
               double  GetBalance() {
                 return this->_Balance ;
               }

               bool IsEmptyClientObj() {
                 return (_enMode::enEmptyClientObject == _Mode);
               }
 
               void Print() override {
                   clsPerson::Print();
                 cout << "The Account Number is: "<<_AccountNumber<<endl;
                   cout << "The Pin is: " << _Pin << endl;
                 cout << "The Balance is : " << _Balance << endl;
               }

               // Manage Files For
             private:
                 clsBankClient ConvertLineToObject(string Line) {
                     //1-split string 
                     //2-each index consider a data member of object
                   vector<clsBankClient> Client = clsString::SplitString(Line)
               }
};
