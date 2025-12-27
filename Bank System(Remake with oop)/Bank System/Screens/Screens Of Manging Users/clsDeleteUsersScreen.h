#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsUser.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\Screens Of Manging Users\clsUtilPrintUserDetails.h"

class clsDeleteUsersScreen :  protected clsScreen 
{

private:

   static void _PrintConfirmation(string Username) {
       cout << "\n\n";
       cout << setw(37) << left << "" << colorText("================================================", "green") << "\n";
       cout << setw(37) << left << "" << "             " << colorText(">> SUCCESS <<", "green") << "\n";
       cout << setw(37) << left << "" << colorText("================================================", "green") << "\n\n";
       cout << setw(37) << left << "" << "         User Deleted Successfully!\n";
       cout << setw(37) << left << "" << "         Username: " << colorText(Username, "cyan") << "\n\n";
       cout << setw(37) << left << "" << colorText("         Note: This action is irreversible.", "yellow") << "\n\n";
       cout << setw(37) << left << "" << colorText("================================================", "green") << "\n\n";
    }

public :

   static void DeleteUser()
    {
       clsScreen::_PrintMenuOption(colorText("         Delete Users Screen","red"));

        clsUser user = clsUser::ReturnEmptyObjForInitializingUser();
        string Username = "";
        Username = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter Username: ");

        // won't allow to delete the "admin" as it is the main user and he controls every thing
        while (!clsUser::FindUserAndReturnObj_If_exist(Username, user) || Username == "admin")  // if the user exists 
        {
            screen_color(red);
            cout << "\n\n\t\t\t\t\tThe User Doesn't Exist!\a\n";  // remove which user that doesn't exist for privacy 
            Username = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter Username: ");
        }

        screen_color(red_on_black);

        if (clsInputAndValidation::Confirm("\n\n\t\t\t\t\tAre Sure About Deleting User " + Username + " [y],[n]: "))
        {
            system("cls");
            _PrintConfirmation(Username);
            user.Delete();
            clsUtilPrintUserDetails::PrintUserInfo(user);
        }
        else {
            system("cls");
            cout <<colorText( "\n\n\n\t\t\t\t\t\tNO CHANGE!\n","pink");
        }

    }

};