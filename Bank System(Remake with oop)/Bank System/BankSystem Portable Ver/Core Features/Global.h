#pragma once
#include "../Core Features/clsUser.h"

// This header will have the things that should be accessed for all classes 

clsUser GCurrentUser = clsUser::ReturnEmptyObjForInitializingUser(); // Current user 

string SuperUser = "admin"; /// the admin of the system that have same exceptions 
