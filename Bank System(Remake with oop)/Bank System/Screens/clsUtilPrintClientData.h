#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
#include<iomanip>

class clsUtilPrintClientData{
    public:
        static void PrintClientData(const clsBankClient& client, string NameOfList = "        CLIENT DETAILS   ")
        {
            // Get terminal width
            int terminalWidth = 120; // Adjust based on your terminal size
            int contentWidth = 48;   // Width of the content box
            int leftPadding = (terminalWidth - contentWidth) / 2;

            std::cout << "\n\n";
            std::cout << setw(leftPadding) << "" << colorText("================================================", "cyan") << "\n";
            std::cout << setw(leftPadding) << "" << "   " << colorText(">> " + NameOfList + " <<", "green") << "\n";
            std::cout << setw(leftPadding) << "" << colorText("================================================", "cyan") << "\n\n";

            std::cout << setw(leftPadding) << "" << colorText("  PERSONAL INFORMATION", "lightpurple") << "\n";
            std::cout << setw(leftPadding) << "" << "  ----------------------------------------------\n";
            std::cout << setw(leftPadding) << "" << "    Name       : " << client.GetFirstName() << " " << client.GetLastName() << "\n";
            std::cout << setw(leftPadding) << "" << "    Email      : " << client.GetEmail() << "\n";
            std::cout << setw(leftPadding) << "" << "    Phone      : " << client.GetPhone() << "\n\n";

            std::cout << setw(leftPadding) << "" << colorText("  ACCOUNT DETAILS", "yellow") << "\n";
            std::cout << setw(leftPadding) << "" << "  ----------------------------------------------\n";
            std::cout << setw(leftPadding) << "" << "    Account No : " << colorText(client.GetAccountNumber(), "cyan") << "\n";
            std::cout << setw(leftPadding) << "" << "    PIN Code   : " << colorText(client.GetPin(), "yellow") << "\n";
            std::cout << setw(leftPadding) << "" << "    Balance    : " << colorText("$", "green") << fixed << setprecision(2) << colorText(to_string(client.GetBalance()), "green") << "\n\n";

            std::cout << setw(leftPadding) << "" << colorText("================================================", "cyan") << "\n\n";
        }
};