#ifndef CHECKEABLE_H
#define CHECKEABLE_H

#include <iostream>
#include <string>

using namespace std;

class Checkeable
{
public:
	Checkeable();
	Checkeable(string name, string basicdefinition,bool specialcase = false);
	virtual void BeCheked();

	string GetName(bool lower = false);
	string GetBasicDefinition();
	int GetCheckTime();

private:
		string name;
		string definition;
		int checktime;
};

#endif

