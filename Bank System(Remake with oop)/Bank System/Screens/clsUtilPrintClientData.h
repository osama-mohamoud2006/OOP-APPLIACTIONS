#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
#include<iomanip>

class clsUtilPrintClientData{
    public:
      static void PrintClientData(const clsBankClient &client , string NameOfList="CLIENT DETAILS")
    {

        std::cout << "\n\n";
        std::cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n";
        std::cout << setw(37) << left << "" << "   " <<
         colorText(">> "+ NameOfList+" <<", "green") << "\n";
        std::cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n\n";

        std::cout << setw(37) << left << "" << colorText("  PERSONAL INFORMATION", "lightpurple") << "\n";
        std::cout << setw(37) << left << "" << "  ----------------------------------------------\n";
        std::cout << setw(37) << left << "" << "    Name       : " << client.GetFirstName() << " " << client.GetLastName() << "\n";
        std::cout << setw(37) << left << "" << "    Email      : " << client.GetEmail() << "\n";
        std::cout << setw(37) << left << "" << "    Phone      : " << client.GetPhone() << "\n\n";

        std::cout << setw(37) << left << "" << colorText("  ACCOUNT DETAILS", "yellow") << "\n";
        std::cout << setw(37) << left << "" << "  ----------------------------------------------\n";
        std::cout << setw(37) << left << "" << "    Account No : " << colorText(client.GetAccountNumber(), "cyan") << "\n";
        std::cout << setw(37) << left << "" << "    PIN Code   : " << colorText(client.GetPin(), "yellow") << "\n";
        std::cout << setw(37) << left << "" << "    Balance    : " << colorText("$", "green") << fixed << setprecision(2) << colorText(to_string(client.GetBalance()), "green") << "\n\n";

        std::cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n\n";
    } 
};