#include "Creature.h"

//Creature::Creature() {
//    this->name = "Test monster";
//    this->maxHp = 20;
//    this->curentHP = 20;
//    this->attack = 5;
//    this->defense = 5;
//    this->speed = 5;
//}

Creature::Creature(string name, string definition, int hp, int attack, int defense, int speed):Checkeable(name,definition) {
    this->currentHP = hp;
    this->attack = attack;
    this->defense = defense;
    this->speed = speed;
}

void Creature::BeCheked() {
    cout << "=== " << Checkeable::GetName() << " ===" << endl;
    cout <<  GetBasicDefinition() << endl;
    cout << "* " << "Attack: "<< this->attack << endl;
    cout << "* " << "Defense: " << this->defense  << endl;
    cout << "" << endl;
}

bool Creature::GetIsDead()
{
    return isDead;
}

int Creature::GetCurrentHP()
{
    return currentHP;
}

int Creature::GetCurrentAttack()
{
    return this->attack;
}

int Creature::GetCurrentDefense()
{
    return this->defense;
}

int Creature::GetCurrentSpeed()
{
    return this->speed;
}

void Creature::BeAttacked(int damage)
{
    currentHP -= damage;

    CheckIfDead();
}

void Creature::CheckIfDead()
{
    if (currentHP <= 0) {
        isDead = true;
        cout << this->GetName() << " is dead." << endl;
    }
}




