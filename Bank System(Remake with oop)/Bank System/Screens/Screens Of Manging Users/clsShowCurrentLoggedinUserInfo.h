#pragma once
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Core Features\Global.h"
#include "E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\Screens\Screens Of Manging Users\clsUtilPrintUserDetails.h"

class clsDisplayCurrentUserInfo
{
public:
	static void DisplayCurrentUserInfo()
	{
		system("cls");
		clsUtilPrintUserDetails::PrintUserInfo(GCurrentUser);
	}

};