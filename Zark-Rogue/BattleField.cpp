#include "BattleField.h"

void BattleField::PrepareBattle(vector<Enemy*> newEmemies)
{
	for (int i = 0; i < newEmemies.size(); i++) {
		this->allmembers.push_back(newEmemies.at(i));
	}

	//Set AT to creatures
	//Less AT, fisrt act
	for (int i = 0; i < allmembers.size(); i++) {
		Creature* battlemember = allmembers.at(i);
		//battlemember->SetCurrentAT(battlemember->GetCurrentSpeed());
	}

	cout << "ANTES DE REORDEMAR" << endl;
	for (int i = 0; i < allmembers.size(); i++) {
		Creature* battlemember = allmembers.at(i);
		//cout << battlemember->GetName() << " " << to_string(battlemember->GetCurrentAT()) << endl;
	}

	//ReOrderByAT();
	
}

void BattleField::AddHero(Hero* h)
{
	this->h = h;
	allmembers.push_back(this->h);
}

int BattleField::ATCalculer(int speed)
{
	int at = ceil(100.0f / speed);

	return at;
}



//bool BattleField::CompareAT(const Creature* const c1, const  Creature* const c2)
//{
//	return (c1.GetCurrentAT() < c2.GetCurrentAT());
//}

//void BattleField::ReOrderByAT()
//{
//	//sort(allmembers.begin(), allmembers.end(), &BattleField::CompareAT);
//	std::sort(allmembers.begin(), allmembers.end(),
//		[](  Creature &c1, Creature &c2) {
//			return c1.GetCurrentAT() < c2.GetCurrentAT();
//		});
//
//	cout << "DESPUES DE REORDEMAR" << endl;
//	for (int i = 0; i < allmembers.size(); i++) {
//		Creature* battlemember = allmembers.at(i);
//		cout << battlemember->GetName() << " " << to_string(battlemember->GetCurrentAT()) << endl;
//	}
//
//
//}
