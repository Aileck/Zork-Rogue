#include "Checkeable.h"

Checkeable::Checkeable(string name, string basicdefinition, bool specialcase)
{
	if (specialcase) {
		this->name = name;
	}
	else {
		this->name = "[" + name + "]";
	}

	this->definition = basicdefinition;
	this->checktime = 0;
}

void Checkeable::BeCheked()
{
}

string Checkeable::GetName()
{
	return this->name;
}

string Checkeable::GetBasicDefinition()
{
	return this->definition;
}

int Checkeable::GetCheckTime()
{
	return this->checktime;
}
