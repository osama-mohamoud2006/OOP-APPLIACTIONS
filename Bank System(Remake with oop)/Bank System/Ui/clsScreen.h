#pragma once 
#include <iostream>
#include <iomanip>


class clsScreen
{

protected:
    static void _ShowScreenHeader(string Title, string SubTitle = "")
    {
        std::cout << "\t\t\t\t\t______________________________________";
        std::cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            std::cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        std::cout << "\n\t\t\t\t\t______________________________________\n\n";
    }

  static  void _PrintMenuOption(string option_name) {
        std::cout << "\n_________________________________________________\n\n\n";
        std::cout << "\t" << option_name << "\n";
        std::cout << "\n_________________________________________________\n";
    }


};
