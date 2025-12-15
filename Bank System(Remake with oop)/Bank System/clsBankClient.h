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
           string FileName = 

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


 

};
