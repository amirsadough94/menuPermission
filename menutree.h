#ifndef MENUTREE_H
#define MENUTREE_H

#include <vector>
class menuTree {
public:

    menuTree(int id, bool hasPermissionSet, bool permission );

    void setParentPermission();

    void setChildPermission();

    void addChild(menuTree* child );

    menuTree* find(int id);

    bool hasParent();

    int myId;
    bool ownPermission;
    bool hasPermissionSet;
    bool finalPermission;
    menuTree* parent;
    std::vector<menuTree*> childs;
    std::vector<menuTree*> allChilds;

};



#endif // MENUTREE_H
