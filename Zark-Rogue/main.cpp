#include <iostream>


#include "World.h"
#include "Scene.h"
#include "Creature.h"
#include "Enemy.h"
#include "Hero.h"
#include "Weapon.h"
#include "InputProcessor.h"

using namespace std;


int main() {
    World* w = new World();

    Scene* s1 = new Scene("Scene 1","Level 1", 1);
    Weapon* newWeapon = new Weapon("Demon Slayer", "Good", 200, 0, 0, 5, Weapon::HAND_LEFT);
    s1->AddWeapon(newWeapon);

    cout << "Game start: ";
    string input;
    getline(std::cin, input);
    InputProcessor::ProcessInput(input,s1);



    //Hero* hero = new Hero();

    //hero->BeCheked();  

    //
    //Weapon* newWeapon2 = new Weapon("Demon Shield", "Bad", 200, 900, 0, 5, Weapon::HAND_RIGHT);
    //Weapon* newWeapon3 = new Weapon("Demon Shadow", "Normal", 200, 900, 10, 5, Weapon::FOOT);

    //newWeapon->BeCheked();
    //newWeapon2->BeCheked();

    //hero->EquipWeapon(newWeapon);
    //hero->EquipWeapon(newWeapon2);
    //hero->EquipWeapon(newWeapon3);
    //cout << "Change" << endl;

    //hero->BeCheked();
    return 0;
}