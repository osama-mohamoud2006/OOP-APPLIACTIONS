#pragma once 
#include <iomanip>
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"

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

    // PrintBasicPersonData person data 
 /*   static  void PrintBasicPersonData(const clsBankClient &client) {
        std::cout << "\nThe First Name is : " << client.GetFirstName() << endl;
        std::cout << "The Last Name  is : " << client.GetLastName() << endl;
        std::cout << "The Email is : " << client.GetEmail() << endl;
        std::cout << "The Phone Number is : " << client.GetPhone() << endl;

    }*/




};
