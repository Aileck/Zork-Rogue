#ifndef ENEMY_H
#define ENEMY_H

#include "creature.h"
#include "Item.h"



class Enemy : public Creature {
public:
    Enemy();
    Enemy(string name,string definition, int hp, int attack, int defense, int speed);
    void SetHold(Item* hold);
    Item* DropHold();
    void CheckIfDead();

private:
    Item* hold;
};

#endif
