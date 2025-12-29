#pragma once 
#include <iomanip>
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsUser.h"

class clsScreen
{

protected:
    static void _PrintMenuOption(string Title, string SubTitle = "")
    {
        std::cout << "\t\t\t\t\t______________________________________";
        std::cout << "\n\n\t\t\t\t\t" << Title;
        if (SubTitle != "")
        {
            std::cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        std::cout << "\n\t\t\t\t\t______________________________________\n\n";
    }

    //To Show The Current Loggedin User 
    static void _PrintMenuOption(string Title, clsUser ShowTheCurrentUser )
    {
        std::cout << "\t\t\t\t\t______________________________________";
        std::cout << "\n\n\t\t\t\t\t" << Title;
      
        
            std::cout << colorText("\n\n\t\t\t\t\t    Current Logged In As: " ,"green") << "@" << ShowTheCurrentUser.GetUserName();
        
        std::cout << "\n\t\t\t\t\t______________________________________\n\n";
    }




};
