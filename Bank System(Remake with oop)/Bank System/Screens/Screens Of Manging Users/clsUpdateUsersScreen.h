#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\Screens Of Manging Users\clsUtilPrintUserDetails.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsUser.h"

class clsUpdateUsersScreen : protected clsScreen
{
private:

public:
   static  void UpdateUser() {

        clsUser user = clsUser::ReturnEmptyObjForInitializingUser();
        string Username = "";
        Username = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter Username: ");

        while (!clsUser::FindUserAndReturnObj_If_exist(Username, user))  // if the user exists 
        {
            screen_color(red);
            cout << "\n\n\t\t\t\t\tThe User Doesn't Exist!\a\n";
            Username = clsInputAndValidation::read_string("\n\t\t\t\t\tEnter Username: ");
        }
        
        system("color 0F"); // rest color 
        user = clsUser::InitializeForUpdatingUser(); // start Updating by Initializing the process 
        user.SetUsername(Username);

        //AddNewUser(user);
        clsUser::enSave;
        //user.Update();

    }

};