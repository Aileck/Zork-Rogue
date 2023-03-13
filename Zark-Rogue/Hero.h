#ifndef HERO_H
#define HERO_H

#include "Creature.h"
#include "Item.h"
#include "Weapon.h"

class Hero : public Creature {
public:
    Hero();
    void BeCheked();
    string EquipWeapon(Weapon* newWeapon);
    string UseItem(Item* item);

    int GetCurrentAttack() override;
    int GetCurrentDefense() override;
    int GetCurrentSpeed() override;
    int GetCriticalRate();
    void CheckIfDead();

    

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
