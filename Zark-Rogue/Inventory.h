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
	void ShowAll();
private:
	vector<Item*> inventoryItems;
	vector<Weapon*> inventoryWeapons;
};

#endif

