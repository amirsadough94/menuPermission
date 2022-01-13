#include <vector>
#include "menu.h"
#include "menutree.h"
#include <iostream>
int main(int argc, char *argv[])
{

    std::vector<menu> menus;

//              1
//       ---------------
//        2            3
//   -----------    --------
//    4   5   6     7      8
//           ---
//            9

    menus.push_back(menu(1,-1,permissionEnum::T));
    menus.push_back(menu(2,1,permissionEnum::F));
    menus.push_back(menu(3,1,permissionEnum::U));
    menus.push_back(menu(4,2,permissionEnum::U));
    menus.push_back(menu(5,2,permissionEnum::U));
    menus.push_back(menu(6,2,permissionEnum::T));
    menus.push_back(menu(7,3,permissionEnum::U));
    menus.push_back(menu(8,3,permissionEnum::U));
    menus.push_back(menu(9,6,permissionEnum::F));

    std::cout << "before setting proper permission..." << std::endl << std::endl;
    menu::print(menus);
    std::cout << "===================================" << std::endl ;
    std::cout << "after setting proper permission..." << std::endl << std::endl;
    menu::setPermission(menus);
    menu::print(menus);

    return 0;
}
