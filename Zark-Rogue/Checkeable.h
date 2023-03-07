#ifndef CHECKEABLE_H
#define CHECKEABLE_H

#include <iostream>
#include <string>

using namespace std;

class Checkeable
{
public:
	Checkeable(string name, string basicdefinition,bool specialcase = false);
	virtual void BeCheked();

	string GetName();
	string GetBasicDefinition();
	int GetCheckTime();

private:
		string name;
		string definition;
		int checktime;
};

#endif

