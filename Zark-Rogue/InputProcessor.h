#ifndef INPUTPROCESSOR_H
#define INPUTPROCESSOR_H

#include "Checkeable.h"
#include "Scene.h"
#include "Hero.h"
#include "World.h"

#include <sstream>

/*
Valid input:
	- {C}heck
	- {Go}to
	- {A}ttack
	- {T}alk
	- {I}nventory
	- {U}se
	- {P}ick
	- {H}elp
*/
class InputProcessor
{
public:
	static bool ProcessInput(string input, World* w);
	enum InputType {
		CHECK,
		GOTO,
		ATTACK,
		TALK,
		INVENTORY,
		USE,
		PICK,
		DROP,
		HELP,
		NOTREGISTERED
	};

private:
	static InputType InputToAction(string s);
	static void CheckAction(World* w, string target);
	static int GotoAction(Scene* s, string target);
	static void InventoryAciton(World* w);
	static void UseAction(World* w, string target);
	static void PickAciton(World* w, string target);
	static void DropAciton(World* w, string target);
};

#endif
