#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsUser.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\Screens Of Manging Users\clsUtilPrintUserDetails.h"

class clsDeleteUsersScreen :  protected clsScreen 
{

public :

   static void DeleteUser()
    {
       clsScreen::_PrintMenuOption(colorText("      Delete Users Screen","red"));

        clsUser user = clsUser::ReturnEmptyObjForInitializingUser();
        string Username = "";
        Username = clsInputAndValidation::read_string("\n\t\t\t\tEnter Username: ");

        // wonot allow to delete the "admin" as it is the main user and he controls every thing
        while (!clsUser::FindUserAndReturnObj_If_exist(Username, user) && Username == "admin")  // if the user exists 
        {
            screen_color(red);
            cout << "\n\n\t\t\t\tThe User " << Username << " isn't Exists!\a\n";
            Username = clsInputAndValidation::read_string("\n\t\t\t\tEnter Username: ");
        }

        screen_color(red_on_black);

        if (clsInputAndValidation::Confirm("\n\n\t\t\t\tAre Sure About Deleting User " + Username + " [y],[n]: "))
        {
            user.Delete();
            clsUtilPrintUserDetails::PrintUserInfo(user);
        }
        else {
            cout <<colorText( "\n\n\n\NO change!\n","pink");
        }

    }

};