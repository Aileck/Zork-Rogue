#ifndef CEATURE_H
#define CEATURE_H

#include "Checkeable.h";

using namespace std;

class Creature:public Checkeable {
public:
    //Creature();
    Creature(string name, string definition,int hp, int attack, int defense, int speed);
    virtual void BeCheked();

    bool GetIsDead();
    int GetCurrentHP();
    virtual int GetCurrentAttack();
    virtual int GetCurrentDefense();
    virtual int GetCurrentSpeed();

    void BeAttacked(int damage);
    virtual void CheckIfDead();

protected:
    int currentHP;
    int attack;
    int defense;
    int speed;

    bool isDead;

};

#endif