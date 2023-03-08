#ifndef INPUTPROCESSOR_H
#define INPUTPROCESSOR_H

#include "Scene.h"

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
*/
class InputProcessor
{
public:
	static bool ProcessInput(string input, Scene* scene);

private:
};

#endif
