#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsLoginHistory.h"

class clsLoginHistoryScreen : clsScreen
{

    static void _PrintHeader() {
        std::cout << "| " << left << colorText("Time - Date", "lightpurple") << setw(25 - 11) << "";
        std::cout << "| " << left << colorText("UserName", "lightpurple") << setw(15 - 8) << "";
        std::cout << "| " << left << colorText("Password", "lightpurple") << setw(15 - 8) << "";
        std::cout << "| " << left << colorText("Permissions", "lightpurple") << setw(15 - 11) << "";
        std::cout << "\n_________________________________________________________________________________\n" << endl;
    }

    static void _PrintUserLoginRecord(clsLoginHistory User) {
        std::cout << "| " << setw(25) << left << User.GetTimeDate();
        std::cout << "| " << setw(15) << left << User.GetUsername();
        std::cout << "| " << setw(15) << left << User.GetPassword();
        std::cout << "| " << setw(15) << left << User.GetPermission();
        std::cout << endl;
    }

public:
	static void ShowLoginHistoryScreen() 
	{
		vector < clsLoginHistory> Log = clsLoginHistory::FileOnVector();
		clsScreen::_PrintMenuOption(colorText("          Login History Screen\n", "cyan"), "           (" + to_string(Log.size()) + ") User(s).");

        _PrintHeader();

        if (Log.empty()) {
            std::cout << colorText("\a\n\t\t\t\tNo Users Available In the System!", "red") << endl;
        }

        else {

            for (const clsLoginHistory& U : Log) {
                _PrintUserLoginRecord(U);
            }
            std::cout << "\n_____________________________________________________________________________________________________________________\n" << endl;
        }

	}


};


