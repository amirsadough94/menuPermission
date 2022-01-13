#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

enum permissionEnum{
  T, //true
  F, //false
  U  //unknown
};
class menu
{
public:
    menu(int id, int parentId, enum permissionEnum permission);

    static void setPermission(std::vector<menu>& menus);

    static void print(std::vector<menu>& menus);

    int id;
    int parentId;
    enum permissionEnum permission;
    std::vector<int> childs;
};

#endif // MENU_H
