#pragma once

class clsUtilPrintUserDetails {
private:

    static void _PrintPermissionsOfUser(const int& Permission, int leftPadding)
    {

        if (Permission == -1) {
            cout << colorText("All Permissions", "green") << "\n";
            return;
        }

        bool hasAnyPermission = false;

        if (clsUser::CheckPermission(clsUser::enUserPermission::eAddClient, Permission)) {
            cout << colorText("Add Client", "green");
            hasAnyPermission = true;
        }

        if ( clsUser::CheckPermission(clsUser::enUserPermission::eDeleteClient , Permission) ) {
            if (hasAnyPermission) cout << ", ";
            cout << colorText("Delete Client", "green");
            hasAnyPermission = true;
        }

        if (clsUser::CheckPermission(clsUser::enUserPermission::eFindClient, Permission)) {
            if (hasAnyPermission) cout << ", ";
            cout << colorText("Find Client", "green");
            hasAnyPermission = true;
        }

        if (clsUser::CheckPermission(clsUser::enUserPermission::eListClients, Permission)) {
            if (hasAnyPermission) cout << ", ";
            cout << colorText("List Clients", "green");
            hasAnyPermission = true;
        }

        if (clsUser::CheckPermission(clsUser::enUserPermission::eUpdateClient, Permission)) {
            if (hasAnyPermission) cout << ", ";
            cout << colorText("Update Client", "green");
            hasAnyPermission = true;
        }

        if (clsUser::CheckPermission(clsUser::enUserPermission::eTransactions, Permission)) {
            if (hasAnyPermission) cout << ", ";
            cout << colorText("Transactions", "green");
            hasAnyPermission = true;
        }

        if (clsUser::CheckPermission(clsUser::enUserPermission::eManageUsers, Permission))  {
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