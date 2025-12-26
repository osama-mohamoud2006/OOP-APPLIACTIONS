#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsUser.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsScreen.h"

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

        for (const clsUser& u : users) { _PrintUserRecordLine(u);  cout << endl;  }
           
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};