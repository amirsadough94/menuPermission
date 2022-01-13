#include "menu.h"
#include "menutree.h"
#include "iostream"
#include "inttypes.h"
menu::menu(int id, int parentId, permissionEnum permission)
{
    this->id = id;
    this->parentId = parentId;
    this->parentId = parentId;
    this->permission = permission;
}

void menu::setPermission(std::vector<menu> &menus)
{

    menuTree* root = new menuTree(-1,false,false);
    auto it = menus.begin();
    do{
        bool hasPermission,permission;
        if((*it).permission != permissionEnum::U)
        {
            hasPermission = true;
            permission = ((*it).permission == permissionEnum::T) ?
                                true :false;
        }
        else
        {
            hasPermission = false;
            permission = false;

        }

        menuTree* thisChild = new menuTree((*it).id,
                                           hasPermission,permission);

        root->allChilds.push_back(thisChild);

        if((*it).parentId == -1)
            root->addChild(thisChild);

        ++it;
    }while(it != menus.end());

    for(;;)
    {
        bool completed = false;
        for(auto it = menus.begin();
                 it != menus.end();
                 it++)
        {
            int id = (*it).id;
            int parentId = (*it).parentId;

            menuTree* thisChild;

            thisChild = root->find(id);

            if(!thisChild->hasParent())
            {
                auto tempParent = root->find(parentId);
                if(tempParent != nullptr) tempParent->addChild(thisChild);
            }

        }

        completed = true;
        for(auto i = root->allChilds.begin(); i != root->allChilds.end(); i++)
        {
            if(!(*i)->hasParent())
            {
                completed = false;
                break;
            }
        }

        if(completed) break;

    }


    for(auto i = root->allChilds.begin(); i != root->allChilds.end(); i++)
    {
        if ((*i)->hasPermissionSet)
        {
            if((*i)->ownPermission == true)
            {
                (*i)->setChildPermission();
                (*i)->setParentPermission();

            }
        }

    }

    for(auto j = menus.begin() ; j != menus.end() ; j++)
    {
        for(auto i = root->allChilds.begin(); i != root->allChilds.end(); i++)
        {
            if((*j).id == (*i)->myId)
            {
                (*j).permission = (*i)->finalPermission ?
                                        permissionEnum::T :
                                        permissionEnum::F;

                delete (*i);
                root->allChilds.erase(i);

                break;
            }
        }

    }




        delete root;
}

void menu::print(std::vector<menu> &menus)
{
    for(auto j = menus.begin() ; j != menus.end() ; j++)
    {
        std::string permission;
        switch ((*j).permission ) {
        case permissionEnum::F:
            permission = "false";
            break;
        case permissionEnum::T:
            permission = "true";
            break;
        default:
            permission = "unknown";
            break;
        }
        std::cout << "the permission of " << (*j).id << " is " << permission << std::endl;

    }
}
