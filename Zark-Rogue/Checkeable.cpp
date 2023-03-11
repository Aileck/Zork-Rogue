#include "Checkeable.h"
#include <string>
#include <iostream>
#include <sstream>

Checkeable::Checkeable()
{
	this->name = "Nothing";
	this->definition = "There's nothing here that you're looking for.";
}

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
	this->checktime++;
}


string Checkeable::GetName(bool lower)
{
	if (!lower) {
		return this->name;
	}
	else {
		string lowerName;
		for (char c : this->name) {
			if(c != '[' and c != ']')
				lowerName += tolower(c);
		}
		return lowerName;
	}
		
}

string Checkeable::GetBasicDefinition()
{
	return this->definition;
}

int Checkeable::GetCheckTime()
{
	return this->checktime;
}
