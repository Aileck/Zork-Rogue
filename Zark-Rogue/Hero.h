#ifndef HERO_H
#define HERO_H

#include "Creature.h"
#include "Weapon.h"

class Hero : public Creature {
public:
    Hero();
    virtual void BeCheked();
    string EquipWeapon(Weapon* newWeapon);

private:
    int attackWeapon;
    int defenseWeapon;
    int speedWeapon;

    int criticalRate;

    Weapon* handLeft;
    Weapon* handRight;
    Weapon* foot;

    void ChangePowerByWeapon(Weapon* newWeapon);

};

#endif
