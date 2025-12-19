#pragma once

#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsUtilPrintClientData.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsScreen.h"

#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"

#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h";

class clsShowUpdateClientScreen : protected clsScreen
{

private:
    static void _EnterNewDataToUpdate(clsBankClient &Temp)
    {
        std::cout << "\n\n";
        //_PrintMenuOption(colorText("        Adding New Client", "green"));
        string DataToFill = "";

        DataToFill = clsInputAndValidation::read_string("\nEnter New First Name: ");
        Temp.SetFirstName(DataToFill);

        DataToFill = clsInputAndValidation::read_string("\nEnter New Last Name: ");
        Temp.SetLastName(DataToFill);

        DataToFill = clsInputAndValidation::read_string("\nEnter New Pin number: ");
        Temp.SetPin(DataToFill);

        DataToFill = clsInputAndValidation::read_string("\nEnter Email: ");
        Temp.SetEmail(DataToFill);

        DataToFill = clsInputAndValidation::read_string("\nEnter New Phone number: ");
        Temp.SetPhone(DataToFill);

        double balance = clsInputAndValidation::enter_postive_number("\nEnter Balance: ");
        Temp.SetBalance(balance);
    }

public:
    static void UpdateClientInfo()
    {
        clsScreen::_PrintMenuOption(colorText("          Update Client Screen", "pink"));

        string AccountNumber = "";
        AccountNumber = clsInputAndValidation::read_string("Enter Account Number: ");
        clsBankClient client = clsBankClient::EmptyObjForInitializing();

        // if the account isn't exisiting
        while (!(clsBankClient::ReturnCurrentClient_if_ItExists(AccountNumber, client)))
        {
            screen_color(red);
            cout << "\a\nAccount number: " << AccountNumber << " isn't exising!" << endl;
            cout << "Try agian !\n";
            AccountNumber = clsInputAndValidation::read_string("Enter Account Number: ");
        }

        // it will exit loop only if it found the desired account number
        system("cls");
        screen_color(black);
        cout << "\n";
        clsUtilPrintClientData::PrintClientData(client, "Current Client Info");

        if (clsInputAndValidation::Confirm(
            colorText("\n\n\t\tAre You Sure About Updating?[y],[n]: ","cyan") )  )
        {
            system("cls");
            clsScreen::_PrintMenuOption(colorText("        Updating.....", "cyan"));
            _EnterNewDataToUpdate(client); // take the new data and set them to the object
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
                cout << "failed  to save!" << endl;
            }
        }
    
        else{
            cout<<"\n\n\t\t\t\tOkay No Change Has Happned!\n";
        }
    
        screen_color(black);
    }
};