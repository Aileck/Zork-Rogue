#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>

#include "Checkeable.h";
#include "Enemy.h";
#include "Item.h";
#include "Weapon.h";

class Inventory
{
public:
	Inventory();
	string ShowAll();
	void AddItem(Item* item);
	void AddWeapon(Weapon* weapon);
private:
	vector<Item*> inventoryItems;
	vector<Weapon*> inventoryWeapons;
};


#endif

