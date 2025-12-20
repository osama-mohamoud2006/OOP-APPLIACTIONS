#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h" // core 
#include   "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsManageClientBalanceAccount.h" // core -- > WithDraw 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsUtilPrintClientBalance.h"

class clsWithDrawScreen : protected clsScreen
{
private:
    static void _PrintWithdrawSuccessful() {
        cout << "\n\n";
        cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n";
        cout << setw(37) << left << "" << "             " << colorText(">> SUCCESS <<", "green") << "\n";
        cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n\n";
        cout << setw(37) << left << "" << "         Withdrawn Successfully!\n";
        cout << setw(37) << left << "" << "         Transaction completed.\n\n";
        cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n\n";
    }

    static void _PrintWithdrawFailed() {
        cout << "\n\n";
        cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n";
        cout << setw(37) << left << "" << "  " << colorText(">> FAILED <<", "red") << "\n";
        cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n\n";
        cout << setw(37) << left << "" << " Withdrawal Failed!\n";
        cout << setw(37) << left << "" << " Transaction could not be completed.\n\n";
        cout << setw(37) << left << "" << colorText("================================================", "cyan") << "\n\n";
    }

public:

    static void clsWithDrawFromClientScreen() 
    {

   }



};

