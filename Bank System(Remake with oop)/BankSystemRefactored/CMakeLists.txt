cmake_minimum_required(VERSION 4.0)
project(BankSystemRefactored)

set(CMAKE_CXX_STANDARD 26)
target_include_directories(BankSystemRefactored PRIVATE
        ${CMAKE_SOURCE_DIR}
)

set(CMAKE_CXX_STANDARD 23)


add_executable(BankSystemRefactored main.cpp
        Lib/AllStuff.h
        Lib/logic_stuff.h
        Lib/clsUtillity.h
        Lib/clsString.h
        Lib/clsInputAndVaildation.h
        Lib/clsDate.h
        Lib/clsDate.h
        CoreFeatures/clsBankClient.h
        CoreFeatures/clsManageClientBalanceAccount.h
        CoreFeatures/clsPerson.h
        CoreFeatures/clsUser.h
        CoreFeatures/Global.h
        Screens/clsScreen.h
        "Screens/Main Menu/clsAddNewClientScreen.h"
        Screens/Utils/clsUtilAddNewClientOrUpdate.h
        Screens/Utils/clsUtilBoolFindClient.h
        Screens/Utils/clsUtilPrintClientBalance.h
        Screens/Utils/clsUtilPrintClientData.h
        "Screens/Main Menu/clsDepositScreen.h"
        "Screens/Main Menu/clsLoginHistoryScreen.h"
        "Screens/Main Menu/clsFindClientScreen.h"
        "Screens/Main Menu/clsFindAccountBalanceScreen.h"
        "Screens/Main Menu/clsLogOfTransfer.h"
        "Screens/Main Menu/clsLogOfTransferScreen.h"
        "Screens/Main Menu/clsShowDeleteScreen.h"
        "Screens/Main Menu/clsShowListScreen.h"
        "Screens/Main Menu/clsShowUpdateClientScreen.h"
        "Screens/Main Menu/clsTotalBalancesScreen.h"
        "Screens/Main Menu/clsTransferBetween2Clients.h"
        "Screens/Main Menu/clsWithDrawScreen.h"
        "Screens/Screens Of Manging Users/clsAddUsers.h"
        "Screens/Screens Of Manging Users/LoginScreen.h"
        "Screens/Screens Of Manging Users/clsUtilPrintUserDetails.h"
        "Screens/Screens Of Manging Users/clsUtilPrintStatus.h"
        "Screens/Screens Of Manging Users/clsUtilFillUserData.h"
        "Screens/Screens Of Manging Users/clsUtilAddingPermissionsToUserYOrN.h"
        "Screens/Screens Of Manging Users/clsUpdateUsersScreen.h"
        "Screens/Screens Of Manging Users/clsShowCurrentLoggedinUserInfo.h"
        "Screens/Screens Of Manging Users/clsListUsersScreen.h"
        "Screens/Screens Of Manging Users/clsFindUsersScreen.h"
        "Screens/Screens Of Manging Users/clsDeleteUsersScreen.h")
