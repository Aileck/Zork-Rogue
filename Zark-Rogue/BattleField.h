#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <vector>
#include <math.h>
#include <algorithm>

#include "Creature.h"
#include "Hero.h"
#include "Enemy.h"
class BattleField
{
public:
	void PrepareBattle(vector<Enemy*> newEmemies);
	//void ReOrder();
	//void PlayerAction();
	//void EnemyAction();
	//void CheckIfFinish();
	//void Finish();

	void AddHero(Hero* h);
private:
	Hero* h;
	vector<Enemy*> enemies;
	vector<Creature*> allmembers;

	int turnNumber;

	int ATCalculer(int speed);

	//Calculate action order
	//static bool CompareAT( const Creature* const c1, const  Creature* const c2);

	//void ReOrderByAT();
};

#endif