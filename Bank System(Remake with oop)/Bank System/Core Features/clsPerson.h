#pragma once
#include <iostream>
#include<string>
using namespace std;

class clsPerson {

	private:
       string _FirstName ;
       string _LastName;
        string _Email;
        string _Phone;

          public:
              //constructor 
              clsPerson(string FirstName,string LastName,string Email, string Phone ) {
              this->_FirstName = FirstName;
                this->_LastName = LastName;
              this->_Email = Email;
                this->_Phone = Phone;

              }

         
              // Set and Get methods

              //set
              void SetFirstName(const string &fname) { this->_FirstName = fname;  }
              void SetLastName(const string &lname) { this->_LastName = lname; }
              void SetEmail(const string&Email) { this->_Email = Email; }
              void SetPhone(const string &Phone) { this->_Phone = Phone; }

              // get
              string GetFirstName( )const { return this->_FirstName; }
              string GetLastName( )const { return this->_LastName; }
              string GetEmail( )const { return this->_Email; }
              string GetPhone( ) const { return this->_Phone; }
              string GetFullName() {
                  return _FirstName + " " + _LastName;
              }
 

};
