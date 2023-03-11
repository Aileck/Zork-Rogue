#include "Inventory.h"

void Inventory::ShowAll()
{
    for (int i = 0; i < inventoryWeapons.size(); i++) {

            inventoryWeapons.at(i)->BeCheked();

        }
    }
}
