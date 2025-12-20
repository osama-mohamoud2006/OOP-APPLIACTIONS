#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
class clsUtilClientBalance{

	public:

        static void PrintClientBalanceRecord(clsBankClient& Client) {

            cout << "\n\n\n";
            cout << setw(37) << left << "" << colorText("================================================================", "cyan") << "\n";
            cout << setw(37) << left << "" << "        " << colorText("CLIENT BALANCE INFORMATION", "green") << "\n";
            cout << setw(37) << left << "" << colorText("================================================================", "cyan") << "\n\n";

            cout << setw(37) << left << "" << colorText("  ACCOUNT DETAILS", "yellow") << "\n";
            cout << setw(37) << left << "" << "  --------------------------------------------------------------\n";
            cout << setw(37) << left << "" << "    Account Number : " << colorText(Client.GetAccountNumber(), "cyan") << "\n";
            cout << setw(37) << left << "" << "    Client Name    : " << colorText(Client.GetFullName(), "cyan") << "\n\n";

            cout << setw(37) << left << "" << colorText("  BALANCE INFORMATION", "lightpurple") << "\n";
            cout << setw(37) << left << "" << "  --------------------------------------------------------------\n";
            cout << setw(37) << left << "" << "    Current Balance: " << colorText("$", "green") << fixed << setprecision(2) << colorText(to_string(Client.GetBalance()), "green") << "\n\n";

            cout << setw(37) << left << "" << colorText("================================================================", "cyan") << "\n\n";
        }

        static void PrintClientBalanceRecord(clsBankClient& Client, double PerviousBalance) {
            cout << "\n\n\n";
            cout << setw(37) << left << "" << colorText("================================================================", "cyan") << "\n";
            cout << setw(37) << left << "" << "        " << colorText("CLIENT BALANCE INFORMATION", "green") << "\n";
            cout << setw(37) << left << "" << colorText("================================================================", "cyan") << "\n\n";

            cout << setw(37) << left << "" << colorText("  ACCOUNT DETAILS", "yellow") << "\n";
            cout << setw(37) << left << "" << "  --------------------------------------------------------------\n";
            cout << setw(37) << left << "" << "    Account Number : " << colorText(Client.GetAccountNumber(), "cyan") << "\n";
            cout << setw(37) << left << "" << "    Client Name    : " << colorText(Client.GetFullName(), "cyan") << "\n\n";

            cout << setw(37) << left << "" << colorText("  BALANCE INFORMATION", "lightpurple") << "\n";
            cout << setw(37) << left << "" << "  --------------------------------------------------------------\n";
            cout << setw(37) << left << "" << "    Previous Balance: " << colorText("$", "yellow") << fixed << setprecision(2) << colorText(to_string(PerviousBalance), "yellow") << "\n";
            cout << setw(37) << left << "" << "    Current Balance : " << colorText("$", "green") << fixed << setprecision(2) << colorText(to_string(Client.GetBalance()), "green") << "\n\n";

            cout << setw(37) << left << "" << colorText("================================================================", "cyan") << "\n\n";
        }

};