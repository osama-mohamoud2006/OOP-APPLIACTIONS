#pragma once 
class clsLoginHistoryScreen  :  protected clsScreen
{

    static void _PrintHeader() {
        int leftPadding = 20; // Adjust for centering

        std::cout << setw(leftPadding) << "" << "| " << left << colorText("Time - Date", "lightpurple") << setw(25 - 11) << "";
        std::cout << "| " << left << colorText("UserName", "lightpurple") << setw(15 - 8) << "";
        std::cout << "| " << left << colorText("Password", "lightpurple") << setw(15 - 8) << "";
        std::cout << "| " << left << colorText("Permissions", "lightpurple") << setw(15 - 11) << "";
        std::cout << "\n" << setw(leftPadding) << "" << "_________________________________________________________________________________\n" << endl;
    }

    static void _PrintUserLoginRecord(clsUser::clsLoginHistory User) {
        int leftPadding = 20; // Same padding as header

        std::cout << setw(leftPadding) << "" << "| " << setw(25) << left << User.GetTimeDate();
        std::cout << "| " << setw(15) << left << User.GetUsername();
        std::cout << "| " << setw(15) << left << User.GetPassword();
        std::cout << "| " << setw(15) << left << User.GetPermission();
        std::cout << endl;
    }

public:
	static void ShowLoginHistoryScreen() 
	{
        if (!clsScreen::HavePermission(clsUser::eViewLoginLog)) { return;  }

		vector < clsUser::clsLoginHistory> Log = clsUser::clsLoginHistory::FileOnVector();
		clsScreen::_PrintMenuOption(colorText("         Login History Screen\n", "cyan"), "           (" + to_string(Log.size()) + ") User(s).");

        _PrintHeader();

        if (Log.empty()) {
            std::cout << colorText("\a\n\t\t\t\tNo Users Available In the System!", "red") << endl;
        }

        else {

            for (const clsUser::clsLoginHistory& U : Log) {
                _PrintUserLoginRecord(U);
            }
            std::cout << "\n_____________________________________________________________________________________________________________________\n" << endl;
        }


	}


};



