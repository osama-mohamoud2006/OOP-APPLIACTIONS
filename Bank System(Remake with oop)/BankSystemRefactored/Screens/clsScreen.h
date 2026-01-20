#pragma once 
#include <iomanip>
#include <string>
#include "CoreFeatures/clsBankClient.h"
#include "CoreFeatures/clsUser.h"
#include "CoreFeatures/Global.h"
#include  "Lib/clsDate.h"

class clsScreen
{
private:

    static std::string  _GetNameOfScreen(clsUser::enUserPermission TheNameOfScreen) {

        switch (TheNameOfScreen)
        {
        case clsUser::enUserPermission::eAddClient:
            return "ADD CLIENT SCRREN";

            case  clsUser::enUserPermission::eDeleteClient:
                return "DELETE CLIENT SCRREN";

            case clsUser::enUserPermission::eUpdateClient:
                return "UPDATE CLIENT SCREEN";

                case  clsUser::enUserPermission::eFindClient :
                    return "FIND CLIENT SCREEN";

                    case  clsUser::enUserPermission::eListClients :
                        return  "LIST CLIENT SCREEN";

                        case clsUser::enUserPermission::eManageUsers :
                            return "MANAGE USERS SCREEN";

                            case clsUser::enUserPermission::eTransactions :
                                return "TRANSACTIONS SCREEN";

                            case clsUser::eViewLoginLog:
                                return  "VIEW THE LOG OF LOGIN SCREEN";
        }
        return "";
    }

        static void _PrintYouDonotHavePermission(std::string NameOfScreen) {
            system("cls");
            std::cout << std::setw(37) << std::left << "" << colorText("================================================", "red") << "\n";
            std::cout << std::setw(37) << std::left << "" << "             " << colorText(">> ACCESS DENIED <<", "red") << "\n";
            std::cout << std::setw(37) << std::left << "" << colorText("================================================", "red") << "\n\n";
            std::cout << std::setw(37) << std::left << "" << "  YOU DON'T HAVE ACCESS TO "<< NameOfScreen <<" !\n";
            std::cout << std::setw(37) << std::left << "" << colorText("================================================", "red") << "\n\n";
        }

protected:

    static void _PrintMenuOption(std::string Title, std::string SubTitle = "")
    {

        std::cout << "\n\t\t\t\t\t" << colorText("    THE CURRENT DATE IS: " + clsDate::PrintFullDateForStatic(clsDate::GetCurrentLocalDate()) ,"orange") << std::endl;
        std::cout << "\t\t\t\t\t______________________________________";
        std::cout << "\n\n\t\t\t\t\t" << Title;
        if (SubTitle != "")
        {
            std::cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        std::cout << "\n\t\t\t\t\t______________________________________\n\n";
    }

    //To Show The Current Logged in User
    static void _PrintMenuOption(std::string Title, clsUser ShowTheCurrentUser )
    {
        std::cout << "\n\t\t\t\t\t" << colorText("    THE CURRENT DATE IS: "+ clsDate::PrintFullDateForStatic(clsDate::GetCurrentLocalDate()), "orange") << std::endl;

        std::cout << "\t\t\t\t\t______________________________________";
        std::cout << "\n\n\t\t\t\t\t" << Title;


            std::cout << colorText("\n\n\t\t\t\t\t    Current Logged In As: " ,"green") << "@" << ShowTheCurrentUser.GetUserName();

        std::cout << "\n\t\t\t\t\t______________________________________\n\n";
    }

    // Print If you  Don't Have Permission  (_PrintYouDonotHavePermission )
    static bool HavePermission(clsUser::enUserPermission TheNameOfScreen , int PermissionsOfUser = GCurrentUser.GetPermissions() )
    {
        if (!(clsUser::CheckPermission(TheNameOfScreen, PermissionsOfUser))) // if he hasn't permission
        {
            _PrintYouDonotHavePermission(_GetNameOfScreen(TheNameOfScreen));
            std::cout << "\a";
          //  cout << "\n\t\t\t\t\t\a";
          //  system("pause");
            return false;
        }
        else return true ; // if he has permission
    }

    static bool EndTheScreen(short Trials )
    {
        if (Trials == 0) {
            system("cls");
            system("color 0F");
            std::cout << colorText("\n\t\t\t\t\tTRIALS EXPIRED , GET OUT!\n\n", "red");
            return true;
        }
        else return false;
    }

};