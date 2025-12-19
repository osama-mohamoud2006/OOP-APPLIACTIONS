#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsUtilPrintClientData.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h";

class clsShowDeleteClientScreen : protected clsScreen
{
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

        // Confirming Before Deletion
        screen_color(enScreen_color::red_on_black);
        if (clsInputAndValidation::Confirm("\nAre you sure?[y],[n]: ") && client.DeleteClient())
        {
            // called delete here
            system("cls");
            std::cout << "\n\t\t\tdeleted successfully!\n";
            std::cout << "\n\t\t\tFor Conformation Purpose!\n";
             clsUtilPrintClientData::PrintClientData(client,"Client Details");
        }
        else
        {
            system("cls");
            std::cout << "\n\t\t\tNo change!\n";
            std::cout << "\n\t\t\tFor Conformation Purpose!\n";
            clsUtilPrintClientData::PrintClientData(client,"Client Details");
        }
    }

};