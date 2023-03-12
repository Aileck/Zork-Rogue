#ifndef WEAPON_H
#define WEAPON_H

#include "Checkeable.h";
#include "Item.h";

using namespace std;

class Weapon:public Item
{
public:
	enum WeaponType {
		HAND_LEFT,
		HAND_RIGHT,
		FOOT,
		NO_WEAPON,
		EQUIPPED_ERROR
	};
	Weapon(bool isNoWeaponError = true);
	Weapon(WeaponType type);
	Weapon(string name,string definition ,int attack, int defense, int speed, int critical, WeaponType type);

	void BeCheked();
	void BeEquiped();
	int GetAttack();
	int GetDefense();
	int GetSpeed();
	int GetCritical();
	WeaponType GetType();
	bool GetEquippedError();
	bool GetEquipped();
	

private:
	bool equipped;
	WeaponType type;
	int attack;
	int defense;
	int speed;
	int critical;
};

#endif