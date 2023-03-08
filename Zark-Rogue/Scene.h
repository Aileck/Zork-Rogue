#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <tuple>

#include "Checkeable.h";
#include "Enemy.h";
#include "Item.h";
#include "Weapon.h";

class Scene:public Checkeable
{
public:
	Scene(string name, string definition, int id);
	void AddEnemy(Enemy* enemy);
	void AddItem(Item* item);
	void AddWeapon(Weapon* weapon);

private:
	int id;
	vector<Enemy*> enemies;
	vector<Item*> items;
	vector<Weapon*> weapons;
	//tuple<Enemy, Weapon> eventEnemyWeapon; //To simplify this project, we won't use vectors. 


	
};

#endif