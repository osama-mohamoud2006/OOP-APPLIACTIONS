#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\Screens Of Manging Users\clsUtilPrintUserDetails.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsUser.h"

class clsUpdateUsersScreen : protected clsScreen
{
private:

    enum _enUpdateSpecific
    {
        enChageName = 1,enChangePin = 2,enchangeEmail = 3,enChangePhoneNumber = 4,enChangePassword=5 , enChangePermissions=6,  enChangeAll = 7  };

    static void _PerformAccordingTheOrder(_enUpdateSpecific WhatWillbeChanged, clsBankClient& Temp)
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

        case   _enUpdateSpecific::enChangeBalance: {
            DataToFill = "";
            double balance = 0.0;
            balance = clsInputAndValidation::enter_postive_number("\n\tEnter Balance: ");
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

    static  int  _ReadUserPermission()
    {
        system("cls");
        clsScreen::_PrintMenuOption(colorText("        Adding Permissions To User", "orange"));
        int Permissions = 0;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"List Clients\" [y],[n] : ")) Permissions |= clsUser::enUserPermission::eListClients;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Add Clients\" [y],[n] : ")) Permissions |= clsUser::enUserPermission::eAddClient;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Delete Clients\" [y],[n] : "))Permissions |= clsUser::enUserPermission::eDeleteClient;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Update Clients\" [y],[n] : ")) Permissions |= clsUser::enUserPermission::eUpdateClient;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Find Clients\" [y],[n] : ")) Permissions |= clsUser::enUserPermission::eFindClient;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Do Transactions\"  : ")) Permissions |= clsUser::enUserPermission::eTransactions;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Manage Users\"  : "))  Permissions |= clsUser::enUserPermission::eManageUsers;

        return Permissions;
    }






    static void _FillToUpdateUser(clsUser& User) {

        string Data = "";
        cout << "\n\n";
        clsScreen::_PrintMenuOption(colorText("           Adding New User ", "green")); // will replace the clsScreen print option

        Data = clsInputAndValidation::read_full_line("\n\t\t\t\t\tEnter Password: ");
        User.SetPassword(Data);

        Data = clsInputAndValidation::read_full_line("\n\t\t\t\t\tEnter First Name: ");
        User.SetFirstName(Data);

        Data = clsInputAndValidation::read_full_line("\n\t\t\t\t\tEnter Last Name: ");
        User.SetLastName(Data);

        Data = clsInputAndValidation::read_full_line("\n\t\t\t\t\tEnter Email: ");
        User.SetEmail(Data);

        Data = clsInputAndValidation::read_full_line("\n\t\t\t\t\tEnter Phone: ");
        User.SetPhone(Data);

        /// Will add permissions later 
        if (clsInputAndValidation::Confirm(colorText("\n\n\n\t\t\t\tDo You Want To Set Full Permissions To This User[y],[n] : ", "red"))) User.SetPermissions(-1);
        else  User.SetPermissions(_ReadUserPermission());

    }

public:
   static  void UpdateUser() {

        clsUser user = clsUser::ReturnEmptyObjForInitializingUser();
        string Username = "";
        Username = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter Username: ");

        while (!clsUser::FindUserAndReturnObj_If_exist(Username, user) || Username== "admin"  )  // if the user exists || it is admin cuz admin isn't preparade to be updated  
        {
            screen_color(red);
            cout << "\n\n\t\t\t\t\tThe User Doesn't Exist!\a\n"; // remove which user that doesn't exist for privacy 
            Username = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter Username: ");
        }
        
        system("color 0F"); // rest color 
        user = clsUser::InitializeForUpdatingUser(); // start Updating by Initializing the process 
        user.SetUsername(Username);

        // If y then will update all data else will update what ever you choice 
        if (clsInputAndValidation::Confirm("\n\n\t\t\t\t\tDo You Want To Update All Data Of " + Username + " [y],[n]: "))
        {
          _FillToUpdateUser(user);
        }
        else 
        {

        }
        

        clsUser::enSave SaveStatus;
        SaveStatus= user.Save();
 

    }

};