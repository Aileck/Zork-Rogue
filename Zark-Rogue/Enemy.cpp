#include "Enemy.h"

Enemy::Enemy():Creature("NO ENEMY","NO ENEMY",0,0,0,0)
{
}

Enemy::Enemy(string name, string definition, int hp, int attack, int defense, int speed):Creature(name, definition, hp, attack,defense,speed) {
	
}

void Enemy::SetHold(Item hold)
{
	this->hold = hold;
}
