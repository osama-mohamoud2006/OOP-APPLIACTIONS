#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsPerson.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsScreen.h"
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h";

#include<vector>
#include<string>

class clsShowListScreen : protected clsScreen
{
private:

    static void _PrintHeader() {
        std::cout << "| " << left << colorText("Account Number", "lightpurple") << setw(15 - 14) << "";
        std::cout << "| " << left << colorText("Client Name", "lightpurple") << setw(25 - 11) << "";
        std::cout << "| " << left << colorText("Phone", "lightpurple") << setw(15 - 5) << "";
        std::cout << "| " << left << colorText("Email", "lightpurple") << setw(30 - 5) << "";
        std::cout << "| " << left << colorText("Pin Code", "lightpurple") << setw(10 - 8) << "";
        std::cout << "| " << left << colorText("Balance", "lightpurple") << setw(12 - 7) << "";
        std::cout << "\n_____________________________________________________________________________________________________________________\n" << endl;
    }

    // Print One Client Record
    static void _PrintClientRecord(clsBankClient Client) {

        std::cout << "| " << setw(15) << left << Client.GetAccountNumber();
        std::cout << "| " << setw(25) << left << Client.GetFullName();
        std::cout << "| " << setw(15) << left << Client.GetPhone();
        std::cout << "| " << setw(30) << left << Client.GetEmail();
        std::cout << "| " << setw(10) << left << Client.GetPin();
        std::cout << "| " << setw(12) << left << Client.GetBalance();
        std::cout << endl;
    }

public:

    static void PrintClientList() {

        if (!clsScreen::HavePermission(clsUser::enUserPermission::eListClients)) { return; } // if he hasn't per 

        clsScreen::_PrintMenuOption(colorText("          List Clients Screen", "purple"));
        std::vector<clsBankClient> clients = clsBankClient::GetAllClientsInVector();

        clsScreen::_PrintMenuOption(+"           (" + to_string(clients.size()) + ") Client(s).");

        _PrintHeader();


        if (clients.empty()) {
            std::cout << colorText("\a\n\t\t\t\tNo Clients Available In the System!", "red") << endl;
        }
        else {

            for (const clsBankClient& c : clients) {
                _PrintClientRecord(c);
            }
            std::cout << "\n_____________________________________________________________________________________________________________________\n" << endl;
        }

    }


};



