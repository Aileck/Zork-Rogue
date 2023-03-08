#include "Weapon.h"

Weapon::Weapon(WeaponType type):Checkeable("NOT EQUIPPED", "You are not equipping anything in this slot.")
{
	this->type = type;
	this->attack = 0;
	this->defense = 0;
	this->speed = 0;
	this->critical = 0;
	this->picked = true;
}

Weapon::Weapon(string name,  string definition, int attack, int defense, int speed, int critical, WeaponType type):
	Checkeable(name, definition)
{
	this->attack = attack;
	this->defense = defense;
	this->speed = speed;
	this->critical = critical;
	this->type = type;
	this->picked = false;

}

void Weapon::BeCheked()
{
	cout << "=== " << GetName() << " ===" << endl;
	cout << "* " << GetBasicDefinition()  << endl;
	cout << "* Attack:" << attack << endl;
	cout << "* Defense:" << defense << endl;
	cout << "* Speed:" << speed << endl << endl;

}


int Weapon::GetAttack()
{
	return this->attack;
}

int Weapon::GetDefense()
{
	return this->defense;
}

int Weapon::GetSpeed()
{
	return this->speed;
}

int Weapon::GetCritical()
{
	return this->critical;
}

Weapon::WeaponType Weapon::GetType()
{
	return this->type;
}
