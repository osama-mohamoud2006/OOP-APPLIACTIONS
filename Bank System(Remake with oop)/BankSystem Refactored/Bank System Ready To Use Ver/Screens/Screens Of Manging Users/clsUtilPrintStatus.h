#pragma once 

class clsUtilPrintUserStatus
{


public :
    static void _PrintFailure(string message) {
        system("cls");
        cout << setw(37) << left << "" << colorText("================================================", "red") << "\n";
        cout << setw(37) << left << "" << "             " << colorText(">> FAILED <<", "red") << "\n";
        cout << setw(37) << left << "" << colorText("================================================", "red") << "\n\n";
        cout << setw(37) << left << "" << message << "\n";
        cout << setw(37) << left << "" << colorText("================================================", "red") ;
    }

    static void _PrintSuccess(string message) {
        system("cls");
        cout << setw(37) << left << "" << colorText("================================================", "green") << "\n";
        cout << setw(37) << left << "" << "             " << colorText(">> SUCCESS <<", "green") << "\n";
        cout << setw(37) << left << "" << colorText("================================================", "green") << "\n\n";
        cout << setw(37) << left << ""<< message << "\n";
        cout << setw(37) << left << "" << colorText("================================================", "green") ;
    }


};