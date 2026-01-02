#pragma once

class clsUtilFillUserData  {


public :
	static  void _FillNewUser(clsUser& User) {
        string Data = "";

        Data = clsInputAndValidation::read_full_line("\n\t\t\t\t\tEnter Password: ");
        User.SetPassword(Data);

        Data = clsInputAndValidation::read_full_line("\n\t\t\t\t\tEnter First Name: ");
        User.SetFirstName(Data);

        Data = clsInputAndValidation::read_full_line("\n\t\t\t\t\tEnter Last Name: ");
        User.SetLastName(Data);

        Data = clsInputAndValidation::read_full_line("\n\t\t\t\t\tEnter Email: ");
        User.SetEmail(Data);

        Data = clsInputAndValidation::read_full_line("\n\t\t\t\t\tEnter Phone: ");
        User.SetPhone(Data);

    }

};
