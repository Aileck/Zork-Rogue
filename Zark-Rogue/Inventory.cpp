#include "Inventory.h"

Inventory::Inventory()
{
}

string Inventory::ShowAll()
{
    string out = "You glanced at the item stuck in your belt.";
    out += "\n===Your Inventory===";

    Item* newItem = new Item("1","2",Item::ItemType::Potion);
    inventoryItems.push_back(newItem);
    
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
