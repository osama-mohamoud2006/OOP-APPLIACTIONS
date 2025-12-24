#include <iostream>
#include"E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\clsInputAndVaildation.h"
#include "E:\projects\my library\AllStuff.h"
#include "AllClasses.h" 
#include <string>
#include <iomanip>
using namespace std;

///  ctrl + m+o

void PrintUserInfo(clsUser& user)
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

    cout << setw(leftPadding) << "" << colorText("  ACCOUNT DETAILS", "yellow") << "\n";
    cout << setw(leftPadding) << "" << "  ----------------------------------------------\n";
    cout << setw(leftPadding) << "" << "    Permissions: " << colorText(to_string(user.GetPermissions()), "magenta") << "\n";
    cout << setw(leftPadding) << "" << "    Password   : " << colorText(user.GetPassword(), "red") << "\n\n";

    cout << setw(leftPadding) << "" << colorText("================================================", "green") << "\n\n";
}

void AddNewUser(clsUser & User) {
	string Data = "";

	cout << "\n\n\t\t\t\tAdding New User:\n"; // will replace the clsScreen print option

    //Data = clsInputAndValidation::read_full_line("\nEnter Username: ");


    Data = clsInputAndValidation::read_full_line("\nEnter password: ");
    User.SetPassword(Data);

    Data = clsInputAndValidation::read_full_line("\nEnter first name: ");
	User.SetFirstName(Data);

	Data = clsInputAndValidation::read_full_line("\nEnter last name: ");
	User.SetLastName(Data);

	Data = clsInputAndValidation::read_full_line("\nEnter email: ");
	User.SetEmail(Data);

	Data = clsInputAndValidation::read_full_line("\nEnter phone: ");
	User.SetPhone(Data);

	/// Will add permissions later 
    User.SetPermissions(0);


}

void FindUser() 
{
	string UserName = "";
	clsUser user = clsUser::ReturnEmptyObjForInitializingUser();
	UserName = clsInputAndValidation::read_string("\n\t\t\t\tEnter Username : ");

	while (!( clsUser::FindUserAndReturnObj_If_exist(UserName,user) )  )  // if it isn't existing 
	{
		screen_color(red); 
		cout << "\n\t\t\t\t\aThe Username " << UserName << " isn't existing !\n";
		UserName = clsInputAndValidation::read_string("\n\t\t\t\tEnter Another Username : ");
	}
	system("color 0F"); // rest color 
	cout<< "\n\nthe User is found successfully \n";
	PrintUserInfo(user);

}

void AddNewUser() {

    clsUser user = clsUser::ReturnEmptyObjForInitializingUser();
    string Username = "";
    Username = clsInputAndValidation::read_string("\n\t\t\t\tEnter Username: ");

    while (clsUser::FindUserAndReturnObj_If_exist(Username, user) )  // if the user exists 
    {
        screen_color(red);
        cout << "\n\n\t\t\t\tThe User " << Username << " Exists!\a\n";
        Username = clsInputAndValidation::read_string("\n\t\t\t\tEnter Username: ");
    }
    system("color 0F"); // rest color 
    user = clsUser::InitializeToAddNewUser(); 
    user.SetUsername(Username);
    AddNewUser(user);
    clsUser::enSave SaveReuslts;
    SaveReuslts= user.Save();
    
    if (clsUser::enSave::enSavedSuccessfully == SaveReuslts ) {
        //cout << "\n\t\t\t\tSaved Successfully!\n";
        cout << colorText("User: " + Username + " Added Successfully ! \n", "green");
        PrintUserInfo(user);
    }
    else  if (clsUser::enSave::enUsernameExists == SaveReuslts) {
        string message = "\n\t\t\t\tUsername " + Username + " Exists " + "Failed To Save";
        cout << colorText(message, "red") << endl;
    }
    else cout << colorText("\n\t\t\t\tFailed To Write On File!\n\a","red");



}


int main() {


///clsMainMenuScreen::_ShowMainMenuScreen();

	//FindUser();
    // AddNewUser();
}
