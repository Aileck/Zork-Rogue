#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include "string.h"

using namespace std;

class Creature {
public:
    Creature();
    Creature(string name, int hp, int attack, int defense, int speed);
    virtual void BeCheked();

private:
    string name;
    int maxHp;
    int curentHP;
    int attack;
    int defense;
    int speed;
};

#endif