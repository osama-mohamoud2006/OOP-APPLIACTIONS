#pragma once

#include "Screens/clsUtilPrintClientData.h"
#include "Screens/clsScreen.h"
#include "Core Features/clsBankClient.h"
#include "Lib/clsInputAndVaildation.h" 
#include "Screens/clsUtilAddNewClientOrUpdate.h"

class clsShowUpdateClientScreen : protected clsScreen
{

private:
    static void _EnterNewDataToUpdate(clsBankClient &Temp)
    {
        std::cout << "\n\n";
        clsUtilAddOrUpdateClient::EnterDataOfClient(Temp);
  
    }

    enum _enUpdateSpecific
    {
        enChageName = 1,
        enChangePin = 2,
        enchangeEmail = 3,
        enChangePhoneNumber = 4,
        enChangeBalance = 5,
        enChangeAll = 6
    };

    static void _PerformAccordingTheOrder(_enUpdateSpecific WhatWillbeChanged, clsBankClient &Temp)
    {
        cout << "\n\n";
        string DataToFill = "";
        switch (WhatWillbeChanged)
        {

        case   _enUpdateSpecific::enChageName: {

            DataToFill = clsInputAndValidation::read_string("\n\tEnter New First Name: ");
            Temp.SetFirstName(DataToFill);
            DataToFill = clsInputAndValidation::read_string("\n\tEnter New Last Name: ");
            Temp.SetLastName(DataToFill);

            break;
        }

        case  _enUpdateSpecific::enChangePin: {
            DataToFill = clsInputAndValidation::read_string("\n\tEnter New Pin number: ");
            Temp.SetPin(DataToFill);
            break;
        }

        case _enUpdateSpecific::enchangeEmail: {
            DataToFill = clsInputAndValidation::read_string("\n\tEnter Email: ");
            Temp.SetEmail(DataToFill);
            break;
        }

        case  _enUpdateSpecific::enChangePhoneNumber: {
            DataToFill = clsInputAndValidation::read_string("\n\tEnter New Phone number: ");
            Temp.SetPhone(DataToFill);
            break;
        }

        case   _enUpdateSpecific::enChangeBalance :{
            DataToFill = "";
            double balance = 0.0;
            balance = clsInputAndValidation::clsReadNum<double>::enter_postive_number("\n\tEnter Balance: ");
            Temp.SetBalance(balance);
            break;
        }
          

        case  _enUpdateSpecific::enChangeAll: {
            DataToFill = "";
            _EnterNewDataToUpdate(Temp);
            break;
        }
         
        }


    }

    static void _ShowUpdateOptionsMenu()
    {
        std::cout << setw(37) << left << "" << "===========================================\n";
        std::cout << setw(37) << left << "" << "\t[1] Change The Name Only.\n";
        std::cout << setw(37) << left << "" << "\t[2] Change The Pin Only.\n";
        std::cout << setw(37) << left << "" << "\t[3] Change The Email Only.\n";
        std::cout << setw(37) << left << "" << "\t[4] Change The Phone Number Only.\n";
        std::cout << setw(37) << left << "" << "\t[5] Change The Balance Only.\n";
        std::cout << setw(37) << left << "" << "\t[6] Update All Client Info.\n";

        std::cout << setw(37) << left << "" << "===========================================\n\n";
    }

public:
    static void UpdateClientInfo()
    {

        if (!clsScreen::HavePermission(clsUser::enUserPermission::eUpdateClient)) { return; } // if he hasn't per 

        clsScreen::_PrintMenuOption(colorText("          Update Client Screen", "pink"));

        string AccountNumber = "";
        AccountNumber = clsInputAndValidation::read_string("Enter Account Number: ");
        clsBankClient client = clsBankClient::EmptyObjForInitializing();

        // if the account isn't existing
        short Trials = 5;
        while (!(clsBankClient::ReturnCurrentClient_if_ItExists(AccountNumber, client)))
        {
            Trials--;
            if (EndTheScreen(Trials)) return;

            screen_color(red);
            cout << "\a\nAccount number: " << AccountNumber << " isn't existing!" << endl;
            cout << "Try again !\n";
            AccountNumber = clsInputAndValidation::read_string("Enter Account Number: ");
        }

        //  will exit loop only if it found the desired account number
        system("cls");
        screen_color(black);
        cout << "\n";
        clsUtilPrintClientData::PrintClientData(client, "Current Client Info");

        if (clsInputAndValidation::Confirm(
                colorText("\n\n\t\tAre You Sure About Updating?[y],[n]: ", "cyan"))) {

            system("cls");
            clsScreen::_PrintMenuOption(colorText("        Updating.....", "cyan"));
            _ShowUpdateOptionsMenu();

            _PerformAccordingTheOrder( (_enUpdateSpecific)clsInputAndValidation::clsReadNum<short>::enter_number_from_to(1, 6, "\t\t\t\tEnter What You Want To Change"), client);

            clsBankClient::enSaveMode FinalSave;
            FinalSave = client.Save();
            if (FinalSave == clsBankClient::enSaveMode::SuccessedToSave)
            {
                screen_color(green);
                cout << "\n\n\n\t\t\t\tUpdated Successfully!" << endl;
            }
            else
            {
                screen_color(red);
                cout << "\n\n\n\t\t\t\tfailed  to save!" << endl;
            }

        }

        else
        {
            cout << "\n\n\t\t\t\tOkay No Change Has Happened!\n";
        }

        screen_color(black);
    }


};