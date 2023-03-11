#include "Item.h"

Item::Item() :Checkeable("NO ITEM","NO ITEM") {
    this->type = NO_ITEM;
    this->location = CONSUMED;
}

Item::Item(string name, string description, ItemType type, bool inFloor):Checkeable(name, description)
{
    this->type = type;
    if (inFloor) {
        this->location = FLOOR;
    }
    else {
        this->location = INVENTORY;
    }
}

void Item::BeCheked()
{
    cout << this->GetBasicDefinition() << endl;
    cout << endl;
}

Item::ItemType Item::GetType()
{

    return this->type;
}

void Item::BePicked()
{
    location = INVENTORY;
}
