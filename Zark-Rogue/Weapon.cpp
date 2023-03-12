#include "Weapon.h"

Weapon::Weapon(bool isNoWeaponError):Item("NO WEAPON", "NO WEAPON", ItemType::WEAPON)
{
	if (!isNoWeaponError) {
		this->type = EQUIPPED_ERROR;
	}
	else {
		this->type = NO_WEAPON;
	}

}
Weapon::Weapon(WeaponType type):Item("NOT EQUIPPED", "You are not equipping anything in this slot.", ItemType::WEAPON)
{
	this->type = type;
	this->attack = 0;
	this->defense = 0;
	this->speed = 0;
	this->critical = 0;
	this->equipped = false;
}

Weapon::Weapon(string name,  string definition, int attack, int defense, int speed, int critical, WeaponType type):
	Item(name, definition, ItemType::WEAPON)
{
	this->attack = attack;
	this->defense = defense;
	this->speed = speed;
	this->critical = critical;
	this->type = type;
	this->equipped = false;
}

void Weapon::BeCheked()
{
	cout << "=== " << GetName() << " ===" << endl;
	cout << "* " << GetBasicDefinition()  << endl;
	cout << "* Attack:" << attack << endl;
	cout << "* Defense:" << defense << endl;
	cout << "* Speed:" << speed << endl << endl;

}

void Weapon::BeEquiped()
{
	this->location = INVENTORY;
	this->equipped = true;
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

bool Weapon::GetEquippedError()
{
	return (GetType() == EQUIPPED_ERROR) ? true : false;
}

bool Weapon::GetEquipped()
{
	return equipped;
}
