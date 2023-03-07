#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include "string.h"
#include "Checkeable.h";

using namespace std;

class Weapon:public Checkeable
{
public:
	enum WeaponType {
		HAND_LEFT,
		HAND_RIGHT,
		FOOT
	};
	Weapon(WeaponType type);
	Weapon(string name,string definition ,int attack, int defense, int speed, int critical, WeaponType type);

	void BeCheked();
	string GetName();
	string GetDescription();
	int GetAttack();
	int GetDefense();
	int GetSpeed();
	int GetCritical();
	WeaponType GetType();
	

private:
	WeaponType type;
	int attack;
	int defense;
	int speed;
	int critical;

};

#endif