#include "Inventory.h"

Inventory::Inventory()
{
}

string Inventory::ShowAll()
{
    string out = "You glanced at the item stuck in your belt.";
    out += "\n===Your Inventory===";
    
    //Items
    out += "\n*Items:";
    for (int i = 0; i < inventoryItems.size(); i++) {
        out += "\n\t* " + inventoryItems.at(i)->GetName();
    }
    out += "\n*Weapons:";
    for (int i = 0; i < inventoryWeapons.size(); i++) { 
        out += "\n\t* " + inventoryWeapons.at(i)->GetName();
    }

    if (inventoryWeapons.size() > 2) {
        out += "\nYou couldn't help but marvel at how many things you could fit on your belt.";
    }


    return out;
}

void Inventory::AddItem(Item* item)
{
    item->BePicked();
    inventoryItems.push_back(item);
}

void Inventory::AddWeapon(Weapon* weapon)
{
    weapon->BePicked();
    inventoryWeapons.push_back(weapon);
}
