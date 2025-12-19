#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsPerson.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsScreen.h"
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h";
class clsShowListScreen
{
private:
    // PrintBasicPersonData One Client Record
    void PrintClientRecord(clsBankClient Client) {

        cout << "| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(25) << left << Client.GetFullName();
        cout << "| " << setw(15) << left << Client.GetPhone();
        cout << "| " << setw(30) << left << Client.GetEmail();
        cout << "| " << setw(10) << left << Client.GetPin();
        cout << "| " << setw(12) << left << Client.GetBalance();
        cout << endl;
    }
public:

    void PrintClientList() {

        vector<clsBankClient> clients = clsBankClient::GetAllClientsInVector();
        string SubTitle = "\t\t\t\t\tClient List (" + to_string(clients.size()) + ") Client(s).";

        cout << "\n_____________________________________________________________________________________________________________________\n\n";
        cout << SubTitle;
        cout << "\n_____________________________________________________________________________________________________________________\n" << endl;

        cout << "| " << left << colorText("Account Number", "lightpurple") << setw(15 - 14) << "";
        cout << "| " << left << colorText("Client Name", "lightpurple") << setw(25 - 11) << "";
        cout << "| " << left << colorText("Phone", "lightpurple") << setw(15 - 5) << "";
        cout << "| " << left << colorText("Email", "lightpurple") << setw(30 - 5) << "";
        cout << "| " << left << colorText("Pin Code", "lightpurple") << setw(10 - 8) << "";
        cout << "| " << left << colorText("Balance", "lightpurple") << setw(12 - 7) << "";
        cout << "\n_____________________________________________________________________________________________________________________\n" << endl;

        if (clients.empty()) {
            cout << colorText("\n\t\t\t\tNo Clients Available In the System!", "red") << endl;
        }
        else {

            for (const clsBankClient& c : clients) {
                PrintClientRecord(c);
            }
            cout << "\n_____________________________________________________________________________________________________________________\n" << endl;
        }

    }


};

