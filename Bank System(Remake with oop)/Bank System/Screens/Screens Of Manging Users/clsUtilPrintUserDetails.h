#pragma once

class clsUtilPrintUserDetails {

public:
    static  void  PrintUserInfo(clsUser& user)
    {
        // Get terminal width and calculate padding
        int terminalWidth = 120; // Adjust based on your terminal size
        int contentWidth = 48;   // Width of the content box
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
        cout << setw(leftPadding) << "" << "    Permissions: " << colorText(to_string(user.GetPermissions()), "magenta") << "\n";
        cout << setw(leftPadding) << "" << "    Password   : " << colorText(user.GetPassword(), "red") << "\n\n";

        cout << setw(leftPadding) << "" << colorText("================================================", "green") << "\n\n";
    }

};