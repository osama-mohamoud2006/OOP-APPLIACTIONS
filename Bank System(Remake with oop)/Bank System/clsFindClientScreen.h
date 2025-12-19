#pragma once
#include  "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Ui\clsScreen.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\clsUtilPrintClientData.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsBankClient.h"
class clsFindClientScreen : protected clsScreen
{
	
public:
	static void FindClientByAccountNumber() {
		cout << "\n\n\n\n";
		clsScreen::_PrintMenuOption(colorText("               Find Client Screen", "yellow"));
	}

};

