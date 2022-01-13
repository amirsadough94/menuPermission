simple app to assign permision to menus

the problem has these assumptiom
  1)every menu may have zero or more submenu as child, but one parrent at most
  2)every menu may have set its permission to true or false, or unset to inherit from its parrent
  3)if a child's permission has been set to true, it parent permission must be set to true up to parent (to be able to have access to that child)
 
to solve this problem, i have created menu object representing the menu it self containing
  id
  parent id
  permission (true, false, unknown)
and menuTree class to create a graph and assing proper permission.
each menuTree has ownPermision which is the permission the menu has, and final permission which is the permission it must have. for example, a menu has set to be false, but must be shown as one of its child has permission of true;
