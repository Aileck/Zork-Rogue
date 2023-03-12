#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>

#include "Checkeable.h";
#include "Enemy.h";
#include "Scene.h";
#include "Item.h";
#include "Weapon.h";

class Inventory
{
public:
	Inventory();
	string ShowAll();
	void AddItem(Item* item);
	void AddWeapon(Weapon* weapon);
	void DropItem(Item* item, Scene* scene);
	void DropWeapon(Weapon* weapon, Scene* scene);
	Item* IfContainsItemAndDrop(string target, Scene* scene);
	Weapon* IfContainsWeaponAndDrop(string target, Scene* scene);
private:
	vector<Item*> inventoryItems;
	vector<Weapon*> inventoryWeapons;
};


#endif

