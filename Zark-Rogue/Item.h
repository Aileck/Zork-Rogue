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
        MAP,
        KEY,
        WEAPON,
        NO_ITEM
    };
    enum ItemLocation {
        FLOOR,
        INVENTORY,
        CONSUMED,
    };
    Item();
    Item(string name, string description, ItemType type, bool inFLoor = true);

    void BeCheked();
    ItemType GetType();

protected:
    ItemType type;
    ItemLocation location;
};


#endif
