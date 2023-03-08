#include "Scene.h"

Scene::Scene(string name, string definition, int id):Checkeable(name, definition)
{
	this->id = id;
}

void Scene::AddEnemy(Enemy* enemy)
{
	enemies.push_back(enemy);
}

void Scene::AddItem(Item* item)
{
	items.push_back(item);
}

void Scene::AddWeapon(Weapon* weapon)
{
	weapons.push_back(weapon);
}

Checkeable* Scene::IfContains(string s)
{
	//Enemy
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies.at(i)->GetName(true) == s) {
			enemies.at(i)->BeCheked();
			return enemies.at(i);
		}
	}

	//Item
	//for (int i = 0; i < items.size(); i++) {
	//	if (items.at(i)->GetName(true) == s) {
	//		return items.at(i);
	//	}
	//}
	
	//Weapon
	cout << weapons.size() << endl;
	for (int i = 0; i < weapons.size(); i++) {
		cout << weapons.at(i)->GetName(true) << " " << s << endl;
		if (weapons.at(i)->GetName(true) == s) {
			weapons.at(i)->BeCheked();
			return weapons.at(i);
		}
	}

	Checkeable* notfound = new Checkeable();
	return notfound;
}

