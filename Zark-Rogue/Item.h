#ifndef ITEM_H
#define ITEM_H

#include "Checkeable.h"

/*
Only 4 items
 - Health potion
 - Map
 - Key
 - Weapon
*/

class Item :public Checkeable
{
public:
    enum ItemType {
        Potion,
        Map,
        Key,
        Weapon,
        NO_ITEM
    };
    Item();
    Item(string name, string description, ItemType type);

    void BeCheked();
    ItemType GetType();

private:
    ItemType type;
};


#endif
