#ifndef CEATURE_H
#define CEATURE_H

#include "Checkeable.h";

using namespace std;

class Creature:public Checkeable {
public:
    //Creature();
    Creature(string name, string definition,int hp, int attack, int defense, int speed);
    virtual void BeCheked();

protected:
    int curentHP;
    int attack;
    int defense;
    int speed;
};

#endif