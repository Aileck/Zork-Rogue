#include "Hero.h"

Hero::Hero():Creature("Hero", "The only thing you remember is that you are a hero.", 50,2,2,2) {
    Weapon* nullHandLeft = new Weapon(Weapon::HAND_LEFT);
    Weapon* nullHandRight = new Weapon(Weapon::HAND_RIGHT);
    Weapon* nullFoot = new Weapon(Weapon::FOOT);

    this->handLeft = nullHandLeft;
    this->handRight = nullHandRight;
    this->foot = nullFoot;

    attackWeapon = 0;
    defenseWeapon = 0;
    speedWeapon = 0;

    criticalRate = 10;
}

void Hero::BeCheked() {
    string attackByWeapon = (this->attackWeapon <= 0) ? "":" + (" + std::to_string(this->attackWeapon) + ")";
    string defenseByWeapon = (this->attackWeapon <= 0) ? "" : " + (" + std::to_string(this->attackWeapon) + ")";
    string speedByWeapon = (this->attackWeapon <= 0) ? "" : " + (" + std::to_string(this->attackWeapon) + ")";

    cout << "=== " << Checkeable::GetName() << " ===" << endl;
    cout << "=== " << this->curentHP << "/" << this->maxHp << " ===" << endl;
    cout << "* " << "Attack: " << this->attack  << attackByWeapon << endl; 
    cout << "* " << "Defense: " << this->attack << defenseByWeapon << endl;
    cout << "* " << "Speed: " << this->attack << speedByWeapon << endl;
    cout << " " << endl;
    cout << "Your equipments "<< endl;
    cout << "* " << "Sword: " << handLeft->GetName() << " attack +" << handLeft->GetAttack() << endl;
    cout << "* " << "Shield: " << handRight -> GetName() << " defense +" << handRight ->GetDefense() << endl;
    cout << "* " << "Foot: " << foot -> GetName() << " speed +" << foot->GetSpeed() << endl;


    cout << "" << endl;
}

string Hero::EquipWeapon(Weapon* newWeapon)
{
    newWeapon->BeEquiped();
    Weapon::WeaponType newWeaponType = newWeapon->GetType();
    string out = "Then you equipped " + newWeapon->GetName() + ".";
    switch (newWeaponType)
    {
    case Weapon::HAND_LEFT:
        if (this->handLeft->GetName(true) == "not equipped") {
            out += "\nGreat! You happen to need equip a sword, and then you won't be afraid of the monster in front of you.";
        }
        else {
            out += "\nAnd put " + this->handLeft->GetName()+ " in your inventory that was in your left hand.";
        }
        this->handLeft = newWeapon;
        ChangePowerByWeapon(newWeapon);
        break;
    case Weapon::HAND_RIGHT:
        if (this->handRight->GetName() == "not equipped") {
            out += "\nGreat! You happen to need equip a shield, that way it's harder for monsters to hurt you..";

        }
        else {
            out += "\nAnd put " + this->handLeft->GetName() + " in your inventory that was in your right hand.";
        }
        out += "\nAnd put " + this->handLeft->GetName() + " in your inventory that was in your left hand.";
        this->handRight = newWeapon;
        ChangePowerByWeapon(newWeapon);
        break;
    case Weapon::FOOT:
        if (this->foot->GetName() == "not equipped") {
        }
        else {
            out += "\nAnd put " + this->handLeft->GetName() + " in your inventory that was in your foot.";
        }
        this->foot = newWeapon;
        ChangePowerByWeapon(newWeapon);
        break;
    default:
        break;
    }

    return out;
}

void Hero::ChangePowerByWeapon(Weapon* newWeapon) {
    this->attackWeapon += newWeapon->GetAttack();
    this->defenseWeapon += newWeapon->GetDefense();
    this->speedWeapon += newWeapon->GetSpeed();
    this->criticalRate += newWeapon->GetCritical();
}
