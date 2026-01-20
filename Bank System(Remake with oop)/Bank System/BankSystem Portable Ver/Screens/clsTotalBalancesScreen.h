#pragma once

#include "Screens/clsScreen.h"
#include "Core Features/clsBankClient.h"
#include "Core Features/clsManageClientBalanceAccount.h"
#include  "Lib/clsUtillity.h"

class clsTotalBalanceScreen : protected clsScreen
{

private:
    static void _PrintBalanceHeader() {
        std::cout << "| " << left << colorText("Account Number", "lightpurple") << setw(15 - 14) << "";
        std::cout << "| " << left << colorText("Client Name", "lightpurple") << setw(40 - 11) << "";
        std::cout << "| " << left << colorText("Balance", "lightpurple") << setw(20 - 7) << "";
        std::cout << "\n_____________________________________________________________________________________\n" << endl;
    }

    static void PrintClientBalanceRecord(clsBankClient Client) {
        std::cout << "| " << setw(15) << left << Client.GetAccountNumber();
        std::cout << "| " << setw(40) << left << Client.GetFullName();
        std::cout << "| " << setw(20) << left << fixed << setprecision(2) << Client.GetBalance();
        std::cout << endl;
    }

public:
    static void PrintBalancesClientList() {
        vector<clsBankClient> clients = clsBankClient::GetAllClientsInVector();

        clsScreen::_PrintMenuOption(colorText("        Total Balances Screen", "gray"));
        clsScreen::_PrintMenuOption("           (" + to_string(clients.size()) + ") Client(s).");

        _PrintBalanceHeader();

        if (clients.empty()) {
            std::cout << colorText("\a\n\t\t\t\tNo Clients Available In the System!", "red") << endl;
        }
        else {
            for (const clsBankClient& c : clients) {
                PrintClientBalanceRecord(c);
            }
            std::cout << "\n_____________________________________________________________________________________\n" << endl;

            // Total Section
            double total = clsManageClientBalance::GetTotalBalances();
            cout << "\n\t\t\t\t   " << colorText("Total Balances = $", "green") << fixed << setprecision(2) << colorText(to_string(total), "green") << endl;
            cout << "\t\t\t\t   ( " << colorText(clsUtil::NumberToText((int)total), "lightpurple") << " )" << endl;
        }
    }
};