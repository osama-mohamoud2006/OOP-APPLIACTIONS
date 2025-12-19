#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h";

class clsShowDeleteClientScreen : protected clsScreen
{
private:
    static void _PrintClientData(const clsBankClient &client)
    {

        std::cout << "\n\n";
        std::cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n";
        std::cout << setw(37) << left << "" << "   " << colorText(">> CLIENT DETAILS<<", "green") << "\n";
        std::cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n\n";

        std::cout << setw(37) << left << "" << colorText("  PERSONAL INFORMATION", "lightpurple") << "\n";
        std::cout << setw(37) << left << "" << "  ----------------------------------------------\n";
        std::cout << setw(37) << left << "" << "    Name       : " << client.GetFirstName() << " " << client.GetLastName() << "\n";
        std::cout << setw(37) << left << "" << "    Email      : " << client.GetEmail() << "\n";
        std::cout << setw(37) << left << "" << "    Phone      : " << client.GetPhone() << "\n\n";

        std::cout << setw(37) << left << "" << colorText("  ACCOUNT DETAILS", "yellow") << "\n";
        std::cout << setw(37) << left << "" << "  ----------------------------------------------\n";
        std::cout << setw(37) << left << "" << "    Account No : " << colorText(client.GetAccountNumber(), "cyan") << "\n";
        std::cout << setw(37) << left << "" << "    PIN Code   : " << colorText(client.GetPin(), "yellow") << "\n";
        std::cout << setw(37) << left << "" << "    Balance    : " << colorText("$", "green") << fixed << setprecision(2) << colorText(to_string(client.GetBalance()), "green") << "\n\n";

        std::cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n\n";
    }

public:
    static void DeleteClient()
    {
        clsScreen::_PrintMenuOption(colorText("           Delete Client Screen", "red"));
        string AccountNumber = "";
        AccountNumber = clsInputAndValidation::read_string("Enter account number: ");
        clsBankClient client = clsBankClient::EmptyObjForInitializing();

        while (!(clsBankClient::ReturnCurrentClient_if_ItExists(AccountNumber, client)))
        { // if account isn't exist then you should enter exist account number
            screen_color(red);
            cout << "\n\aAccount number: " << AccountNumber << " isn't exist please enter correct account number !\n";
            AccountNumber = clsInputAndValidation::read_string("\nEnter account number: ");
        }

        // Confriming Before Deletion
        screen_color(enScreen_color::red_on_black);
        if (clsInputAndValidation::Confirm("\nAre you sure?[y],[n]: ") && client.DeleteClient())
        {
            // called delete here
            system("cls");
            std::cout << "\n\t\t\tdeleted successfully!\n";
            std::cout << "\n\t\t\tFor Confrimation Purpose!\n";
            _PrintClientData(client);
        }
        else
        {
            system("cls");
            std::cout << "\n\t\t\tNo change!\n";
            std::cout << "\n\t\t\tFor Confrimation Purpose!\n";
            _PrintClientData(client);
        }
    }
};