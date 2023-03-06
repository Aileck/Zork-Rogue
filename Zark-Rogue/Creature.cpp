#include "Creature.h"

Creature::Creature() {
    this->name = "Test monster";
    this->maxHp = 20;
    this->curentHP = 20;
    this->attack = 5;
    this->defense = 5;
    this->speed = 5;
}

Creature::Creature(string name, int hp, int attack, int defense, int speed) {
    this->name = name;
    this->maxHp = hp;
    this->curentHP = hp;
    this->attack = attack;
    this->defense = defense;
    this->speed = speed;
}

void Creature::BeCheked() {
    cout << "=== " << this->name << " ===" << endl;
    cout << "=== " << this->curentHP << "/" << this->maxHp << " ===" << endl;
    cout << "* " << "Attack: "<< this->attack << endl;
    cout << "* " << "Defense: " << this->attack  << endl;
    cout << "* " << "Speed: " << this->attack  << endl;

    cout << "--------------------------------------" << endl;
    cout << "" << endl;
}
