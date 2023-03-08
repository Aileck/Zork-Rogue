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
	static bool ProcessInput(string input, Scene* scene, Hero* hero);
	enum InputType {
		CHECK,
		GOTO,
		ATTACK,
		TALK,
		INVENTORY,
		USE,
		PICK,
		HELP,
		NOTREGISTERED
	};

private:
	static InputType InputToType(string s);
	static void Check(Scene* s, string target);
};

#endif
