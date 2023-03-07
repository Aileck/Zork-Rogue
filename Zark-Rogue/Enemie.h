#ifndef CAT_H
#define CAT_H

#include "creature.h"


class Enemie : public Creature {
public:
 
    Enemie(string name,string definition, int hp, int attack, int defense, int speed);

};

#endif
