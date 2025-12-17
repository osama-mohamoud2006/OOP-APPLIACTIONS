#pragma once
#include "E:\projects\c++ course\10-OOP Concepts\Project 2\Project 2\clsString.h"
#include"E:\projects\my library\AllStuff.h"  
#include "clsPerson.h"
#include<fstream>
#include<string>
#include<vector>
#include<iostream>
using namespace std ;

class clsBankClient : public clsPerson{
    // clsBankClient is sub class of clsPerson
	private:
  enum _enMode {enUpdateClient=0,enEmptyClientObject=1};
          _enMode _Mode=_enMode::enEmptyClientObject;

		  string _AccountNumber;
          string _Pin;
          double _Balance=0.0;
          static  string FileName ;
            static string Delmi ;

           public:
               // parametrized constructor 
               clsBankClient(_enMode mode,
                   string FirstName , string LastName , string Email , string Phone, // for clsPerson()
                   string AccountNumber ,string Pin , double Balance ) 
                   : clsPerson(FirstName, LastName, Email, Phone) 
              {  
               this->_AccountNumber = AccountNumber;
               this->_Mode = mode;
                 this->_Pin = Pin;
               this->_Balance = Balance;

               }

             // Used to just initlize 
               clsBankClient(){
                   *this = clsBankClient::_ReturnEmptyObject(); // make empty object 
               } 


               //set 
protected :
               void SetFileName(string FileName) { this->FileName = FileName;  }

public:
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

               // for testing puposes 
       /*        void  GetCurrentMode() {
                   (!IsEmptyClientObj()) ? cout << "Client is existing!\n" : cout << "empty object!\a\n";
               }*/

               double  GetBalance() {
                 return this->_Balance ;
               }
               
               bool IsEmptyClientObj() {
                 return ( _Mode== _enMode::enEmptyClientObject);
               }
 
               void Print() override {
                   clsPerson::Print(); // call the print method of super class 
                 cout << "The Account Number is: "<<_AccountNumber<<endl;
                   cout << "The Pin is: " << _Pin << endl;
                 cout << "The Balance is : " << _Balance << endl;
               }

               // Manage Files For
             private:
                static clsBankClient _ConvertLineToObject(string Line) {
                     //1-split string 
                     //2-each index consider a data member of object
                   clsString::SetDelmi(Delmi);
                   vector<string> Client =clsString::SplitString(Line); // convert line to vector data 
                 // create temp object
                   return clsBankClient(
                       _enMode::enUpdateClient, Client.at(0),
                                 Client.at(1), Client.at(2), Client.at(3),
                                 Client.at(4),Client.at(5),stod( Client.at(6) )  ); // call the constructor
               }

                static clsBankClient _ReturnEmptyObject() 
                {
                     return clsBankClient(_enMode::enEmptyClientObject, "", "", "", "", "", "",0.0 );
                }


                 public:
                     // if it found the client it would return  object
                     static clsBankClient Find(string AccountNumber) {
                     fstream Read;
                       Read.open(FileName, ios::in); //read mode
                     if (Read.is_open()) 
                     {
                         string Line = ""; // line of data
                       while ( getline(Read, Line) ) 
                       {
                           clsBankClient Client = _ConvertLineToObject(Line); // convert the line from file to object
                         if (Client.GetAccountNumber() == AccountNumber) {
                             Read.close();
                           return Client; // return the object of this client if it found 
                         }

                       }

                     } 
                     else {
                       screen_color(red);
                       cout << "\aCouldn't Open FIle! ";
                       Read.close();
                    
                     }
                      
                     // if it didn't find the desired AccountNumber in file 
                    return _ReturnEmptyObject();
                   }
                     static clsBankClient Find(string AccountNumber,string Pin) {
                       fstream Read;
                       Read.open(FileName, ios::in); // read mode
                       if (Read.is_open()) {
                         string Line = ""; // line of data
                         while (getline(Read, Line)) {
                           clsBankClient Client = _ConvertLineToObject( Line); // convert the line from file to object

                           if (Client.GetAccountNumber() == AccountNumber &&  Client.GetPin() == Pin) {
                             Read.close();
                             return Client; // return the object of this client  if it found      
                           }

                         }

                       } 

                       else {
                         screen_color(red);
                         cout << "\aCouldn't Open FIle! ";
                         Read.close();
                       }

                       // if it didn't find the desired AccountNumber in file
                       return _ReturnEmptyObject();
                     }

                     static bool IsClientExist(string AccountNumber, string Pin) {
                         clsBankClient temp = clsBankClient::Find(AccountNumber, Pin);
                         return !(  temp.IsEmptyClientObj() ) ;
                         
                     }

                     static bool IsClientExist(string AccountNumber) {
                         clsBankClient temp = clsBankClient::Find(AccountNumber);
                         return !(temp.IsEmptyClientObj());

                     }

                     static bool ReturnCurrentClient_if_ItExists(string AccountNumber , clsBankClient & FoundCurrentClient) {

                         clsBankClient temp = clsBankClient::Find(AccountNumber); // -> obj : Empty
                  
                         if (!(temp.IsEmptyClientObj())) {
                             FoundCurrentClient = temp; // return the current object which have data 
                             return true;
                         }
                         else return false;
                     }

                 
              /////// //  ////                                            Update Client Data                                                                                  ///////////



};


string clsBankClient::FileName = "Clients.txt";
string clsBankClient::Delmi = "#//#";