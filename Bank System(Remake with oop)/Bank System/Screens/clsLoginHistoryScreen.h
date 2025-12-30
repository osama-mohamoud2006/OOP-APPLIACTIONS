#pragma once 
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\clsLoginHistory.h"

class clsLoginHistoryScreen : clsScreen
{
public:
	static void ShowLoginHistoryScreen() 
	{
		vector < clsLoginHistory> Log = clsLoginHistory::FileOnVector();
		clsScreen::_PrintMenuOption(colorText("           Login History Screen", "cyan"));
	}


};


