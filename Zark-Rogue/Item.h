#ifndef ITEM_H
#define ITEM_H

#include "Checkeable.h"

/*
Only 3 items
 - Health potion
 - Map
 - Key
*/

class Item :public Checkeable
{
public:
    Item(string name, string description);
    enum ItemType {
        Potion,
        Map,
        Key,
        Weapon
    };
    void BeCheked();
    ItemType GetType();

private:
    ItemType type;
};


#endif
