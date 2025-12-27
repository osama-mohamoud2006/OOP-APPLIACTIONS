#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsUser.h"

class clsAddUsers : protected  clsScreen
{

private:

    static  int  _ReadUserPermission( )
    {
        system("cls");
        clsScreen::_PrintMenuOption(colorText("        Adding Permissions To User", "orange"));
        int Permissions = 0;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"List Clients \" : ")) Permissions |= clsUser::enUserPermission::eListClients;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Add Clients\" : ")) Permissions |= clsUser::enUserPermission::eAddClient;
            if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Delete Clients\" : "))Permissions |= clsUser::enUserPermission::eDeleteClient;
                if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Update Clients\" : ")) Permissions |= clsUser::enUserPermission::eUpdateClient;
                   if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \" Find Clients\" : ")) Permissions |= clsUser::enUserPermission::eFindClient;
                      if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Do Transactions\"  : ")) Permissions |= clsUser::enUserPermission::eTransactions;
                        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Manage Users\"  : "))  Permissions |= clsUser::enUserPermission::eManageUsers;

                        return Permissions;
    }

   static  void _PrintUserInfo(clsUser& user)
    {
        // Get terminal width and calculate padding
        int terminalWidth = 120; // Adjust based on your terminal size
        int contentWidth = 48;   // Width of the content box
        int leftPadding = (terminalWidth - contentWidth) / 2;

        cout << "\n\n";
        cout << setw(leftPadding) << "" << colorText("================================================", "green") << "\n";
        cout << setw(leftPadding) << "" << "             " << colorText(">> USER CARD <<", "yellow") << "\n";
        cout << setw(leftPadding) << "" << colorText("================================================", "green") << "\n\n";

        cout << setw(leftPadding) << "" << colorText("  PERSONAL INFORMATION", "lightpurple") << "\n";
        cout << setw(leftPadding) << "" << "  ----------------------------------------------\n";
        cout << setw(leftPadding) << "" << "    Username   : " << colorText(user.GetUserName(), "cyan") << "\n";
        cout << setw(leftPadding) << "" << "    Full Name  : " << user.GetFullName() << "\n";
        cout << setw(leftPadding) << "" << "    Email      : " << user.GetEmail() << "\n";
        cout << setw(leftPadding) << "" << "    Phone      : " << user.GetPhone() << "\n\n";

        cout << setw(leftPadding) << "" << colorText("  USER DETAILS", "yellow") << "\n";
        cout << setw(leftPadding) << "" << "  ----------------------------------------------\n";
        cout << setw(leftPadding) << "" << "    Permissions: " << colorText(to_string(user.GetPermissions()), "magenta") << "\n";
        cout << setw(leftPadding) << "" << "    Password   : " << colorText(user.GetPassword(), "red") << "\n\n";

        cout << setw(leftPadding) << "" << colorText("================================================", "green") << "\n\n";
    }

   static void _FillNewUser(clsUser& User) {
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
        if (clsInputAndValidation::Confirm(  colorText( "\n\t\t\t\t\tDo You Want To Set Full Permissions To This User[y],[n] : ","red") ) ) User.SetPermissions(-1);
        else  User.SetPermissions(_ReadUserPermission());
       
    }

public:

    static void AddNewUser() {

        do {
            system("cls");
            cout << "\n\n";
            clsScreen::_PrintMenuOption(colorText("        Add New User Screen", "cyan"));

            clsUser user = clsUser::ReturnEmptyObjForInitializingUser();
            string Username = "";
            Username = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter Username: ");

            while (clsUser::FindUserAndReturnObj_If_exist(Username, user))  // if the user exists 
            {
                screen_color(red);
                cout << "\n\n\t\t\t\t\tThe User " << Username << " Exists!\a\n";
                Username = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter Username: ");
            }

            system("color 0F"); // rest color 
            system("cls");

            user = clsUser::InitializeToAddNewUser();
            user.SetUsername(Username);
            _FillNewUser(user);

            clsUser::enSave SaveReuslts;
            SaveReuslts = user.Save();

            switch (SaveReuslts) {

            case clsUser::enSave::enSavedSuccessfully:
            {
                system("cls");
                cout << colorText("\n\t\t\t\t\tUser: " + Username + " Added Successfully ! \n", "green");
                _PrintUserInfo(user);
                break;
            };

            case clsUser::enSave::enUsernameExists:
            {
                system("cls");
                string message = "\n\t\t\t\t\tUsername " + Username + " Exists " + "Failed To Save";
                cout << colorText(message, "red") << endl;
                break;
            };

            case clsUser::enSave::enFailedOrEmptyToSave:
            {
                system("cls");
                cout << colorText("\n\t\t\t\t\tFailed To Write On File!\n\a", "red");
                break;
            };

            }

        } while (clsInputAndValidation::Confirm("\n\n\t\t\t\t\tDO YOU WANT TO ADD OTHER USERS[Y],[N]: "));
      
    }

};