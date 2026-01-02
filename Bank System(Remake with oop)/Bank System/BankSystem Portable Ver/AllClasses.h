#pragma once

#include "Lib/clsUtillity.h"
//core
#include "Core Features/clsBankClient.h"
#include "Core Features/clsPerson.h"

// Super Class Of Screens and Ui (s)
#include "Screens/clsScreen.h"

//Ui  - Main menu 

#include "Ui/clsMainMenuUi.h"
#include "Screens/clsUtilPrintClientData.h"


//Screens - Main Menu 
#include "Screens/clsShowListScreen.h"
#include "Screens/clsAddNewClientScreen.h"
#include "Screens/clsUtilAddNewClientOrUpdate.h"
#include "Screens/clsShowDeleteScreen.h"
#include "Screens/clsShowUpdateClientScreen.h"
#include "Screens/clsFindClientScreen.h"
#include "Screens/Screens Of Manging Users\clsShowCurrentLoggedinUserInfo.h"


// Core Of Each Transaction Operation
#include "Core Features/clsManageClientBalanceAccount.h"

// Ui - Transactions Menu 
#include "Ui/clsTransactionMenuUi.h"


// Screens - Transaction Screen 
#include "Screens/clsDepositScreen.h"
#include  "Screens/clsWithDrawScreen.h"
#include "Screens/clsFindAccountBalanceScreen.h"
#include "Screens/clsTransferBetween2Clients.h"
#include "Screens/clsTotalBalancesScreen.h"
#include "Screens/clsLogOfTransferScreen.h"

// Ui - Mange Users
#include "Ui/clsManageUsersMenuUi.h"


// Core - For Managing Users
#include "Core Features/clsUser.h"
#include "Core Features/Global.h" /// ---> current signed in user 

// Screens - For Managing Users
#include "Screens/Screens Of Manging Users\clsListUsersScreen.h"
#include "Screens/Screens Of Manging Users\clsAddUsers.h"
#include "Screens/Screens Of Manging Users\clsDeleteUsersScreen.h"
#include "Screens/Screens Of Manging Users\clsUpdateUsersScreen.h"
#include "Screens/Screens Of Manging Users\clsFindUsersScreen.h"


// Login 
#include "Screens/Screens Of Manging Users\LoginScreen.h"

// login history 
#include "Screens/clsLoginHistoryScreen.h"

// Utils
#include "Screens/clsUtilPrintClientBalance.h"
#include "Screens/Screens Of Manging Users\clsUtilPrintStatus.h"
#include "Screens/Screens Of Manging Users\clsUtilPrintUserDetails.h"
#include "Screens/Screens Of Manging Users\clsUtilAddingPermissionsToUserYOrN.h"
#include "Screens/Screens Of Manging Users\clsUtilFillUserData.h"
