#include "menutree.h"



menuTree::menuTree(int id, bool hasPermissionSet, bool permission)
{
    myId = id;
    this->hasPermissionSet = hasPermissionSet;
    this->ownPermission = permission;
    finalPermission = permission;
    parent = nullptr;
}


void menuTree::setParentPermission()
{
    if(parent == nullptr) return;
    parent->finalPermission = true;
    if(parent->hasParent()) parent->setParentPermission();
}

void menuTree::setChildPermission()
{
    for(auto i = childs.begin(); i != childs.end(); i++)
    {
        if((*i)->hasPermissionSet == false )
        {
            (*i)->finalPermission = true;
            (*i)->setChildPermission();
        }
    }
}

void menuTree::addChild(::menuTree *child)
{
    child->parent = this;
    childs.push_back(child);
}

menuTree *menuTree::find(int id)
{
    menuTree* thisChild = nullptr;
    for(auto child = allChilds.begin(); child != allChilds.end(); child++)
    {
        if((*child)->myId == id)
        {
            thisChild = (*child);
            break;
        }
    }
    return thisChild;

}

bool menuTree::hasParent()
{
    return (parent != nullptr);
}


