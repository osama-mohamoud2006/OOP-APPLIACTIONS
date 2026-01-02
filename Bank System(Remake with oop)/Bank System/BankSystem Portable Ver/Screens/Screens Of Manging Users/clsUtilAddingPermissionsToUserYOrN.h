#pragma once 

class clsUtilAddingPermissionsInput {

public :

     static  int  _ReadUserPermission()
    {
        int Permissions = 0;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"List Clients\" [y],[n] : ")) Permissions |= clsUser::enUserPermission::eListClients;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Add Clients\" [y],[n] : ")) Permissions |= clsUser::enUserPermission::eAddClient;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Delete Clients\" [y],[n] : "))Permissions |= clsUser::enUserPermission::eDeleteClient;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Update Clients\" [y],[n] : ")) Permissions |= clsUser::enUserPermission::eUpdateClient;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Find Clients\" [y],[n] : ")) Permissions |= clsUser::enUserPermission::eFindClient;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Do Transactions\"  : ")) Permissions |= clsUser::enUserPermission::eTransactions;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"Manage Users\"  : "))  Permissions |= clsUser::enUserPermission::eManageUsers;
        if (clsInputAndValidation::Confirm("\n\t\t\t\tDo You Want To Give Access For \"View Login Log Of Users\"  : "))  Permissions |= clsUser::enUserPermission::eViewLoginLog;

        return Permissions;
    }

};
