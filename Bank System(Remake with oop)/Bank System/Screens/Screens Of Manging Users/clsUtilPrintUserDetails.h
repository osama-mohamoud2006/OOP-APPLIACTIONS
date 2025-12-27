#pragma once
class clsUtilPrintUserDetails {
private:

	static bool _HasPermission(int Permission, clsUser::enUserPermission HasPermission) { // Will Be Moved to clsUser later
        return ((Permission & HasPermission) == HasPermission);
    }

    static void _PrintPermissionsOfUser(const int& Permission, int leftPadding)
    {

        if (Permission == -1) {
            cout << colorText("All Permissions", "green") << "\n";
            return;
        }

        bool hasAnyPermission = false;

        if (_HasPermission(Permission, clsUser::enUserPermission::eAddClient)) {
            cout << colorText("Add Client", "green");
            hasAnyPermission = true;
        }
        if (_HasPermission(Permission, clsUser::enUserPermission::eDeleteClient)) {
            if (hasAnyPermission) cout << ", ";
            cout << colorText("Delete Client", "green");
            hasAnyPermission = true;
        }
        if (_HasPermission(Permission, clsUser::enUserPermission::eFindClient)) {
            if (hasAnyPermission) cout << ", ";
            cout << colorText("Find Client", "green");
            hasAnyPermission = true;
        }
        if (_HasPermission(Permission, clsUser::enUserPermission::eListClients)) {
            if (hasAnyPermission) cout << ", ";
            cout << colorText("List Clients", "green");
            hasAnyPermission = true;
        }
        if (_HasPermission(Permission, clsUser::enUserPermission::eUpdateClient)) {
            if (hasAnyPermission) cout << ", ";
            cout << colorText("Update Client", "green");
            hasAnyPermission = true;
        }
        if (_HasPermission(Permission, clsUser::enUserPermission::eTransactions)) {
            if (hasAnyPermission) cout << ", ";
            cout << colorText("Transactions", "green");
            hasAnyPermission = true;
        }
        if (_HasPermission(Permission, clsUser::enUserPermission::eManageUsers)) {
            if (hasAnyPermission) cout << ", ";
            cout << colorText("Manage Users", "green");
            hasAnyPermission = true;
        }

        if (!hasAnyPermission) {
            cout << colorText("No Permissions", "red");
        }

        cout << "\n";
    }

public:
    static void PrintUserInfo(clsUser& user)
    {
        // Get terminal width and calculate padding
        int terminalWidth = 120;
        int contentWidth = 48;
        int leftPadding = (terminalWidth - contentWidth) / 2;

        cout << "\n\n";
        cout << setw(leftPadding) << "" << colorText("================================================", "green") << "\n";
        cout << setw(leftPadding) << "" << "             " << colorText(">> USER CARD <<", "yellow") << "\n";
        cout << setw(leftPadding) << "" << colorText("================================================", "green") << "\n\n";

        cout << setw(leftPadding) << "" << colorText("  PERSONAL INFORMATION", "lightpurple") << "\n";
        cout << setw(leftPadding) << "" << "  ----------------------------------------------\n";
        cout << setw(leftPadding) << "" << "    Username   : " << colorText(user.GetUserName(), "cyan") << "\n";
        cout << setw(leftPadding) << "" << "    Full Name  : " << user.GetFullName() << "\n";
        cout << setw(leftPadding) << "" << "    Email      : " << user.GetEmail() << "\n";
        cout << setw(leftPadding) << "" << "    Phone      : " << user.GetPhone() << "\n\n";

        cout << setw(leftPadding) << "" << colorText("  USER DETAILS", "yellow") << "\n";
        cout << setw(leftPadding) << "" << "  ----------------------------------------------\n";
        cout << setw(leftPadding) << "" << "    Permissions: ";
        _PrintPermissionsOfUser(user.GetPermissions(), leftPadding);
        cout << setw(leftPadding) << "" << "    Password   : " << colorText(user.GetPassword(), "red") << "\n\n";

        cout << setw(leftPadding) << "" << colorText("================================================", "green") << "\n\n";
    }

};