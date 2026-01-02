#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsUser.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\Screens Of Manging Users\clsUtilPrintUserDetails.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\Screens Of Manging Users\clsUtilAddingPermissionsToUserYOrN.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\Screens Of Manging Users\clsUtilFillUserData.h"

class clsAddUsers : protected  clsScreen
{

private:

    static  int  _ReadUserPermission()
    {
        system("cls");
        clsScreen::_PrintMenuOption(colorText("        Adding Permissions To User", "orange"));
        return clsUtilAddingPermissionsInput::_ReadUserPermission();
    }

    static void _FillNewUser(clsUser& User) {

        cout << "\n\n";
        clsScreen::_PrintMenuOption(colorText("           Adding New User ", "green")); // will replace the clsScreen print option

        clsUtilFillUserData::_FillNewUser(User);

        /// Will add permissions later 
        if (clsInputAndValidation::Confirm(colorText("\n\n\n\t\t\t\tDo You Want To Set Full Permissions To This User[y],[n] : ", "red"))) User.SetPermissions(-1);
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

            short Trials = 5;
            while (clsUser::FindUserAndReturnObj_If_exist(Username, user))  // if the user exists 
            {
                Trials--;
                if (EndTheScreen(Trials)) return;

                screen_color(red);
                cout << "\n\n\t\t\t\t\tThe User Exists!\a\n"; // remove which user that exists for privacy 
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
                cout << colorText("\n\t\t\t\t\t\tUser: " + Username + " Added Successfully ! \n", "green");
                clsUtilPrintUserDetails::PrintUserInfo(user);
                break;
            };

            case clsUser::enSave::enUsernameExists:
            {
                system("cls");
                string message = "\n\t\t\t\t\t\t\aUsername " + Username + " Exists " + "Failed To Save";
                cout << colorText(message, "red") << endl;
                break;
            };

            case clsUser::enSave::enFailedOrEmptyToSave:
            {
                system("cls");
                cout << colorText("\n\t\t\t\t\t\tFailed To Write On File!\n\a", "red");
                break;
            };

            }

        } while (clsInputAndValidation::Confirm(colorText("\n\n\t\t\t\t\tDO YOU WANT TO ADD MORE USERS[Y],[N]: ", "green")));

    }

};