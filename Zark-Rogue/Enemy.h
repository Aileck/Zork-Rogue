#ifndef CAT_H
#define CAT_H

#include "creature.h"
#include "Item.h"


class Enemy : public Creature {
public:
    Enemy();
    Enemy(string name,string definition, int hp, int attack, int defense, int speed);
    void SetHold(Item hold);

private:
    Item hold;
};

#endif
