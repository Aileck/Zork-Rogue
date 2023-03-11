#include "Item.h"

Item::Item() :Checkeable("NO ITEM","NO ITEM") {
    this->type = NO_ITEM;
}

Item::Item(string name, string description, ItemType type):Checkeable(name, description)
{
    this->type = type;
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
