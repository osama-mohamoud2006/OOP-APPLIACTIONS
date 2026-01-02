#pragma once
#include "../Screens/clsUtilPrintClientData.h"
#include "../Screens/clsScreen.h"
#include "../Lib/clsInputAndVaildation.h"

class clsShowDeleteClientScreen : protected clsScreen
{
public:
    static void DeleteClient()
    {

        if (!clsScreen::HavePermission(clsUser::enUserPermission::eDeleteClient)) { return; } // if he hasn't per 

        clsScreen::_PrintMenuOption(colorText("           Delete Client Screen", "red"));
        string AccountNumber = "";
        AccountNumber = clsInputAndValidation::read_string("Enter account number: ");
        clsBankClient client = clsBankClient::EmptyObjForInitializing();

        //check if client isn't existing then ask for another account number 
        short Trials = 5;
        while (!(clsBankClient::ReturnCurrentClient_if_ItExists(AccountNumber, client)))
        { // if account isn't exist then you should enter exist account number

            Trials--;
            if (EndTheScreen(Trials)) return;

            screen_color(red);
            cout << "\n\aAccount number: " << AccountNumber << " isn't exist please enter correct account number !\n";
            AccountNumber = clsInputAndValidation::read_string("\nEnter account number: ");
        }

        
        clsUtilPrintClientData::PrintClientData(client, "Client Details"); // view client details before deletion 

        // Confirming Before Deletion
        screen_color(enScreen_color::red_on_black);
        /// If y and delete done successfully 
        if (clsInputAndValidation::Confirm("\n\t\t\t\t\tAre you sure?[y],[n]: ") && client.DeleteClient())
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
