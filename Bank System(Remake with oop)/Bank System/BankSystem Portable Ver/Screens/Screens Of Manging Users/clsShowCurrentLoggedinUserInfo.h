#pragma once
#include "Core Features/Global.h"
#include "Screens/Screens Of Manging Users/clsUtilPrintUserDetails.h"

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