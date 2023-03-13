#ifndef ITEM_H
#define ITEM_H

#include "Checkeable.h"


/*
Only 4 items
 - Health potion
 - Bottle
 - Map
 - Key
 - Weapon
*/

class Item :public Checkeable
{
public:
    enum ItemType {
        Potion,
        BOTTLE,
        MAP,
        KEY,
        WEAPON,
        NO_ITEM
    };
    enum ItemLocation {
        FLOOR,
        INVENTORY,
        CONSUMED
    };
    Item();
    Item(string name, string description, ItemType type, bool inFLoor = true);

    void BeCheked();
    ItemType GetType();
    ItemLocation GetLocation();
    void BePicked();
    void BeDropped();
    void BeConsumed();
    int GetUseTime();
    void BeUsed();
    //string BeUsed(Hero* h);

protected:
    ItemType type;
    ItemLocation location;
    int useTime;
};


#endif
