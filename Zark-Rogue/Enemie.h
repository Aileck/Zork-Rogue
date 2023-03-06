#ifndef CAT_H
#define CAT_H

#include "creature.h"


class Enemie : public Creature {
public:
    Enemie();
    Enemie(string name, int hp, int attack, int defense, int speed);

};

#endif
