#pragma once
#include "Core Features/clsUser.h"
#include "Screens/clsScreen.h"

class clsListUsersScreen : protected clsScreen
{

private:
    static void _Header()
    {
        cout << setw(6) << left << ""
            << "| " << left << colorText("UserName", "lightpurple") << setw(12 - 8) << ""
            << "| " << left << colorText("Full Name", "lightpurple") << setw(22 - 9) << ""
            << "| " << left << colorText("Phone", "lightpurple") << setw(12 - 5) << ""
            << "| " << left << colorText("Email", "lightpurple") << setw(24 - 5) << ""
            << "| " << left << colorText("Password", "lightpurple") << setw(10 - 8) << ""
            << "| " << left << colorText("Permissions", "lightpurple") << setw(13 - 11) << ""
            << "\n      _______________________________________________________________________________________________________\n" << endl;
    }

    static void _PrintUserRecordLine(clsUser User)
    {
        cout << setw(6) << left << ""
            << "| " << setw(12) << left << User.GetUserName()
            << "| " << setw(22) << left << User.GetFullName()
            << "| " << setw(12) << left << User.GetPhone()
            << "| " << setw(24) << left << User.GetEmail()
            << "| " << setw(10) << left << User.GetPassword()
            << "| " << setw(13) << left << User.GetPermissions()
            << endl;
    }

public:

    static void ListUsersScreen() {
        vector<clsUser> users = clsUser::LoadTheWholeFileOnVector();

        clsScreen::_PrintMenuOption(colorText("        List Users Screen\n","lightpurple")," The Num Of Users In System: "+to_string(users.size()) );

        _Header();

        if(users.empty())      cout << "\n\t\t\t\tNo Users Available In the System!";
        // Update the function to not print the admin details to protect the admin's privacy 
        for ( clsUser& u : users) {  if(  u.GetUserName() != "admin")  _PrintUserRecordLine(u);  cout << endl;  } // Print Everyone Except "admin"
           
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};