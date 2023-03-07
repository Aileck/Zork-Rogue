#include <iostream>

#include "Creature.h"
#include "Enemie.h"
#include "Hero.h"

#include "Weapon.h"

using namespace std;


int main() {
    Hero* hero = new Hero();

    hero->BeCheked();  

    Weapon* newWeapon = new Weapon("Demon Slayer", "Good", 200, 0, 0, 5, Weapon::HAND_LEFT);
    Weapon* newWeapon2 = new Weapon("Demon Shield", "Bad", 200, 900, 0, 5, Weapon::HAND_RIGHT);
    Weapon* newWeapon3 = new Weapon("Demon Shadow", "Normal", 200, 900, 10, 5, Weapon::FOOT);

    newWeapon->BeCheked();
    newWeapon2->BeCheked();

    hero->EquipWeapon(newWeapon);
    hero->EquipWeapon(newWeapon2);
    hero->EquipWeapon(newWeapon3);
    cout << "Change" << endl;

    hero->BeCheked();
    return 0;
}