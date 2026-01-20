#pragma once
#include <iostream>
#include<string>


class clsPerson  {

	private:
       std::string _FirstName ;
       std::string _LastName;
        std::string _Email;
        std::string _Phone;

          public:
              //constructor 
              clsPerson(std::string FirstName, std::string LastName, std::string Email, std::string Phone ) {
              this->_FirstName = FirstName;
                this->_LastName = LastName;
              this->_Email = Email;
                this->_Phone = Phone;

              }

         
              // Set and Get methods

              //set
              void SetFirstName(const std::string &fname) { this->_FirstName = fname;  }
              void SetLastName(const std::string &lname) { this->_LastName = lname; }
              void SetEmail(const std::string &Email) { this->_Email = Email; }
              void SetPhone(const std::string &Phone) { this->_Phone = Phone; }

              // get
              std::string GetFirstName( )const { return this->_FirstName; }
              std::string GetLastName( )const { return this->_LastName; }
              std::string GetEmail( )const { return this->_Email; }
              std::string GetPhone( ) const { return this->_Phone; }
              std::string GetFullName() {
                  return _FirstName + " " + _LastName;
              }
 
            
};
