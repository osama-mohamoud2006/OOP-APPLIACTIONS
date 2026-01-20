#include <iostream>
#pragma once

#include "Lib/clsUtillity.h"
//core
#include "CoreFeatures/clsBankClient.h"
#include "CoreFeatures/clsPerson.h"

// Super Class Of Screens and Ui (s)
#include "Screens/clsScreen.h"

//Ui  - Main menu

#include "Ui/clsMainMenuUi.h"
#include "Screens/Utils/clsUtilPrintClientData.h"


//Screens - Main Menu
#include "Screens/Main Menu/clsShowListScreen.h"
#include "Screens/Main Menu//clsAddNewClientScreen.h"
#include "Screens/Utils/clsUtilAddNewClientOrUpdate.h"
#include "Screens/Main Menu//clsShowDeleteScreen.h"
#include "Screens/Main Menu/clsShowUpdateClientScreen.h"
#include "Screens/Main Menu//clsFindClientScreen.h"
#include "Screens/Screens Of Manging Users\clsShowCurrentLoggedinUserInfo.h"


// Core Of Each Transaction Operation
#include "CoreFeatures/clsManageClientBalanceAccount.h"

// Ui - Transactions Menu
#include "Ui/clsTransactionMenuUi.h"


// Screens - Transaction Screen
#include "Screens/Main Menu/clsDepositScreen.h"
#include  "Screens/Main Menu/clsWithDrawScreen.h"
#include "Screens/Main Menu/clsFindAccountBalanceScreen.h"
#include "Screens/Main Menu/clsTransferBetween2Clients.h"
#include "Screens/Main Menu/clsTotalBalancesScreen.h"
#include "Screens/Main Menu/clsLogOfTransferScreen.h"

// Ui - Mange Users
#include "Ui/clsManageUsersMenuUi.h"


// Core - For Managing Users
#include "CoreFeatures/clsUser.h"
#include "CoreFeatures/Global.h" /// ---> current signed in user

// Screens - For Managing Users
#include "Screens/Screens Of Manging Users\clsListUsersScreen.h"
#include "Screens/Screens Of Manging Users\clsAddUsers.h"
#include "Screens/Screens Of Manging Users\clsDeleteUsersScreen.h"
#include "Screens/Screens Of Manging Users\clsUpdateUsersScreen.h"
#include "Screens/Screens Of Manging Users\clsFindUsersScreen.h"


// Login
#include "Screens/Screens Of Manging Users\LoginScreen.h"

// login history
// #include "Screens/clsLoginHistoryScreen.h"

// Utils
#include "Screens/Utils//clsUtilPrintClientBalance.h"
#include "Screens/Screens Of Manging Users\clsUtilPrintStatus.h"
#include "Screens/Screens Of Manging Users\clsUtilPrintUserDetails.h"
#include "Screens/Screens Of Manging Users\clsUtilAddingPermissionsToUserYOrN.h"
#include "Screens/Screens Of Manging Users\clsUtilFillUserData.h"

using namespace std;
//  ctrl + m+o

// Good Bye done at : 20/1/2026 
// lol i started this project last year 



int main() {

	while (true) 	if (!clsLoginScreen::ShowLoginScreen()) break; 
}
