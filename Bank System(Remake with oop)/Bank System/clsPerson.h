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

              clsPerson() {

              }
              // Set and Get methods

              //set
              void SetFirstName(string fname) { this->_FirstName = fname;  }
              void SetLastName(string lname) { this->_LastName = lname; }
              void SetEmail(string Email) { this->_Email = Email; }
              void SetPhone(string Phone) { this->_Phone = Phone; }

              // get
              string GetFirstName(string fname) { return this->_FirstName; }
              string GetLastName(string lname) { return this->_LastName; }
              string GetEmail(string Email) { return this->_Email; }
              string GetPhone(string Phone) { return this->_Phone; }

             // Print person data 
            virtual  void Print() {
              //  cout << "\n_________________________________\n";
                cout << "\nThe First Name is : " << _FirstName << endl;
                cout << "The Last Name  is : " << _LastName << endl;
                cout << "The Email is : " << _Email << endl;
                cout << "The Phone Number is : " << _Phone << endl;
                
              }

};
