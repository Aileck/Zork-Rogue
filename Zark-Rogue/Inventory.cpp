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

void Inventory::DropItem(Item* item, Scene* scene)
{
    item->BeDropped();
    scene->AddItem(item);
}

void Inventory::DropWeapon(Weapon* weapon, Scene* scene)
{
    weapon->BeDropped();
    scene->AddWeapon(weapon);
}

Item* Inventory::IfContainsItemAndDrop(string target, Scene* scene)
{
    // Item
    for (int i = 0; i < inventoryItems.size(); i++) {
        if (inventoryItems.at(i)->GetName(true) == target) {
            Item* copy = inventoryItems.at(i);
            inventoryItems.erase(inventoryItems.begin() + (i));
            return copy;
        }
    }

    return new Item();
}

Weapon* Inventory::IfContainsWeaponAndDrop(string target, Scene* scene)
{
    // Weapon
    for (int i = 0; i < inventoryWeapons.size(); i++) {
        if (inventoryWeapons.at(i)->GetName(true) == target) {
            Weapon* copy = inventoryWeapons.at(i);
            if (copy->GetEquipped()) {
                //Return an error
                return new Weapon(false);
            }
            inventoryWeapons.erase(inventoryWeapons.begin() + (i));
            return copy;
        }
    }

    return new Weapon();
}


