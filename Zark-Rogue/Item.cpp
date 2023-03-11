#include "Item.h"

void Item::BeCheked()
{
    cout << this->GetBasicDefinition() << endl;
    cout << endl;
}

Item::ItemType Item::GetType()
{
    return this->type;
}
