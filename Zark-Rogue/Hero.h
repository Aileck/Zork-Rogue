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
    void UnEquipWeapon(Weapon* newWeapon);
    string UseItem(Item* item);

    int GetCurrentAttack() override;
    int GetCurrentDefense() override;
    int GetCurrentSpeed() override;
    int GetCriticalRate();
    void CheckIfDead();
    void LeveUp();

    

private:
    int attackWeapon;
    int defenseWeapon;
    int speedWeapon;

    //Secret value
    int criticalRate;

    Weapon* handLeft;
    Weapon* handRight;
    Weapon* foot;

    void ChangePowerByWeapon(Weapon* newWeapon);

};

#endif
