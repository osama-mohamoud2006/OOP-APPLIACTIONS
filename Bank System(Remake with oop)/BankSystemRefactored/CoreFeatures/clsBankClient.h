#pragma once
#include"Lib/clsString.h"
#include "CoreFeatures/clsPerson.h"
#include<fstream>
#include<string>
#include<vector>

class clsBankClient : public clsPerson {
    // clsBankClient is sub class of clsPerson
private:
    enum _enMode { enUpdateClient = 0, enAddNewClient = 1, enEmptyClientObject = 2 };
    _enMode _Mode = _enMode::enEmptyClientObject;

    std::string _AccountNumber;
    std::string _Pin;
    double _Balance = 0.0;
    static  std::string FileName;
    static std::string Delmi;
    bool _MarkForDelete = false;

    static void ThrowExceptionCouldnotOpenFile() {
        throw std::invalid_argument("failed to open/read file\a");
    }

    void SetClientMarkedForDelete() {
        _MarkForDelete = true;
    }

    bool GetClientDeleteStatus() {
        return _MarkForDelete;
    }

public:
    // parametrized constructor 
    clsBankClient(_enMode mode,
        std::string FirstName, std::string LastName, std::string Email, std::string Phone, // for clsPerson()
        std::string AccountNumber, std::string Pin, double Balance)
        : clsPerson(FirstName, LastName, Email, Phone)
    {
        this->_AccountNumber = AccountNumber;
        this->_Mode = mode;
        this->_Pin = Pin;
        this->_Balance = Balance;

    }

    //set 
protected:
    void SetFileName(const std::string& FileName) { this->FileName = FileName; }

public:

    void SetAccountNumber(const std::string& AccountNumber) {
        this->_AccountNumber = AccountNumber;
    }
    void SetPin(const std::string& Pin) { this->_Pin = Pin; }
    void SetBalance(const double& Balance) { this->_Balance = Balance; }

    //get

    std::string  GetAccountNumber()const {
        return this->_AccountNumber;
    }
    std::string  GetPin() const { return this->_Pin; }

    // for testing purposes 
/*        void  GetCurrentMode() {
            (!IsEmptyClientObj()) ? cout << "Client is existing!\n" : cout << "empty object!\a\n";
        }*/

    double  GetBalance()const {
        return this->_Balance;
    }

    bool IsEmptyClientObj()const {
        return (_Mode == _enMode::enEmptyClientObject);
    }


    // Manage Files
private:
    static clsBankClient _ConvertLineToObject(std::string Line) {
        //1-split string 
        //2-each index consider a data member of object
        clsString::SetDelmi(Delmi);
        std::vector<std::string> Client = clsString::SplitString(Line); // convert line to vector data 

        return clsBankClient(
            _enMode::enUpdateClient, Client.at(0),
            Client.at(1), Client.at(2), Client.at(3),
            Client.at(4), Client.at(5), std::stod(Client.at(6))); // call the constructor
    }

    static clsBankClient _ReturnEmptyObject()
    {
        return clsBankClient(_enMode::enEmptyClientObject, "", "", "", "", "", "", 0.0);
    }

public:

    static clsBankClient EmptyObjForInitializing() {
        return _ReturnEmptyObject();
    }


    ////                                                                                                                Find  Client                                                                                                                   /////

    // if it found the client it would return  object
    static clsBankClient Find(std::string AccountNumber) {
        std::fstream Read;
        Read.open(FileName, std::ios::in); //read mode
        if (Read.is_open())
        {
            std::string Line = ""; // line of data
            while (getline(Read, Line))
            {
                clsBankClient Client = _ConvertLineToObject(Line); // convert the line from file to object
                if (Client.GetAccountNumber() == AccountNumber) {
                    Read.close();
                    return Client; // return the object of this client if it found 
                }

            }

        }
        else {
            //  screen_color(red);
              //cout << "\aCouldn't Open FIle! ";
            ThrowExceptionCouldnotOpenFile();
            Read.close();

        }

        // if it didn't find the desired AccountNumber in file 
        Read.close();
        return _ReturnEmptyObject();
    }
    static clsBankClient Find(std::string AccountNumber, std::string Pin) {
        std::fstream Read;
        Read.open(FileName, std::ios::in); // read mode
        if (Read.is_open()) {
            std::string Line = ""; // line of data
            while (getline(Read, Line)) {
                clsBankClient Client = _ConvertLineToObject(Line); // convert the line from file to object

                if (Client.GetAccountNumber() == AccountNumber && Client.GetPin() == Pin) {
                    Read.close();
                    return Client; // return the object of this client  if it found      
                }

            }

        }

        else {
            //screen_color(red);
           // cout << "\aCouldn't Open FIle! ";
            ThrowExceptionCouldnotOpenFile();
            Read.close();
        }

        // if it didn't find the desired AccountNumber in file
        Read.close();
        return _ReturnEmptyObject();
    }

    static bool IsClientExist(std::string AccountNumber, std::string Pin) {
        clsBankClient temp = clsBankClient::Find(AccountNumber, Pin);
        return !(temp.IsEmptyClientObj());

    }

    static bool IsClientExist(std::string AccountNumber) {
        clsBankClient temp = clsBankClient::Find(AccountNumber);
        return !(temp.IsEmptyClientObj());

    }

    static bool ReturnCurrentClient_if_ItExists(std::string AccountNumber, clsBankClient& FoundCurrentClient) {

        clsBankClient temp = clsBankClient::Find(AccountNumber); // -> obj : Empty

        if (!(temp.IsEmptyClientObj())) {
            FoundCurrentClient = temp; // return the current object which have data 
            return true;
        }
        else return false;
    }



    /////// //  ////                                            Update Client Data                                                                                  ///////////


//The high level explanation  of Data update client data: ///
//  load file --> search the account number on file(check if account number of current obj == record on file)
// --> if  it found then change the record to the new object 

private:

    static std::string _ConvertObjectToLine(clsBankClient CurrentClient) {
        std::string record
            = CurrentClient.GetFirstName() + Delmi
            + CurrentClient.GetLastName() + Delmi
            + CurrentClient.GetEmail() + Delmi
            + CurrentClient.GetPhone() + Delmi
            + CurrentClient.GetAccountNumber() + Delmi
            + CurrentClient.GetPin() + Delmi
            + std::to_string(CurrentClient.GetBalance());
        return record;
    }

    static std::vector<clsBankClient>_LoadClientsFile() {
        std::fstream Read;
        std::vector< clsBankClient> FileOfClientsLoadedOnVector;
        Read.open(FileName, std::ios::in);
        if (Read.is_open()) {

            std::string Record;
            while (getline(Read, Record)) {
                // convert line to object then push it to vector
                FileOfClientsLoadedOnVector.push_back(_ConvertLineToObject(Record));
            }

            Read.close();
        }
        else {
            //  screen_color(red);
             // cout << "\a\nCann't Load On Vector File  Please Check the " << FileName << " And Try Again!" << endl;
            ThrowExceptionCouldnotOpenFile();
            Read.close();
            exit(0);
        }

        return FileOfClientsLoadedOnVector;
    }

    static void _UpdateFile(const std::vector<clsBankClient>& VectorOfClients)
    {
        if (VectorOfClients.empty()) ThrowExceptionCouldnotOpenFile(); // vector is empty no data on file ! 
        std::fstream Write;
        Write.open(FileName, std::ios::out); // overwrite 
        if (Write.is_open()) {

            std::string FromVectorLineOfData = "";
            for (clsBankClient C : VectorOfClients)
            {
                if (C.GetClientDeleteStatus() == false) {
                    Write << _ConvertObjectToLine(C) << std::endl; // convert object from file to line of record 
                }
            }

            Write.close();
        }

        else {
            // screen_color(red);
           //  cout << "\a\nCouldn't Save File Please Check the " << FileName << " And Try Again!" << endl;
            ThrowExceptionCouldnotOpenFile();
            Write.close();
        }

    }

    void _Update()
    {

        std::vector<clsBankClient> FileOfClients = _LoadClientsFile(); // load file of clients 

        for (clsBankClient& C : FileOfClients)
        {
            // c --> client from file record  
            if (C.GetAccountNumber() == GetAccountNumber()) {
                C = *this; // make the Client of file takes updated object 
                break;
            }
        }

        // Load New Data to File 
        _UpdateFile(FileOfClients);

    }

private:
    bool _CheckBeforeAddClient() {
        return (GetAccountNumber() == "" || GetPin() == "" || GetBalance() < 0.0 || GetFirstName() == "" || GetLastName() == "" || GetEmail() == "" || GetPhone() == "") ? true : false;
    }

public:
    enum enSaveMode { FailedOrEmptyObj = 0, SuccessedToSave = 1, AccountNumberExists = 3 };

    //this method check if it is empty object then update will be failed other wise it will update normally
    enSaveMode Save() {

        switch (_Mode) {

        case enEmptyClientObject:
        {
            return enSaveMode::FailedOrEmptyObj; //  failure  
        }

        case enUpdateClient: {// if empty then the save failed check Before Saving
            if (!_CheckBeforeAddClient()) { // if isn't empty
                _Update();
                return SuccessedToSave;
            }
            else return  FailedOrEmptyObj;
        }

        case enAddNewClient:
        {
            if (IsClientExist(this->GetAccountNumber())) // when add new client to file check if account is already exists in file
            {
                return   enSaveMode::AccountNumberExists;
            }
            else {
                if (_CheckBeforeAddClient()) {
                    _Mode = _enMode::enEmptyClientObject; //rest it
                    return enSaveMode::FailedOrEmptyObj; //  failure  
                }
                else {
                    _AddNewClientToFile(); // take the current obj and throw it in file 
                    _Mode = _enMode::enUpdateClient; /// rest it 
                    return enSaveMode::SuccessedToSave;
                }

            }
        }

        }

    }


    ////                                                                                  Add New Client                                                                                                                          //////////////

    static  clsBankClient InitializeToAddNewClient() {
        return  clsBankClient(enAddNewClient, "", "", "", "", "", "", 0.0);
    }
private:
    static void _WriteNewLineToFile(std::string Line) {
        std::fstream write;
        write.open(FileName, std::ios::out | std::ios::app);
        if (write.is_open()) {
            write << Line << std::endl;
        }
        else     ThrowExceptionCouldnotOpenFile();
    }
    void _AddNewClientToFile()
    {
        _WriteNewLineToFile(_ConvertObjectToLine(*this));
    }



    ///                                                                                        Delete Client                                                                                                                      ////////


public:
    bool DeleteClient() {
        // check if client is existing
        if (!(clsBankClient::IsClientExist(GetAccountNumber()))) return false;

        std::vector<clsBankClient> FileOfClients = _LoadClientsFile(); // load the clients file 

        for (clsBankClient& c : FileOfClients) {
            if (c.GetAccountNumber() == this->GetAccountNumber()) { // search the account number 
                c._MarkForDelete = true; // mark the account for deletion
                break;
            }
        }

        _UpdateFile(FileOfClients);
        *this = clsBankClient::_ReturnEmptyObject();
        return true;
    }


    //                                                                For Using it In Print Clients Feature                                                                                         ////////////                          

    // don't forget here in this class we focus only on the core no ui !

    static std::vector<clsBankClient> GetAllClientsInVector() { // For using in Printing or what ever 
        return _LoadClientsFile();
    }




};


std::string clsBankClient::FileName = "Clients.txt";
std::string clsBankClient::Delmi = "#//#";