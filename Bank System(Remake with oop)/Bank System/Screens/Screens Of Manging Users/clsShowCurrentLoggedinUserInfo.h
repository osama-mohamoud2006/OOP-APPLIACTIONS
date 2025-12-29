#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\Global.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\Screens Of Manging Users\clsUtilPrintUserDetails.h"

class clsDisplayCurrentUserInfo : protected  clsScreen
{
public:
	static void DisplayCurrentUserInfo()
	{
		system("cls");
		clsScreen::_PrintMenuOption(colorText("      Display Current User Screen", "yellow"));
		clsUtilPrintUserDetails::PrintUserInfo(GCurrentUser);
	}

};