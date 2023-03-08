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
